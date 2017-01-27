/* $Id$
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * File Description:
 *   This code was generated by application DATATOOL
 *   using the following specifications:
 *   'blast.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serialimpl.hpp>

// generated includes
#include <objects/blast/Blast4_error_code.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_INFO("Blast4-error-code", EBlast4_error_code, true)
{
    SET_ENUM_MODULE("NCBI-Blast4");
    ADD_ENUM_VALUE("conversion-warning", eBlast4_error_code_conversion_warning);
    ADD_ENUM_VALUE("internal-error", eBlast4_error_code_internal_error);
    ADD_ENUM_VALUE("not-implemented", eBlast4_error_code_not_implemented);
    ADD_ENUM_VALUE("not-allowed", eBlast4_error_code_not_allowed);
    ADD_ENUM_VALUE("bad-request", eBlast4_error_code_bad_request);
    ADD_ENUM_VALUE("bad-request-id", eBlast4_error_code_bad_request_id);
    ADD_ENUM_VALUE("search-pending", eBlast4_error_code_search_pending);
}
END_ENUM_INFO


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

