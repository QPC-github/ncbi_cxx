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
 *   'espell.dtd'.
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
#include <objtools/eutils/espell/ESpellResult.hpp>
#include <objtools/eutils/espell/SpelledQuery.hpp>
BEGIN_espell_SCOPE // namespace espell::


// generated classes

void CESpellResult_Base::ResetDatabase(void)
{
    m_Database.erase();
    m_set_State[0] &= ~0x3;
}

void CESpellResult_Base::ResetQuery(void)
{
    m_Query.erase();
    m_set_State[0] &= ~0xc;
}

void CESpellResult_Base::ResetCorrectedQuery(void)
{
    m_CorrectedQuery.erase();
    m_set_State[0] &= ~0x30;
}

void CESpellResult_Base::ResetSpelledQuery(void)
{
    if ( !m_SpelledQuery ) {
        m_SpelledQuery.Reset(new TSpelledQuery());
        return;
    }
    (*m_SpelledQuery).Reset();
}

void CESpellResult_Base::SetSpelledQuery(CESpellResult_Base::TSpelledQuery& value)
{
    m_SpelledQuery.Reset(&value);
}

void CESpellResult_Base::ResetERROR(void)
{
    m_ERROR.erase();
    m_set_State[0] &= ~0x300;
}

void CESpellResult_Base::Reset(void)
{
    ResetDatabase();
    ResetQuery();
    ResetCorrectedQuery();
    ResetSpelledQuery();
    ResetERROR();
}

BEGIN_NAMED_BASE_CLASS_INFO("eSpellResult", CESpellResult)
{
    SET_CLASS_MODULE("espell");
    ADD_NAMED_STD_MEMBER("Database", m_Database)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("Query", m_Query)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("CorrectedQuery", m_CorrectedQuery)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_REF_MEMBER("SpelledQuery", m_SpelledQuery, CSpelledQuery)->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("ERROR", m_ERROR)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CESpellResult_Base::CESpellResult_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSpelledQuery();
    }
}

// destructor
CESpellResult_Base::~CESpellResult_Base(void)
{
}



END_espell_SCOPE // namespace espell::
