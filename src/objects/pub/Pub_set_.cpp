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
 *   'pub.asn'.
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
#include <objects/pub/Pub_set.hpp>
#include <objects/biblio/Cit_art.hpp>
#include <objects/biblio/Cit_book.hpp>
#include <objects/biblio/Cit_jour.hpp>
#include <objects/biblio/Cit_pat.hpp>
#include <objects/biblio/Cit_proc.hpp>
#include <objects/medline/Medline_entry.hpp>
#include <objects/pub/Pub.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPub_set_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CPub_set_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Pub:
        m_Pub.Destruct();
        break;
    case e_Medline:
        m_Medline.Destruct();
        break;
    case e_Article:
        m_Article.Destruct();
        break;
    case e_Journal:
        m_Journal.Destruct();
        break;
    case e_Book:
        m_Book.Destruct();
        break;
    case e_Proc:
        m_Proc.Destruct();
        break;
    case e_Patent:
        m_Patent.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CPub_set_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Pub:
        m_Pub.Construct();
        break;
    case e_Medline:
        m_Medline.Construct();
        break;
    case e_Article:
        m_Article.Construct();
        break;
    case e_Journal:
        m_Journal.Construct();
        break;
    case e_Book:
        m_Book.Construct();
        break;
    case e_Proc:
        m_Proc.Construct();
        break;
    case e_Patent:
        m_Patent.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CPub_set_Base::sm_SelectionNames[] = {
    "not set",
    "pub",
    "medline",
    "article",
    "journal",
    "book",
    "proc",
    "patent"
};

NCBI_NS_STD::string CPub_set_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CPub_set_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Pub-set", CPub_set)
{
    SET_CHOICE_MODULE("NCBI-Pub");
    ADD_NAMED_BUF_CHOICE_VARIANT("pub", m_Pub, STL_list_set, (STL_CRef, (CLASS, (CPub))));
    ADD_NAMED_BUF_CHOICE_VARIANT("medline", m_Medline, STL_list_set, (STL_CRef, (CLASS, (CMedline_entry))));
    ADD_NAMED_BUF_CHOICE_VARIANT("article", m_Article, STL_list_set, (STL_CRef, (CLASS, (CCit_art))));
    ADD_NAMED_BUF_CHOICE_VARIANT("journal", m_Journal, STL_list_set, (STL_CRef, (CLASS, (CCit_jour))));
    ADD_NAMED_BUF_CHOICE_VARIANT("book", m_Book, STL_list_set, (STL_CRef, (CLASS, (CCit_book))));
    ADD_NAMED_BUF_CHOICE_VARIANT("proc", m_Proc, STL_list_set, (STL_CRef, (CLASS, (CCit_proc))));
    ADD_NAMED_BUF_CHOICE_VARIANT("patent", m_Patent, STL_list_set, (STL_CRef, (CLASS, (CCit_pat))));
}
END_CHOICE_INFO

// constructor
CPub_set_Base::CPub_set_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CPub_set_Base::~CPub_set_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

