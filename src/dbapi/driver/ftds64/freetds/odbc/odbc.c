/* FreeTDS - Library of routines accessing Sybase and Microsoft databases
 * Copyright (C) 1998, 1999, 2000, 2001  Brian Bruns
 * Copyright (C) 2002, 2003, 2004, 2005, 2006  Frediano Ziglio
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * PROGRAMMER   NAME            CONTACT
 *==============================================================
 * BSB          Brian Bruns     camber@ais.org
 * PAH          Peter Harvey    pharvey@codebydesign.com
 * SMURPH       Steve Murphree  smurph@smcomp.com
 *
 ***************************************************************
 * DATE         PROGRAMMER  CHANGE
 *==============================================================
 *                          Original.
 * 03.FEB.02    PAH         Started adding use of SQLGetPrivateProfileString().
 * 04.FEB.02	PAH         Fixed small error preventing SQLBindParameter from being called
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#include <stdio.h>

#if HAVE_STDLIB_H
#include <stdlib.h>
#endif /* HAVE_STDLIB_H */

#if HAVE_STRING_H
#include <string.h>
#endif /* HAVE_STRING_H */

#include <stdarg.h>
#include <assert.h>
#include <ctype.h>

#include "tdsodbc.h"
#include "tdsstring.h"
#include "tdsconvert.h"
#include "replacements.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif

TDS_RCSID(var, "$Id: odbc.c 355815 2012-03-08 17:05:20Z ivanovp $");

static SQLRETURN SQL_API _SQLAllocConnect(SQLHENV henv, SQLHDBC FAR * phdbc);
static SQLRETURN SQL_API _SQLAllocEnv(SQLHENV FAR * phenv);
static SQLRETURN SQL_API _SQLAllocStmt(SQLHDBC hdbc, SQLHSTMT FAR * phstmt);
static SQLRETURN SQL_API _SQLAllocDesc(SQLHDBC hdbc, SQLHSTMT FAR * phstmt);
static SQLRETURN SQL_API _SQLFreeConnect(SQLHDBC hdbc);
static SQLRETURN SQL_API _SQLFreeEnv(SQLHENV henv);
static SQLRETURN SQL_API _SQLFreeStmt(SQLHSTMT hstmt, SQLUSMALLINT fOption, int force);
static SQLRETURN SQL_API _SQLFreeDesc(SQLHDESC hdesc);
static SQLRETURN SQL_API _SQLExecute(TDS_STMT * stmt);
static SQLRETURN SQL_API _SQLGetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength,
					    SQLINTEGER * StringLength);
static SQLRETURN SQL_API _SQLSetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength);
static SQLRETURN SQL_API _SQLSetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength);
static SQLRETURN SQL_API _SQLGetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength,
					 SQLINTEGER * StringLength);
static SQLRETURN SQL_API _SQLColAttribute(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType, SQLPOINTER rgbDesc,
					  SQLSMALLINT cbDescMax, SQLSMALLINT FAR * pcbDesc, SQLLEN FAR * pfDesc);
static SQLRETURN SQL_API _SQLFetch(TDS_STMT * stmt);
static int query_timeout_cancel(void *param, unsigned int total_timeout);
static SQLRETURN odbc_populate_ird(TDS_STMT * stmt);
static int odbc_errmsg_handler(const TDSCONTEXT * ctx, TDSSOCKET * tds, TDSMESSAGE * msg);
static void odbc_log_unimplemented_type(const char function_name[], int fType);
static void odbc_upper_column_names(TDS_STMT * stmt);
static void odbc_col_setname(TDS_STMT * stmt, int colpos, const char *name);
static SQLRETURN odbc_stat_execute(TDS_STMT * stmt, const char *begin, int nparams, ...);
static SQLRETURN odbc_free_dynamic(TDS_STMT * stmt);
static SQLSMALLINT odbc_swap_datetime_sql_type(SQLSMALLINT sql_type);
static int odbc_process_tokens(TDS_STMT * stmt, unsigned flag);

#if ENABLE_EXTRA_CHECKS
static void odbc_ird_check(TDS_STMT * stmt);

#define IRD_CHECK odbc_ird_check(stmt)
#else
#define IRD_CHECK
#endif

/**
 * \defgroup odbc_api ODBC API
 * Functions callable by \c ODBC client programs
 */


/* utils to check handles */
#define CHECK_HDBC  if ( SQL_NULL_HDBC  == hdbc || !IS_HDBC(hdbc) ) return SQL_INVALID_HANDLE;
#define CHECK_HSTMT if ( SQL_NULL_HSTMT == hstmt || !IS_HSTMT(hstmt) ) return SQL_INVALID_HANDLE;
#define CHECK_HENV  if ( SQL_NULL_HENV  == henv || !IS_HENV(henv) ) return SQL_INVALID_HANDLE;
#define CHECK_HDESC if ( SQL_NULL_HDESC == hdesc || !IS_HDESC(hdesc) ) return SQL_INVALID_HANDLE;

#define INIT_HSTMT \
	TDS_STMT *stmt = (TDS_STMT*)hstmt; \
	CHECK_HSTMT; \
	CHECK_STMT_EXTRA(stmt); \
	odbc_errs_reset(&stmt->errs); \

#define INIT_HDBC \
	TDS_DBC *dbc = (TDS_DBC*)hdbc; \
	CHECK_HDBC; \
	CHECK_DBC_EXTRA(dbc); \
	odbc_errs_reset(&dbc->errs); \

#define INIT_HENV \
	TDS_ENV *env = (TDS_ENV*)henv; \
	CHECK_HENV; \
	CHECK_ENV_EXTRA(env); \
	odbc_errs_reset(&env->errs); \

#define INIT_HDESC \
	TDS_DESC *desc = (TDS_DESC*)hdesc; \
	CHECK_HDESC; \
	CHECK_DESC_EXTRA(desc); \
	odbc_errs_reset(&desc->errs); \

#define IS_VALID_LEN(len) ((len) >= 0 || (len) == SQL_NTS || (len) == SQL_NULL_DATA)

/*
 * Note: I *HATE* hungarian notation, it has to be the most idiotic thing
 * I've ever seen. So, you will note it is avoided other than in the function
 * declarations. "Gee, let's make our code totally hard to read and they'll
 * beg for GUI tools"
 * Bah!
 */

static void
odbc_col_setname(TDS_STMT * stmt, int colpos, const char *name)
{
#if ENABLE_EXTRA_CHECKS
	TDSRESULTINFO *resinfo;
#endif

	IRD_CHECK;

#if ENABLE_EXTRA_CHECKS
	if (colpos > 0 && stmt->dbc->tds_socket != NULL && (resinfo = stmt->dbc->tds_socket->current_results) != NULL) {
		if (colpos <= resinfo->num_cols) {
			/* no overflow possible, name is always shorter */
			strcpy(resinfo->columns[colpos - 1]->column_name, name);
			resinfo->columns[colpos - 1]->column_namelen = strlen(name);
		}
	}
#endif

	if (colpos > 0 && colpos <= stmt->ird->header.sql_desc_count) {
		--colpos;
		tds_dstr_copy(&stmt->ird->records[colpos].sql_desc_label, name);
		tds_dstr_copy(&stmt->ird->records[colpos].sql_desc_name, name);
	}
}

/* spinellia@acm.org : copied shamelessly from change_database */
static SQLRETURN
change_autocommit(TDS_DBC * dbc, int state)
{
	TDSSOCKET *tds = dbc->tds_socket;
	char query[80];

	/*
	 * We may not be connected yet and dbc->tds_socket
	 * may not initialized.
	 */
	if (tds) {
		/*
		 * mssql: SET IMPLICIT_TRANSACTION ON
		 * sybase: SET CHAINED ON
		 */

		/* implicit transactions are on if autocommit is off :-| */
		if (TDS_IS_MSSQL(tds))
			sprintf(query, "SET IMPLICIT_TRANSACTIONS %s", (state == SQL_AUTOCOMMIT_ON) ? "OFF" : "ON");
		else {
			/* Sybase, do not use SET CHAINED but emulate for compatility */
			if (state == SQL_AUTOCOMMIT_ON)
				strcpy(query, "WHILE @@TRANCOUNT > 0 COMMIT");
			else
				strcpy(query, "BEGIN TRANSACTION");
		}

		tdsdump_log(TDS_DBG_INFO1, "change_autocommit: executing %s\n", query);

		if (tds_submit_query(tds, query) != TDS_SUCCEED) {
			odbc_errs_add(&dbc->errs, "HY000", "Could not change transaction status");
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		if (tds_process_simple_query(tds) != TDS_SUCCEED) {
			odbc_errs_add(&dbc->errs, "HY000", "Could not change transaction status");
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		dbc->attr.autocommit = state;
	}
	ODBC_RETURN_(dbc);
}

static SQLRETURN
change_database(TDS_DBC * dbc, char *database, int database_len)
{
	TDSSOCKET *tds = dbc->tds_socket;

	/*
	 * We may not be connected yet and dbc->tds_socket
	 * may not initialized.
	 */
	if (tds) {
		/* build query */
		char *query = (char *) malloc(6 + tds_quote_id(tds, NULL, database, database_len));

		if (!query) {
			odbc_errs_add(&dbc->errs, "HY001", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		strcpy(query, "USE ");
		tds_quote_id(tds, query + 4, database, database_len);


		tdsdump_log(TDS_DBG_INFO1, "change_database: executing %s\n", query);

		if (tds_submit_query(tds, query) != TDS_SUCCEED) {
			free(query);
			odbc_errs_add(&dbc->errs, "HY000", "Could not change database");
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		free(query);
		if (tds_process_simple_query(tds) != TDS_SUCCEED) {
			odbc_errs_add(&dbc->errs, "HY000", "Could not change database");
			ODBC_RETURN(dbc, SQL_ERROR);
		}
	}
	ODBC_RETURN_(dbc);
}

static void
odbc_env_change(TDSSOCKET * tds, int type, char *oldval, char *newval)
{
	TDS_DBC *dbc;

	if (tds == NULL) {
		return;
	}
	dbc = (TDS_DBC *) tds->parent;
	if (!dbc)
		return;

	switch (type) {
	case TDS_ENV_DATABASE:
		tds_dstr_copy(&dbc->attr.current_catalog, newval);
		break;
	case TDS_ENV_PACKSIZE:
		dbc->attr.packet_size = atoi(newval);
		break;
	}
}

static SQLRETURN
odbc_connect(TDS_DBC * dbc, TDSCONNECTION * connection)
{
	TDS_ENV *env = dbc->env;

	dbc->tds_socket = tds_alloc_socket(env->tds_ctx, 512);
	if (!dbc->tds_socket) {
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
	tds_set_parent(dbc->tds_socket, (void *) dbc);

	/* Set up our environment change hook */
	dbc->tds_socket->env_chg_func = odbc_env_change;

	tds_fix_connection(connection);

	connection->connect_timeout = dbc->attr.connection_timeout;

	if (tds_connect(dbc->tds_socket, connection) == TDS_FAIL) {
		tds_free_socket(dbc->tds_socket);
		dbc->tds_socket = NULL;
		odbc_errs_add(&dbc->errs, "08001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
	/* this overwrite any error arrived (wanted behavior, Sybase return error for conversion errors) */
	ODBC_RETURN(dbc, SQL_SUCCESS);
}

SQLRETURN SQL_API
SQLDriverConnect(SQLHDBC hdbc, SQLHWND hwnd, SQLCHAR FAR * szConnStrIn, SQLSMALLINT cbConnStrIn, SQLCHAR FAR * szConnStrOut,
		 SQLSMALLINT cbConnStrOutMax, SQLSMALLINT FAR * pcbConnStrOut, SQLUSMALLINT fDriverCompletion)
{
	TDSCONNECTION *connection;
	int conlen = odbc_get_string_size(cbConnStrIn, szConnStrIn);

	INIT_HDBC;

#ifdef TDS_NO_DM
	/* Check string length */
	if (!IS_VALID_LEN(conlen) || conlen == 0) {
		odbc_errs_add(&dbc->errs, "HY090", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* Check completion param */
	switch (fDriverCompletion) {
	case SQL_DRIVER_NOPROMPT:
	case SQL_DRIVER_COMPLETE:
	case SQL_DRIVER_PROMPT:
	case SQL_DRIVER_COMPLETE_REQUIRED:
		break;
	default:
		odbc_errs_add(&dbc->errs, "HY110", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
#endif

	connection = tds_alloc_connection(dbc->env->tds_ctx->locale);
	if (!connection) {
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* parse the DSN string */
	odbc_parse_connect_string((const char *) szConnStrIn, (const char *) szConnStrIn + conlen, connection);

	/* add login info */
	if (hwnd) {
#ifdef WIN32
		/* prompt for login information */
		if (!get_login_info(hwnd, connection)) {
			tds_free_connection(connection);
			odbc_errs_add(&dbc->errs, "08001", "User canceled login");
			ODBC_RETURN(dbc, SQL_ERROR);
		}
#else
		/* we dont support a dialog box */
		odbc_errs_add(&dbc->errs, "HYC00", NULL);
#endif
	}

	/* TODO what should be correct behavior for output string?? -- freddy77 */
	if (szConnStrOut)
		odbc_set_string(szConnStrOut, cbConnStrOutMax, pcbConnStrOut, (const char *) szConnStrIn, conlen);

	if (tds_dstr_isempty(&connection->server_name)) {
		tds_free_connection(connection);
		odbc_errs_add(&dbc->errs, "IM007", "Could not find Servername or server parameter");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	if (tds_dstr_isempty(&connection->user_name)) {
		tds_free_connection(connection);
		odbc_errs_add(&dbc->errs, "IM007", "Could not find UID parameter");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	if (odbc_connect(dbc, connection) != SQL_SUCCESS) {
		tds_free_connection(connection);
		ODBC_RETURN_(dbc);
	}

	tds_free_connection(connection);
	ODBC_RETURN_(dbc);
}

#if 0
SQLRETURN SQL_API
SQLBrowseConnect(SQLHDBC hdbc, SQLCHAR FAR * szConnStrIn, SQLSMALLINT cbConnStrIn, SQLCHAR FAR * szConnStrOut,
		 SQLSMALLINT cbConnStrOutMax, SQLSMALLINT FAR * pcbConnStrOut)
{
	INIT_HDBC;
	odbc_errs_add(&dbc->errs, "HYC00", "SQLBrowseConnect: function not implemented");
	ODBC_RETURN(dbc, SQL_ERROR);
}
#endif

SQLRETURN SQL_API
SQLColumnPrivileges(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
		    SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName, SQLCHAR FAR * szColumnName,
		    SQLSMALLINT cbColumnName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_column_privileges ", 4, "O@table_qualifier", szCatalogName, cbCatalogName,
				  "O@table_owner", szSchemaName, cbSchemaName, "O@table_name", szTableName, cbTableName,
				  "P@column_name", szColumnName, cbColumnName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

#if 0
SQLRETURN SQL_API
SQLDescribeParam(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT FAR * pfSqlType, SQLUINTEGER FAR * pcbParamDef,
		 SQLSMALLINT FAR * pibScale, SQLSMALLINT FAR * pfNullable)
{
	INIT_HSTMT;
	odbc_errs_add(&stmt->errs, "HYC00", "SQLDescribeParam: function not implemented");
	ODBC_RETURN(stmt, SQL_ERROR);
}
#endif

SQLRETURN SQL_API
SQLExtendedFetch(SQLHSTMT hstmt, SQLUSMALLINT fFetchType, SQLLEN irow, SQLULEN FAR * pcrow, SQLUSMALLINT FAR * rgfRowStatus)
{
	SQLRETURN ret;
	SQLULEN * tmp_rows;
	SQLUSMALLINT * tmp_status;
	SQLULEN tmp_size;
	SQLLEN * tmp_offset;

	INIT_HSTMT;

	/* still we do not support cursors and scrolling */
	/* TODO cursors */
	if (fFetchType != SQL_FETCH_NEXT) {
		odbc_errs_add(&stmt->errs, "HY106", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* save and change IRD/ARD state */
	tmp_rows = stmt->ird->header.sql_desc_rows_processed_ptr;
	stmt->ird->header.sql_desc_rows_processed_ptr = pcrow;
	tmp_status = stmt->ird->header.sql_desc_array_status_ptr;
	stmt->ird->header.sql_desc_array_status_ptr = rgfRowStatus;
	tmp_size = stmt->ard->header.sql_desc_array_size;
	stmt->ard->header.sql_desc_array_size = stmt->sql_rowset_size;
	tmp_offset = stmt->ard->header.sql_desc_bind_offset_ptr;
	stmt->ard->header.sql_desc_bind_offset_ptr = NULL;

	/* TODO errors are sligthly different ... perhaps it's better to leave DM do this job ?? */
	ret = _SQLFetch(stmt);

	/* restore IRD/ARD */
	stmt->ird->header.sql_desc_rows_processed_ptr = tmp_rows;
	stmt->ird->header.sql_desc_array_status_ptr = tmp_status;
	stmt->ard->header.sql_desc_array_size = tmp_size;
	stmt->ard->header.sql_desc_bind_offset_ptr = tmp_offset;

	ODBC_RETURN(stmt, ret);
}

SQLRETURN SQL_API
SQLForeignKeys(SQLHSTMT hstmt, SQLCHAR FAR * szPkCatalogName, SQLSMALLINT cbPkCatalogName, SQLCHAR FAR * szPkSchemaName,
	       SQLSMALLINT cbPkSchemaName, SQLCHAR FAR * szPkTableName, SQLSMALLINT cbPkTableName, SQLCHAR FAR * szFkCatalogName,
	       SQLSMALLINT cbFkCatalogName, SQLCHAR FAR * szFkSchemaName, SQLSMALLINT cbFkSchemaName, SQLCHAR FAR * szFkTableName,
	       SQLSMALLINT cbFkTableName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_fkeys ", 6, "O@pktable_qualifier", szPkCatalogName, cbPkCatalogName, "O@pktable_owner",
				  szPkSchemaName, cbPkSchemaName, "O@pktable_name", szPkTableName, cbPkTableName,
				  "O@fktable_qualifier", szFkCatalogName, cbFkCatalogName, "O@fktable_owner", szFkSchemaName,
				  cbFkSchemaName, "O@fktable_name", szFkTableName, cbFkTableName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "PKTABLE_CAT");
		odbc_col_setname(stmt, 2, "PKTABLE_SCHEM");
		odbc_col_setname(stmt, 5, "FKTABLE_CAT");
		odbc_col_setname(stmt, 6, "FKTABLE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLMoreResults(SQLHSTMT hstmt)
{
	TDSSOCKET *tds;
	TDS_INT result_type;
	int tdsret;
	int in_row = 0;
	SQLUSMALLINT param_status;
	int token_flags;

	INIT_HSTMT;

	tds = stmt->dbc->tds_socket;

	/* we already readed all results... */
	/* TODO cursor */
	if (stmt->dbc->current_statement != stmt)
		ODBC_RETURN(stmt, SQL_NO_DATA);

	stmt->row_count = TDS_NO_COUNT;
	stmt->special_row = 0;

	/* TODO this code is TOO similar to _SQLExecute, merge it - freddy77 */
	/* try to go to the next recordset */
	if (stmt->row_status == IN_COMPUTE_ROW) {
		/* FIXME doesn't seem so fine ... - freddy77 */
		tds_process_tokens(stmt->dbc->tds_socket, &result_type, NULL, TDS_TOKEN_TRAILING);
		stmt->row_status = IN_COMPUTE_ROW;
		in_row = 1;
	}

	param_status = SQL_PARAM_SUCCESS;
	token_flags = (TDS_TOKEN_RESULTS & (~TDS_STOPAT_COMPUTE)) | TDS_RETURN_COMPUTE;
	if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3)
		token_flags |= TDS_RETURN_MSG;
	for (;;) {
		result_type = odbc_process_tokens(stmt, token_flags);
		switch (result_type) {
		case TDS_CMD_DONE:
			if (stmt->dbc->current_statement == stmt)
				stmt->dbc->current_statement = NULL;
#if 1 /* !UNIXODBC */
			tds_free_all_results(tds);
#endif
			odbc_populate_ird(stmt);
			if (stmt->row_count == TDS_NO_COUNT && !in_row) {
				stmt->row_status = NOT_IN_ROW;
				if (stmt->next_row_count != TDS_NO_COUNT) {
					stmt->row_count = stmt->next_row_count;
					stmt->row_status = PRE_NORMAL_ROW;
				}
			}
			stmt->next_row_count = TDS_NO_COUNT;
			if (stmt->row_count == TDS_NO_COUNT && (stmt->errs.lastrc == SQL_SUCCESS || stmt->errs.lastrc == SQL_SUCCESS_WITH_INFO))
				ODBC_RETURN(stmt, SQL_NO_DATA);
			ODBC_RETURN_(stmt);

		case TDS_CMD_FAIL:
			ODBC_RETURN(stmt, SQL_ERROR);

		case TDS_COMPUTE_RESULT:
			switch (stmt->row_status) {
			/* skip this recordset */
			case IN_COMPUTE_ROW:
				/* TODO here we should set current_results to normal results */
				in_row = 1;
				/* fall throgh */
			/* in normal row, put in compute status */
			case AFTER_COMPUTE_ROW:
			case IN_NORMAL_ROW:
			case PRE_NORMAL_ROW:
				stmt->row_status = IN_COMPUTE_ROW;
				odbc_populate_ird(stmt);
				ODBC_RETURN_(stmt);
			case NOT_IN_ROW:
				/* this should never happen, protocol error */
				ODBC_RETURN(stmt, SQL_ERROR);
				break;
			}
			break;

		case TDS_ROW_RESULT:
			if (in_row || (stmt->row_status != IN_NORMAL_ROW && stmt->row_status != PRE_NORMAL_ROW)) {
				stmt->row_status = PRE_NORMAL_ROW;
				odbc_populate_ird(stmt);
				ODBC_RETURN_(stmt);
			}
			/* Skipping current result set's rows to access next resultset or proc's retval */
			tdsret = tds_process_tokens(tds, &result_type, NULL, TDS_STOPAT_ROWFMT|TDS_RETURN_DONE|TDS_STOPAT_COMPUTE);
			/* TODO should we set in_row ?? */
			if (tdsret == TDS_FAIL || tdsret == TDS_CANCELLED)
				ODBC_RETURN(stmt, SQL_ERROR);
			break;

		case TDS_DONE_RESULT:
		case TDS_DONEPROC_RESULT:
			/* FIXME here ??? */
			if (!in_row)
				tds_free_all_results(tds);
			switch (stmt->errs.lastrc) {
			case SQL_ERROR:
				param_status = SQL_PARAM_ERROR;
				break;
			case SQL_SUCCESS_WITH_INFO:
				param_status = SQL_PARAM_SUCCESS_WITH_INFO;
				break;
			}
			if (stmt->curr_param_row < stmt->num_param_rows) {
				if (stmt->ipd->header.sql_desc_array_status_ptr)
					stmt->ipd->header.sql_desc_array_status_ptr[stmt->curr_param_row] = param_status;
				++stmt->curr_param_row;
				if (stmt->ipd->header.sql_desc_rows_processed_ptr)
					*stmt->ipd->header.sql_desc_rows_processed_ptr = stmt->curr_param_row;
			}
			if (stmt->curr_param_row < stmt->num_param_rows) {
#if 0
				if (stmt->errs.lastrc == SQL_SUCCESS_WITH_INFO)
					found_info = 1;
				if (stmt->errs.lastrc == SQL_ERROR)
					found_error = 1;
#endif
				stmt->errs.lastrc = SQL_SUCCESS;
				param_status = SQL_PARAM_SUCCESS;
				break;
			}
			odbc_populate_ird(stmt);
			ODBC_RETURN_(stmt);
			break;

			/*
			 * TODO test flags ? check error and change result ?
			 * see also other DONEINPROC handle (below)
			 */
		case TDS_DONEINPROC_RESULT:
			if (in_row) {
				odbc_populate_ird(stmt);
				ODBC_RETURN_(stmt);
			}
			/* TODO perhaps it can be a problem if SET NOCOUNT ON, test it */
			tds_free_all_results(tds);
			odbc_populate_ird(stmt);
			break;

			/* do not stop at metadata, an error can follow... */
		case TDS_ROWFMT_RESULT:
			if (in_row) {
				odbc_populate_ird(stmt);
				ODBC_RETURN_(stmt);
			}
			stmt->row = 0;
			stmt->row_count = TDS_NO_COUNT;
			stmt->next_row_count = TDS_NO_COUNT;
			/* we expect a row */
			stmt->row_status = PRE_NORMAL_ROW;
			in_row = 1;
			break;

		case TDS_MSG_RESULT:
			if (!in_row) {
				tds_free_all_results(tds);
				odbc_populate_ird(stmt);
			}
			in_row = 1;
			break;
		}
	}
	ODBC_RETURN(stmt, SQL_ERROR);
}

SQLRETURN SQL_API
SQLNativeSql(SQLHDBC hdbc, SQLCHAR FAR * szSqlStrIn, SQLINTEGER cbSqlStrIn, SQLCHAR FAR * szSqlStr, SQLINTEGER cbSqlStrMax,
	     SQLINTEGER FAR * pcbSqlStr)
{
	SQLRETURN ret = SQL_SUCCESS;
	DSTR query;

	INIT_HDBC;

	tds_dstr_init(&query);

#ifdef TDS_NO_DM
	if (!szSqlStrIn || !IS_VALID_LEN(cbSqlStrIn)) {
		odbc_errs_add(&dbc->errs, "HY009", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
#endif

	if (!tds_dstr_copyn(&query, (const char *) szSqlStrIn, odbc_get_string_size(cbSqlStrIn, szSqlStrIn))) {
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* TODO support not null terminated in native_sql */
	native_sql(dbc, tds_dstr_cstr(&query));

	ret = odbc_set_string_i(szSqlStr, cbSqlStrMax, pcbSqlStr, tds_dstr_cstr(&query), -1);

	tds_dstr_free(&query);

	ODBC_RETURN(dbc, ret);
}

SQLRETURN SQL_API
SQLNumParams(SQLHSTMT hstmt, SQLSMALLINT FAR * pcpar)
{
	INIT_HSTMT;
	*pcpar = stmt->param_count;
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLParamOptions(SQLHSTMT hstmt, SQLULEN crow, SQLULEN FAR * pirow)
{
	SQLRETURN res;

	/* emulate for ODBC 2 DM */
	res = _SQLSetStmtAttr(hstmt, SQL_ATTR_PARAMS_PROCESSED_PTR, pirow, 0);
	if (res != SQL_SUCCESS)
		return res;
	return _SQLSetStmtAttr(hstmt, SQL_ATTR_PARAMSET_SIZE, (SQLPOINTER) crow, 0);
}

SQLRETURN SQL_API
SQLPrimaryKeys(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
	       SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_pkeys ", 3, "O@table_qualifier", szCatalogName, cbCatalogName, "O@table_owner",
				  szSchemaName, cbSchemaName, "O@table_name", szTableName, cbTableName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLProcedureColumns(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
		    SQLSMALLINT cbSchemaName, SQLCHAR FAR * szProcName, SQLSMALLINT cbProcName, SQLCHAR FAR * szColumnName,
		    SQLSMALLINT cbColumnName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_sproc_columns ", 4, "O@procedure_qualifier", szCatalogName, cbCatalogName,
				  "P@procedure_owner", szSchemaName, cbSchemaName, "P@procedure_name", szProcName, cbProcName,
				  "P@column_name", szColumnName, cbColumnName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "PROCEDURE_CAT");
		odbc_col_setname(stmt, 2, "PROCEDURE_SCHEM");
		odbc_col_setname(stmt, 8, "COLUMN_SIZE");
		odbc_col_setname(stmt, 9, "BUFFER_LENGTH");
		odbc_col_setname(stmt, 10, "DECIMAL_DIGITS");
		odbc_col_setname(stmt, 11, "NUM_PREC_RADIX");
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLProcedures(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
	      SQLSMALLINT cbSchemaName, SQLCHAR FAR * szProcName, SQLSMALLINT cbProcName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "..sp_stored_procedures ", 3, "P@sp_name", szProcName, cbProcName, "P@sp_owner", szSchemaName,
				  cbSchemaName, "O@sp_qualifier", szCatalogName, cbCatalogName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "PROCEDURE_CAT");
		odbc_col_setname(stmt, 2, "PROCEDURE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

#if 0
SQLRETURN SQL_API
SQLSetPos(SQLHSTMT hstmt, SQLUSMALLINT irow, SQLUSMALLINT fOption, SQLUSMALLINT fLock)
{
	INIT_HSTMT;
	/* TODO cursors */
	odbc_errs_add(&stmt->errs, "HYC00", "SQLSetPos: function not implemented");
	ODBC_RETURN(stmt, SQL_ERROR);
}
#endif

SQLRETURN SQL_API
SQLTablePrivileges(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
		   SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_table_privileges ", 3, "O@table_qualifier", szCatalogName, cbCatalogName,
				  "P@table_owner", szSchemaName, cbSchemaName, "P@table_name", szTableName, cbTableName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLSetEnvAttr(SQLHENV henv, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER StringLength)
{
	INIT_HENV;

	switch (Attribute) {
	case SQL_ATTR_CONNECTION_POOLING:
	case SQL_ATTR_CP_MATCH:
		odbc_errs_add(&env->errs, "HYC00", NULL);
		ODBC_RETURN(env, SQL_ERROR);
		break;
	case SQL_ATTR_ODBC_VERSION:
		switch ((SQLULEN) Value) {
		case SQL_OV_ODBC3:
		case SQL_OV_ODBC2:
			break;
		default:
			odbc_errs_add(&env->errs, "HY024", NULL);
			ODBC_RETURN(env, SQL_ERROR);
		}
		env->attr.odbc_version = (SQLINTEGER) Value;
		ODBC_RETURN_(env);
		break;
	case SQL_ATTR_OUTPUT_NTS:
		env->attr.output_nts = (SQLINTEGER) Value;
		/* TODO - Make this really work */
		/* env->attr.output_nts = SQL_TRUE; */
		ODBC_RETURN_(env);
		break;
	}
	odbc_errs_add(&env->errs, "HY092", NULL);
	ODBC_RETURN(env, SQL_ERROR);
}

SQLRETURN SQL_API
SQLGetEnvAttr(SQLHENV henv, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER * StringLength)
{
	size_t size;
	void *src;

	INIT_HENV;

	switch (Attribute) {
	case SQL_ATTR_CONNECTION_POOLING:
		src = &env->attr.connection_pooling;
		size = sizeof(env->attr.connection_pooling);
		break;
	case SQL_ATTR_CP_MATCH:
		src = &env->attr.cp_match;
		size = sizeof(env->attr.cp_match);
		break;
	case SQL_ATTR_ODBC_VERSION:
		src = &env->attr.odbc_version;
		size = sizeof(env->attr.odbc_version);
		break;
	case SQL_ATTR_OUTPUT_NTS:
		/* TODO handle output_nts flags */
		env->attr.output_nts = SQL_TRUE;
		src = &env->attr.output_nts;
		size = sizeof(env->attr.output_nts);
		break;
	default:
		odbc_errs_add(&env->errs, "HY092", NULL);
		ODBC_RETURN(env, SQL_ERROR);
		break;
	}

	if (StringLength) {
		*StringLength = size;
	}
	memcpy(Value, src, size);

	ODBC_RETURN_(env);
}

#endif

static SQLRETURN
_SQLBindParameter(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fParamType, SQLSMALLINT fCType, SQLSMALLINT fSqlType,
		  SQLULEN cbColDef, SQLSMALLINT ibScale, SQLPOINTER rgbValue, SQLLEN cbValueMax, SQLLEN FAR * pcbValue)
{
	TDS_DESC *apd, *ipd;
	struct _drecord *drec;
	SQLSMALLINT orig_apd_size, orig_ipd_size;
	int is_numeric = 0;

	INIT_HSTMT;

#ifdef TDS_NO_DM
	/* TODO - more error checking ...  XXX smurph */

	/* Check param type */
	switch (fParamType) {
	case SQL_PARAM_INPUT:
	case SQL_PARAM_INPUT_OUTPUT:
	case SQL_PARAM_OUTPUT:
		break;
	default:
		odbc_errs_add(&stmt->errs, "HY105", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* Check max buffer length */
	if (cbValueMax < 0) {
		odbc_errs_add(&stmt->errs, "HY090", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
#endif

	/* check cbColDef and ibScale */
	if (fSqlType == SQL_DECIMAL || fSqlType == SQL_NUMERIC) {
		is_numeric = 1;
		if (cbColDef < 1 || cbColDef > 38) {
			odbc_errs_add(&stmt->errs, "HY104", "Invalid precision value");
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		if (ibScale < 0 || (SQLULEN)ibScale > cbColDef) {
			odbc_errs_add(&stmt->errs, "HY104", "Invalid scale value");
			ODBC_RETURN(stmt, SQL_ERROR);
		}
	}

	/* Check parameter number */
	if (ipar <= 0 || ipar > 4000) {
		odbc_errs_add(&stmt->errs, "07009", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* fill APD related fields */
	apd = stmt->apd;
	orig_apd_size = apd->header.sql_desc_count;
	if (ipar > apd->header.sql_desc_count && desc_alloc_records(apd, ipar) != SQL_SUCCESS) {
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	drec = &apd->records[ipar - 1];

	if (odbc_set_concise_c_type(fCType, drec, 0) != SQL_SUCCESS) {
		desc_alloc_records(apd, orig_apd_size);
		odbc_errs_add(&stmt->errs, "HY004", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	stmt->need_reprepare = 1;

	/* TODO other types ?? handle SQL_C_DEFAULT */
	if (drec->sql_desc_type == SQL_C_CHAR || drec->sql_desc_type == SQL_C_BINARY)
		drec->sql_desc_octet_length = cbValueMax;
	drec->sql_desc_indicator_ptr = pcbValue;
	drec->sql_desc_octet_length_ptr = pcbValue;
	drec->sql_desc_data_ptr = (char *) rgbValue;

	/* field IPD related fields */
	ipd = stmt->ipd;
	orig_ipd_size = ipd->header.sql_desc_count;
	if (ipar > ipd->header.sql_desc_count && desc_alloc_records(ipd, ipar) != SQL_SUCCESS) {
		desc_alloc_records(apd, orig_apd_size);
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	drec = &ipd->records[ipar - 1];

	drec->sql_desc_parameter_type = fParamType;
	if (odbc_set_concise_sql_type(fSqlType, drec, 0) != SQL_SUCCESS) {
		desc_alloc_records(ipd, orig_ipd_size);
		desc_alloc_records(apd, orig_apd_size);
		odbc_errs_add(&stmt->errs, "HY004", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	if (is_numeric) {
		drec->sql_desc_precision = (SQLSMALLINT)cbColDef;
		drec->sql_desc_scale = ibScale;
	} else {
		drec->sql_desc_length = cbColDef;
	}

	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLBindParameter(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fParamType, SQLSMALLINT fCType, SQLSMALLINT fSqlType,
		 SQLULEN cbColDef, SQLSMALLINT ibScale, SQLPOINTER rgbValue, SQLLEN cbValueMax, SQLLEN FAR * pcbValue)
{
	return _SQLBindParameter(hstmt, ipar, fParamType, fCType, fSqlType, cbColDef, ibScale, rgbValue, cbValueMax, pcbValue);
}

/* compatibility with X/Open */
SQLRETURN SQL_API
SQLBindParam(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fCType, SQLSMALLINT fSqlType, SQLULEN cbColDef, SQLSMALLINT ibScale,
	     SQLPOINTER rgbValue, SQLLEN FAR * pcbValue)
{
	return _SQLBindParameter(hstmt, ipar, SQL_PARAM_INPUT, fCType, fSqlType, cbColDef, ibScale, rgbValue, 0, pcbValue);
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE * OutputHandle)
{
	switch (HandleType) {
	case SQL_HANDLE_STMT:
		return _SQLAllocStmt(InputHandle, OutputHandle);
		break;
	case SQL_HANDLE_DBC:
		return _SQLAllocConnect(InputHandle, OutputHandle);
		break;
	case SQL_HANDLE_ENV:
		return _SQLAllocEnv(OutputHandle);
		break;
	case SQL_HANDLE_DESC:
		return _SQLAllocDesc(InputHandle, OutputHandle);
		break;
	}
	return SQL_ERROR;
}
#endif

static SQLRETURN SQL_API
_SQLAllocConnect(SQLHENV henv, SQLHDBC FAR * phdbc)
{
	TDS_DBC *dbc;

	INIT_HENV;

	dbc = (TDS_DBC *) malloc(sizeof(TDS_DBC));
	if (!dbc) {
		odbc_errs_add(&env->errs, "HY001", NULL);
		ODBC_RETURN(env, SQL_ERROR);
	}

	memset(dbc, '\0', sizeof(TDS_DBC));

	dbc->htype = SQL_HANDLE_DBC;
	dbc->env = env;
	tds_dstr_init(&dbc->server);
	tds_dstr_init(&dbc->dsn);

	dbc->attr.access_mode = SQL_MODE_READ_WRITE;
	dbc->attr.async_enable = SQL_ASYNC_ENABLE_OFF;
	dbc->attr.auto_ipd = SQL_FALSE;
	/*
	 * spinellia@acm.org
	 * after login is enabled autocommit
	 */
	dbc->attr.autocommit = SQL_AUTOCOMMIT_ON;
	dbc->attr.connection_dead = SQL_CD_TRUE;	/* No connection yet */
	dbc->attr.connection_timeout = 0;
	/* This is set in the environment change function */
	tds_dstr_init(&dbc->attr.current_catalog);
	dbc->attr.login_timeout = 0;	/* TODO */
	dbc->attr.metadata_id = SQL_FALSE;
	dbc->attr.odbc_cursors = SQL_CUR_USE_IF_NEEDED;
	dbc->attr.packet_size = 0;
	dbc->attr.quite_mode = NULL;	/* We don't support GUI dialogs yet */
#ifdef TDS_NO_DM
	dbc->attr.trace = SQL_OPT_TRACE_OFF;
	tds_dstr_init(&dbc->attr.tracefile);
#endif
	tds_dstr_init(&dbc->attr.translate_lib);
	dbc->attr.translate_option = 0;
	dbc->attr.txn_isolation = SQL_TXN_READ_COMMITTED;

	*phdbc = (SQLHDBC) dbc;

	ODBC_RETURN_(env);
}

SQLRETURN SQL_API
SQLAllocConnect(SQLHENV henv, SQLHDBC FAR * phdbc)
{
	odbc_errs_reset(&((TDS_ENV *) henv)->errs);
	return _SQLAllocConnect(henv, phdbc);
}

static SQLRETURN SQL_API
_SQLAllocEnv(SQLHENV FAR * phenv)
{
	TDS_ENV *env;
	TDSCONTEXT *ctx;

	env = (TDS_ENV *) malloc(sizeof(TDS_ENV));
	if (!env)
		return SQL_ERROR;

	memset(env, '\0', sizeof(TDS_ENV));

	env->htype = SQL_HANDLE_ENV;
	env->attr.odbc_version = SQL_OV_ODBC2;
	/* TODO use it */
	env->attr.output_nts = SQL_TRUE;

	ctx = tds_alloc_context(env);
	if (!ctx) {
		free(env);
		return SQL_ERROR;
	}
	env->tds_ctx = ctx;
	ctx->msg_handler = odbc_errmsg_handler;
	ctx->err_handler = odbc_errmsg_handler;

	/* ODBC has its own format */
	if (ctx->locale->date_fmt)
		free(ctx->locale->date_fmt);
	ctx->locale->date_fmt = strdup("%Y-%m-%d %H:%M:%S.%z");

	*phenv = (SQLHENV) env;

	return SQL_SUCCESS;
}

SQLRETURN SQL_API
SQLAllocEnv(SQLHENV FAR * phenv)
{
	return _SQLAllocEnv(phenv);
}

static SQLRETURN SQL_API
_SQLAllocDesc(SQLHDBC hdbc, SQLHSTMT FAR * phstmt)
{
	TDS_DESC *desc = NULL;
	int i;

	INIT_HDBC;

	for (i = 0; i < TDS_MAX_APP_DESC; ++i) {
		if (dbc->uad[i] == NULL) {
			dbc->uad[i] = desc_alloc(dbc, DESC_ARD, SQL_DESC_ALLOC_USER);
			if (dbc->uad[i] == NULL) {
				odbc_errs_add(&dbc->errs, "HY001", NULL);
				ODBC_RETURN(dbc, SQL_ERROR);
			}
			desc = dbc->uad[i];
		}
	}

	if (i == TDS_MAX_APP_DESC && desc == NULL) {
		odbc_errs_add(&dbc->errs, "HY014", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
	*phstmt = (SQLHDESC) desc;
	ODBC_RETURN_(dbc);
}

static SQLRETURN SQL_API
_SQLAllocStmt(SQLHDBC hdbc, SQLHSTMT FAR * phstmt)
{
	TDS_STMT *stmt;
	char *pstr;

	INIT_HDBC;

	stmt = (TDS_STMT *) malloc(sizeof(TDS_STMT));
	if (!stmt) {
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
	memset(stmt, '\0', sizeof(TDS_STMT));
	tds_dstr_init(&stmt->cursor_name);

	stmt->htype = SQL_HANDLE_STMT;
	stmt->dbc = dbc;
	pstr = NULL;
	if (asprintf(&pstr, "C%lx", (unsigned long) stmt) < 0 || !tds_dstr_set(&stmt->cursor_name, pstr)) {
		free(stmt);
		if (pstr != NULL)
			free(pstr);
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}
	/* do not free pstr tds_dstr_set do it if necessary */

	/* allocate descriptors */
	stmt->ird = desc_alloc(stmt, DESC_IRD, SQL_DESC_ALLOC_AUTO);
	stmt->ard = desc_alloc(stmt, DESC_ARD, SQL_DESC_ALLOC_AUTO);
	stmt->ipd = desc_alloc(stmt, DESC_IPD, SQL_DESC_ALLOC_AUTO);
	stmt->apd = desc_alloc(stmt, DESC_APD, SQL_DESC_ALLOC_AUTO);
	if (!stmt->ird || !stmt->ard || !stmt->ipd || !stmt->apd) {
		tds_dstr_free(&stmt->cursor_name);
		desc_free(stmt->ird);
		desc_free(stmt->ard);
		desc_free(stmt->ipd);
		desc_free(stmt->apd);
		free(stmt);
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* save original ARD and APD */
	stmt->orig_apd = stmt->apd;
	stmt->orig_ard = stmt->ard;

	/* set the default statement attributes */
/*	stmt->attr.app_param_desc = stmt->apd; */
/*	stmt->attr.app_row_desc = stmt->ard; */
	stmt->attr.async_enable = SQL_ASYNC_ENABLE_OFF;
	stmt->attr.concurrency = SQL_CONCUR_READ_ONLY;
	stmt->attr.cursor_scrollable = SQL_NONSCROLLABLE;
	stmt->attr.cursor_sensitivity = SQL_UNSPECIFIED;
	stmt->attr.cursor_type = SQL_CURSOR_FORWARD_ONLY;
	/* TODO ?? why two attributes */
	stmt->attr.enable_auto_ipd = dbc->attr.auto_ipd = SQL_FALSE;
	stmt->attr.fetch_bookmark_ptr = NULL;
/*	stmt->attr.imp_param_desc = stmt->ipd; */
/*	stmt->attr.imp_row_desc = stmt->ird; */
	stmt->attr.keyset_size = 0;
	stmt->attr.max_length = 0;
	stmt->attr.max_rows = 0;
	stmt->attr.metadata_id = dbc->attr.metadata_id;
	/* TODO check this flag in prepare_call */
	stmt->attr.noscan = SQL_NOSCAN_OFF;
	assert(stmt->apd->header.sql_desc_bind_offset_ptr == NULL);
	assert(stmt->apd->header.sql_desc_bind_type == SQL_PARAM_BIND_BY_COLUMN);
	assert(stmt->apd->header.sql_desc_array_status_ptr == NULL);
	assert(stmt->ipd->header.sql_desc_array_status_ptr == NULL);
	assert(stmt->ipd->header.sql_desc_rows_processed_ptr == NULL);
	assert(stmt->apd->header.sql_desc_array_size == 1);
	stmt->attr.query_timeout = 0;
	stmt->attr.retrieve_data = SQL_RD_ON;
	assert(stmt->ard->header.sql_desc_array_size == 1);
	assert(stmt->ard->header.sql_desc_bind_offset_ptr == NULL);
	assert(stmt->ard->header.sql_desc_bind_type == SQL_BIND_BY_COLUMN);
	stmt->attr.row_number = 0;
	assert(stmt->ard->header.sql_desc_array_status_ptr == NULL);
	assert(stmt->ird->header.sql_desc_array_status_ptr == NULL);
	assert(stmt->ird->header.sql_desc_rows_processed_ptr == NULL);
	stmt->attr.simulate_cursor = SQL_SC_NON_UNIQUE;
	stmt->attr.use_bookmarks = SQL_UB_OFF;

	/* is not the same of using APD sql_desc_bind_type */
	stmt->sql_rowset_size = SQL_BIND_BY_COLUMN;

	stmt->row_count = TDS_NO_COUNT;
	stmt->next_row_count = TDS_NO_COUNT;
	stmt->row_status = NOT_IN_ROW;

	/* insert into list */
	stmt->next = dbc->stmt_list;
	if (dbc->stmt_list)
		dbc->stmt_list->prev = stmt;
	dbc->stmt_list = stmt;

	*phstmt = (SQLHSTMT) stmt;

	ODBC_RETURN_(dbc);
}

SQLRETURN SQL_API
SQLAllocStmt(SQLHDBC hdbc, SQLHSTMT FAR * phstmt)
{
	INIT_HDBC;
	return _SQLAllocStmt(hdbc, phstmt);
}

SQLRETURN SQL_API
SQLBindCol(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLSMALLINT fCType, SQLPOINTER rgbValue, SQLLEN cbValueMax, SQLLEN FAR * pcbValue)
{
	SQLRETURN rc = SQL_SUCCESS;
	TDS_DESC *ard;
	struct _drecord *drec;
	SQLSMALLINT orig_ard_size;

	INIT_HSTMT;

	/* TODO - More error checking XXX smurph */

#ifdef TDS_NO_DM
	/* check conversion type */
	switch (fCType) {
	case SQL_C_CHAR:
	case SQL_C_BINARY:
	case SQL_C_DEFAULT:
		/* check max buffer length */
		if (!IS_VALID_LEN(cbValueMax)) {
			odbc_errs_add(&stmt->errs, "HY090", NULL);
			rc = SQL_ERROR;
		}
		break;
	}
#endif

	if (icol <= 0 || icol > 4000) {
		odbc_errs_add(&stmt->errs, "07009", NULL);
		rc = SQL_ERROR;
	}

	if (rc != SQL_SUCCESS) {
		ODBC_RETURN(stmt, rc);
	}

	ard = stmt->ard;
	orig_ard_size = ard->header.sql_desc_count;
	if (icol > ard->header.sql_desc_count && desc_alloc_records(ard, icol) != SQL_SUCCESS) {
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	drec = &ard->records[icol - 1];

	if (odbc_set_concise_c_type(fCType, drec, 0) != SQL_SUCCESS) {
		desc_alloc_records(ard, orig_ard_size);
		odbc_errs_add(&stmt->errs, "HY003", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	drec->sql_desc_octet_length = cbValueMax;
	drec->sql_desc_octet_length_ptr = pcbValue;
	drec->sql_desc_indicator_ptr = pcbValue;
	drec->sql_desc_data_ptr = rgbValue;

	/* force rebind */
	stmt->row = 0;

	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLCancel(SQLHSTMT hstmt)
{
	TDSSOCKET *tds;

	/*
	 * FIXME this function can be called from other thread, do not free
	 * errors for this function
	 * If function is called from another thread errors are not touched
	 */
	/* TODO some tests required */
	INIT_HSTMT;
	tds = stmt->dbc->tds_socket;

	/* FIXME test current statement */

	if (tds_send_cancel(tds) == TDS_FAIL)
		ODBC_RETURN(stmt, SQL_ERROR);

	if (tds_process_cancel(tds) == TDS_FAIL)
		ODBC_RETURN(stmt, SQL_ERROR);

	stmt->dbc->current_statement = NULL;

	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLConnect(SQLHDBC hdbc, SQLCHAR FAR * szDSN, SQLSMALLINT cbDSN, SQLCHAR FAR * szUID, SQLSMALLINT cbUID, SQLCHAR FAR * szAuthStr,
	   SQLSMALLINT cbAuthStr)
{
	SQLRETURN result;
	TDSCONNECTION *connection;

	INIT_HDBC;

#ifdef TDS_NO_DM
	if (szDSN && !IS_VALID_LEN(cbDSN)) {
		odbc_errs_add(&dbc->errs, "HY090", "Invalid DSN buffer length");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	if (szUID && !IS_VALID_LEN(cbUID)) {
		odbc_errs_add(&dbc->errs, "HY090", "Invalid UID buffer length");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	if (szAuthStr && !IS_VALID_LEN(cbAuthStr)) {
		odbc_errs_add(&dbc->errs, "HY090", "Invalid PWD buffer length");
		ODBC_RETURN(dbc, SQL_ERROR);
	}
#endif

	connection = tds_alloc_connection(dbc->env->tds_ctx->locale);
	if (!connection) {
		odbc_errs_add(&dbc->errs, "HY001", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* data source name */
	if (szDSN || (*szDSN))
		tds_dstr_copyn(&dbc->dsn, (const char *) szDSN, odbc_get_string_size(cbDSN, szDSN));
	else
		tds_dstr_copy(&dbc->dsn, "DEFAULT");


	if (!odbc_get_dsn_info(tds_dstr_cstr(&dbc->dsn), connection)) {
		tds_free_connection(connection);
		odbc_errs_add(&dbc->errs, "IM007", "Error getting DSN information");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/*
	 * username/password are never saved to ini file,
	 * so you do not check in ini file
	 */
	/* user id */
	if (szUID && (*szUID)) {
		if (!tds_dstr_copyn(&connection->user_name, (char *) szUID, odbc_get_string_size(cbUID, szUID))) {
			tds_free_connection(connection);
			odbc_errs_add(&dbc->errs, "HY001", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
	}

	/* password */
	if (szAuthStr) {
		if (!tds_dstr_copyn(&connection->password, (char *) szAuthStr, odbc_get_string_size(cbAuthStr, szAuthStr))) {
			tds_free_connection(connection);
			odbc_errs_add(&dbc->errs, "HY001", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
	}

	/* DO IT */
	if ((result = odbc_connect(dbc, connection)) != SQL_SUCCESS) {
		tds_free_connection(connection);
		ODBC_RETURN_(dbc);
	}

	tds_free_connection(connection);
	ODBC_RETURN_(dbc);
}

SQLRETURN SQL_API
SQLDescribeCol(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLCHAR FAR * szColName, SQLSMALLINT cbColNameMax, SQLSMALLINT FAR * pcbColName,
	       SQLSMALLINT FAR * pfSqlType, SQLULEN FAR * pcbColDef, SQLSMALLINT FAR * pibScale, SQLSMALLINT FAR * pfNullable)
{
	TDS_DESC *ird;
	struct _drecord *drec;

	INIT_HSTMT;

	ird = stmt->ird;

	if (icol <= 0 || icol > ird->header.sql_desc_count) {
		odbc_errs_add(&stmt->errs, "07009", "Column out of range");
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	/* check name length */
	if (cbColNameMax < 0) {
		odbc_errs_add(&stmt->errs, "HY090", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	drec = &ird->records[icol - 1];

	/* cbColNameMax can be 0 (to retrieve name length) */
	if (szColName && cbColNameMax) {
		SQLRETURN result;

		/* straight copy column name up to cbColNameMax */
		result = odbc_set_string(szColName, cbColNameMax, pcbColName, tds_dstr_cstr(&drec->sql_desc_name), -1);
		if (result == SQL_SUCCESS_WITH_INFO) {
			odbc_errs_add(&stmt->errs, "01004", NULL);
			stmt->errs.lastrc = SQL_SUCCESS_WITH_INFO;
		}
	}
	if (pfSqlType) {
		/* TODO sure ? check documentation for date and intervals */
		*pfSqlType = drec->sql_desc_concise_type;
	}

	if (pcbColDef) {
		if (drec->sql_desc_type == SQL_NUMERIC || drec->sql_desc_type == SQL_DECIMAL) {
			*pcbColDef = drec->sql_desc_precision;
		} else {
			*pcbColDef = drec->sql_desc_length;
		}
	}
	if (pibScale) {
		if (drec->sql_desc_type == SQL_NUMERIC || drec->sql_desc_type == SQL_DECIMAL) {
			*pibScale = drec->sql_desc_scale;
		} else {
			*pibScale = 0;
		}
	}
	if (pfNullable) {
		*pfNullable = drec->sql_desc_nullable;
	}
	ODBC_RETURN_(stmt);
}

static SQLRETURN SQL_API
_SQLColAttribute(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType, SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax,
		 SQLSMALLINT FAR * pcbDesc, SQLLEN FAR * pfDesc)
{
	TDS_DESC *ird;
	struct _drecord *drec;
	SQLRETURN result = SQL_SUCCESS;

	INIT_HSTMT;

	ird = stmt->ird;

#define COUT(src) result = odbc_set_string(rgbDesc, cbDescMax, pcbDesc, src ? (char *)src : (char *)"", -1);
#define SOUT(src) result = odbc_set_string(rgbDesc, cbDescMax, pcbDesc, tds_dstr_cstr(&src), -1);

/* SQLColAttribute returns always attributes using SQLINTEGER */
#if ENABLE_EXTRA_CHECKS
#define IOUT(type, src) do { \
	/* trick warning if type wrong */ \
	type *p_test = &src; p_test = p_test; \
	*pfDesc = src; } while(0)
#else
#define IOUT(type, src) *pfDesc = src
#endif


	/* dont check column index for these */
	switch (fDescType) {
#if SQL_COLUMN_COUNT != SQL_DESC_COUNT
	case SQL_COLUMN_COUNT:
#endif
	case SQL_DESC_COUNT:
		IOUT(SQLSMALLINT, ird->header.sql_desc_count);
		ODBC_RETURN(stmt, SQL_SUCCESS);
		break;
	}

	if (!ird->header.sql_desc_count) {
		odbc_errs_add(&stmt->errs, "07005", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	if (icol <= 0 || icol > ird->header.sql_desc_count) {
		odbc_errs_add(&stmt->errs, "07009", "Column out of range");
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	drec = &ird->records[icol - 1];

	tdsdump_log(TDS_DBG_INFO1, "odbc:SQLColAttribute: fDescType is %d\n", fDescType);

	switch (fDescType) {
	case SQL_DESC_AUTO_UNIQUE_VALUE:
		IOUT(SQLUINTEGER, drec->sql_desc_auto_unique_value);
		break;
	case SQL_DESC_BASE_COLUMN_NAME:
		SOUT(drec->sql_desc_base_column_name);
		break;
	case SQL_DESC_BASE_TABLE_NAME:
		SOUT(drec->sql_desc_base_table_name);
		break;
	case SQL_DESC_CASE_SENSITIVE:
		IOUT(SQLINTEGER, drec->sql_desc_case_sensitive);
		break;
	case SQL_DESC_CATALOG_NAME:
		SOUT(drec->sql_desc_catalog_name);
		break;
#if SQL_COLUMN_TYPE != SQL_DESC_CONCISE_TYPE
	case SQL_COLUMN_TYPE:
		/* special case, get ODBC 2 type, not ODBC 3 SQL_DESC_CONCISE_TYPE (different for datetime) */
		if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
			IOUT(SQLSMALLINT, drec->sql_desc_concise_type);
			break;
		}

		/* get type and convert it to ODBC 2 type */
		{
			SQLSMALLINT type = drec->sql_desc_concise_type;

			switch (type) {
			case SQL_TYPE_DATE:
				type = SQL_DATE;
				break;
			case SQL_TYPE_TIME:
				type = SQL_TIME;
				break;
			case SQL_TYPE_TIMESTAMP:
				type = SQL_TIMESTAMP;
				break;
			}
			IOUT(SQLSMALLINT, type);
		}
		break;
#else
	case SQL_DESC_CONCISE_TYPE:
		IOUT(SQLSMALLINT, drec->sql_desc_concise_type);
		break;
#endif
	case SQL_DESC_DISPLAY_SIZE:
		IOUT(SQLLEN, drec->sql_desc_display_size);
		break;
	case SQL_DESC_FIXED_PREC_SCALE:
		IOUT(SQLSMALLINT, drec->sql_desc_fixed_prec_scale);
		break;
	case SQL_DESC_LABEL:
		SOUT(drec->sql_desc_label);
		break;
		/* FIXME special cases for SQL_COLUMN_LENGTH */
	case SQL_COLUMN_LENGTH:
	case SQL_DESC_LENGTH:
		IOUT(SQLULEN, drec->sql_desc_length);
		break;
	case SQL_DESC_LITERAL_PREFIX:
		COUT(drec->sql_desc_literal_prefix);
		break;
	case SQL_DESC_LITERAL_SUFFIX:
		COUT(drec->sql_desc_literal_suffix);
		break;
	case SQL_DESC_LOCAL_TYPE_NAME:
		SOUT(drec->sql_desc_local_type_name);
		break;
#if SQL_COLUMN_NAME != SQL_DESC_NAME
	case SQL_COLUMN_NAME:
#endif
	case SQL_DESC_NAME:
		SOUT(drec->sql_desc_name);
		break;
#if SQL_COLUMN_NULLABLE != SQL_DESC_NULLABLE
	case SQL_COLUMN_NULLABLE:
#endif
	case SQL_DESC_NULLABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_nullable);
		break;
	case SQL_DESC_NUM_PREC_RADIX:
		IOUT(SQLINTEGER, drec->sql_desc_num_prec_radix);
		break;
	case SQL_DESC_OCTET_LENGTH:
		IOUT(SQLLEN, drec->sql_desc_octet_length);
		break;
		/* FIXME special cases for SQL_COLUMN_PRECISION */
	case SQL_COLUMN_PRECISION:
	case SQL_DESC_PRECISION:	/* this section may be wrong */
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IOUT(SQLSMALLINT, drec->sql_desc_precision);
		else
			*pfDesc = drec->sql_desc_length;
		break;
		/* FIXME special cases for SQL_COLUMN_SCALE */
	case SQL_COLUMN_SCALE:
	case SQL_DESC_SCALE:	/* this section may be wrong */
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IOUT(SQLSMALLINT, drec->sql_desc_scale);
		else
			*pfDesc = 0;
		break;
	case SQL_DESC_SCHEMA_NAME:
		SOUT(drec->sql_desc_schema_name);
		break;
	case SQL_DESC_SEARCHABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_searchable);
		break;
	case SQL_DESC_TABLE_NAME:
		SOUT(drec->sql_desc_table_name);
		break;
	case SQL_DESC_TYPE:
		IOUT(SQLSMALLINT, drec->sql_desc_type);
		break;
	case SQL_DESC_TYPE_NAME:
		COUT(drec->sql_desc_type_name);
		break;
	case SQL_DESC_UNNAMED:
		IOUT(SQLSMALLINT, drec->sql_desc_unnamed);
		break;
	case SQL_DESC_UNSIGNED:
		IOUT(SQLSMALLINT, drec->sql_desc_unsigned);
		break;
	case SQL_DESC_UPDATABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_updatable);
		break;
	default:
		tdsdump_log(TDS_DBG_INFO2, "odbc:SQLColAttribute: fDescType %d not catered for...\n", fDescType);
		odbc_errs_add(&stmt->errs, "HY091", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
		break;
	}

	if (result == SQL_SUCCESS_WITH_INFO)
		odbc_errs_add(&stmt->errs, "01004", NULL);

	ODBC_RETURN(stmt, result);

#undef COUT
#undef SOUT
#undef IOUT
}

SQLRETURN SQL_API
SQLColAttributes(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType,
		 SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax, SQLSMALLINT FAR * pcbDesc, SQLLEN FAR * pfDesc)
{
	return _SQLColAttribute(hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc);
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLColAttribute(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType,
		SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax, SQLSMALLINT FAR * pcbDesc,
#ifdef TDS_SQLCOLATTRIBUTE_SQLLEN
		SQLLEN FAR * pfDesc
#else
		SQLPOINTER pfDesc
#endif
	)
{
	return _SQLColAttribute(hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc);
}
#endif

SQLRETURN SQL_API
SQLDisconnect(SQLHDBC hdbc)
{
	int i;

	INIT_HDBC;

	/* free all associated statements */
	while (dbc->stmt_list)
		_SQLFreeStmt(dbc->stmt_list, SQL_DROP, 1);

	/* free all associated descriptors */
	for (i = 0; i < TDS_MAX_APP_DESC; ++i) {
		if (dbc->uad[i]) {
			desc_free(dbc->uad[i]);
			dbc->uad[i] = NULL;
		}
	}

	tds_free_socket(dbc->tds_socket);
	dbc->tds_socket = NULL;

	ODBC_RETURN_(dbc);
}

static int
odbc_errmsg_handler(const TDSCONTEXT * ctx, TDSSOCKET * tds, TDSMESSAGE * msg)
{
	struct _sql_errors *errs = NULL;
	TDS_DBC *dbc = NULL;

	if (tds && tds->parent) {
		dbc = (TDS_DBC *) tds->parent;
		errs = &dbc->errs;
		if (dbc->current_statement)
			errs = &dbc->current_statement->errs;
		/* set server info if not setted in dbc */
		if (msg->server && tds_dstr_isempty(&dbc->server))
			tds_dstr_copy(&dbc->server, msg->server);
	} else if (ctx->parent) {
		errs = &((TDS_ENV *) ctx->parent)->errs;
	}
	if (errs) {
		int severity = msg->severity;
		const char * state = msg->sql_state;

		/* fix severity for Sybase */
		if (severity <= 10 && dbc && !TDS_IS_MSSQL(dbc->tds_socket) && msg->sql_state && msg->sql_state[0]
		    && strncmp(msg->sql_state, "00", 2) != 0) {
			if (strncmp(msg->sql_state, "01", 2) != 0 && strncmp(msg->sql_state, "IM", 2) != 0)
				severity = 11;
		}

		/* compute state if not available */
		if (!state)
			state = severity <= 10 ? "01000" : "42000";
		odbc_errs_add_rdbms(errs, msg->msgno, state, msg->message, msg->line_number, msg->severity,
				    msg->server);

		/* set lastc according */
		if (severity <= 10) {
			if (errs->lastrc == SQL_SUCCESS)
				errs->lastrc = SQL_SUCCESS_WITH_INFO;
		} else {
			errs->lastrc = SQL_ERROR;
		}
	}
	return 1;
}

/* TODO optimize, change only if some data change (set same value should not set this flag) */
#define DESC_SET_NEED_REPREPARE \
	do {\
		if (desc->type == DESC_IPD) {\
			assert(IS_HSTMT(desc->parent));\
			((TDS_STMT *) desc->parent)->need_reprepare = 1;\
		 }\
	} while(0)

SQLRETURN SQL_API
SQLSetDescRec(SQLHDESC hdesc, SQLSMALLINT nRecordNumber, SQLSMALLINT nType, SQLSMALLINT nSubType, SQLLEN nLength,
	      SQLSMALLINT nPrecision, SQLSMALLINT nScale, SQLPOINTER pData, SQLLEN FAR * pnStringLength, SQLLEN FAR * pnIndicator)
{
	struct _drecord *drec;
	SQLSMALLINT concise_type;

	INIT_HDESC;

	if (desc->type == DESC_IRD) {
		odbc_errs_add(&desc->errs, "HY016", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	if (nRecordNumber > desc->header.sql_desc_count || nRecordNumber < 0) {
		odbc_errs_add(&desc->errs, "07009", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	drec = &desc->records[nRecordNumber];

	/* check for valid types and return "HY021" if not */
	if (desc->type == DESC_IPD) {
		DESC_SET_NEED_REPREPARE;
		concise_type = odbc_get_concise_sql_type(nType, nSubType);
	} else {
		concise_type = odbc_get_concise_c_type(nType, nSubType);
	}
	if (nType == SQL_INTERVAL || nType == SQL_DATETIME) {
		if (!concise_type) {
			odbc_errs_add(&desc->errs, "HY021", NULL);
			ODBC_RETURN(desc, SQL_ERROR);
		}
	} else {
		if (concise_type != nType) {
			odbc_errs_add(&desc->errs, "HY021", NULL);
			ODBC_RETURN(desc, SQL_ERROR);
		}
		nSubType = 0;
	}
	drec->sql_desc_concise_type = concise_type;
	drec->sql_desc_type = nType;
	drec->sql_desc_datetime_interval_code = nSubType;

	drec->sql_desc_octet_length = nLength;
	drec->sql_desc_precision = nPrecision;
	drec->sql_desc_scale = nScale;
	drec->sql_desc_data_ptr = pData;
	drec->sql_desc_octet_length_ptr = pnStringLength;
	drec->sql_desc_indicator_ptr = pnIndicator;

	ODBC_RETURN_(desc);
}

SQLRETURN SQL_API
SQLGetDescRec(SQLHDESC hdesc, SQLSMALLINT RecordNumber, SQLCHAR * Name, SQLSMALLINT BufferLength, SQLSMALLINT * StringLength,
	      SQLSMALLINT * Type, SQLSMALLINT * SubType, SQLLEN FAR * Length, SQLSMALLINT * Precision, SQLSMALLINT * Scale,
	      SQLSMALLINT * Nullable)
{
	struct _drecord *drec = NULL;
	SQLRETURN rc = SQL_SUCCESS;

	INIT_HDESC;

	if (desc->type == DESC_IRD && desc->header.sql_desc_count) {
		odbc_errs_add(&desc->errs, "HY007", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	if (RecordNumber > desc->header.sql_desc_count || RecordNumber < 0) {
		odbc_errs_add(&desc->errs, "07009", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	drec = &desc->records[RecordNumber];

	if ((rc = odbc_set_string(Name, BufferLength, StringLength, tds_dstr_cstr(&drec->sql_desc_name), -1)) != SQL_SUCCESS)
		odbc_errs_add(&desc->errs, "01004", NULL);

	if (Type)
		*Type = drec->sql_desc_type;
	if (Length)
		*Length = drec->sql_desc_octet_length;
	if (Precision)
		*Precision = drec->sql_desc_precision;
	if (Scale)
		*Scale = drec->sql_desc_scale;
	if (SubType)
		*SubType = drec->sql_desc_datetime_interval_code;
	if (Nullable)
		*Nullable = drec->sql_desc_nullable;

	ODBC_RETURN(desc, rc);
}

SQLRETURN SQL_API
SQLGetDescField(SQLHDESC hdesc, SQLSMALLINT icol, SQLSMALLINT fDescType, SQLPOINTER Value, SQLINTEGER BufferLength,
		SQLINTEGER * StringLength)
{
	struct _drecord *drec;
	SQLRETURN result = SQL_SUCCESS;

	INIT_HDESC;

#define COUT(src) result = odbc_set_string_i(Value, BufferLength, StringLength, src, -1);
#define SOUT(src) result = odbc_set_string_i(Value, BufferLength, StringLength, tds_dstr_cstr(&src), -1);

#if ENABLE_EXTRA_CHECKS
#define IOUT(type, src) do { \
	/* trick warning if type wrong */ \
	type *p_test = &src; p_test = p_test; \
	*((type *)Value) = src; } while(0)
#else
#define IOUT(type, src) *((type *)Value) = src
#endif

	/* dont check column index for these */
	switch (fDescType) {
	case SQL_DESC_ALLOC_TYPE:
		IOUT(SQLSMALLINT, desc->header.sql_desc_alloc_type);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_ARRAY_SIZE:
		IOUT(SQLULEN, desc->header.sql_desc_array_size);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_ARRAY_STATUS_PTR:
		IOUT(SQLUSMALLINT *, desc->header.sql_desc_array_status_ptr);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_BIND_OFFSET_PTR:
		IOUT(SQLLEN *, desc->header.sql_desc_bind_offset_ptr);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_BIND_TYPE:
		IOUT(SQLINTEGER, desc->header.sql_desc_bind_type);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_COUNT:
		IOUT(SQLSMALLINT, desc->header.sql_desc_count);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_ROWS_PROCESSED_PTR:
		IOUT(SQLULEN *, desc->header.sql_desc_rows_processed_ptr);
		ODBC_RETURN_(desc);
		break;
	}

	if (!desc->header.sql_desc_count) {
		odbc_errs_add(&desc->errs, "07005", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	if (icol < 1) {
		odbc_errs_add(&desc->errs, "07009", "Column out of range");
		ODBC_RETURN(desc, SQL_ERROR);
	}
	if (icol > desc->header.sql_desc_count)
		ODBC_RETURN(desc, SQL_NO_DATA);
	drec = &desc->records[icol - 1];

	tdsdump_log(TDS_DBG_INFO1, "odbc:SQLGetDescField: fDescType is %d\n", fDescType);

	switch (fDescType) {
	case SQL_DESC_AUTO_UNIQUE_VALUE:
		IOUT(SQLUINTEGER, drec->sql_desc_auto_unique_value);
		break;
	case SQL_DESC_BASE_COLUMN_NAME:
		SOUT(drec->sql_desc_base_column_name);
		break;
	case SQL_DESC_BASE_TABLE_NAME:
		SOUT(drec->sql_desc_base_table_name);
		break;
	case SQL_DESC_CASE_SENSITIVE:
		IOUT(SQLINTEGER, drec->sql_desc_case_sensitive);
		break;
	case SQL_DESC_CATALOG_NAME:
		SOUT(drec->sql_desc_catalog_name);
		break;
	case SQL_DESC_CONCISE_TYPE:
		IOUT(SQLSMALLINT, drec->sql_desc_concise_type);
		break;
	case SQL_DESC_DATA_PTR:
		IOUT(SQLPOINTER, drec->sql_desc_data_ptr);
		break;
	case SQL_DESC_DATETIME_INTERVAL_CODE:
		IOUT(SQLSMALLINT, drec->sql_desc_datetime_interval_code);
		break;
	case SQL_DESC_DATETIME_INTERVAL_PRECISION:
		IOUT(SQLINTEGER, drec->sql_desc_datetime_interval_precision);
		break;
	case SQL_DESC_DISPLAY_SIZE:
		IOUT(SQLLEN, drec->sql_desc_display_size);
		break;
	case SQL_DESC_FIXED_PREC_SCALE:
		IOUT(SQLSMALLINT, drec->sql_desc_fixed_prec_scale);
		break;
	case SQL_DESC_INDICATOR_PTR:
		IOUT(SQLLEN *, drec->sql_desc_indicator_ptr);
		break;
	case SQL_DESC_LABEL:
		SOUT(drec->sql_desc_label);
		break;
	case SQL_DESC_LENGTH:
		IOUT(SQLULEN, drec->sql_desc_length);
		break;
	case SQL_DESC_LITERAL_PREFIX:
		COUT(drec->sql_desc_literal_prefix);
		break;
	case SQL_DESC_LITERAL_SUFFIX:
		COUT(drec->sql_desc_literal_suffix);
		break;
	case SQL_DESC_LOCAL_TYPE_NAME:
		SOUT(drec->sql_desc_local_type_name);
		break;
	case SQL_DESC_NAME:
		SOUT(drec->sql_desc_name);
		break;
	case SQL_DESC_NULLABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_nullable);
		break;
	case SQL_DESC_NUM_PREC_RADIX:
		IOUT(SQLINTEGER, drec->sql_desc_num_prec_radix);
		break;
	case SQL_DESC_OCTET_LENGTH:
		IOUT(SQLLEN, drec->sql_desc_octet_length);
		break;
	case SQL_DESC_OCTET_LENGTH_PTR:
		IOUT(SQLLEN *, drec->sql_desc_octet_length_ptr);
		break;
	case SQL_DESC_PARAMETER_TYPE:
		IOUT(SQLSMALLINT, drec->sql_desc_parameter_type);
		break;
	case SQL_DESC_PRECISION:
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IOUT(SQLSMALLINT, drec->sql_desc_precision);
		else
			/* TODO support date/time */
			*((SQLSMALLINT *) Value) = 0;
		break;
#ifdef SQL_DESC_ROWVER
	case SQL_DESC_ROWVER:
		IOUT(SQLSMALLINT, drec->sql_desc_rowver);
		break;
#endif
	case SQL_DESC_SCALE:
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IOUT(SQLSMALLINT, drec->sql_desc_scale);
		else
			*((SQLSMALLINT *) Value) = 0;
		break;
	case SQL_DESC_SCHEMA_NAME:
		SOUT(drec->sql_desc_schema_name);
		break;
	case SQL_DESC_SEARCHABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_searchable);
		break;
	case SQL_DESC_TABLE_NAME:
		SOUT(drec->sql_desc_table_name);
		break;
	case SQL_DESC_TYPE:
		IOUT(SQLSMALLINT, drec->sql_desc_type);
		break;
	case SQL_DESC_TYPE_NAME:
		COUT(drec->sql_desc_type_name);
		break;
	case SQL_DESC_UNNAMED:
		IOUT(SQLSMALLINT, drec->sql_desc_unnamed);
		break;
	case SQL_DESC_UNSIGNED:
		IOUT(SQLSMALLINT, drec->sql_desc_unsigned);
		break;
	case SQL_DESC_UPDATABLE:
		IOUT(SQLSMALLINT, drec->sql_desc_updatable);
		break;
	default:
		odbc_errs_add(&desc->errs, "HY091", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
		break;
	}

	if (result == SQL_SUCCESS_WITH_INFO)
		odbc_errs_add(&desc->errs, "01004", NULL);

	ODBC_RETURN(desc, result);

#undef COUT
#undef SOUT
#undef IOUT
}

SQLRETURN SQL_API
SQLSetDescField(SQLHDESC hdesc, SQLSMALLINT icol, SQLSMALLINT fDescType, SQLPOINTER Value, SQLINTEGER BufferLength)
{
	struct _drecord *drec;
	SQLRETURN result = SQL_SUCCESS;

	INIT_HDESC;

#if ENABLE_EXTRA_CHECKS
#define IIN(type, dest) do { \
	/* trick warning if type wrong */ \
	type *p_test = &dest; p_test = p_test; \
	dest = (type)(TDS_INTPTR)Value; } while(0)
#define PIN(type, dest) do { \
	/* trick warning if type wrong */ \
	type *p_test = &dest; p_test = p_test; \
	dest = (type)Value; } while(0)
#else
#define IIN(type, dest) dest = (type)(TDS_INTPTR)Value
#define PIN(type, dest) dest = (type)Value
#endif

	/* special case for IRD */
	if (desc->type == DESC_IRD && fDescType != SQL_DESC_ARRAY_STATUS_PTR && fDescType != SQL_DESC_ROWS_PROCESSED_PTR) {
		odbc_errs_add(&desc->errs, "HY016", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	/* dont check column index for these */
	switch (fDescType) {
	case SQL_DESC_ALLOC_TYPE:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		ODBC_RETURN(desc, SQL_ERROR);
		break;
	case SQL_DESC_ARRAY_SIZE:
		IIN(SQLULEN, desc->header.sql_desc_array_size);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_ARRAY_STATUS_PTR:
		PIN(SQLUSMALLINT *, desc->header.sql_desc_array_status_ptr);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_ROWS_PROCESSED_PTR:
		PIN(SQLULEN *, desc->header.sql_desc_rows_processed_ptr);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_BIND_TYPE:
		IIN(SQLINTEGER, desc->header.sql_desc_bind_type);
		ODBC_RETURN_(desc);
		break;
	case SQL_DESC_COUNT:
		{
			int n = (int) (TDS_INTPTR) Value;

			if (n <= 0 || n > 4000) {
				odbc_errs_add(&desc->errs, "07009", NULL);
				ODBC_RETURN(desc, SQL_ERROR);
			}
			result = desc_alloc_records(desc, n);
			if (result == SQL_ERROR)
				odbc_errs_add(&desc->errs, "HY001", NULL);
			ODBC_RETURN(desc, result);
		}
		break;
	}

	if (!desc->header.sql_desc_count) {
		odbc_errs_add(&desc->errs, "07005", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	if (icol <= 0 || icol > desc->header.sql_desc_count) {
		odbc_errs_add(&desc->errs, "07009", "Column out of range");
		ODBC_RETURN(desc, SQL_ERROR);
	}
	drec = &desc->records[icol - 1];

	tdsdump_log(TDS_DBG_INFO1, "odbc:SQLColAttributes: fDescType is %d\n", fDescType);

	switch (fDescType) {
	case SQL_DESC_AUTO_UNIQUE_VALUE:
	case SQL_DESC_BASE_COLUMN_NAME:
	case SQL_DESC_BASE_TABLE_NAME:
	case SQL_DESC_CASE_SENSITIVE:
	case SQL_DESC_CATALOG_NAME:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_CONCISE_TYPE:
		DESC_SET_NEED_REPREPARE;
		if (desc->type == DESC_IPD)
			result = odbc_set_concise_sql_type((SQLSMALLINT) (TDS_INTPTR) Value, drec, 0);
		else
			result = odbc_set_concise_c_type((SQLSMALLINT) (TDS_INTPTR) Value, drec, 0);
		if (result != SQL_SUCCESS)
			odbc_errs_add(&desc->errs, "HY021", NULL);
		break;
	case SQL_DESC_DATA_PTR:
		PIN(SQLPOINTER, drec->sql_desc_data_ptr);
		break;
		/* TODO SQL_DESC_DATETIME_INTERVAL_CODE remember to check sql_desc_type */
		/* TODO SQL_DESC_DATETIME_INTERVAL_PRECISION */
	case SQL_DESC_DISPLAY_SIZE:
	case SQL_DESC_FIXED_PREC_SCALE:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_INDICATOR_PTR:
		PIN(SQLLEN *, drec->sql_desc_indicator_ptr);
		break;
	case SQL_DESC_LABEL:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_LENGTH:
		DESC_SET_NEED_REPREPARE;
		IIN(SQLULEN, drec->sql_desc_length);
		break;
	case SQL_DESC_LITERAL_PREFIX:
	case SQL_DESC_LITERAL_SUFFIX:
	case SQL_DESC_LOCAL_TYPE_NAME:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_NAME:
		{
			/* FIXME test len >= 0 */
			int len = odbc_get_string_size(BufferLength, (SQLCHAR *) Value);

			if (!tds_dstr_copyn(&drec->sql_desc_name, Value, len)) {
				odbc_errs_add(&desc->errs, "HY001", NULL);
				result = SQL_ERROR;
			}
		}
		break;
	case SQL_DESC_NULLABLE:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_NUM_PREC_RADIX:
		IIN(SQLINTEGER, drec->sql_desc_num_prec_radix);
		break;
	case SQL_DESC_OCTET_LENGTH:
		DESC_SET_NEED_REPREPARE;
		IIN(SQLLEN, drec->sql_desc_octet_length);
		break;
	case SQL_DESC_OCTET_LENGTH_PTR:
		PIN(SQLLEN *, drec->sql_desc_octet_length_ptr);
		break;
	case SQL_DESC_PARAMETER_TYPE:
		DESC_SET_NEED_REPREPARE;
		IIN(SQLSMALLINT, drec->sql_desc_parameter_type);
		break;
	case SQL_DESC_PRECISION:
		DESC_SET_NEED_REPREPARE;
		/* TODO correct ?? */
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IIN(SQLSMALLINT, drec->sql_desc_precision);
		else
			IIN(SQLULEN, drec->sql_desc_length);
		break;
#ifdef SQL_DESC_ROWVER
	case SQL_DESC_ROWVER:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
#endif
	case SQL_DESC_SCALE:
		DESC_SET_NEED_REPREPARE;
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			IIN(SQLSMALLINT, drec->sql_desc_scale);
		else
			drec->sql_desc_scale = 0;
		break;
	case SQL_DESC_SCHEMA_NAME:
	case SQL_DESC_SEARCHABLE:
	case SQL_DESC_TABLE_NAME:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_TYPE:
		DESC_SET_NEED_REPREPARE;
		IIN(SQLSMALLINT, drec->sql_desc_type);
		/* FIXME what happen for interval/datetime ?? */
		drec->sql_desc_concise_type = drec->sql_desc_type;
		break;
	case SQL_DESC_TYPE_NAME:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	case SQL_DESC_UNNAMED:
		IIN(SQLSMALLINT, drec->sql_desc_unnamed);
		break;
	case SQL_DESC_UNSIGNED:
	case SQL_DESC_UPDATABLE:
		odbc_errs_add(&desc->errs, "HY091", "Descriptor type read only");
		result = SQL_ERROR;
		break;
	default:
		odbc_errs_add(&desc->errs, "HY091", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
		break;
	}

#undef IIN

	ODBC_RETURN(desc, result);
}

SQLRETURN SQL_API
SQLCopyDesc(SQLHDESC hdesc, SQLHDESC htarget)
{
	TDS_DESC *target;

	INIT_HDESC;

	if (SQL_NULL_HDESC == htarget || !IS_HDESC(htarget))
		return SQL_INVALID_HANDLE;
	target = (TDS_DESC *) htarget;
	CHECK_DESC_EXTRA(target);

	/* do not write on IRD */
	if (target->type == DESC_IRD) {
		odbc_errs_add(&target->errs, "HY016", NULL);
		ODBC_RETURN(target, SQL_ERROR);
	}

	ODBC_RETURN(target, desc_copy(target, desc));
}

#if ENABLE_EXTRA_CHECKS
static void
odbc_ird_check(TDS_STMT * stmt)
{
	TDS_DESC *ird = stmt->ird;
	struct _drecord *drec;
	TDSCOLUMN *col;
	TDSRESULTINFO *res_info = NULL;
	int cols = 0, i;

	if (!stmt->dbc->tds_socket)
		return;
	if (stmt->dbc->tds_socket->current_results) {
		res_info = stmt->dbc->tds_socket->current_results;
		cols = res_info->num_cols;
	}

	/* check columns number */
	assert(ird->header.sql_desc_count == cols || ird->header.sql_desc_count == 0);


	/* check all columns */
	for (i = 0; i < ird->header.sql_desc_count; ++i) {
		drec = &ird->records[i];
		col = res_info->columns[i];
		assert(tds_dstr_len(&drec->sql_desc_label) == col->column_namelen);
		assert(memcmp(tds_dstr_cstr(&drec->sql_desc_label), col->column_name, col->column_namelen) == 0);
	}
}
#endif

/* FIXME check result !!! */
static SQLRETURN
odbc_populate_ird(TDS_STMT * stmt)
{
	TDS_DESC *ird = stmt->ird;
	struct _drecord *drec;
	TDSCOLUMN *col;
	TDSRESULTINFO *res_info;
	int num_cols;
	int i;

	desc_free_records(ird);
	if (!stmt->dbc->tds_socket || !(res_info = stmt->dbc->tds_socket->current_results))
		return SQL_SUCCESS;
	num_cols = res_info->num_cols;

	/* TODO set error */
	if (desc_alloc_records(ird, num_cols) != SQL_SUCCESS)
		return SQL_ERROR;

	for (i = 0; i < num_cols; i++) {
		drec = &ird->records[i];
		col = res_info->columns[i];
		drec->sql_desc_auto_unique_value = col->column_identity ? SQL_TRUE : SQL_FALSE;
		/* TODO SQL_FALSE ?? */
		drec->sql_desc_case_sensitive = SQL_TRUE;
		/* TODO test error ?? */
		odbc_set_concise_sql_type(odbc_server_to_sql_type(col->column_type, col->column_size), drec, 0);
		drec->sql_desc_display_size =
			odbc_sql_to_displaysize(drec->sql_desc_concise_type, col->column_size, col->column_prec);
		drec->sql_desc_fixed_prec_scale = (col->column_prec && col->column_scale) ? SQL_TRUE : SQL_FALSE;
		if (!tds_dstr_copyn(&drec->sql_desc_label, col->column_name, col->column_namelen))
			return SQL_ERROR;

		/* TODO other types for date ?? SQL_TYPE_DATE, SQL_TYPE_TIME */
		if (drec->sql_desc_concise_type == SQL_TIMESTAMP)
			drec->sql_desc_length = sizeof("2000-01-01 12:00:00.0000")-1;
		else
			drec->sql_desc_length = col->column_size;
		odbc_set_sql_type_info(col, drec);

		if (!tds_dstr_copyn(&drec->sql_desc_name, col->column_name, col->column_namelen))
			return SQL_ERROR;

        /* ssikorsk ... */
		if (!tds_dstr_copyn(&drec->sql_desc_base_column_name, col->column_name, col->column_namelen))
			return SQL_ERROR;

        /* ssikorsk ... */
		if (!tds_dstr_copyn(&drec->sql_desc_base_table_name, col->table_name, col->table_namelen))
			return SQL_ERROR;

		drec->sql_desc_unnamed = tds_dstr_isempty(&drec->sql_desc_name) ? SQL_UNNAMED : SQL_NAMED;
		/* TODO use is_nullable_type ?? */
		drec->sql_desc_nullable = col->column_nullable ? SQL_TRUE : SQL_FALSE;
		if (drec->sql_desc_concise_type == SQL_NUMERIC || drec->sql_desc_concise_type == SQL_DECIMAL)
			drec->sql_desc_num_prec_radix = 10;
		else
			drec->sql_desc_num_prec_radix = 0;

		drec->sql_desc_octet_length = col->column_size;
		drec->sql_desc_octet_length_ptr = NULL;
		drec->sql_desc_precision = col->column_prec;
		/* TODO test timestamp from db, FOR BROWSE query */
		drec->sql_desc_rowver = SQL_FALSE;
		drec->sql_desc_scale = col->column_scale;
		/* TODO seem not correct */
		drec->sql_desc_searchable = (drec->sql_desc_unnamed == SQL_NAMED) ? SQL_PRED_SEARCHABLE : SQL_UNSEARCHABLE;
		/* TODO perhaps TINYINY and BIT.. */
		drec->sql_desc_unsigned = SQL_FALSE;
		drec->sql_desc_updatable = col->column_writeable ? SQL_TRUE : SQL_FALSE;
	}
	return (SQL_SUCCESS);
}

static int
query_timeout_cancel(void *param, unsigned int total_timeout)
{
	TDS_STMT *stmt = (TDS_STMT *) param;

	assert(stmt != NULL);

	if (!stmt->dbc->tds_socket->in_cancel)
		odbc_errs_add(&stmt->errs, "HYT00", "Timeout expired");
	stmt->errs.lastrc = SQL_ERROR;

	/* attent indefinitely cancel */
	stmt->dbc->tds_socket->query_timeout = 0;

	return TDS_INT_CANCEL;
}

static SQLRETURN SQL_API
_SQLExecute(TDS_STMT * stmt)
{
	int ret;
	TDSSOCKET *tds = stmt->dbc->tds_socket;
	TDS_INT result_type;
	TDS_INT done = 0;
	int in_row = 0;
	SQLUSMALLINT param_status;
	int found_info = 0, found_error = 0;

	stmt->row = 0;

	tds->query_timeout_func = query_timeout_cancel;
	tds->query_timeout_param = stmt;
	tds->query_timeout = stmt->attr.query_timeout;

	/* check parameters are all OK */
	if (stmt->params && stmt->param_num <= (int)stmt->param_count)
		/* TODO what error ?? */
		return SQL_ERROR;

	if (tds->state != TDS_IDLE) {
		if (tds->state == TDS_DEAD) {
			odbc_errs_add(&stmt->errs, "08S01", NULL);
		} else {
			odbc_errs_add(&stmt->errs, "24000", NULL);
		}
		return SQL_ERROR;
	}

	stmt->curr_param_row = 0;
	stmt->num_param_rows = stmt->apd->header.sql_desc_array_size;

	if (stmt->prepared_query_is_rpc) {
		/* TODO support stmt->apd->header.sql_desc_array_size for RPC */
		/* get rpc name */
		/* TODO change method */
		/* TODO cursor change way of calling */
		char *name = stmt->query;
		char *end, tmp;

		if (!name)
			name = stmt->prepared_query;

		end = name;
		if (*end == '[')
			end = (char *) tds_skip_quoted(end);
		else
			while (!isspace((unsigned char) *++end) && *end);
		stmt->prepared_pos = end;
		tmp = *end;
		*end = 0;
		ret = tds_submit_rpc(tds, name, stmt->params);
		*end = tmp;
	} else if (stmt->query) {
		/* not prepared query */
		/* TODO cursor change way of calling */
		/* SQLExecDirect */
		if (stmt->num_param_rows <= 1) {
			if (!stmt->params) {
				ret = tds_submit_query(tds, stmt->query);
			} else {
				ret = tds_submit_execdirect(tds, stmt->query, stmt->params);
			}
		} else {
			/* pack multiple submit using language */
			TDSMULTIPLE multiple;

			ret = tds_multiple_init(tds, &multiple, TDS_MULTIPLE_QUERY);
			for (stmt->curr_param_row = 0; ret == TDS_SUCCEED; ) {
				/* submit a query */
				ret = tds_multiple_query(tds, &multiple, stmt->query, stmt->params);
				if (++stmt->curr_param_row >= stmt->num_param_rows)
					break;
				/* than process others parameters */
				/* TODO handle all results*/
				if (start_parse_prepared_query(stmt, 1) != SQL_SUCCESS)
					break;
			}
			if (ret == TDS_SUCCEED)
				ret = tds_multiple_done(tds, &multiple);
		}
	} else {
		/* TODO cursor change way of calling */
		/* SQLPrepare */
		TDSDYNAMIC *dyn;

		/* prepare dynamic query (only for first SQLExecute call) */
		if (!stmt->dyn || (stmt->need_reprepare && !stmt->dyn->emulated && IS_TDS7_PLUS(tds))) {

			/* free previous prepared statement */
			if (stmt->dyn) {
				if (odbc_free_dynamic(stmt) != SQL_SUCCESS)
					ODBC_RETURN(stmt, SQL_ERROR);
			}
			stmt->need_reprepare = 0;

			tdsdump_log(TDS_DBG_INFO1, "Creating prepared statement\n");
			/* TODO use tds_submit_prepexec (mssql2k, tds8) */
			if (tds_submit_prepare(tds, stmt->prepared_query, NULL, &stmt->dyn, stmt->params) == TDS_FAIL) {
				/* TODO ?? tds_free_param_results(params); */
				ODBC_RETURN(stmt, SQL_ERROR);
			}
			stmt->dbc->current_statement = stmt;
			if (tds_process_simple_query(tds) != TDS_SUCCEED) {
				dyn = stmt->dyn;
				stmt->dyn = NULL;
				tds_free_dynamic(tds, dyn);
				/* TODO ?? tds_free_param_results(params); */
				ODBC_RETURN(stmt, SQL_ERROR);
			}
		}
		if (stmt->num_param_rows <= 1) {
			dyn = stmt->dyn;
			tds_free_input_params(dyn);
			dyn->params = stmt->params;
			/* prevent double free */
			stmt->params = NULL;
			tdsdump_log(TDS_DBG_INFO1, "End prepare, execute\n");
			/* TODO return error to client */
			ret = tds_submit_execute(tds, dyn);
		} else {
			TDSMULTIPLE multiple;

			ret = tds_multiple_init(tds, &multiple, TDS_MULTIPLE_EXECUTE);
			for (stmt->curr_param_row = 0; ret == TDS_SUCCEED; ) {
				dyn = stmt->dyn;
				tds_free_input_params(dyn);
				dyn->params = stmt->params;
				/* prevent double free */
				stmt->params = NULL;
				ret = tds_multiple_execute(tds, &multiple, dyn);
				if (++stmt->curr_param_row >= stmt->num_param_rows)
					break;
				/* than process others parameters */
				/* TODO handle all results*/
				if (start_parse_prepared_query(stmt, 1) != SQL_SUCCESS)
					break;
			}
			if (ret == TDS_SUCCEED)
				ret = tds_multiple_done(tds, &multiple);
		}
	}
	if (ret != TDS_SUCCEED)
		ODBC_RETURN(stmt, SQL_ERROR);
	/* catch all errors */
	stmt->dbc->current_statement = stmt;

	stmt->row_count = TDS_NO_COUNT;
	stmt->next_row_count = TDS_NO_COUNT;
	stmt->row_status = PRE_NORMAL_ROW;

	stmt->curr_param_row = 0;
	param_status = SQL_PARAM_SUCCESS;

	/* TODO review this, ODBC return parameter in other way, for compute I don't know */
	/* TODO perhaps we should return SQL_NO_DATA if no data available... see old SQLExecute code */
	for (;;) {
		result_type = odbc_process_tokens(stmt, TDS_TOKEN_RESULTS);
		switch (result_type) {
		case TDS_CMD_FAIL:
		case TDS_CMD_DONE:
		case TDS_COMPUTE_RESULT:
		case TDS_ROW_RESULT:
			done = 1;
			break;

		case TDS_DONE_RESULT:
		case TDS_DONEPROC_RESULT:
			switch (stmt->errs.lastrc) {
			case SQL_ERROR:
				param_status = SQL_PARAM_ERROR;
				break;
			case SQL_SUCCESS_WITH_INFO:
				param_status = SQL_PARAM_SUCCESS_WITH_INFO;
				break;
			}
			if (stmt->curr_param_row < stmt->num_param_rows && stmt->ipd->header.sql_desc_array_status_ptr)
				stmt->ipd->header.sql_desc_array_status_ptr[stmt->curr_param_row] = param_status;
			if (stmt->curr_param_row + 1 >= stmt->num_param_rows) {
				done = 1;
				break;
			}
			if (stmt->errs.lastrc == SQL_SUCCESS_WITH_INFO)
				found_info = 1;
			if (stmt->errs.lastrc == SQL_ERROR)
				found_error = 1;
			stmt->errs.lastrc = SQL_SUCCESS;
			param_status = SQL_PARAM_SUCCESS;
			++stmt->curr_param_row;
			break;

		case TDS_DONEINPROC_RESULT:
			if (in_row)
				done = 1;
			break;

			/* ignore metadata, stop at done or row */
		case TDS_ROWFMT_RESULT:
			if (in_row) {
				done = 1;
				break;
			}
			stmt->row = 0;
			stmt->row_count = TDS_NO_COUNT;
			stmt->next_row_count = TDS_NO_COUNT;
			stmt->row_status = PRE_NORMAL_ROW;
			in_row = 1;
			break;
		}
		if (done)
			break;
	}
	if ((found_info || found_error) && stmt->errs.lastrc != SQL_ERROR)
		stmt->errs.lastrc = SQL_SUCCESS_WITH_INFO;
	if (stmt->curr_param_row < stmt->num_param_rows) {
		if (stmt->ipd->header.sql_desc_array_status_ptr)
			stmt->ipd->header.sql_desc_array_status_ptr[stmt->curr_param_row] = param_status;
		++stmt->curr_param_row;
		if (stmt->ipd->header.sql_desc_rows_processed_ptr)
			*stmt->ipd->header.sql_desc_rows_processed_ptr = stmt->curr_param_row;
	}
	tds->query_timeout = 0;
	tds->query_timeout_param = NULL;
	tds->query_timeout_func = NULL;

	odbc_populate_ird(stmt);
	switch (result_type) {
	case TDS_CMD_DONE:
		if (stmt->dbc->current_statement == stmt)
			stmt->dbc->current_statement = NULL;
		if (stmt->errs.lastrc == SQL_SUCCESS && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3 && stmt->row_count == TDS_NO_COUNT)
			ODBC_RETURN(stmt, SQL_NO_DATA);
		break;

	case TDS_CMD_FAIL:
		/* TODO test what happened, report correct error to client */
		tdsdump_log(TDS_DBG_INFO1, "SQLExecute: bad results\n");
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLExecDirect(SQLHSTMT hstmt, SQLCHAR FAR * szSqlStr, SQLINTEGER cbSqlStr)
{
	SQLRETURN res;

	INIT_HSTMT;

	if (SQL_SUCCESS != odbc_set_stmt_query(stmt, (char *) szSqlStr, cbSqlStr)) {
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* count placeholders */
	/* note: szSqlStr can be no-null terminated, so first we set query and then count placeholders */
	stmt->param_count = tds_count_placeholders(stmt->query);
	stmt->param_data_called = 0;

	if (SQL_SUCCESS != prepare_call(stmt)) {
		/* TODO return another better error, prepare_call should set error ?? */
		odbc_errs_add(&stmt->errs, "HY000", "Could not prepare call");
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	res = start_parse_prepared_query(stmt, 1);
	if (SQL_SUCCESS != res)
		ODBC_RETURN(stmt, res);

	return _SQLExecute(stmt);
}

SQLRETURN SQL_API
SQLExecute(SQLHSTMT hstmt)
{
	SQLRETURN res;

	INIT_HSTMT;

	if (!stmt->prepared_query)
		/* TODO error report, only without DM ?? */
		ODBC_RETURN(stmt, SQL_ERROR);

	/* TODO rebuild should be done for every bingings change, not every time */
	/* TODO free previous parameters */
	/* build parameters list */
	stmt->param_data_called = 0;
	stmt->curr_param_row = 0;
	res = start_parse_prepared_query(stmt, 1);
	if (SQL_SUCCESS != res)
		ODBC_RETURN(stmt, res);

	/* TODO test if two SQLPrepare on a statement */
	/* TODO test unprepare on statement free or connection close */

	return _SQLExecute(stmt);
}

static int
odbc_process_tokens(TDS_STMT * stmt, unsigned flag)
{
	TDS_INT result_type;
	int done_flags;
	TDSSOCKET * tds = stmt->dbc->tds_socket;

	flag |= TDS_RETURN_DONE | TDS_RETURN_PROC;
	for (;;) {
		switch (tds_process_tokens(tds, &result_type, &done_flags, flag)) {
		case TDS_NO_MORE_RESULTS:
			return TDS_CMD_DONE;
		case TDS_CANCELLED:
		case TDS_FAIL:
			return TDS_CMD_FAIL;
		}

		switch (result_type) {
		case TDS_STATUS_RESULT:
			odbc_set_return_status(stmt);
			break;
		case TDS_PARAM_RESULT:
			odbc_set_return_params(stmt);
			break;

		case TDS_DONE_RESULT:
		case TDS_DONEPROC_RESULT:
			if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3)
				flag |= TDS_STOPAT_MSG;
			if (done_flags & TDS_DONE_COUNT) {
				if (stmt->row_count == TDS_NO_COUNT)
					stmt->row_count = tds->rows_affected;
				else
					stmt->next_row_count = tds->rows_affected;
			}
			if (done_flags & TDS_DONE_ERROR)
				stmt->errs.lastrc = SQL_ERROR;
			/* test for internal_sp not very fine, used for param set  -- freddy77 */
			if ((done_flags & (TDS_DONE_COUNT|TDS_DONE_ERROR)) != 0
			    || (stmt->errs.lastrc == SQL_SUCCESS_WITH_INFO && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3)
			    || (result_type == TDS_DONEPROC_RESULT && tds->internal_sp_called == TDS_SP_EXECUTE)) {
				/* FIXME this row is used only as a flag for update binding, should be cleared if binding/result changed */
				stmt->row = 0;
#if 0
				tds_free_all_results(tds);
				odbc_populate_ird(stmt);
#endif
				return result_type;
			}
			break;

		/*
		 * TODO test flags ? check error and change result ?
		 * see also other DONEINPROC handle (below)
		 */
		case TDS_DONEINPROC_RESULT:
			if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3)
				flag |= TDS_STOPAT_MSG;
			if (done_flags & TDS_DONE_COUNT) {
				if (stmt->row_count == TDS_NO_COUNT)
					stmt->row_count = tds->rows_affected;
				else
					stmt->next_row_count = tds->rows_affected;
			}
			if (done_flags & TDS_DONE_ERROR)
				stmt->errs.lastrc = SQL_ERROR;
			/* TODO perhaps it can be a problem if SET NOCOUNT ON, test it */
#if 0
			tds_free_all_results(tds);
			odbc_populate_ird(stmt);
#endif
			if (stmt->row_status == PRE_NORMAL_ROW)
				return result_type;
			break;

		default:
			return result_type;
		}
	}
}

/*
 * TODO support multi-row fetch
 * - handle correctly SQLGetData (for forward cursors accept only row_size == 1
 *   for other types application must use SQLSetPos)
 * - handle correctly results (SQL_SUCCESS_WITH_INFO if error on some rows,
 *   SQL_ERROR for all rows, see doc)
 */
static SQLRETURN SQL_API
_SQLFetch(TDS_STMT * stmt)
{
	/* TODO cursors send cursor fetch it needed */
	TDSSOCKET *tds;
	TDSRESULTINFO *resinfo;
	TDSCOLUMN *colinfo;
	int i;
	SQLULEN curr_row, num_rows;
	SQLINTEGER len = 0;
	TDS_CHAR *src;
	int srclen;
	struct _drecord *drec_ard;
	TDS_DESC *ard;
	TDSCONTEXT *context;
	SQLULEN dummy, *fetched_ptr;
	SQLUSMALLINT *status_ptr, row_status;

#define AT_ROW(ptr, type) (row_offset ? (type*)(((char*)(ptr)) + row_offset) : &ptr[curr_row])
	SQLLEN row_offset = 0;

	if (stmt->ard->header.sql_desc_bind_type != SQL_BIND_BY_COLUMN && stmt->ard->header.sql_desc_bind_offset_ptr)
		row_offset = *stmt->ard->header.sql_desc_bind_offset_ptr;

	ard = stmt->ard;

	if (stmt->dbc->current_statement != stmt || stmt->row_status == NOT_IN_ROW) {
		odbc_errs_add(&stmt->errs, "24000", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	IRD_CHECK;

	if (stmt->ird->header.sql_desc_count <= 0) {
		odbc_errs_add(&stmt->errs, "24000", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	tds = stmt->dbc->tds_socket;

	context = stmt->dbc->env->tds_ctx;

	stmt->row++;

	fetched_ptr = &dummy;
	if (stmt->ird->header.sql_desc_rows_processed_ptr)
		fetched_ptr = stmt->ird->header.sql_desc_rows_processed_ptr;
	*fetched_ptr = 0;

	num_rows = stmt->ard->header.sql_desc_array_size;
	status_ptr = stmt->ird->header.sql_desc_array_status_ptr;
	if (status_ptr) {
		for (i = 0; i < (int)num_rows; ++i)
			*status_ptr++ = SQL_ROW_NOROW;
		status_ptr = stmt->ird->header.sql_desc_array_status_ptr;
	}

	curr_row = 0;
	do {
		TDS_INT result_type;
		int truncated = 0;

		row_status = SQL_ROW_SUCCESS;

		/* do not get compute row if we are not expecting a compute row */
		switch (stmt->row_status) {
		case AFTER_COMPUTE_ROW:
			/* handle done if needed */
			/* FIXME doesn't seem so fine ... - freddy77 */
			tds_process_tokens(stmt->dbc->tds_socket, &result_type, NULL, TDS_TOKEN_TRAILING);
			goto all_done;

		case IN_COMPUTE_ROW:
			/* compute recorset contains only a row */
			/* we already fetched compute row in SQLMoreResults so do not fetch another one */
			num_rows = 1;
			stmt->row_status = AFTER_COMPUTE_ROW;
			break;

		default:
			/* FIXME stmt->row_count set correctly ?? TDS_DONE_COUNT not checked */
			switch (odbc_process_tokens(stmt, TDS_STOPAT_ROWFMT|TDS_RETURN_ROW|TDS_STOPAT_COMPUTE)) {
			case TDS_ROW_RESULT:
				break;
			default:
#if 0
				stmt->row_count = tds->rows_affected;
#endif
				/*
				 * NOTE do not set row_status to NOT_IN_ROW,
				 * if compute tds_process_tokens above returns TDS_NO_MORE_RESULTS
				 */
				stmt->row_status = PRE_NORMAL_ROW;
				stmt->special_row = 0;
#if 0
				odbc_populate_ird(stmt);
#endif
				tdsdump_log(TDS_DBG_INFO1, "SQLFetch: NO_DATA_FOUND\n");
				goto all_done;
				break;
			case TDS_CMD_FAIL:
				ODBC_RETURN(stmt, SQL_ERROR);
				break;
			}

			stmt->row_status = IN_NORMAL_ROW;

			/* handle special row */
			switch (stmt->special_row) {
			case 1: /* GetTypeInfo row convert type */
				resinfo = tds->current_results;
				if (resinfo->num_cols >= 2) {
					colinfo = resinfo->columns[1];
					if (colinfo->column_type == SYBINT2) {
						TDS_SMALLINT *data = (TDS_SMALLINT *) (resinfo->current_row + colinfo->column_offset);
						*data = odbc_swap_datetime_sql_type(*data);
					}
				}
				break;
			}
		}

		resinfo = tds->current_results;
		if (!resinfo) {
			tdsdump_log(TDS_DBG_INFO1, "SQLFetch: !resinfo\n");
			break;
		}

		/* we got a row, return a row readed even if error (for ODBC specifications) */
		++(*fetched_ptr);
		for (i = 0; i < resinfo->num_cols; i++) {
			colinfo = resinfo->columns[i];
			colinfo->column_text_sqlgetdatapos = 0;
			drec_ard = (i < ard->header.sql_desc_count) ? &ard->records[i] : NULL;
			if (!drec_ard) {
				num_rows = 1;
				continue;
			}
			if (colinfo->column_cur_size < 0) {
				if (drec_ard->sql_desc_indicator_ptr) {
					*AT_ROW(drec_ard->sql_desc_indicator_ptr, SQLLEN) = SQL_NULL_DATA;
				} else if (drec_ard->sql_desc_data_ptr) {
					odbc_errs_add(&stmt->errs, "22002", NULL);
					row_status = SQL_ROW_ERROR;
					break;
				}
				continue;
			}
			/* set indicator to 0 if data is not null */
			if (drec_ard->sql_desc_indicator_ptr)
				*AT_ROW(drec_ard->sql_desc_indicator_ptr, SQLLEN) = 0;

			/* TODO what happen to length if no data is returned (drec->sql_desc_data_ptr == NULL) ?? */
			len = 0;
			if (drec_ard->sql_desc_data_ptr) {
				int c_type;
				TDS_CHAR *data_ptr = (TDS_CHAR *) drec_ard->sql_desc_data_ptr;

				src = (TDS_CHAR *) & resinfo->current_row[colinfo->column_offset];
				if (is_blob_type(colinfo->column_type))
					src = ((TDSBLOB *) src)->textvalue;
				srclen = colinfo->column_cur_size;
				c_type = drec_ard->sql_desc_concise_type;
				if (c_type == SQL_C_DEFAULT)
					c_type = odbc_sql_to_c_type_default(stmt->ird->records[i].sql_desc_concise_type);
				if (row_offset || curr_row == 0) {
					data_ptr += row_offset;
				} else {
					SQLLEN len;

					/* this shit is mine -- freddy77 */
					switch (c_type) {
					case SQL_C_CHAR:
					case SQL_C_BINARY:
						len = drec_ard->sql_desc_octet_length;
						break;
					case SQL_C_DATE:
					case SQL_C_TYPE_DATE:
						len = sizeof(DATE_STRUCT);
						break;
					case SQL_C_TIME:
					case SQL_C_TYPE_TIME:
						len = sizeof(TIME_STRUCT);
						break;
					case SQL_C_TIMESTAMP:
					case SQL_C_TYPE_TIMESTAMP:
						len = sizeof(TIMESTAMP_STRUCT);
						break;
					case SQL_C_NUMERIC:
						len = sizeof(SQL_NUMERIC_STRUCT);
						break;
					default:
						len = tds_get_size_by_type(odbc_c_to_server_type(c_type));
						break;
					}
					if (len < 0) {
						row_status = SQL_ROW_ERROR;
						break;
					}
					data_ptr += len * curr_row;
				}
				len = convert_tds2sql(context, tds_get_conversion_type(colinfo->column_type, colinfo->column_size),
						      src, srclen, c_type, data_ptr, drec_ard->sql_desc_octet_length, drec_ard);
				if (len < 0) {
					row_status = SQL_ROW_ERROR;
					break;
				}
				if ((c_type == SQL_C_CHAR && len >= drec_ard->sql_desc_octet_length)
				    || (c_type == SQL_C_BINARY && len > drec_ard->sql_desc_octet_length)) {
					truncated = 1;
					stmt->errs.lastrc = SQL_SUCCESS_WITH_INFO;
				}
			} else {
				/* TODO change when we code cursors support... */
				/* stop looping, forward cursor support only one row */
				num_rows = 1;
			}
			if (drec_ard->sql_desc_octet_length_ptr)
				*AT_ROW(drec_ard->sql_desc_octet_length_ptr, SQLLEN) = len;
		}

		if (status_ptr)
			*status_ptr++ = truncated ? SQL_ROW_ERROR : row_status;
		if (row_status == SQL_ROW_ERROR) {
			stmt->errs.lastrc = SQL_ERROR;
			break;
		}
#if SQL_BIND_BY_COLUMN != 0
		if (stmt->ard->header.sql_desc_bind_type != SQL_BIND_BY_COLUMN)
#endif
			row_offset += stmt->ard->header.sql_desc_bind_type;
	} while (++curr_row < num_rows);

      all_done:
	if (*fetched_ptr == 0 && (stmt->errs.lastrc == SQL_SUCCESS || stmt->errs.lastrc == SQL_SUCCESS_WITH_INFO))
		ODBC_RETURN(stmt, SQL_NO_DATA);
	if (stmt->errs.lastrc == SQL_ERROR && (*fetched_ptr > 1 || (*fetched_ptr == 1 && row_status != SQL_ROW_ERROR)))
		ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLFetch(SQLHSTMT hstmt)
{
	INIT_HSTMT;

	ODBC_RETURN(stmt, _SQLFetch(stmt));
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLFetchScroll(SQLHSTMT hstmt, SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
{
	INIT_HSTMT;

	/* still we do not support cursors and scrolling */
	/* TODO cursors */
	if (FetchOrientation != SQL_FETCH_NEXT) {
		odbc_errs_add(&stmt->errs, "HY106", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	ODBC_RETURN(stmt, _SQLFetch(stmt));
}
#endif


#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
{
	tdsdump_log(TDS_DBG_INFO1, "SQLFreeHandle(%d, 0x%p)\n", HandleType, (void *) Handle);

	switch (HandleType) {
	case SQL_HANDLE_STMT:
		return _SQLFreeStmt(Handle, SQL_DROP, 0);
		break;
	case SQL_HANDLE_DBC:
		return _SQLFreeConnect(Handle);
		break;
	case SQL_HANDLE_ENV:
		return _SQLFreeEnv(Handle);
		break;
	case SQL_HANDLE_DESC:
		return _SQLFreeDesc(Handle);
		break;
	}
	return SQL_ERROR;
}

static SQLRETURN SQL_API
_SQLFreeConnect(SQLHDBC hdbc)
{
	int i;

	INIT_HDBC;

	/* TODO if connected return error */
	tds_free_socket(dbc->tds_socket);

	/* free attributes */
	tds_dstr_free(&dbc->attr.current_catalog);
	tds_dstr_free(&dbc->attr.translate_lib);

	tds_dstr_free(&dbc->server);
	tds_dstr_free(&dbc->dsn);

	for (i = 0; i < TDS_MAX_APP_DESC; i++) {
		if (dbc->uad[i]) {
			desc_free(dbc->uad[i]);
		}
	}
	odbc_errs_reset(&dbc->errs);

	free(dbc);

	return SQL_SUCCESS;
}

SQLRETURN SQL_API
SQLFreeConnect(SQLHDBC hdbc)
{
	return _SQLFreeConnect(hdbc);
}
#endif

static SQLRETURN SQL_API
_SQLFreeEnv(SQLHENV henv)
{
	INIT_HENV;

	odbc_errs_reset(&env->errs);
	tds_free_context(env->tds_ctx);
	free(env);

	return SQL_SUCCESS;
}

SQLRETURN SQL_API
SQLFreeEnv(SQLHENV henv)
{
	return _SQLFreeEnv(henv);
}

static SQLRETURN SQL_API
_SQLFreeStmt(SQLHSTMT hstmt, SQLUSMALLINT fOption, int force)
{
	TDSSOCKET *tds;

	INIT_HSTMT;

	/* check if option correct */
	if (fOption != SQL_DROP && fOption != SQL_CLOSE && fOption != SQL_UNBIND && fOption != SQL_RESET_PARAMS) {
		tdsdump_log(TDS_DBG_ERROR, "odbc:SQLFreeStmt: Unknown option %d\n", fOption);
		odbc_errs_add(&stmt->errs, "HY092", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* if we have bound columns, free the temporary list */
	if (fOption == SQL_DROP || fOption == SQL_UNBIND) {
		desc_free_records(stmt->ard);
	}

	/* do the same for bound parameters */
	if (fOption == SQL_DROP || fOption == SQL_RESET_PARAMS) {
		desc_free_records(stmt->apd);
		desc_free_records(stmt->ipd);
	}

	/* close statement */
	if (fOption == SQL_DROP || fOption == SQL_CLOSE) {
		SQLRETURN retcode;

		tds = stmt->dbc->tds_socket;
		/*
		 * FIXME -- otherwise make sure the current statement is complete
		 */
		/* do not close other running query ! */
		if (tds->state != TDS_IDLE && tds->state != TDS_DEAD && stmt->dbc->current_statement == stmt) {
			if (tds_send_cancel(tds) == TDS_SUCCEED)
				tds_process_cancel(tds);
		}

		/* TODO cursors free cursor too */

		/* close prepared statement or add to connection */
		retcode = odbc_free_dynamic(stmt);
		if (!force && retcode != SQL_SUCCESS)
			return retcode;
	}

	/* free it */
	if (fOption == SQL_DROP) {
		/* detatch from list */
		if (stmt->next)
			stmt->next->prev = stmt->prev;
		if (stmt->prev)
			stmt->prev->next = stmt->next;
		if (stmt->dbc->stmt_list == stmt)
			stmt->dbc->stmt_list = stmt->next;

		if (stmt->query)
			free(stmt->query);
		if (stmt->prepared_query)
			free(stmt->prepared_query);
		tds_free_param_results(stmt->params);
		odbc_errs_reset(&stmt->errs);
		if (stmt->dbc->current_statement == stmt)
			stmt->dbc->current_statement = NULL;
		tds_dstr_free(&stmt->cursor_name);
		desc_free(stmt->ird);
		desc_free(stmt->ipd);
		desc_free(stmt->orig_ard);
		desc_free(stmt->orig_apd);
		free(stmt);

		/* NOTE we freed stmt, do not use ODBC_RETURN */
		return SQL_SUCCESS;
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLFreeStmt(SQLHSTMT hstmt, SQLUSMALLINT fOption)
{
	return _SQLFreeStmt(hstmt, fOption, 0);
}

SQLRETURN SQL_API
SQLCloseCursor(SQLHSTMT hstmt)
{
	/* TODO cursors */
	/*
	 * Basic implementation for when no driver manager is present.
	 *  - according to ODBC documentation SQLCloseCursor is more or less
	 *    equivalent to SQLFreeStmt(..., SQL_CLOSE).
	 *  - indeed that is what the DM does if it can't find the function
	 *    in the driver, so this is pretty close.
	 */
	/* TODO remember to close cursors really when get implemented */
	/* TODO read all results and discard them or use cancellation ?? test behaviour */
	return _SQLFreeStmt(hstmt, SQL_CLOSE, 0);
}

static SQLRETURN SQL_API
_SQLFreeDesc(SQLHDESC hdesc)
{
	INIT_HDESC;

	if (desc->header.sql_desc_alloc_type != SQL_DESC_ALLOC_USER) {
		odbc_errs_add(&desc->errs, "HY017", NULL);
		ODBC_RETURN(desc, SQL_ERROR);
	}

	if (IS_HDBC(desc->parent)) {
		TDS_DBC *dbc = (TDS_DBC *) desc->parent;
		TDS_STMT *stmt;
		int i;

		/* freeing descriptors associated to statements revert state of statements */
		for (stmt = dbc->stmt_list; stmt != NULL; stmt = stmt->next) {
			if (stmt->ard == desc)
				stmt->ard = stmt->orig_ard;
			if (stmt->apd == desc)
				stmt->apd = stmt->orig_apd;
		}

		for (i = 0; i < TDS_MAX_APP_DESC; ++i) {
			if (dbc->uad[i] == desc) {
				dbc->uad[i] = NULL;
				desc_free(desc);
				break;
			}
		}
	}

	return SQL_SUCCESS;
}

static SQLRETURN SQL_API
_SQLGetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER * StringLength)
{
	void *src;
	size_t size;

	INIT_HSTMT;

	/* TODO assign directly, use macro for size */
	switch (Attribute) {
	case SQL_ATTR_APP_PARAM_DESC:
		size = sizeof(stmt->apd);
		src = &stmt->apd;
		break;
	case SQL_ATTR_APP_ROW_DESC:
		size = sizeof(stmt->ard);
		src = &stmt->ard;
		break;
	case SQL_ATTR_ASYNC_ENABLE:
		size = sizeof(stmt->attr.async_enable);
		src = &stmt->attr.async_enable;
		break;
	case SQL_ATTR_CONCURRENCY:
		size = sizeof(stmt->attr.concurrency);
		src = &stmt->attr.concurrency;
		break;
	case SQL_ATTR_CURSOR_TYPE:
		size = sizeof(stmt->attr.cursor_type);
		src = &stmt->attr.cursor_type;
		break;
	case SQL_ATTR_ENABLE_AUTO_IPD:
		size = sizeof(stmt->attr.enable_auto_ipd);
		src = &stmt->attr.enable_auto_ipd;
		break;
	case SQL_ATTR_FETCH_BOOKMARK_PTR:
		size = sizeof(stmt->attr.fetch_bookmark_ptr);
		src = &stmt->attr.fetch_bookmark_ptr;
		break;
	case SQL_ATTR_KEYSET_SIZE:
		size = sizeof(stmt->attr.keyset_size);
		src = &stmt->attr.keyset_size;
		break;
	case SQL_ATTR_MAX_LENGTH:
		size = sizeof(stmt->attr.max_length);
		src = &stmt->attr.max_length;
		break;
	case SQL_ATTR_MAX_ROWS:
		size = sizeof(stmt->attr.max_rows);
		src = &stmt->attr.max_rows;
		break;
	case SQL_ATTR_METADATA_ID:
		size = sizeof(stmt->attr.metadata_id);
		src = &stmt->attr.noscan;
		break;
	case SQL_ATTR_NOSCAN:
		size = sizeof(stmt->attr.noscan);
		src = &stmt->attr.noscan;
		break;
	case SQL_ATTR_PARAM_BIND_OFFSET_PTR:
		size = sizeof(stmt->apd->header.sql_desc_bind_offset_ptr);
		src = &stmt->apd->header.sql_desc_bind_offset_ptr;
		break;
	case SQL_ATTR_PARAM_BIND_TYPE:
		size = sizeof(stmt->apd->header.sql_desc_bind_type);
		src = &stmt->apd->header.sql_desc_bind_type;
		break;
	case SQL_ATTR_PARAM_OPERATION_PTR:
		size = sizeof(stmt->apd->header.sql_desc_array_status_ptr);
		src = &stmt->apd->header.sql_desc_array_status_ptr;
		break;
	case SQL_ATTR_PARAM_STATUS_PTR:
		size = sizeof(stmt->ipd->header.sql_desc_array_status_ptr);
		src = &stmt->ipd->header.sql_desc_array_status_ptr;
		break;
	case SQL_ATTR_PARAMS_PROCESSED_PTR:
		size = sizeof(stmt->ipd->header.sql_desc_rows_processed_ptr);
		src = &stmt->ipd->header.sql_desc_rows_processed_ptr;
		break;
	case SQL_ATTR_PARAMSET_SIZE:
		size = sizeof(stmt->apd->header.sql_desc_array_size);
		src = &stmt->apd->header.sql_desc_array_size;
		break;
	case SQL_ATTR_QUERY_TIMEOUT:
		size = sizeof(stmt->attr.query_timeout);
		src = &stmt->attr.query_timeout;
		break;
	case SQL_ATTR_RETRIEVE_DATA:
		size = sizeof(stmt->attr.retrieve_data);
		src = &stmt->attr.retrieve_data;
		break;
	case SQL_ATTR_ROW_BIND_OFFSET_PTR:
		size = sizeof(stmt->ard->header.sql_desc_bind_offset_ptr);
		src = &stmt->ard->header.sql_desc_bind_offset_ptr;
		break;
#if SQL_BIND_TYPE != SQL_ATTR_ROW_BIND_TYPE
	case SQL_BIND_TYPE:	/* although this is ODBC2 we must support this attribute */
#endif
	case SQL_ATTR_ROW_BIND_TYPE:
		size = sizeof(stmt->ard->header.sql_desc_bind_type);
		src = &stmt->ard->header.sql_desc_bind_type;
		break;
	case SQL_ATTR_ROW_NUMBER:
		/* TODO update this value */
		size = sizeof(stmt->attr.row_number);
		src = &stmt->attr.row_number;
		break;
	case SQL_ATTR_ROW_OPERATION_PTR:
		size = sizeof(stmt->ard->header.sql_desc_array_status_ptr);
		src = &stmt->ard->header.sql_desc_array_status_ptr;
		break;
	case SQL_ATTR_ROW_STATUS_PTR:
		size = sizeof(stmt->ird->header.sql_desc_array_status_ptr);
		src = &stmt->ird->header.sql_desc_array_status_ptr;
		break;
	case SQL_ATTR_ROWS_FETCHED_PTR:
		size = sizeof(stmt->ird->header.sql_desc_rows_processed_ptr);
		src = &stmt->ird->header.sql_desc_rows_processed_ptr;
		break;
	case SQL_ATTR_ROW_ARRAY_SIZE:
		size = sizeof(stmt->ard->header.sql_desc_array_size);
		src = &stmt->ard->header.sql_desc_array_size;
		break;
	case SQL_ATTR_SIMULATE_CURSOR:
		size = sizeof(stmt->attr.simulate_cursor);
		src = &stmt->attr.simulate_cursor;
		break;
	case SQL_ATTR_USE_BOOKMARKS:
		size = sizeof(stmt->attr.use_bookmarks);
		src = &stmt->attr.use_bookmarks;
		break;
	case SQL_ATTR_CURSOR_SCROLLABLE:
		size = sizeof(stmt->attr.cursor_scrollable);
		src = &stmt->attr.cursor_scrollable;
		break;
	case SQL_ATTR_CURSOR_SENSITIVITY:
		size = sizeof(stmt->attr.cursor_sensitivity);
		src = &stmt->attr.cursor_sensitivity;
		break;
	case SQL_ATTR_IMP_ROW_DESC:
		size = sizeof(stmt->ird);
		src = &stmt->ird;
		break;
	case SQL_ATTR_IMP_PARAM_DESC:
		size = sizeof(stmt->ipd);
		src = &stmt->ipd;
		break;
	case SQL_ROWSET_SIZE:	/* although this is ODBC2 we must support this attribute */
		size = sizeof(stmt->sql_rowset_size);
		src = &stmt->sql_rowset_size;
		break;
		/* TODO SQL_COLUMN_SEARCHABLE, although ODBC2 */
	default:
		odbc_errs_add(&stmt->errs, "HY092", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	memcpy(Value, src, size);
	if (StringLength)
		*StringLength = size;

	ODBC_RETURN_(stmt);
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLGetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER * StringLength)
{
	return _SQLGetStmtAttr(hstmt, Attribute, Value, BufferLength, StringLength);
}
#endif

SQLRETURN SQL_API
SQLGetStmtOption(SQLHSTMT hstmt, SQLUSMALLINT fOption, SQLPOINTER pvParam)
{
	return _SQLGetStmtAttr(hstmt, (SQLINTEGER) fOption, pvParam, SQL_MAX_OPTION_STRING_LENGTH, NULL);
}

SQLRETURN SQL_API
SQLNumResultCols(SQLHSTMT hstmt, SQLSMALLINT FAR * pccol)
{
	INIT_HSTMT;

	/*
	 * 3/15/2001 bsb - DBD::ODBC calls SQLNumResultCols on non-result
	 * generating queries such as 'drop table'
	 */
#if 0
	if (stmt->row_status == NOT_IN_ROW) {
		odbc_errs_add(&stmt->errs, "24000", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
#endif
	*pccol = stmt->ird->header.sql_desc_count;
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLPrepare(SQLHSTMT hstmt, SQLCHAR FAR * szSqlStr, SQLINTEGER cbSqlStr)
{
	SQLRETURN retcode;

	INIT_HSTMT;

	/* try to free dynamic associated */
	retcode = odbc_free_dynamic(stmt);
	if (retcode != SQL_SUCCESS)
		return retcode;

	if (SQL_SUCCESS != odbc_set_stmt_prepared_query(stmt, (char *) szSqlStr, cbSqlStr))
		ODBC_RETURN(stmt, SQL_ERROR);

	/* count parameters */
	stmt->param_count = tds_count_placeholders(stmt->prepared_query);

	/* trasform to native (one time, not for every SQLExecute) */
	if (SQL_SUCCESS != prepare_call(stmt))
		ODBC_RETURN(stmt, SQL_ERROR);

	/* try to prepare query */
	/* TODO support getting info for RPC */
	if (!stmt->prepared_query_is_rpc) {
		TDSDYNAMIC *dyn;

		TDS_INT result_type;
		int in_row = 0;
		int done_flags;
		TDSPARAMINFO *params = NULL;
		TDSSOCKET *tds = stmt->dbc->tds_socket;

		/* TODO needed ?? */
		if (stmt->dyn) {
			tds_free_dynamic(tds, stmt->dyn);
			stmt->dyn = NULL;
		}

		/*
		 * using TDS7+ we need parameters to prepare a query so try
		 * to get them
		 * TDS5 do not need parameters type and we have always to
		 * prepare sepatarely so this is not an issue
		 */
		if (IS_TDS7_PLUS(tds)) {
			SQLRETURN res;

			/* use current parameter informations if availables */
			res = start_parse_prepared_query(stmt, 0);
			if (res != SQL_SUCCESS) {
				/*
				 * not all parameters are bounded, prepare
				 * with dummy parameters however we need to
				 * prepare again later
				 * TODO prepare only getting information
				 */
				stmt->need_reprepare = 1;
			} else {
				params = stmt->params;
			}
			/*
			 * we can't reuse parsed parameters cause we didn't
			 * compute row for execute
			 */
			stmt->param_num = 0;
		}

		tdsdump_log(TDS_DBG_INFO1, "Creating prepared statement\n");
		if (tds_submit_prepare(tds, stmt->prepared_query, NULL, &stmt->dyn, params) == TDS_FAIL) {
			tds_free_param_results(params);
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		stmt->dbc->current_statement = stmt;

		/* try to go to the next recordset */
		/* TODO merge with similar code */
		desc_free_records(stmt->ird);
		stmt->row_status = PRE_NORMAL_ROW;
		for (;;) {
			switch (tds_process_tokens(tds, &result_type, &done_flags, TDS_RETURN_ROWFMT|TDS_RETURN_DONE)) {
			case TDS_SUCCEED:
				switch (result_type) {
				case TDS_DONE_RESULT:
				case TDS_DONEPROC_RESULT:
				case TDS_DONEINPROC_RESULT:
					stmt->row_count = tds->rows_affected;
					if (done_flags & TDS_DONE_ERROR && !stmt->dyn->emulated)
						stmt->errs.lastrc = SQL_ERROR;
					/* FIXME this row is used only as a flag for update binding, should be cleared if binding/result changed */
					stmt->row = 0;
					break;

				case TDS_ROWFMT_RESULT:
					/* store first row informations */
					if (!in_row)
						odbc_populate_ird(stmt);
					stmt->row = 0;
					stmt->row_count = TDS_NO_COUNT;
					stmt->next_row_count = TDS_NO_COUNT;
					stmt->row_status = PRE_NORMAL_ROW;
					in_row = 1;
					break;
				}
				continue;
			case TDS_NO_MORE_RESULTS:
				break;
			default:
				stmt->errs.lastrc = SQL_ERROR;
				break;
			}

			if (stmt->dbc->current_statement == stmt)
				stmt->dbc->current_statement = NULL;
			if (stmt->errs.lastrc == SQL_ERROR && !stmt->dyn->emulated) {
				dyn = stmt->dyn;
				stmt->dyn = NULL;
				tds_free_dynamic(tds, dyn);
			}
			/* TODO ?? tds_free_param_results(params); */
			ODBC_RETURN_(stmt);
		}
	}

	ODBC_RETURN_(stmt);
}

SQLRETURN
_SQLRowCount(SQLHSTMT hstmt, SQLLEN FAR * pcrow)
{
	TDSSOCKET *tds;

	INIT_HSTMT;

	tds = stmt->dbc->tds_socket;
	if (stmt->row_status == NOT_IN_ROW) {
		odbc_errs_add(&stmt->errs, "24000", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	*pcrow = -1;
	if (stmt->row_count != TDS_NO_COUNT)
		*pcrow = stmt->row_count;
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLRowCount(SQLHSTMT hstmt, SQLLEN FAR * pcrow)
{
	return _SQLRowCount(hstmt, pcrow);
}

SQLRETURN SQL_API
SQLSetCursorName(SQLHSTMT hstmt, SQLCHAR FAR * szCursor, SQLSMALLINT cbCursor)
{
	INIT_HSTMT;

	/* TODO cursors use it */
	if (!tds_dstr_copyn(&stmt->cursor_name, (const char *) szCursor, odbc_get_string_size(cbCursor, szCursor))) {
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLGetCursorName(SQLHSTMT hstmt, SQLCHAR FAR * szCursor, SQLSMALLINT cbCursorMax, SQLSMALLINT FAR * pcbCursor)
{
	SQLRETURN rc;

	INIT_HSTMT;

	/* TODO cursors how to read real cursor ?? */
	if ((rc = odbc_set_string(szCursor, cbCursorMax, pcbCursor, tds_dstr_cstr(&stmt->cursor_name), -1)))
		odbc_errs_add(&stmt->errs, "01004", NULL);

	ODBC_RETURN(stmt, rc);
}

/*
 * spinellia@acm.org : copied shamelessly from change_database
 * transaction support
 * 1 = commit, 0 = rollback
 */
static SQLRETURN
change_transaction(TDS_DBC * dbc, int state)
{
	const char *query;
	TDSSOCKET *tds = dbc->tds_socket;

	tdsdump_log(TDS_DBG_INFO1, "change_transaction(0x%p,%d)\n", dbc, state);

	if (dbc->attr.autocommit == SQL_AUTOCOMMIT_ON || TDS_IS_MSSQL(tds))
		query = state ? "IF @@TRANCOUNT > 0 COMMIT" : "IF @@TRANCOUNT > 0 ROLLBACK";
	else
		query = state ? "IF @@TRANCOUNT > 0 COMMIT BEGIN TRANSACTION" : "IF @@TRANCOUNT > 0 ROLLBACK BEGIN TRANSACTION";

	/* if pending drop all recordset, don't issue cancel */
	if (tds->state == TDS_PENDING && dbc->current_statement != NULL) {
		/* TODO what happen on multiple errors ?? discard all ?? */
		if (tds_process_simple_query(tds) == TDS_FAIL)
			return SQL_ERROR;
	}

	if (tds_submit_query(tds, query) != TDS_SUCCEED) {
		odbc_errs_add(&dbc->errs, "HY000", "Could not perform COMMIT or ROLLBACK");
		return SQL_ERROR;
	}

	if (tds_process_simple_query(tds) != TDS_SUCCEED)
		return SQL_ERROR;

	/* TODO some query can collect errors so perhaps it's better to return SUCCES_WITH_INFO in such case... */
	return SQL_SUCCESS;
}

static SQLRETURN SQL_API
_SQLTransact(SQLHENV henv, SQLHDBC hdbc, SQLUSMALLINT fType)
{
	int op = (fType == SQL_COMMIT ? 1 : 0);

	/* I may live without a HENV */
	/*     CHECK_HENV; */
	/* ..but not without a HDBC! */
	INIT_HDBC;

	tdsdump_log(TDS_DBG_INFO1, "SQLTransact(0x%p,0x%p,%d)\n", henv, hdbc, fType);
	ODBC_RETURN(dbc, change_transaction(dbc, op));
}

SQLRETURN SQL_API
SQLTransact(SQLHENV henv, SQLHDBC hdbc, SQLUSMALLINT fType)
{
	return _SQLTransact(henv, hdbc, fType);
}

#if ODBCVER >= 0x300
SQLRETURN SQL_API
SQLEndTran(SQLSMALLINT handleType, SQLHANDLE handle, SQLSMALLINT completionType)
{
	/*
	 * Do not call the exported SQLTransact(),
	 * because we may wind up calling a function with the same name implemented by the DM.
	 */
	switch (handleType) {
	case SQL_HANDLE_ENV:
		return _SQLTransact(handle, NULL, completionType);
	case SQL_HANDLE_DBC:
		return _SQLTransact(NULL, handle, completionType);
	}
	return SQL_ERROR;
}
#endif

/* end of transaction support */

SQLRETURN SQL_API
SQLSetParam(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fCType, SQLSMALLINT fSqlType, SQLULEN cbParamDef,
	    SQLSMALLINT ibScale, SQLPOINTER rgbValue, SQLLEN FAR * pcbValue)
{
	return _SQLBindParameter(hstmt, ipar, SQL_PARAM_INPUT_OUTPUT, fCType, fSqlType, cbParamDef, ibScale, rgbValue,
				 SQL_SETPARAM_VALUE_MAX, pcbValue);
}

/**
 * SQLColumns
 *
 * Return column information for a table or view. This is
 * mapped to a call to sp_columns which - lucky for us - returns
 * the exact result set we need.
 *
 * exec sp_columns [ @table_name = ] object
 *                 [ , [ @table_owner = ] owner ]
 *                 [ , [ @table_qualifier = ] qualifier ]
 *                 [ , [ @column_name = ] column ]
 *                 [ , [ @ODBCVer = ] ODBCVer ]
 *
 */
SQLRETURN SQL_API
SQLColumns(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName,	/* object_qualifier */
	   SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,	/* object_owner */
	   SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName,	/* object_name */
	   SQLSMALLINT cbTableName, SQLCHAR FAR * szColumnName,	/* column_name */
	   SQLSMALLINT cbColumnName)
{
	int retcode;

	INIT_HSTMT;

	retcode =
		odbc_stat_execute(stmt, "sp_columns ", 4, "P@table_name", szTableName, cbTableName, "P@table_owner", szSchemaName,
				  cbSchemaName, "O@table_qualifier", szCatalogName, cbCatalogName, "P@column_name", szColumnName,
				  cbColumnName);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
		odbc_col_setname(stmt, 7, "COLUMN_SIZE");
		odbc_col_setname(stmt, 8, "BUFFER_LENGTH");
		odbc_col_setname(stmt, 9, "DECIMAL_DIGITS");
		odbc_col_setname(stmt, 10, "NUM_PREC_RADIX");
	}
	ODBC_RETURN_(stmt);
}

static SQLRETURN SQL_API
_SQLGetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER * StringLength)
{
	char *p = NULL;
	SQLRETURN rc;

	INIT_HDBC;

	switch (Attribute) {
	case SQL_ATTR_AUTOCOMMIT:
		*((SQLUINTEGER *) Value) = dbc->attr.autocommit;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_CONNECTION_TIMEOUT:
		*((SQLUINTEGER *) Value) = dbc->attr.connection_timeout;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_ACCESS_MODE:
		*((SQLUINTEGER *) Value) = dbc->attr.access_mode;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_CURRENT_CATALOG:
		p = tds_dstr_cstr(&dbc->attr.current_catalog);
		break;
	case SQL_ATTR_LOGIN_TIMEOUT:
		*((SQLUINTEGER *) Value) = dbc->attr.login_timeout;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_ODBC_CURSORS:
		*((SQLUINTEGER *) Value) = dbc->attr.odbc_cursors;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_PACKET_SIZE:
		*((SQLUINTEGER *) Value) = dbc->attr.packet_size;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_QUIET_MODE:
		*((SQLHWND *) Value) = dbc->attr.quite_mode;
		ODBC_RETURN_(dbc);
		break;
#ifdef TDS_NO_DM
	case SQL_ATTR_TRACE:
		*((SQLUINTEGER *) Value) = dbc->attr.trace;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_TRACEFILE:
		p = tds_dstr_cstr(&dbc->attr.tracefile);
		break;
#endif
	case SQL_ATTR_TXN_ISOLATION:
		*((SQLUINTEGER *) Value) = dbc->attr.txn_isolation;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_TRANSLATE_LIB:
	case SQL_ATTR_TRANSLATE_OPTION:
		odbc_errs_add(&dbc->errs, "HYC00", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
		break;
	default:
		odbc_errs_add(&dbc->errs, "HY092", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
		break;
	}

	assert(p);

	rc = odbc_set_string_i(Value, BufferLength, StringLength, p, -1);
	ODBC_RETURN(dbc, rc);
}

#if ODBCVER >= 0x300
SQLRETURN SQL_API
SQLGetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER * StringLength)
{
	return _SQLGetConnectAttr(hdbc, Attribute, Value, BufferLength, StringLength);
}
#endif

SQLRETURN SQL_API
SQLGetConnectOption(SQLHDBC hdbc, SQLUSMALLINT fOption, SQLPOINTER pvParam)
{
	return _SQLGetConnectAttr(hdbc, (SQLINTEGER) fOption, pvParam, SQL_MAX_OPTION_STRING_LENGTH, NULL);
}

SQLRETURN SQL_API
SQLGetData(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLSMALLINT fCType, SQLPOINTER rgbValue, SQLLEN cbValueMax, SQLLEN FAR * pcbValue)
{
	/* TODO cursors fetch row if needed ?? */
	TDSCOLUMN *colinfo;
	TDSRESULTINFO *resinfo;
	TDSSOCKET *tds;
	TDS_CHAR *src;
	int srclen;
	TDSCONTEXT *context;
	SQLLEN dummy_cb;
	int nSybType;

	INIT_HSTMT;

	/* read data from TDS only if current statement */
	if (stmt->dbc->current_statement != stmt || stmt->row_status == PRE_NORMAL_ROW || stmt->row_status == NOT_IN_ROW) {
		odbc_errs_add(&stmt->errs, "24000", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	IRD_CHECK;

	if (!pcbValue)
		pcbValue = &dummy_cb;

	tds = stmt->dbc->tds_socket;
	context = stmt->dbc->env->tds_ctx;
	resinfo = tds->current_results;
	if (!resinfo) {
		odbc_errs_add(&stmt->errs, "HY010", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	if (icol <= 0 || icol > resinfo->num_cols) {
		odbc_errs_add(&stmt->errs, "07009", "Column out of range");
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	colinfo = resinfo->columns[icol - 1];

	if (colinfo->column_cur_size < 0) {
		*pcbValue = SQL_NULL_DATA;
	} else {
		src = (TDS_CHAR *) & resinfo->current_row[colinfo->column_offset];
		if (is_blob_type(colinfo->column_type)) {
			if (colinfo->column_text_sqlgetdatapos >= colinfo->column_cur_size)
				ODBC_RETURN(stmt, SQL_NO_DATA);

			/* 2003-8-29 check for an old bug -- freddy77 */
			assert(colinfo->column_text_sqlgetdatapos >= 0);
			src = ((TDSBLOB *) src)->textvalue + colinfo->column_text_sqlgetdatapos;
			srclen = colinfo->column_cur_size - colinfo->column_text_sqlgetdatapos;
		} else {
			srclen = colinfo->column_cur_size;
		}
		nSybType = tds_get_conversion_type(colinfo->column_type, colinfo->column_size);
		if (fCType == SQL_C_DEFAULT)
			fCType = odbc_sql_to_c_type_default(stmt->ird->records[icol - 1].sql_desc_concise_type);
		assert(fCType);
		*pcbValue = convert_tds2sql(context, nSybType, src, srclen, fCType, (TDS_CHAR *) rgbValue, cbValueMax, NULL);
		if (*pcbValue < 0)
			ODBC_RETURN(stmt, SQL_ERROR);

		if (is_blob_type(colinfo->column_type)) {
			/* calc how many bytes was readed */
			int readed = cbValueMax;

			/* FIXME test on destination char ??? */
			if (stmt->dbc->env->attr.output_nts != SQL_FALSE && nSybType == SYBTEXT && readed > 0)
				--readed;
			if (readed > *pcbValue)
				readed = *pcbValue;
			colinfo->column_text_sqlgetdatapos += readed;
			/* not all readed ?? */
			if (colinfo->column_text_sqlgetdatapos < colinfo->column_cur_size)
				ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLGetFunctions(SQLHDBC hdbc, SQLUSMALLINT fFunction, SQLUSMALLINT FAR * pfExists)
{
	int i;

	INIT_HDBC;

	tdsdump_log(TDS_DBG_FUNC, "SQLGetFunctions: fFunction is %d\n", fFunction);
	switch (fFunction) {
#if (ODBCVER >= 0x0300)
	case SQL_API_ODBC3_ALL_FUNCTIONS:
		for (i = 0; i < SQL_API_ODBC3_ALL_FUNCTIONS_SIZE; ++i) {
			pfExists[i] = 0;
		}

		/*
		 * every api available are contained in a macro
		 * all these macro begin with API followed by 2 letter
		 * first letter mean pre ODBC 3 (_) or ODBC 3 (3)
		 * second letter mean implemented (X) or unimplemented (_)
		 * You should copy these macro 3 times... not very good
		 * but works. Perhaps best method is build the bit array statically
		 * and then use it but I don't know how to build it...
		 */
#undef ODBC_ALL_API
#undef ODBC_COLATTRIBUTES

#if SQL_API_SQLCOLATTRIBUTE != SQL_API_SQLCOLATTRIBUTES
#define ODBC_COLATTRIBUTES(s) s
#else
#define ODBC_COLATTRIBUTES(s)
#endif

#define ODBC_ALL_API \
	API_X(SQL_API_SQLALLOCCONNECT);\
	API_X(SQL_API_SQLALLOCENV);\
	API3X(SQL_API_SQLALLOCHANDLE);\
	API_X(SQL_API_SQLALLOCSTMT);\
	API_X(SQL_API_SQLBINDCOL);\
	API_X(SQL_API_SQLBINDPARAM);\
	API_X(SQL_API_SQLBINDPARAMETER);\
	API__(SQL_API_SQLBROWSECONNECT);\
	API3_(SQL_API_SQLBULKOPERATIONS);\
	API_X(SQL_API_SQLCANCEL);\
	API3X(SQL_API_SQLCLOSECURSOR);\
	API3X(SQL_API_SQLCOLATTRIBUTE);\
	ODBC_COLATTRIBUTES(API_X(SQL_API_SQLCOLATTRIBUTES);)\
	API_X(SQL_API_SQLCOLUMNPRIVILEGES);\
	API_X(SQL_API_SQLCOLUMNS);\
	API_X(SQL_API_SQLCONNECT);\
	API3X(SQL_API_SQLCOPYDESC);\
	API_X(SQL_API_SQLDESCRIBECOL);\
	API__(SQL_API_SQLDESCRIBEPARAM);\
	API_X(SQL_API_SQLDISCONNECT);\
	API_X(SQL_API_SQLDRIVERCONNECT);\
	API3X(SQL_API_SQLENDTRAN);\
	API_X(SQL_API_SQLERROR);\
	API_X(SQL_API_SQLEXECDIRECT);\
	API_X(SQL_API_SQLEXECUTE);\
	API_X(SQL_API_SQLEXTENDEDFETCH);\
	API_X(SQL_API_SQLFETCH);\
	API3X(SQL_API_SQLFETCHSCROLL);\
	API_X(SQL_API_SQLFOREIGNKEYS);\
	API_X(SQL_API_SQLFREECONNECT);\
	API_X(SQL_API_SQLFREEENV);\
	API3X(SQL_API_SQLFREEHANDLE);\
	API_X(SQL_API_SQLFREESTMT);\
	API3X(SQL_API_SQLGETCONNECTATTR);\
	API_X(SQL_API_SQLGETCONNECTOPTION);\
	API_X(SQL_API_SQLGETCURSORNAME);\
	API_X(SQL_API_SQLGETDATA);\
	API3X(SQL_API_SQLGETDESCFIELD);\
	API3X(SQL_API_SQLGETDESCREC);\
	API3X(SQL_API_SQLGETDIAGFIELD);\
	API3X(SQL_API_SQLGETDIAGREC);\
	API3X(SQL_API_SQLGETENVATTR);\
	API_X(SQL_API_SQLGETFUNCTIONS);\
	API_X(SQL_API_SQLGETINFO);\
	API3X(SQL_API_SQLGETSTMTATTR);\
	API_X(SQL_API_SQLGETSTMTOPTION);\
	API_X(SQL_API_SQLGETTYPEINFO);\
	API_X(SQL_API_SQLMORERESULTS);\
	API_X(SQL_API_SQLNATIVESQL);\
	API_X(SQL_API_SQLNUMPARAMS);\
	API_X(SQL_API_SQLNUMRESULTCOLS);\
	API_X(SQL_API_SQLPARAMDATA);\
	API_X(SQL_API_SQLPARAMOPTIONS);\
	API_X(SQL_API_SQLPREPARE);\
	API_X(SQL_API_SQLPRIMARYKEYS);\
	API_X(SQL_API_SQLPROCEDURECOLUMNS);\
	API_X(SQL_API_SQLPROCEDURES);\
	API_X(SQL_API_SQLPUTDATA);\
	API_X(SQL_API_SQLROWCOUNT);\
	API3X(SQL_API_SQLSETCONNECTATTR);\
	API_X(SQL_API_SQLSETCONNECTOPTION);\
	API_X(SQL_API_SQLSETCURSORNAME);\
	API3X(SQL_API_SQLSETDESCFIELD);\
	API3X(SQL_API_SQLSETDESCREC);\
	API3X(SQL_API_SQLSETENVATTR);\
	API_X(SQL_API_SQLSETPARAM);\
	API__(SQL_API_SQLSETPOS);\
	API__(SQL_API_SQLSETSCROLLOPTIONS);\
	API3X(SQL_API_SQLSETSTMTATTR);\
	API_X(SQL_API_SQLSETSTMTOPTION);\
	API_X(SQL_API_SQLSPECIALCOLUMNS);\
	API_X(SQL_API_SQLSTATISTICS);\
	API_X(SQL_API_SQLTABLEPRIVILEGES);\
	API_X(SQL_API_SQLTABLES);\
	API_X(SQL_API_SQLTRANSACT);

#define API_X(n) if (n >= 0 && n < (16*SQL_API_ODBC3_ALL_FUNCTIONS_SIZE)) pfExists[n/16] |= (1 << n%16);
#define API__(n)
#define API3X(n) if (n >= 0 && n < (16*SQL_API_ODBC3_ALL_FUNCTIONS_SIZE)) pfExists[n/16] |= (1 << n%16);
#define API3_(n)
		ODBC_ALL_API
#undef API_X
#undef API__
#undef API3X
#undef API3_
		ODBC_RETURN(dbc, SQL_SUCCESS);
#endif

	case SQL_API_ALL_FUNCTIONS:
		tdsdump_log(TDS_DBG_FUNC, "odbc:SQLGetFunctions: " "fFunction is SQL_API_ALL_FUNCTIONS\n");
		for (i = 0; i < 100; ++i) {
			pfExists[i] = SQL_FALSE;
		}

#define API_X(n) if (n >= 0 && n < 100) pfExists[n] = SQL_TRUE;
#define API__(n)
#define API3X(n)
#define API3_(n)
		ODBC_ALL_API
#undef API_X
#undef API__
#undef API3X
#undef API3_
		ODBC_RETURN(dbc, SQL_SUCCESS);
		break;
#define API_X(n) case n:
#define API__(n)
#if (ODBCVER >= 0x300)
#define API3X(n) case n:
#else
#define API3X(n)
#endif
#define API3_(n)
		ODBC_ALL_API
#undef API_X
#undef API__
#undef API3X
#undef API3_
		*pfExists = SQL_TRUE;
		ODBC_RETURN(dbc, SQL_SUCCESS);
	default:
		*pfExists = SQL_FALSE;
		ODBC_RETURN(dbc, SQL_SUCCESS);
		break;
	}
	ODBC_RETURN(dbc, SQL_SUCCESS);
#undef ODBC_ALL_API
}


SQLRETURN SQL_API
SQLGetInfo(SQLHDBC hdbc, SQLUSMALLINT fInfoType, SQLPOINTER rgbInfoValue, SQLSMALLINT cbInfoValueMax,
	   SQLSMALLINT FAR * pcbInfoValue)
{
	const char *p = NULL;
	char buf[32];
	TDSSOCKET *tds;
	int is_ms = -1;
	unsigned int smajor = 6;
	SQLUINTEGER mssql7plus_mask = 0;
	int out_len = -1;

#define SIVAL out_len = sizeof(SQLSMALLINT), *((SQLSMALLINT *) rgbInfoValue)
#define USIVAL out_len = sizeof(SQLUSMALLINT), *((SQLUSMALLINT *) rgbInfoValue)
#define IVAL out_len = sizeof(SQLINTEGER), *((SQLINTEGER *) rgbInfoValue)
#define UIVAL out_len = sizeof(SQLUINTEGER), *((SQLUINTEGER *) rgbInfoValue)
#define ULVAL out_len = sizeof(SQLULEN), *((SQLULEN *) rgbInfoValue)

	INIT_HDBC;

	if ((tds = dbc->tds_socket) != NULL) {
		is_ms = TDS_IS_MSSQL(tds);
		smajor = (tds->product_version >> 24) & 0x7F;
		if (is_ms && smajor >= 7)
			mssql7plus_mask = ~((SQLUINTEGER) 0);
	}

	switch (fInfoType) {
	case SQL_ACCESSIBLE_PROCEDURES:
	case SQL_ACCESSIBLE_TABLES:
		p = "Y";
		break;
		/* SQL_ACTIVE_CONNECTIONS renamed to SQL_MAX_DRIVER_CONNECTIONS */
#if (ODBCVER >= 0x0300)
	case SQL_ACTIVE_ENVIRONMENTS:
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
#if (ODBCVER >= 0x0300)
	case SQL_AGGREGATE_FUNCTIONS:
		UIVAL = SQL_AF_ALL;
		break;
	case SQL_ALTER_DOMAIN:
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_ALTER_TABLE:
		UIVAL = SQL_AT_ADD_COLUMN | SQL_AT_ADD_COLUMN_DEFAULT | SQL_AT_ADD_COLUMN_SINGLE | SQL_AT_ADD_CONSTRAINT |
			SQL_AT_ADD_TABLE_CONSTRAINT | SQL_AT_CONSTRAINT_NAME_DEFINITION | SQL_AT_DROP_COLUMN_RESTRICT;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_ASYNC_MODE:
		/* TODO we hope so in a not-too-far future */
		/* UIVAL = SQL_AM_STATEMENT; */
		UIVAL = SQL_AM_NONE;
		break;
	case SQL_BATCH_ROW_COUNT:
		UIVAL = SQL_BRC_EXPLICIT;
		break;
	case SQL_BATCH_SUPPORT:
		UIVAL = SQL_BS_ROW_COUNT_EXPLICIT | SQL_BS_ROW_COUNT_PROC | SQL_BS_SELECT_EXPLICIT | SQL_BS_SELECT_PROC;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_BOOKMARK_PERSISTENCE:
		/* TODO ??? */
		UIVAL = SQL_BP_DELETE | SQL_BP_SCROLL | SQL_BP_UPDATE;
		break;
	case SQL_CATALOG_LOCATION:
		SIVAL = SQL_CL_START;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_CATALOG_NAME:
		p = "Y";
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_CATALOG_NAME_SEPARATOR:
		p = ".";
		break;
	case SQL_CATALOG_TERM:
		p = "database";
		break;
	case SQL_CATALOG_USAGE:
		UIVAL = SQL_CU_DML_STATEMENTS | SQL_CU_PROCEDURE_INVOCATION | SQL_CU_TABLE_DEFINITION;
		break;
		/* TODO */
#if 0
	case SQL_COLLATION_SEQ:
		break;
#endif
	case SQL_COLUMN_ALIAS:
		p = "Y";
		break;
	case SQL_CONCAT_NULL_BEHAVIOR:
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		/* TODO a bit more complicate for mssql2k.. */
		SIVAL = (!is_ms || smajor < 7) ? SQL_CB_NON_NULL : SQL_CB_NULL;
		break;
		/* TODO SQL_CONVERT_BIGINT SQL_CONVERT_GUID SQL_CONVERT_DATE SQL_CONVERT_TIME */
		/* For Sybase/MSSql6.x we return 0 cause NativeSql is not so implemented */
	case SQL_CONVERT_BINARY:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_VARCHAR |
			 SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_TINYINT | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_BIT:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_CHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT |
			 SQL_CVT_TINYINT | SQL_CVT_TIMESTAMP | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_DECIMAL:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_FLOAT:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BIT | SQL_CVT_TINYINT | SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) &
			mssql7plus_mask;
		break;
	case SQL_CONVERT_INTEGER:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_LONGVARCHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_NUMERIC:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_REAL:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BIT | SQL_CVT_TINYINT | SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) &
			mssql7plus_mask;
		break;
	case SQL_CONVERT_SMALLINT:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_TIMESTAMP:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_TIMESTAMP | SQL_CVT_WCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_TINYINT:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT | SQL_CVT_TINYINT |
			 SQL_CVT_WCHAR | SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_VARBINARY:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_VARCHAR |
			 SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_TINYINT | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_VARCHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT |
			 SQL_CVT_TINYINT | SQL_CVT_TIMESTAMP | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_LONGVARBINARY:
		UIVAL = (SQL_CVT_BINARY | SQL_CVT_LONGVARBINARY | SQL_CVT_VARBINARY) & mssql7plus_mask;
		break;
	case SQL_CONVERT_WLONGVARCHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_CONVERT_WCHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT |
			 SQL_CVT_TINYINT | SQL_CVT_TIMESTAMP | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
	case SQL_CONVERT_WVARCHAR:
		UIVAL = (SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL | SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT |
			 SQL_CVT_REAL | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR | SQL_CVT_BINARY | SQL_CVT_VARBINARY | SQL_CVT_BIT |
			 SQL_CVT_TINYINT | SQL_CVT_TIMESTAMP | SQL_CVT_LONGVARBINARY | SQL_CVT_WCHAR | SQL_CVT_WLONGVARCHAR |
			 SQL_CVT_WVARCHAR) & mssql7plus_mask;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_CONVERT_FUNCTIONS:
		/* TODO no CAST for Sybase ?? */
		UIVAL = SQL_FN_CVT_CONVERT | SQL_FN_CVT_CAST;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_CREATE_ASSERTION:
	case SQL_CREATE_CHARACTER_SET:
	case SQL_CREATE_COLLATION:
	case SQL_CREATE_DOMAIN:
		UIVAL = 0;
		break;
	case SQL_CREATE_SCHEMA:
		UIVAL = SQL_CS_AUTHORIZATION | SQL_CS_CREATE_SCHEMA;
		break;
	case SQL_CREATE_TABLE:
		UIVAL = SQL_CT_CREATE_TABLE;
		break;
	case SQL_CREATE_TRANSLATION:
		UIVAL = 0;
		break;
	case SQL_CREATE_VIEW:
		UIVAL = SQL_CV_CHECK_OPTION | SQL_CV_CREATE_VIEW;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_CORRELATION_NAME:
		USIVAL = SQL_CN_ANY;
		break;
	case SQL_CURSOR_COMMIT_BEHAVIOR:
		/* currently cursors are not supported however sql server close automaticly cursors on commit */
		/* TODO cursors test what happen if rollback, cursors get properly deleted ?? */
		USIVAL = SQL_CB_CLOSE;
		break;
	case SQL_CURSOR_ROLLBACK_BEHAVIOR:
		USIVAL = SQL_CB_CLOSE;
		break;
	case SQL_CURSOR_SENSITIVITY:
		UIVAL = SQL_SENSITIVE;
		break;
	case SQL_DATABASE_NAME:
		p = tds_dstr_cstr(&dbc->attr.current_catalog);
		break;
	case SQL_DATA_SOURCE_NAME:
		p = tds_dstr_cstr(&dbc->dsn);
		break;
	case SQL_DATA_SOURCE_READ_ONLY:
		/*
		 * TODO: determine the right answer from connection
		 * attribute SQL_ATTR_ACCESS_MODE
		 */
		p = "N";	/* false, writable */
		break;
#if (ODBCVER >= 0x0300)
	case SQL_DATETIME_LITERALS:
		/* TODO ok ?? */
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_DBMS_NAME:
		p = tds->product_name;
		break;
	case SQL_DBMS_VER:
		if (!dbc->tds_socket)
			return SQL_ERROR;
		odbc_rdbms_version(dbc->tds_socket, buf);
		p = buf;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_DDL_INDEX:
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_DEFAULT_TXN_ISOLATION:
		UIVAL = SQL_TXN_READ_COMMITTED;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_DESCRIBE_PARAMETER:
		p = "N";
		break;
#endif /* ODBCVER >= 0x0300 */
#ifdef TDS_NO_DM
	case SQL_DRIVER_HDBC:
		ULVAL = (SQLULEN) dbc;
		break;
	case SQL_DRIVER_HENV:
		ULVAL = (SQLULEN) dbc->env;
		break;
	case SQL_DRIVER_HSTMT:
		ULVAL = (SQLULEN) dbc->current_statement;
		break;
#endif
	case SQL_DRIVER_NAME:	/* ODBC 2.0 */
		p = "libtdsodbc.so";
		break;
	case SQL_DRIVER_ODBC_VER:
		p = "03.00";
		break;
	case SQL_DRIVER_VER:
		/* TODO check ##.##.#### format */
		p = VERSION;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_DROP_ASSERTION:
	case SQL_DROP_CHARACTER_SET:
	case SQL_DROP_COLLATION:
	case SQL_DROP_DOMAIN:
	case SQL_DROP_SCHEMA:
		UIVAL = 0;
		break;
	case SQL_DROP_TABLE:
		UIVAL = SQL_DT_DROP_TABLE;
		break;
	case SQL_DROP_TRANSLATION:
		UIVAL = 0;
		break;
	case SQL_DROP_VIEW:
		UIVAL = SQL_DV_DROP_VIEW;
		break;
	case SQL_DYNAMIC_CURSOR_ATTRIBUTES1:
	case SQL_DYNAMIC_CURSOR_ATTRIBUTES2:
		/* TODO cursors */
		/* Cursors not supported yet */
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_EXPRESSIONS_IN_ORDERBY:
		p = "Y";
		break;
	case SQL_FILE_USAGE:
		USIVAL = SQL_FILE_NOT_SUPPORTED;
		break;
	case SQL_FETCH_DIRECTION:
		/* TODO cursors */
		/*
		 * TODO not supported
		 * UIVAL = SQL_FD_FETCH_ABSOLUTE | SQL_FD_FETCH_BOOKMARK | SQL_FD_FETCH_FIRST | SQL_FD_FETCH_LAST | SQL_FD_FETCH_NEXT
		 * | SQL_FD_FETCH_PRIOR | SQL_FD_FETCH_RELATIVE;
		 */
		UIVAL = 0;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1:
	case SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2:
		/* TODO cursors */
		/* Cursors not supported yet */
		/* TODO NEXT supported ?? */
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_GETDATA_EXTENSIONS:
		/* TODO FreeTDS support more ?? */
		UIVAL = SQL_GD_BLOCK;
		break;
	case SQL_GROUP_BY:
		USIVAL = SQL_GB_GROUP_BY_CONTAINS_SELECT;
		break;
	case SQL_IDENTIFIER_CASE:
		/* TODO configuration dependend */
		USIVAL = SQL_IC_MIXED;
		break;
	case SQL_IDENTIFIER_QUOTE_CHAR:
		p = "\"";
		/* TODO workaround for Sybase, use SET QUOTED_IDENTIFIER ON and fix unwanted quote */
		if (!is_ms)
			p = "";
		break;
#if (ODBCVER >= 0x0300)
	case SQL_INDEX_KEYWORDS:
		UIVAL = SQL_IK_ASC | SQL_IK_DESC;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_INFO_SCHEMA_VIEWS:
		/* TODO finish */
		UIVAL = 0;
		break;
	case SQL_INSERT_STATEMENT:
		UIVAL = 0;
		break;
		/* renamed from SQL_ODBC_SQL_OPT_IEF */
	case SQL_INTEGRITY:
		p = "Y";
		break;
	case SQL_KEYSET_CURSOR_ATTRIBUTES1:
	case SQL_KEYSET_CURSOR_ATTRIBUTES2:
		/* TODO cursors */
		/* Cursors not supported yet */
		UIVAL = 0;
		break;
	case SQL_KEYWORDS:
		/* TODO ok for Sybase ? */
		p = "BREAK,BROWSE,BULK,CHECKPOINT,CLUSTERED,"
			"COMMITTED,COMPUTE,CONFIRM,CONTROLROW,DATABASE,"
			"DBCC,DISK,DISTRIBUTED,DUMMY,DUMP,ERRLVL,"
			"ERROREXIT,EXIT,FILE,FILLFACTOR,FLOPPY,HOLDLOCK,"
			"IDENTITY_INSERT,IDENTITYCOL,IF,KILL,LINENO,"
			"LOAD,MIRROREXIT,NONCLUSTERED,OFF,OFFSETS,ONCE,"
			"OVER,PERCENT,PERM,PERMANENT,PLAN,PRINT,PROC,"
			"PROCESSEXIT,RAISERROR,READ,READTEXT,RECONFIGURE,"
			"REPEATABLE,RETURN,ROWCOUNT,RULE,SAVE,SERIALIZABLE,"
			"SETUSER,SHUTDOWN,STATISTICS,TAPE,TEMP,TEXTSIZE,"
			"TRAN,TRIGGER,TRUNCATE,TSEQUEL,UNCOMMITTED," "UPDATETEXT,USE,WAITFOR,WHILE,WRITETEXT";
		break;
	case SQL_LIKE_ESCAPE_CLAUSE:
		p = "Y";
		break;
	case SQL_LOCK_TYPES:
		/* TODO cursors */
		/*
		 * TODO we do not support SQLSetPos
		 * IVAL = SQL_LCK_NO_CHANGE;
		 */
		IVAL = 0;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_MAX_ASYNC_CONCURRENT_STATEMENTS:
		UIVAL = 1;
		break;
#endif /* ODBCVER >= 0x0300 */
		/* TODO same limits for Sybase ? */
	case SQL_MAX_BINARY_LITERAL_LEN:
		UIVAL = 131072;
		break;
	case SQL_MAX_CHAR_LITERAL_LEN:
		UIVAL = 131072;
		break;
	case SQL_MAX_CONCURRENT_ACTIVITIES:
		USIVAL = 1;
		break;
	case SQL_MAX_COLUMNS_IN_GROUP_BY:
	case SQL_MAX_COLUMNS_IN_INDEX:
	case SQL_MAX_COLUMNS_IN_ORDER_BY:
		/* TODO Sybase ? */
		USIVAL = 16;
		break;
	case SQL_MAX_COLUMNS_IN_SELECT:
		/* TODO Sybase ? */
		USIVAL = 4000;
		break;
	case SQL_MAX_COLUMNS_IN_TABLE:
		/* TODO Sybase ? */
		USIVAL = 250;
		break;
	case SQL_MAX_DRIVER_CONNECTIONS:
		USIVAL = 0;
		break;
	case SQL_MAX_IDENTIFIER_LEN:
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		USIVAL = (!is_ms || smajor < 7) ? 30 : 128;
		break;
	case SQL_MAX_INDEX_SIZE:
		UIVAL = 127;
		break;
	case SQL_MAX_PROCEDURE_NAME_LEN:
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		/* TODO Sybase ? */
		USIVAL = (is_ms && smajor >= 7) ? 134 : 36;
		break;
	case SQL_MAX_ROW_SIZE:
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		/* TODO Sybase ? */
		UIVAL = (is_ms && smajor >= 7) ? 8062 : 1962;
		break;
	case SQL_MAX_ROW_SIZE_INCLUDES_LONG:
		p = "N";
		break;
	case SQL_MAX_STATEMENT_LEN:
		/* TODO Sybase ? */
		UIVAL = 131072;
		break;
	case SQL_MAX_TABLES_IN_SELECT:
		/* TODO Sybase ? */
		USIVAL = 16;
		break;
	case SQL_MAX_USER_NAME_LEN:
		/* TODO Sybase ? */
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		USIVAL = (is_ms && smajor >= 7) ? 128 : 30;
		break;
	case SQL_MAX_COLUMN_NAME_LEN:
	case SQL_MAX_CURSOR_NAME_LEN:
	case SQL_MAX_SCHEMA_NAME_LEN:
	case SQL_MAX_CATALOG_NAME_LEN:
	case SQL_MAX_TABLE_NAME_LEN:
		/* TODO Sybase ? */
		if (is_ms == -1)
			ODBC_RETURN(dbc, SQL_ERROR);
		USIVAL = (is_ms && smajor >= 7) ? 128 : 30;
		break;
	case SQL_MULT_RESULT_SETS:
		p = "Y";
		break;
	case SQL_MULTIPLE_ACTIVE_TXN:
		p = "Y";
		break;
	case SQL_NEED_LONG_DATA_LEN:
		/* current implementation do not require length, however future will, so is correct to return yes */
		p = "Y";
		break;
	case SQL_NON_NULLABLE_COLUMNS:
		USIVAL = SQL_NNC_NON_NULL;
		break;
	case SQL_NULL_COLLATION:
		USIVAL = SQL_NC_LOW;
		break;
	case SQL_NUMERIC_FUNCTIONS:
		UIVAL = (SQL_FN_NUM_ABS | SQL_FN_NUM_ACOS | SQL_FN_NUM_ASIN | SQL_FN_NUM_ATAN | SQL_FN_NUM_ATAN2 |
			 SQL_FN_NUM_CEILING | SQL_FN_NUM_COS | SQL_FN_NUM_COT | SQL_FN_NUM_DEGREES | SQL_FN_NUM_EXP |
			 SQL_FN_NUM_FLOOR | SQL_FN_NUM_LOG | SQL_FN_NUM_LOG10 | SQL_FN_NUM_MOD | SQL_FN_NUM_PI | SQL_FN_NUM_POWER |
			 SQL_FN_NUM_RADIANS | SQL_FN_NUM_RAND | SQL_FN_NUM_ROUND | SQL_FN_NUM_SIGN | SQL_FN_NUM_SIN |
			 SQL_FN_NUM_SQRT | SQL_FN_NUM_TAN) & mssql7plus_mask;
		break;
	case SQL_ODBC_API_CONFORMANCE:
		SIVAL = SQL_OAC_LEVEL2;
		break;
#if (ODBCVER >= 0x0300)
	case SQL_ODBC_INTERFACE_CONFORMANCE:
		UIVAL = SQL_OAC_LEVEL2;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_ODBC_SAG_CLI_CONFORMANCE:
		SIVAL = SQL_OSCC_NOT_COMPLIANT;
		break;
	case SQL_ODBC_SQL_CONFORMANCE:
		SIVAL = SQL_OSC_CORE;
		break;
#ifdef TDS_NO_DM
	case SQL_ODBC_VER:
		/* TODO check format ##.##.0000 */
		p = VERSION;
		break;
#endif
#if (ODBCVER >= 0x0300)
	case SQL_OJ_CAPABILITIES:
		UIVAL = SQL_OJ_ALL_COMPARISON_OPS | SQL_OJ_FULL | SQL_OJ_INNER | SQL_OJ_LEFT | SQL_OJ_NESTED | SQL_OJ_NOT_ORDERED |
			SQL_OJ_RIGHT;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_ORDER_BY_COLUMNS_IN_SELECT:
		p = "N";
		break;
	case SQL_OUTER_JOINS:
		p = "Y";
		break;
#if (ODBCVER >= 0x0300)
	case SQL_PARAM_ARRAY_ROW_COUNTS:
		UIVAL = SQL_PARC_BATCH;
		break;
	case SQL_PARAM_ARRAY_SELECTS:
		UIVAL = SQL_PAS_BATCH;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_POS_OPERATIONS:
		/* TODO cursors */
		/*
		 * TODO SQLSetPos not supported
		 * UIVAL = SQL_POS_ADD | SQL_POS_DELETE | SQL_POS_POSITION | SQL_POS_REFRESH | SQL_POS_UPDATE;
		 */
		IVAL = 0;
		break;
	case SQL_POSITIONED_STATEMENTS:
		/* TODO cursors */
		/* TODO ok or should be 0 ?? */
		IVAL = SQL_PS_POSITIONED_DELETE | SQL_PS_POSITIONED_UPDATE | SQL_PS_SELECT_FOR_UPDATE;
		break;
	case SQL_PROCEDURE_TERM:
		p = "stored procedure";
		break;
	case SQL_PROCEDURES:
		p = "Y";
		break;
	case SQL_QUOTED_IDENTIFIER_CASE:
		/* TODO usually insensitive */
		USIVAL = SQL_IC_MIXED;
		break;
	case SQL_ROW_UPDATES:
		p = "N";
		break;
#if (ODBCVER >= 0x0300)
	case SQL_SCHEMA_TERM:
		p = "owner";
		break;
	case SQL_SCHEMA_USAGE:
		UIVAL = SQL_OU_DML_STATEMENTS | SQL_OU_INDEX_DEFINITION | SQL_OU_PRIVILEGE_DEFINITION | SQL_OU_PROCEDURE_INVOCATION
			| SQL_OU_TABLE_DEFINITION;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_SCROLL_CONCURRENCY:
		/* TODO cursors */
		IVAL = SQL_SCCO_READ_ONLY;
		break;
	case SQL_SCROLL_OPTIONS:
		/* TODO cursors */
		UIVAL = SQL_SO_FORWARD_ONLY | SQL_SO_STATIC;
		break;
	case SQL_SEARCH_PATTERN_ESCAPE:
		p = "\\";
		break;
	case SQL_SERVER_NAME:
		p = tds_dstr_cstr(&dbc->server);
		break;
	case SQL_SPECIAL_CHARACTERS:
		/* TODO others ?? */
		p = "\'\"[]{}";
		break;
#if (ODBCVER >= 0x0300)
	case SQL_SQL_CONFORMANCE:
		UIVAL = SQL_SC_SQL92_ENTRY;
		break;
	case SQL_SQL92_DATETIME_FUNCTIONS:
	case SQL_SQL92_FOREIGN_KEY_DELETE_RULE:
	case SQL_SQL92_FOREIGN_KEY_UPDATE_RULE:
		UIVAL = 0;
		break;
	case SQL_SQL92_GRANT:
		UIVAL = SQL_SG_WITH_GRANT_OPTION;
		break;
	case SQL_SQL92_NUMERIC_VALUE_FUNCTIONS:
		UIVAL = 0;
		break;
	case SQL_SQL92_PREDICATES:
		/* TODO Sybase ?? */
		UIVAL = SQL_SP_EXISTS | SQL_SP_ISNOTNULL | SQL_SP_ISNULL;
		break;
	case SQL_SQL92_RELATIONAL_JOIN_OPERATORS:
		/* TODO Sybase ?? */
		UIVAL = SQL_SRJO_CROSS_JOIN | SQL_SRJO_FULL_OUTER_JOIN | SQL_SRJO_INNER_JOIN | SQL_SRJO_LEFT_OUTER_JOIN |
			SQL_SRJO_RIGHT_OUTER_JOIN | SQL_SRJO_UNION_JOIN;
		break;
	case SQL_SQL92_REVOKE:
		UIVAL = SQL_SR_GRANT_OPTION_FOR;
		break;
	case SQL_SQL92_ROW_VALUE_CONSTRUCTOR:
		UIVAL = SQL_SRVC_DEFAULT | SQL_SRVC_NULL | SQL_SRVC_ROW_SUBQUERY | SQL_SRVC_VALUE_EXPRESSION;
		break;
	case SQL_SQL92_STRING_FUNCTIONS:
		UIVAL = SQL_SSF_LOWER | SQL_SSF_UPPER;
		break;
	case SQL_SQL92_VALUE_EXPRESSIONS:
		/* TODO Sybase ? CAST supported ? */
		UIVAL = SQL_SVE_CASE | SQL_SVE_CAST | SQL_SVE_COALESCE | SQL_SVE_NULLIF;
		break;
	case SQL_STANDARD_CLI_CONFORMANCE:
		UIVAL = SQL_SCC_ISO92_CLI;
		break;
	case SQL_STATIC_SENSITIVITY:
		IVAL = 0;
		break;
	case SQL_STATIC_CURSOR_ATTRIBUTES1:
	case SQL_STATIC_CURSOR_ATTRIBUTES2:
		/* TODO cursors */
		/* Cursors not supported yet */
		UIVAL = 0;
		break;
#endif /* ODBCVER >= 0x0300 */
	case SQL_STRING_FUNCTIONS:
		UIVAL = (SQL_FN_STR_ASCII | SQL_FN_STR_BIT_LENGTH | SQL_FN_STR_CHAR | SQL_FN_STR_CONCAT | SQL_FN_STR_DIFFERENCE |
			 SQL_FN_STR_INSERT | SQL_FN_STR_LCASE | SQL_FN_STR_LEFT | SQL_FN_STR_LENGTH | SQL_FN_STR_LOCATE_2 |
			 SQL_FN_STR_LTRIM | SQL_FN_STR_OCTET_LENGTH | SQL_FN_STR_REPEAT | SQL_FN_STR_RIGHT | SQL_FN_STR_RTRIM |
			 SQL_FN_STR_SOUNDEX | SQL_FN_STR_SPACE | SQL_FN_STR_SUBSTRING | SQL_FN_STR_UCASE) & mssql7plus_mask;
		break;
	case SQL_SUBQUERIES:
		UIVAL = SQL_SQ_COMPARISON | SQL_SQ_CORRELATED_SUBQUERIES | SQL_SQ_EXISTS | SQL_SQ_IN | SQL_SQ_QUANTIFIED;
		break;
	case SQL_SYSTEM_FUNCTIONS:
		UIVAL = SQL_FN_SYS_DBNAME | SQL_FN_SYS_IFNULL | SQL_FN_SYS_USERNAME;
		break;
	case SQL_TABLE_TERM:
		p = "table";
		break;
	case SQL_TIMEDATE_ADD_INTERVALS:
		UIVAL = (SQL_FN_TSI_DAY | SQL_FN_TSI_FRAC_SECOND | SQL_FN_TSI_HOUR | SQL_FN_TSI_MINUTE | SQL_FN_TSI_MONTH |
			 SQL_FN_TSI_QUARTER | SQL_FN_TSI_SECOND | SQL_FN_TSI_WEEK | SQL_FN_TSI_YEAR) & mssql7plus_mask;
		break;
	case SQL_TIMEDATE_DIFF_INTERVALS:
		UIVAL = (SQL_FN_TSI_DAY | SQL_FN_TSI_FRAC_SECOND | SQL_FN_TSI_HOUR | SQL_FN_TSI_MINUTE | SQL_FN_TSI_MONTH |
			 SQL_FN_TSI_QUARTER | SQL_FN_TSI_SECOND | SQL_FN_TSI_WEEK | SQL_FN_TSI_YEAR) & mssql7plus_mask;
		break;
	case SQL_TIMEDATE_FUNCTIONS:
		UIVAL = (SQL_FN_TD_CURDATE | SQL_FN_TD_CURRENT_DATE | SQL_FN_TD_CURRENT_TIME | SQL_FN_TD_CURRENT_TIMESTAMP |
			 SQL_FN_TD_CURTIME | SQL_FN_TD_DAYNAME | SQL_FN_TD_DAYOFMONTH | SQL_FN_TD_DAYOFWEEK | SQL_FN_TD_DAYOFYEAR |
			 SQL_FN_TD_EXTRACT | SQL_FN_TD_HOUR | SQL_FN_TD_MINUTE | SQL_FN_TD_MONTH | SQL_FN_TD_MONTHNAME |
			 SQL_FN_TD_NOW | SQL_FN_TD_QUARTER | SQL_FN_TD_SECOND | SQL_FN_TD_TIMESTAMPADD | SQL_FN_TD_TIMESTAMPDIFF |
			 SQL_FN_TD_WEEK | SQL_FN_TD_YEAR) & mssql7plus_mask;
		break;
	case SQL_TXN_CAPABLE:
		/* transaction for DML and DDL */
		SIVAL = SQL_TC_ALL;
		break;
	case SQL_TXN_ISOLATION_OPTION:
		/* TODO check SQLSetConnectAttr support */
		UIVAL = SQL_TXN_READ_COMMITTED | SQL_TXN_READ_UNCOMMITTED | SQL_TXN_REPEATABLE_READ | SQL_TXN_SERIALIZABLE;
		break;
	case SQL_UNION:
		UIVAL = SQL_U_UNION | SQL_U_UNION_ALL;
		break;
		/* TODO finish */
	case SQL_USER_NAME:
		/* TODO this is not correct username */
		/* p = tds_dstr_cstr(&dbc->tds_login->user_name); */
		/* make OpenOffice happy :) */
		p = "";
		break;
	case SQL_XOPEN_CLI_YEAR:
		/* TODO check specifications */
		p = "1995";
		break;
	default:
		odbc_log_unimplemented_type("SQLGetInfo", fInfoType);
		odbc_errs_add(&dbc->errs, "HY092", "Option not supported");
		ODBC_RETURN(dbc, SQL_ERROR);
	}

	/* char data */
	if (p) {
		ODBC_RETURN(dbc, odbc_set_string(rgbInfoValue, cbInfoValueMax, pcbInfoValue, p, -1));
	} else {
		if (out_len > 0 && pcbInfoValue)
			*pcbInfoValue = out_len;
	}

	ODBC_RETURN(dbc, SQL_SUCCESS);
#undef SIVAL
#undef USIVAL
#undef IVAL
#undef UIVAL
}

static void
tds_ascii_strupr(char *s)
{
	for (; *s; ++s)
		if ('a' <= *s && *s <= 'z')
			*s = *s & (~0x20);
}

static void
odbc_upper_column_names(TDS_STMT * stmt)
{
#if ENABLE_EXTRA_CHECKS
	TDSRESULTINFO *resinfo;
	TDSCOLUMN *colinfo;
	TDSSOCKET *tds;
#endif
	int icol;
	TDS_DESC *ird;

	IRD_CHECK;

#if ENABLE_EXTRA_CHECKS
	tds = stmt->dbc->tds_socket;
	if (!tds || !tds->current_results)
		return;

	resinfo = tds->current_results;
	for (icol = 0; icol < resinfo->num_cols; ++icol) {
		char *p;

		colinfo = resinfo->columns[icol];
		/* upper case */
		/* TODO procedure */
		for (p = colinfo->column_name; p < (colinfo->column_name + colinfo->column_namelen); ++p)
			if ('a' <= *p && *p <= 'z')
				*p = *p & (~0x20);
	}
#endif

	ird = stmt->ird;
	for (icol = ird->header.sql_desc_count; --icol >= 0;) {
		struct _drecord *drec = &ird->records[icol];

		/* upper case */
		tds_ascii_strupr(tds_dstr_cstr(&drec->sql_desc_label));
		tds_ascii_strupr(tds_dstr_cstr(&drec->sql_desc_name));
	}
}

static SQLSMALLINT
odbc_swap_datetime_sql_type(SQLSMALLINT sql_type)
{
	switch (sql_type) {
	case SQL_TYPE_TIMESTAMP:
		sql_type = SQL_TIMESTAMP;
		break;
	case SQL_TIMESTAMP:
		sql_type = SQL_TYPE_TIMESTAMP;
		break;
	case SQL_TYPE_DATE:
		sql_type = SQL_DATE;
		break;
	case SQL_DATE:
		sql_type = SQL_TYPE_DATE;
		break;
	case SQL_TYPE_TIME:
		sql_type = SQL_TIME;
		break;
	case SQL_TIME:
		sql_type = SQL_TYPE_TIME;
		break;
	}
	return sql_type;
}

SQLRETURN SQL_API
SQLGetTypeInfo(SQLHSTMT hstmt, SQLSMALLINT fSqlType)
{
	SQLRETURN res;
	TDSSOCKET *tds;
	TDS_INT result_type;
	TDS_INT compute_id;
	int varchar_pos = -1, n;
	static const char sql_templ[] = "EXEC sp_datatype_info %d";
	char sql[sizeof(sql_templ) + 30];

	INIT_HSTMT;

	tds = stmt->dbc->tds_socket;

	/* For MSSQL6.5 and Sybase 11.9 sp_datatype_info work */
	/* TODO what about early Sybase products ? */
	/* TODO Does Sybase return all ODBC3 columns? Add them if not */
	/* TODO ODBC3 convert type to ODBC version 2 (date) */
	if (TDS_IS_SYBASE(tds) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		fSqlType = odbc_swap_datetime_sql_type(fSqlType);
		stmt->special_row = 1;
	}

	sprintf(sql, sql_templ, fSqlType);
	if (TDS_IS_MSSQL(tds) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3)
		strcat(sql, ",3");
	if (SQL_SUCCESS != odbc_set_stmt_query(stmt, sql, strlen(sql)))
		ODBC_RETURN(stmt, SQL_ERROR);

      redo:
	res = _SQLExecute(stmt);

	odbc_upper_column_names(stmt);
	if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 3, "COLUMN_SIZE");
		odbc_col_setname(stmt, 11, "FIXED_PREC_SCALE");
		odbc_col_setname(stmt, 12, "AUTO_UNIQUE_VALUE");
	}

	/* workaround for a mispelled column name in Sybase */
	if (TDS_IS_SYBASE(stmt->dbc->tds_socket) && stmt->dbc->env->attr.odbc_version != SQL_OV_ODBC3)
		odbc_col_setname(stmt, 3, "PRECISION");

	if (TDS_IS_MSSQL(stmt->dbc->tds_socket) || fSqlType != 12 || res != SQL_SUCCESS)
		ODBC_RETURN(stmt, res);

	/*
	 * Sybase return first nvarchar for char... and without length !!!
	 * Some program use first entry so we discard all entry bfore varchar
	 */
	n = 0;
	while (tds->current_results) {
		TDSRESULTINFO *resinfo;
		TDSCOLUMN *colinfo;
		char *name;

		/* if next is varchar leave next for SQLFetch */
		if (n == (varchar_pos - 1))
			break;

		switch (tds_process_tokens(stmt->dbc->tds_socket, &result_type, &compute_id, TDS_STOPAT_ROWFMT|TDS_RETURN_ROW)) {
		case TDS_SUCCEED:
			if (result_type == TDS_ROW_RESULT)
				break;
		case TDS_NO_MORE_RESULTS:
			/* discard other tokens */
			tds_process_simple_query(tds);
			if (n >= varchar_pos && varchar_pos > 0)
				goto redo;
			break;
		}
		if (!tds->current_results)
			break;
		++n;

		resinfo = tds->current_results;
		colinfo = resinfo->columns[0];
		name = (char *) (resinfo->current_row + colinfo->column_offset);
		/* skip nvarchar and sysname */
		if (colinfo->column_cur_size == 7 && memcmp("varchar", name, 7) == 0) {
			varchar_pos = n;
		}
	}
	ODBC_RETURN(stmt, res);
}

SQLRETURN SQL_API
SQLParamData(SQLHSTMT hstmt, SQLPOINTER FAR * prgbValue)
{
	INIT_HSTMT;

	if (stmt->params && stmt->param_num <= (int)stmt->param_count) {
		SQLRETURN res;

		if (stmt->param_num <= 0 || stmt->param_num > stmt->apd->header.sql_desc_count) {
			/* TODO what error ?? */
			ODBC_RETURN(stmt, SQL_ERROR);
		}

		/*
		 * TODO compute output value with this formula:
		 * Bound Address + Binding Offset + ((Row Number – 1) x Element Size)
		 * (see SQLParamData documentation)
		 * This is needed for updates using SQLBulkOperation (not currently supported)
		 */
		if (!stmt->param_data_called) {
			stmt->param_data_called = 1;
			*prgbValue = stmt->apd->records[stmt->param_num - 1].sql_desc_data_ptr;
			ODBC_RETURN(stmt, SQL_NEED_DATA);
		}
		++stmt->param_num;
		switch (res = parse_prepared_query(stmt, 1)) {
		case SQL_NEED_DATA:
			*prgbValue = stmt->apd->records[stmt->param_num - 1].sql_desc_data_ptr;
			ODBC_RETURN(stmt, SQL_NEED_DATA);
		case SQL_SUCCESS:
			return _SQLExecute(stmt);
		}
		ODBC_RETURN(stmt, res);
	}

	odbc_errs_add(&stmt->errs, "HY010", NULL);
	ODBC_RETURN(stmt, SQL_ERROR);
}

SQLRETURN SQL_API
SQLPutData(SQLHSTMT hstmt, SQLPOINTER rgbValue, SQLLEN cbValue)
{
	INIT_HSTMT;

	if (stmt->prepared_query || stmt->prepared_query_is_rpc) {
		/* TODO do some more tests before setting this flag */
		stmt->param_data_called = 1;
		ODBC_RETURN(stmt, continue_parse_prepared_query(stmt, rgbValue, cbValue));
	}

	/* TODO return correct error */
	ODBC_RETURN(stmt, SQL_ERROR);
}


static SQLRETURN SQL_API
_SQLSetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength)
{
	SQLULEN u_value = (SQLULEN) ValuePtr;
	int len = 0;
	SQLRETURN ret = SQL_SUCCESS;

	INIT_HDBC;

	switch (Attribute) {
	case SQL_ATTR_AUTOCOMMIT:
		/* spinellia@acm.org */
		ODBC_RETURN(dbc, change_autocommit(dbc, u_value));
		break;
	case SQL_ATTR_CONNECTION_TIMEOUT:
		dbc->attr.connection_timeout = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_ACCESS_MODE:
		dbc->attr.access_mode = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_CURRENT_CATALOG:
		if (!IS_VALID_LEN(StringLength)) {
			odbc_errs_add(&dbc->errs, "HY090", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		len = odbc_get_string_size(StringLength, (SQLCHAR *) ValuePtr);
		ret = change_database(dbc, (char *) ValuePtr, len);
		ODBC_RETURN(dbc, ret);
		break;
	case SQL_ATTR_LOGIN_TIMEOUT:
		dbc->attr.login_timeout = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_ODBC_CURSORS:
		/* TODO cursors */
		dbc->attr.odbc_cursors = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_PACKET_SIZE:
		dbc->attr.packet_size = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_QUIET_MODE:
		dbc->attr.quite_mode = (SQLHWND) u_value;
		ODBC_RETURN_(dbc);
		break;
#ifdef TDS_NO_DM
	case SQL_ATTR_TRACE:
		dbc->attr.trace = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_TRACEFILE:
		if (!IS_VALID_LEN(StringLength)) {
			odbc_errs_add(&dbc->errs, "HY090", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		len = odbc_get_string_size(StringLength, (SQLCHAR *) ValuePtr);
		if (tds_dstr_copyn(&dbc->attr.tracefile, (const char *) ValuePtr, len))
			ODBC_RETURN_(dbc);
		else {
			odbc_errs_add(&dbc->errs, "HY001", NULL);
			ODBC_RETURN(dbc, SQL_ERROR);
		}
		break;
#endif
	case SQL_ATTR_TXN_ISOLATION:
		dbc->attr.txn_isolation = u_value;
		ODBC_RETURN_(dbc);
		break;
	case SQL_ATTR_TRANSLATE_LIB:
	case SQL_ATTR_TRANSLATE_OPTION:
		odbc_errs_add(&dbc->errs, "HYC00", NULL);
		ODBC_RETURN(dbc, SQL_ERROR);
		break;
	}
	odbc_errs_add(&dbc->errs, "HY092", NULL);
	ODBC_RETURN(dbc, SQL_ERROR);
}

SQLRETURN SQL_API
SQLSetConnectAttr(SQLHDBC hdbc, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength)
{
	return _SQLSetConnectAttr(hdbc, Attribute, ValuePtr, StringLength);
}

SQLRETURN SQL_API
SQLSetConnectOption(SQLHDBC hdbc, SQLUSMALLINT fOption, SQLULEN vParam)
{
	return _SQLSetConnectAttr(hdbc, (SQLINTEGER) fOption, (SQLPOINTER) vParam, SQL_NTS);
}

static SQLRETURN SQL_API
_SQLSetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength)
{
	SQLULEN ui = (SQLULEN) ValuePtr;
	SQLUSMALLINT *usip = (SQLUSMALLINT *) ValuePtr;
	SQLLEN *lp = (SQLLEN *) ValuePtr;
	SQLULEN *ulp = (SQLULEN *) ValuePtr;

	INIT_HSTMT;

	/* TODO - error checking and real functionality :-) */
	/* TODO some setting set also other attribute, see documentation */
	switch (Attribute) {
		/* TODO check SQLFreeHandle on descriptor. Is possible to free an associated descriptor ? */
	case SQL_ATTR_APP_PARAM_DESC:
	case SQL_ATTR_APP_ROW_DESC:
		{
			TDS_DESC *orig;
			TDS_DESC **curr;
			TDS_DESC *val = (TDS_DESC *) ValuePtr;

			if (Attribute == SQL_ATTR_APP_PARAM_DESC) {
				orig = stmt->orig_apd;
				curr = &stmt->apd;
			} else {
				orig = stmt->orig_ard;
				curr = &stmt->ard;
			}
			/* if ValuePtr is NULL or original descriptor set original */
			if (!val || val == orig) {
				*curr = orig;
				break;
			}

			/* must be allocated by user, not implicit ones */
			if (val->header.sql_desc_alloc_type != SQL_DESC_ALLOC_USER) {
				odbc_errs_add(&stmt->errs, "HY017", NULL);
				ODBC_RETURN(stmt, SQL_ERROR);
			}
			/* TODO check HDESC (not associated, from DBC HY024) */
			*curr = val;
		}
		break;
	case SQL_ATTR_ASYNC_ENABLE:
		if (stmt->attr.async_enable != ui) {
			odbc_errs_add(&stmt->errs, "HYC00", NULL);
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		stmt->attr.async_enable = ui;
		break;
	case SQL_ATTR_CONCURRENCY:
		/* TODO cursors */
		if (stmt->attr.concurrency != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.concurrency = ui;
		break;
	case SQL_ATTR_CURSOR_SCROLLABLE:
		/* TODO cursors */
		if (stmt->attr.cursor_scrollable != ui) {
			odbc_errs_add(&stmt->errs, "HYC00", NULL);
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		stmt->attr.cursor_scrollable = ui;
		break;
	case SQL_ATTR_CURSOR_SENSITIVITY:
		/* TODO cursors */
		if (stmt->attr.cursor_sensitivity != ui) {
			odbc_errs_add(&stmt->errs, "HYC00", NULL);
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		stmt->attr.cursor_sensitivity = ui;
		break;
	case SQL_ATTR_CURSOR_TYPE:
		/* TODO cursors */
		if (stmt->attr.cursor_type != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.cursor_type = ui;
		break;
	case SQL_ATTR_ENABLE_AUTO_IPD:
		if (stmt->attr.enable_auto_ipd != ui) {
			odbc_errs_add(&stmt->errs, "HYC00", NULL);
			ODBC_RETURN(stmt, SQL_ERROR);
		}
		stmt->attr.enable_auto_ipd = ui;
		break;
	case SQL_ATTR_FETCH_BOOKMARK_PTR:
		stmt->attr.fetch_bookmark_ptr = ValuePtr;
		break;
	case SQL_ATTR_IMP_ROW_DESC:
	case SQL_ATTR_IMP_PARAM_DESC:
		odbc_errs_add(&stmt->errs, "HY017", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
		break;
		/* TODO what's is this ??? */
	case SQL_ATTR_KEYSET_SIZE:
		stmt->attr.keyset_size = ui;
		break;
		/* TODO max length of data returned. Use SQL TEXTSIZE or just truncate ?? */
	case SQL_ATTR_MAX_LENGTH:
		if (stmt->attr.max_length != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.max_length = ui;
		break;
		/* TODO max row returned. Use SET ROWCOUNT */
	case SQL_ATTR_MAX_ROWS:
		if (stmt->attr.max_rows != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.max_rows = ui;
		break;
	case SQL_ATTR_METADATA_ID:
		stmt->attr.metadata_id = ui;
		break;
		/* TODO use it !!! */
	case SQL_ATTR_NOSCAN:
		stmt->attr.noscan = ui;
		break;
	case SQL_ATTR_PARAM_BIND_OFFSET_PTR:
		stmt->apd->header.sql_desc_bind_offset_ptr = lp;
		break;
	case SQL_ATTR_PARAM_BIND_TYPE:
		stmt->apd->header.sql_desc_bind_type = ui;
		break;
	case SQL_ATTR_PARAM_OPERATION_PTR:
		stmt->apd->header.sql_desc_array_status_ptr = usip;
		break;
	case SQL_ATTR_PARAM_STATUS_PTR:
		stmt->ipd->header.sql_desc_array_status_ptr = usip;
		break;
	case SQL_ATTR_PARAMS_PROCESSED_PTR:
		stmt->ipd->header.sql_desc_rows_processed_ptr = ulp;
		break;
		/* allow to exec procedure multiple time */
	case SQL_ATTR_PARAMSET_SIZE:
		stmt->apd->header.sql_desc_array_size = ui;
		break;
	case SQL_ATTR_QUERY_TIMEOUT:
		stmt->attr.query_timeout = ui;
		break;
		/* retrieve data after positioning the cursor */
	case SQL_ATTR_RETRIEVE_DATA:
		/* TODO cursors */
		if (stmt->attr.retrieve_data != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.retrieve_data = ui;
		break;
	case SQL_ATTR_ROW_ARRAY_SIZE:
		stmt->ard->header.sql_desc_array_size = ui;
		break;
	case SQL_ATTR_ROW_BIND_OFFSET_PTR:
		/* TODO test what happen with column-wise and row-wise bindings and SQLGetData */
		stmt->ard->header.sql_desc_bind_offset_ptr = lp;
		break;
#if SQL_BIND_TYPE != SQL_ATTR_ROW_BIND_TYPE
	case SQL_BIND_TYPE:	/* although this is ODBC2 we must support this attribute */
#endif
	case SQL_ATTR_ROW_BIND_TYPE:
		stmt->ard->header.sql_desc_bind_type = ui;
		break;
	case SQL_ATTR_ROW_NUMBER:
		odbc_errs_add(&stmt->errs, "HY092", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
		break;
	case SQL_ATTR_ROW_OPERATION_PTR:
		stmt->ard->header.sql_desc_array_status_ptr = usip;
		break;
	case SQL_ATTR_ROW_STATUS_PTR:
		stmt->ird->header.sql_desc_array_status_ptr = usip;
		break;
	case SQL_ATTR_ROWS_FETCHED_PTR:
		stmt->ird->header.sql_desc_rows_processed_ptr = ulp;
		break;
	case SQL_ATTR_SIMULATE_CURSOR:
		/* TODO cursors */
		if (stmt->attr.simulate_cursor != ui) {
			odbc_errs_add(&stmt->errs, "01S02", NULL);
			ODBC_RETURN(stmt, SQL_SUCCESS_WITH_INFO);
		}
		stmt->attr.simulate_cursor = ui;
		break;
	case SQL_ATTR_USE_BOOKMARKS:
		stmt->attr.use_bookmarks = ui;
		break;
	case SQL_ROWSET_SIZE:	/* although this is ODBC2 we must support this attribute */
		stmt->sql_rowset_size = ui;
		break;
	default:
		odbc_errs_add(&stmt->errs, "HY092", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
	ODBC_RETURN_(stmt);
}

#if (ODBCVER >= 0x0300)
SQLRETURN SQL_API
SQLSetStmtAttr(SQLHSTMT hstmt, SQLINTEGER Attribute, SQLPOINTER ValuePtr, SQLINTEGER StringLength)
{
	return _SQLSetStmtAttr(hstmt, Attribute, ValuePtr, StringLength);
}
#endif

SQLRETURN SQL_API
SQLSetStmtOption(SQLHSTMT hstmt, SQLUSMALLINT fOption, SQLULEN vParam)
{
	return _SQLSetStmtAttr(hstmt, (SQLINTEGER) fOption, (SQLPOINTER) vParam, SQL_NTS);
}

SQLRETURN SQL_API
SQLSpecialColumns(SQLHSTMT hstmt, SQLUSMALLINT fColType, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName,
		  SQLCHAR FAR * szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName,
		  SQLUSMALLINT fScope, SQLUSMALLINT fNullable)
{
	int retcode;
	char nullable, scope, col_type;

	INIT_HSTMT;

#ifdef TDS_NO_DM
	/* Check column type */
	if (fColType != SQL_BEST_ROWID && fColType != SQL_ROWVER) {
		odbc_errs_add(&stmt->errs, "HY097", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* check our buffer lengths */
	if (!IS_VALID_LEN(cbCatalogName) || !IS_VALID_LEN(cbSchemaName) || !IS_VALID_LEN(cbTableName)) {
		odbc_errs_add(&stmt->errs, "HY090", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* Check nullable */
	if (fNullable != SQL_NO_NULLS && fNullable != SQL_NULLABLE) {
		odbc_errs_add(&stmt->errs, "HY099", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	if (!odbc_get_string_size(cbTableName, szTableName)) {
		odbc_errs_add(&stmt->errs, "HY009", "SQLSpecialColumns: The table name parameter is required");
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	switch (fScope) {
	case SQL_SCOPE_CURROW:
	case SQL_SCOPE_TRANSACTION:
	case SQL_SCOPE_SESSION:
		break;
	default:
		odbc_errs_add(&stmt->errs, "HY098", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
#endif

	if (fNullable == SQL_NO_NULLS)
		nullable = 'O';
	else
		nullable = 'U';

	if (fScope == SQL_SCOPE_CURROW)
		scope = 'C';
	else
		scope = 'T';

	if (fColType == SQL_BEST_ROWID)
		col_type = 'R';
	else
		col_type = 'V';

	retcode =
		odbc_stat_execute(stmt, "sp_special_columns ", TDS_IS_MSSQL(stmt->dbc->tds_socket) ? 6 : 4, "O", szTableName,
				  cbTableName, "O", szSchemaName, cbSchemaName, "O@qualifier", szCatalogName, cbCatalogName,
				  "@col_type", &col_type, 1, "@scope", &scope, 1, "@nullable", &nullable, 1);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 5, "COLUMN_SIZE");
		odbc_col_setname(stmt, 6, "BUFFER_LENGTH");
		odbc_col_setname(stmt, 7, "DECIMAL_DIGITS");
	}
	ODBC_RETURN_(stmt);
}

SQLRETURN SQL_API
SQLStatistics(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
	      SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName, SQLUSMALLINT fUnique,
	      SQLUSMALLINT fAccuracy)
{
	int retcode;
	char unique, accuracy;

	INIT_HSTMT;

#ifdef TDS_NO_DM
	/* check our buffer lengths */
	if (!IS_VALID_LEN(cbCatalogName) || !IS_VALID_LEN(cbSchemaName) || !IS_VALID_LEN(cbTableName)) {
		odbc_errs_add(&stmt->errs, "HY090", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* check our uniqueness value */
	if (fUnique != SQL_INDEX_UNIQUE && fUnique != SQL_INDEX_ALL) {
		odbc_errs_add(&stmt->errs, "HY100", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* check our accuracy value */
	if (fAccuracy != SQL_QUICK && fAccuracy != SQL_ENSURE) {
		odbc_errs_add(&stmt->errs, "HY101", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	if (!odbc_get_string_size(cbTableName, szTableName)) {
		odbc_errs_add(&stmt->errs, "HY009", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}
#endif

	if (fAccuracy == SQL_ENSURE)
		accuracy = 'E';
	else
		accuracy = 'Q';

	if (fUnique == SQL_INDEX_UNIQUE)
		unique = 'Y';
	else
		unique = 'N';

	retcode =
		odbc_stat_execute(stmt, "sp_statistics ", TDS_IS_MSSQL(stmt->dbc->tds_socket) ? 5 : 4, "O@table_qualifier",
				  szCatalogName, cbCatalogName, "O@table_owner", szSchemaName, cbSchemaName, "O@table_name",
				  szTableName, cbTableName, "@is_unique", &unique, 1, "@accuracy", &accuracy, 1);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
		odbc_col_setname(stmt, 8, "ORDINAL_POSITION");
		odbc_col_setname(stmt, 10, "ASC_OR_DESC");
	}
	ODBC_RETURN_(stmt);
}


SQLRETURN SQL_API
SQLTables(SQLHSTMT hstmt, SQLCHAR FAR * szCatalogName, SQLSMALLINT cbCatalogName, SQLCHAR FAR * szSchemaName,
	  SQLSMALLINT cbSchemaName, SQLCHAR FAR * szTableName, SQLSMALLINT cbTableName, SQLCHAR FAR * szTableType,
	  SQLSMALLINT cbTableType)
{
	int retcode;
	char *type = NULL;
	const char *proc = NULL;
	int wildcards;
	TDSSOCKET *tds;

	INIT_HSTMT;

	tds = stmt->dbc->tds_socket;

	/* fix for processing */
	if (cbCatalogName == SQL_NULL_DATA)
		szCatalogName = NULL;
	cbCatalogName = odbc_get_string_size(cbCatalogName, szCatalogName);

	/* support wildcards on catalog (only odbc 3) */
	wildcards = 0;
	if (stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3 && stmt->dbc->attr.metadata_id == SQL_FALSE &&
	    (memchr(szCatalogName, '%', cbCatalogName) || memchr(szCatalogName, '_', cbCatalogName)))
		wildcards = 1;

	proc = "sp_tables ";
	if (cbCatalogName > 0 && (cbCatalogName != 1 || szCatalogName[0] != '%' || cbTableName > 0 || cbSchemaName > 0)) {
		if (wildcards) {
			/* if catalog specified and wildcards use sp_tableswc under mssql2k */
			if (TDS_IS_MSSQL(tds) && tds->product_version >= TDS_MS_VER(8,0,0))
				proc = "sp_tableswc ";

			/*
			 * TODO support wildcards on catalog even for Sybase
			 * first execute a select name from master..sysdatabases where name like catalog quoted
			 * build a db1..sp_tables args db2..sp_tables args ... query
			 * collapse results in a single recordset (how??)
			 */
		} else {
			/* if catalog specified and not wildcards use catatog on name (catalog..sp_tables) */
			proc = "..sp_tables ";
		}
	}

	/* fix type if needed quoting it */
	if (szTableType && cbTableType != SQL_NULL_DATA) {
		int len = odbc_get_string_size(cbTableType, szTableType);
		int to_fix = 0;
		int elements = 0;
		char *p = (char *) szTableType;
		char *const end = p + len;

		for (;;) {
			char *begin = p;

			p = memchr(p, ',', end - p);
			if (!p)
				p = end;
			++elements;
			if ((p - begin) < 2 || begin[0] != '\'' || p[-1] != '\'')
				to_fix = 1;
			if (p >= end)
				break;
			++p;
		}
		/* fix it */
		tdsdump_log(TDS_DBG_INFO1, "len %d to_fix %d elements %d\n", len, to_fix, elements);
		if (len && to_fix) {
			char *dst;

			tdsdump_log(TDS_DBG_INFO1, "fixing type elements\n");
			type = (char *) malloc(len + elements * 2);
			if (!type) {
				odbc_errs_add(&stmt->errs, "HY001", NULL);
				ODBC_RETURN(stmt, SQL_ERROR);
			}
			p = (char *) szTableType;
			dst = type;
			for (;;) {
				char *begin = p;

				p = memchr(p, ',', end - p);
				if (!p)
					p = end;
				if ((p - begin) < 2 || begin[0] != '\'' || p[-1] != '\'') {
					*dst++ = '\'';
					memcpy(dst, begin, p - begin);
					dst += p - begin;
					*dst++ = '\'';
				} else {
					memcpy(dst, begin, p - begin);
					dst += p - begin;
				}
				if (p >= end)
					break;
				*dst++ = *p++;
			}
			cbTableType = dst - type;
			szTableType = (SQLCHAR *) type;
		}
	}

	retcode =
		odbc_stat_execute(stmt, proc, 4, "P@table_name", szTableName, cbTableName, "P@table_owner", szSchemaName,
				  cbSchemaName, "P@table_qualifier", szCatalogName, cbCatalogName, "@table_type", szTableType,
				  cbTableType);
	if (type)
		free(type);
	if (SQL_SUCCEEDED(retcode) && stmt->dbc->env->attr.odbc_version == SQL_OV_ODBC3) {
		odbc_col_setname(stmt, 1, "TABLE_CAT");
		odbc_col_setname(stmt, 2, "TABLE_SCHEM");
	}
	ODBC_RETURN_(stmt);
}

/**
 * Log a useful message about unimplemented options
 * Defying belief, Microsoft defines mutually exclusive options that
 * some ODBC implementations #define as duplicate values (meaning, of course,
 * that they couldn't be implemented in the same function because they're
 * indistinguishable.
 *
 * Those duplicates are commented out below.
 */
static void
odbc_log_unimplemented_type(const char function_name[], int fType)
{
	const char *name, *category;

	switch (fType) {
#ifdef SQL_ALTER_SCHEMA
	case SQL_ALTER_SCHEMA:
		name = "SQL_ALTER_SCHEMA";
		category = "Supported SQL";
		break;
#endif
#ifdef SQL_ANSI_SQL_DATETIME_LITERALS
	case SQL_ANSI_SQL_DATETIME_LITERALS:
		name = "SQL_ANSI_SQL_DATETIME_LITERALS";
		category = "Supported SQL";
		break;
#endif
	case SQL_COLLATION_SEQ:
		name = "SQL_COLLATION_SEQ";
		category = "Data Source Information";
		break;
	case SQL_CONVERT_BIGINT:
		name = "SQL_CONVERT_BIGINT";
		category = "Conversion Information";
		break;
	case SQL_CONVERT_DATE:
		name = "SQL_CONVERT_DATE";
		category = "Conversion Information";
		break;
	case SQL_CONVERT_DOUBLE:
		name = "SQL_CONVERT_DOUBLE";
		category = "Conversion Information";
		break;
	case SQL_CONVERT_INTERVAL_DAY_TIME:
		name = "SQL_CONVERT_INTERVAL_DAY_TIME";
		category = "Conversion Information";
		break;
	case SQL_CONVERT_INTERVAL_YEAR_MONTH:
		name = "SQL_CONVERT_INTERVAL_YEAR_MONTH";
		category = "Conversion Information";
		break;
	case SQL_DM_VER:
		name = "SQL_DM_VER";
		category = "Added for ODBC 3.x";
		break;
	case SQL_DRIVER_HDESC:
		name = "SQL_DRIVER_HDESC";
		category = "Driver Information";
		break;
	case SQL_DRIVER_HLIB:
		name = "SQL_DRIVER_HLIB";
		category = "Driver Information";
		break;
#ifdef SQL_ODBC_STANDARD_CLI_CONFORMANCE
	case SQL_ODBC_STANDARD_CLI_CONFORMANCE:
		name = "SQL_ODBC_STANDARD_CLI_CONFORMANCE";
		category = "Driver Information";
		break;
#endif
	case SQL_USER_NAME:
		name = "SQL_USER_NAME";
		category = "Data Source Information";
		break;
	default:
		name = "unknown";
		category = "unknown";
		break;
	}

	tdsdump_log(TDS_DBG_INFO1, "odbc: not implemented: %s: option/type %d(%s) [category %s]\n", function_name, fType, name,
		    category);

	return;
}

static int
odbc_quote_metadata(TDS_DBC * dbc, char type, char *dest, const char *s, int len)
{
	int unquote = 0;
	char prev, buf[1200], *dst;

	if (!type || (type == 'O' && dbc->attr.metadata_id == SQL_FALSE))
		return tds_quote_string(dbc->tds_socket, dest, s, len);

	/* where we can have ID or PV */
	assert(type == 'P' || (type == 'O' && dbc->attr.metadata_id != SQL_FALSE));

	/* ID ? */
	if (dbc->attr.metadata_id != SQL_FALSE) {
		/* strip leading and trailing spaces */
		while (len > 0 && *s == ' ')
			++s, --len;
		while (len > 0 && s[len - 1] == ' ')
			--len;
		/* unquote if necessary */
		if (len > 2 && *s == '\"' && s[len - 1] == '\"') {
			++s, len -= 2;
			unquote = 1;
		}
	}

	/* limit string/id lengths */
	if (len > 384)
		len = 384;

	if (!dest)
		dest = buf;
	dst = dest;

	/*
	 * handle patterns
	 * "'" -> "''" (normal string quoting)
	 *
	 * if metadata_id is FALSE
	 * "\_" -> "[_]"
	 * "\%" -> "[%]"
	 * "[" -> "[[]"
	 *
	 * if metadata_id is TRUE
	 * "\"\"" -> "\"" (if unquote id)
	 * "_" -> "[_]"
	 * "%" -> "[%]"
	 * "[" -> "[[]"
	 */
	prev = 0;
	*dst++ = '\'';
	for (; --len >= 0; prev = *s++) {
		switch (*s) {
		case '\'':
			*dst++ = '\'';
			break;
		case '\"':
			if (unquote && prev == '\"') {
				prev = 0;	/* avoid "\"\"\"" -> "\"" */
				--dst;
				continue;
			}
			break;
		case '_':
		case '%':
			if (dbc->attr.metadata_id == SQL_FALSE) {
				if (prev != '\\')
					break;
				--dst;
			}
		case '[':
			if (type != 'P')
				break;
			/* quote search string */
			*dst++ = '[';
			*dst++ = *s;
			*dst++ = ']';
			prev = 0;
			continue;
		}
		*dst++ = *s;
	}
	*dst++ = '\'';
	return dst - dest;
}

#define ODBC_MAX_STAT_PARAM 8
static SQLRETURN
odbc_stat_execute(TDS_STMT * stmt, const char *begin, int nparams, ...)
{
	struct param
	{
		char *name;
		char *value;
		int len;
		char type;
	}
	params[ODBC_MAX_STAT_PARAM];
	int i, len, param_qualifier = -1;
	char *proc, *p;
	int retcode;
	va_list marker;


	assert(nparams < ODBC_MAX_STAT_PARAM);

	/* read all params and calc len required */
	va_start(marker, nparams);
	len = strlen(begin) + 2;
	for (i = 0; i < nparams; ++i) {
		int param_len;

		p = va_arg(marker, char *);

		switch (*p) {
		case 'O':	/* ordinary arguments */
		case 'P':	/* pattern value arguments */
			params[i].type = *p++;
			break;
		default:
			params[i].type = 0;	/* ordinary type */
			break;
		}
		params[i].name = p;

		params[i].value = va_arg(marker, char *);
		param_len = va_arg(marker, int);
		if (params[i].value && param_len != SQL_NULL_DATA) {
			params[i].len = odbc_get_string_size(param_len, (SQLCHAR *) params[i].value);
			len += strlen(params[i].name) + odbc_quote_metadata(stmt->dbc, params[i].type, NULL,
									    params[i].value, params[i].len) + 3;
			if (begin[0] == '.' && strstr(params[i].name, "qualifier")) {
				len += tds_quote_id(stmt->dbc->tds_socket, NULL, params[i].value, params[i].len);
				param_qualifier = i;
			}
		} else {
			params[i].value = NULL;
		}

	}
	va_end(marker);

	/* allocate space for string */
	if (!(proc = (char *) malloc(len))) {
		odbc_errs_add(&stmt->errs, "HY001", NULL);
		ODBC_RETURN(stmt, SQL_ERROR);
	}

	/* build string */
	p = proc;
	if (param_qualifier >= 0)
		p += tds_quote_id(stmt->dbc->tds_socket, p, params[param_qualifier].value, params[param_qualifier].len);
	strcpy(p, begin);
	p += strlen(begin);
	for (i = 0; i < nparams; ++i) {
		if (!params[i].value)
			continue;
		if (params[i].name[0]) {
			strcpy(p, params[i].name);
			p += strlen(params[i].name);
			*p++ = '=';
		}
		p += odbc_quote_metadata(stmt->dbc, params[i].type, p, params[i].value, params[i].len);
		*p++ = ',';
	}
	*--p = '\0';
	assert(p - proc + 1 <= len);

	/* set it */
	retcode = odbc_set_stmt_query(stmt, proc, p - proc);
	free(proc);

	if (retcode != SQL_SUCCESS)
		ODBC_RETURN(stmt, retcode);

	/* execute it */
	retcode = _SQLExecute(stmt);
	if (SQL_SUCCEEDED(retcode))
		odbc_upper_column_names(stmt);

	ODBC_RETURN(stmt, retcode);
}

static SQLRETURN
odbc_free_dynamic(TDS_STMT * stmt)
{
	TDSSOCKET *tds = stmt->dbc->tds_socket;

	if (stmt->dyn) {
		if (tds_submit_unprepare(tds, stmt->dyn) == TDS_SUCCEED) {
			if (tds_process_simple_query(tds) != TDS_SUCCEED)
				ODBC_RETURN(stmt, SQL_ERROR);
			tds_free_dynamic(tds, stmt->dyn);
			stmt->dyn = NULL;
		} else {
			/* TODO if fail add to odbc to free later, when we are in idle */
			ODBC_RETURN(stmt, SQL_ERROR);
		}
	}
	return SQL_SUCCESS;
}
