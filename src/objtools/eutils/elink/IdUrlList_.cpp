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
 *   'elink.dtd'.
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
#include <objtools/eutils/elink/IdUrlList.hpp>
#include <objtools/eutils/elink/FirstChars.hpp>
#include <objtools/eutils/elink/IdUrlSet.hpp>
BEGIN_elink_SCOPE // namespace elink::


// generated classes

void CIdUrlList_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CIdUrlList_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_IdUrlSet:
        m_IdUrlSet.Destruct();
        break;
    case e_FirstChars:
        m_FirstChars.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CIdUrlList_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_IdUrlSet:
        m_IdUrlSet.Construct();
        break;
    case e_FirstChars:
        m_FirstChars.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CIdUrlList_Base::sm_SelectionNames[] = {
    "not set",
    "IdUrlSet",
    "FirstChars"
};

NCBI_NS_STD::string CIdUrlList_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CIdUrlList_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("IdUrlList", CIdUrlList)
{
    SET_CHOICE_MODULE("elink");
    ADD_NAMED_BUF_CHOICE_VARIANT("IdUrlSet", m_IdUrlSet, STL_list, (STL_CRef, (CLASS, (CIdUrlSet))))->SetNoPrefix();
    ADD_NAMED_BUF_CHOICE_VARIANT("FirstChars", m_FirstChars, STL_list, (STL_CRef, (CLASS, (CFirstChars))))->SetNoPrefix();
}
END_CHOICE_INFO

// constructor
CIdUrlList_Base::CIdUrlList_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CIdUrlList_Base::~CIdUrlList_Base(void)
{
    Reset();
}



END_elink_SCOPE // namespace elink::

