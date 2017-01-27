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
 *   'biblio.asn'.
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
#include <objects/biblio/Cit_book.hpp>
#include <objects/biblio/Auth_list.hpp>
#include <objects/biblio/Imprint.hpp>
#include <objects/biblio/Title.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCit_book_Base::ResetTitle(void)
{
    if ( !m_Title ) {
        m_Title.Reset(new TTitle());
        return;
    }
    (*m_Title).Reset();
}

void CCit_book_Base::SetTitle(CCit_book_Base::TTitle& value)
{
    m_Title.Reset(&value);
}

void CCit_book_Base::ResetColl(void)
{
    m_Coll.Reset();
}

void CCit_book_Base::SetColl(CCit_book_Base::TColl& value)
{
    m_Coll.Reset(&value);
}

CCit_book_Base::TColl& CCit_book_Base::SetColl(void)
{
    if ( !m_Coll )
        m_Coll.Reset(new ncbi::objects::CTitle());
    return (*m_Coll);
}

void CCit_book_Base::ResetAuthors(void)
{
    if ( !m_Authors ) {
        m_Authors.Reset(new TAuthors());
        return;
    }
    (*m_Authors).Reset();
}

void CCit_book_Base::SetAuthors(CCit_book_Base::TAuthors& value)
{
    m_Authors.Reset(&value);
}

void CCit_book_Base::ResetImp(void)
{
    if ( !m_Imp ) {
        m_Imp.Reset(new TImp());
        return;
    }
    (*m_Imp).Reset();
}

void CCit_book_Base::SetImp(CCit_book_Base::TImp& value)
{
    m_Imp.Reset(&value);
}

void CCit_book_Base::Reset(void)
{
    ResetTitle();
    ResetColl();
    ResetAuthors();
    ResetImp();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cit-book", CCit_book)
{
    SET_CLASS_MODULE("NCBI-Biblio");
    ADD_NAMED_REF_MEMBER("title", m_Title, CTitle);
    ADD_NAMED_REF_MEMBER("coll", m_Coll, CTitle)->SetOptional();
    ADD_NAMED_REF_MEMBER("authors", m_Authors, CAuth_list);
    ADD_NAMED_REF_MEMBER("imp", m_Imp, CImprint);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CCit_book_Base::CCit_book_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetTitle();
        ResetAuthors();
        ResetImp();
    }
}

// destructor
CCit_book_Base::~CCit_book_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

