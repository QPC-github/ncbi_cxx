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
#include <objects/blast/Blas_get_searc_resul_reply.hpp>
#include <objects/blast/Blast4_ka_block.hpp>
#include <objects/blast/Blast4_mask.hpp>
#include <objects/blast/Blast4_phi_alignments.hpp>
#include <objects/blast/Blast4_simple_results.hpp>
#include <objects/scoremat/PssmWithParameters.hpp>
#include <objects/seqalign/Seq_align_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_get_search_results_reply_Base::ResetAlignments(void)
{
    m_Alignments.Reset();
}

void CBlast4_get_search_results_reply_Base::SetAlignments(CBlast4_get_search_results_reply_Base::TAlignments& value)
{
    m_Alignments.Reset(&value);
}

CBlast4_get_search_results_reply_Base::TAlignments& CBlast4_get_search_results_reply_Base::SetAlignments(void)
{
    if ( !m_Alignments )
        m_Alignments.Reset(new ncbi::objects::CSeq_align_set());
    return (*m_Alignments);
}

void CBlast4_get_search_results_reply_Base::ResetPhi_alignments(void)
{
    m_Phi_alignments.Reset();
}

void CBlast4_get_search_results_reply_Base::SetPhi_alignments(CBlast4_get_search_results_reply_Base::TPhi_alignments& value)
{
    m_Phi_alignments.Reset(&value);
}

CBlast4_get_search_results_reply_Base::TPhi_alignments& CBlast4_get_search_results_reply_Base::SetPhi_alignments(void)
{
    if ( !m_Phi_alignments )
        m_Phi_alignments.Reset(new ncbi::objects::CBlast4_phi_alignments());
    return (*m_Phi_alignments);
}

void CBlast4_get_search_results_reply_Base::ResetMasks(void)
{
    m_Masks.clear();
    m_set_State[0] &= ~0x30;
}

void CBlast4_get_search_results_reply_Base::ResetKa_blocks(void)
{
    m_Ka_blocks.clear();
    m_set_State[0] &= ~0xc0;
}

void CBlast4_get_search_results_reply_Base::ResetSearch_stats(void)
{
    m_Search_stats.clear();
    m_set_State[0] &= ~0x300;
}

void CBlast4_get_search_results_reply_Base::ResetPssm(void)
{
    m_Pssm.Reset();
}

void CBlast4_get_search_results_reply_Base::SetPssm(CBlast4_get_search_results_reply_Base::TPssm& value)
{
    m_Pssm.Reset(&value);
}

CBlast4_get_search_results_reply_Base::TPssm& CBlast4_get_search_results_reply_Base::SetPssm(void)
{
    if ( !m_Pssm )
        m_Pssm.Reset(new ncbi::objects::CPssmWithParameters());
    return (*m_Pssm);
}

void CBlast4_get_search_results_reply_Base::ResetSimple_results(void)
{
    m_Simple_results.Reset();
}

void CBlast4_get_search_results_reply_Base::SetSimple_results(CBlast4_get_search_results_reply_Base::TSimple_results& value)
{
    m_Simple_results.Reset(&value);
}

CBlast4_get_search_results_reply_Base::TSimple_results& CBlast4_get_search_results_reply_Base::SetSimple_results(void)
{
    if ( !m_Simple_results )
        m_Simple_results.Reset(new ncbi::objects::CBlast4_simple_results());
    return (*m_Simple_results);
}

void CBlast4_get_search_results_reply_Base::Reset(void)
{
    ResetAlignments();
    ResetPhi_alignments();
    ResetMasks();
    ResetKa_blocks();
    ResetSearch_stats();
    ResetPssm();
    ResetSimple_results();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-get-search-results-reply", CBlast4_get_search_results_reply)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_REF_MEMBER("alignments", m_Alignments, CSeq_align_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("phi-alignments", m_Phi_alignments, CBlast4_phi_alignments)->SetOptional();
    ADD_NAMED_MEMBER("masks", m_Masks, STL_list, (STL_CRef, (CLASS, (CBlast4_mask))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("ka-blocks", m_Ka_blocks, STL_list, (STL_CRef, (CLASS, (CBlast4_ka_block))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("search-stats", m_Search_stats, STL_list, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("pssm", m_Pssm, CPssmWithParameters)->SetOptional();
    ADD_NAMED_REF_MEMBER("simple-results", m_Simple_results, CBlast4_simple_results)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CBlast4_get_search_results_reply_Base::CBlast4_get_search_results_reply_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CBlast4_get_search_results_reply_Base::~CBlast4_get_search_results_reply_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

