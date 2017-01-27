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
 *   'macro.asn'.
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
#include <objects/macro/Simple_replace.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSimple_replace_Base::ResetReplace(void)
{
    m_Replace.erase();
    m_set_State[0] &= ~0x3;
}

void CSimple_replace_Base::Reset(void)
{
    ResetReplace();
    ResetWhole_string();
    ResetWeasel_to_putative();
}

BEGIN_NAMED_BASE_CLASS_INFO("Simple-replace", CSimple_replace)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_STD_MEMBER("replace", m_Replace)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("whole-string", m_Whole_string)->SetDefault(new TWhole_string(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("weasel-to-putative", m_Weasel_to_putative)->SetDefault(new TWeasel_to_putative(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSimple_replace_Base::CSimple_replace_Base(void)
    : m_Whole_string(false), m_Weasel_to_putative(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSimple_replace_Base::~CSimple_replace_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

