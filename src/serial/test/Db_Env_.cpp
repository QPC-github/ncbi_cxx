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
 *   'we_cpp.asn'.
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
#include <serial/test/Db_Env.hpp>
#include <serial/test/Argument.hpp>
#include <serial/test/Db_Clipboard.hpp>
#include <serial/test/Filter_Value.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CDb_Env_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0x3;
}

void CDb_Env_Base::ResetArguments(void)
{
    m_Arguments.clear();
    m_set_State[0] &= ~0xc;
}

void CDb_Env_Base::ResetFilters(void)
{
    m_Filters.clear();
    m_set_State[0] &= ~0x30;
}

void CDb_Env_Base::ResetClipboard(void)
{
    m_Clipboard.clear();
    m_set_State[0] &= ~0xc0;
}

void CDb_Env_Base::Reset(void)
{
    ResetName();
    ResetArguments();
    ResetFilters();
    ResetClipboard();
}

BEGIN_NAMED_BASE_CLASS_INFO("Db-Env", CDb_Env)
{
    SET_CLASS_MODULE("NCBI-Env");
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("arguments", m_Arguments, STL_list_set, (STL_CRef, (CLASS, (CArgument))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("filters", m_Filters, STL_list_set, (STL_CRef, (CLASS, (CFilter_Value))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("clipboard", m_Clipboard, STL_list_set, (STL_CRef, (CLASS, (CDb_Clipboard))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CDb_Env_Base::CDb_Env_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CDb_Env_Base::~CDb_Env_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

