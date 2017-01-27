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
 *   'seqloc.asn'.
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
#include <objects/seqloc/Seq_point.hpp>
#include <objects/general/Int_fuzz.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSeq_point_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CSeq_point_Base::SetId(CSeq_point_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CSeq_point_Base::ResetFuzz(void)
{
    m_Fuzz.Reset();
}

void CSeq_point_Base::SetFuzz(CSeq_point_Base::TFuzz& value)
{
    m_Fuzz.Reset(&value);
}

CSeq_point_Base::TFuzz& CSeq_point_Base::SetFuzz(void)
{
    if ( !m_Fuzz )
        m_Fuzz.Reset(new ncbi::objects::CInt_fuzz());
    return (*m_Fuzz);
}

void CSeq_point_Base::Reset(void)
{
    ResetPoint();
    ResetStrand();
    ResetId();
    ResetFuzz();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-point", CSeq_point)
{
    SET_CLASS_MODULE("NCBI-Seqloc");
    ADD_NAMED_STD_MEMBER("point", m_Point)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("strand", m_Strand, ENa_strand)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("id", m_Id, CSeq_id);
    ADD_NAMED_REF_MEMBER("fuzz", m_Fuzz, CInt_fuzz)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSeq_point_Base::CSeq_point_Base(void)
    : m_Point(0), m_Strand((ncbi::objects::ENa_strand)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
    }
}

// destructor
CSeq_point_Base::~CSeq_point_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

