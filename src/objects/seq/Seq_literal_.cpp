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
 *   'seq.asn'.
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
#include <objects/seq/Seq_literal.hpp>
#include <objects/general/Int_fuzz.hpp>
#include <objects/seq/Seq_data.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSeq_literal_Base::ResetFuzz(void)
{
    m_Fuzz.Reset();
}

void CSeq_literal_Base::SetFuzz(CSeq_literal_Base::TFuzz& value)
{
    m_Fuzz.Reset(&value);
}

CSeq_literal_Base::TFuzz& CSeq_literal_Base::SetFuzz(void)
{
    if ( !m_Fuzz )
        m_Fuzz.Reset(new ncbi::objects::CInt_fuzz());
    return (*m_Fuzz);
}

void CSeq_literal_Base::ResetSeq_data(void)
{
    m_Seq_data.Reset();
}

void CSeq_literal_Base::SetSeq_data(CSeq_literal_Base::TSeq_data& value)
{
    m_Seq_data.Reset(&value);
}

CSeq_literal_Base::TSeq_data& CSeq_literal_Base::SetSeq_data(void)
{
    if ( !m_Seq_data )
        m_Seq_data.Reset(new ncbi::objects::CSeq_data());
    return (*m_Seq_data);
}

void CSeq_literal_Base::Reset(void)
{
    ResetLength();
    ResetFuzz();
    ResetSeq_data();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-literal", CSeq_literal)
{
    SET_CLASS_MODULE("NCBI-Sequence");
    ADD_NAMED_STD_MEMBER("length", m_Length)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("fuzz", m_Fuzz, CInt_fuzz)->SetOptional();
    ADD_NAMED_REF_MEMBER("seq-data", m_Seq_data, CSeq_data)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSeq_literal_Base::CSeq_literal_Base(void)
    : m_Length(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSeq_literal_Base::~CSeq_literal_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

