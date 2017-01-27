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
 *   'seqalign.asn'.
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
#include <objects/seqalign/Sparse_seg.hpp>
#include <objects/seqalign/Score.hpp>
#include <objects/seqalign/Sparse_align.hpp>
#include <objects/seqalign/Sparse_seg_ext.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSparse_seg_Base::ResetMaster_id(void)
{
    m_Master_id.Reset();
}

void CSparse_seg_Base::SetMaster_id(CSparse_seg_Base::TMaster_id& value)
{
    m_Master_id.Reset(&value);
}

CSparse_seg_Base::TMaster_id& CSparse_seg_Base::SetMaster_id(void)
{
    if ( !m_Master_id )
        m_Master_id.Reset(new ncbi::objects::CSeq_id());
    return (*m_Master_id);
}

void CSparse_seg_Base::ResetRows(void)
{
    m_Rows.clear();
    m_set_State[0] &= ~0xc;
}

void CSparse_seg_Base::ResetRow_scores(void)
{
    m_Row_scores.clear();
    m_set_State[0] &= ~0x30;
}

void CSparse_seg_Base::ResetExt(void)
{
    m_Ext.clear();
    m_set_State[0] &= ~0xc0;
}

void CSparse_seg_Base::Reset(void)
{
    ResetMaster_id();
    ResetRows();
    ResetRow_scores();
    ResetExt();
}

BEGIN_NAMED_BASE_CLASS_INFO("Sparse-seg", CSparse_seg)
{
    SET_CLASS_MODULE("NCBI-Seqalign");
    ADD_NAMED_REF_MEMBER("master-id", m_Master_id, CSeq_id)->SetOptional();
    ADD_NAMED_MEMBER("rows", m_Rows, STL_vector_set, (STL_CRef, (CLASS, (CSparse_align))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("row-scores", m_Row_scores, STL_vector_set, (STL_CRef, (CLASS, (CScore))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("ext", m_Ext, STL_vector_set, (STL_CRef, (CLASS, (CSparse_seg_ext))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSparse_seg_Base::CSparse_seg_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSparse_seg_Base::~CSparse_seg_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

