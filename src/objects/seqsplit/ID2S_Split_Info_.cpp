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
 *   'seqsplit.asn'.
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
#include <objects/seqsplit/ID2S_Split_Info.hpp>
#include <objects/seqset/Seq_entry.hpp>
#include <objects/seqsplit/ID2S_Bioseqs_Info.hpp>
#include <objects/seqsplit/ID2S_Chunk_Info.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2S_Split_Info_Base::ResetBioseqs_info(void)
{
    m_Bioseqs_info.clear();
    m_set_State[0] &= ~0x3;
}

void CID2S_Split_Info_Base::ResetChunks(void)
{
    m_Chunks.clear();
    m_set_State[0] &= ~0xc;
}

void CID2S_Split_Info_Base::ResetSkeleton(void)
{
    m_Skeleton.Reset();
}

void CID2S_Split_Info_Base::SetSkeleton(CID2S_Split_Info_Base::TSkeleton& value)
{
    m_Skeleton.Reset(&value);
}

CID2S_Split_Info_Base::TSkeleton& CID2S_Split_Info_Base::SetSkeleton(void)
{
    if ( !m_Skeleton )
        m_Skeleton.Reset(new ncbi::objects::CSeq_entry());
    return (*m_Skeleton);
}

void CID2S_Split_Info_Base::Reset(void)
{
    ResetBioseqs_info();
    ResetChunks();
    ResetSkeleton();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2S-Split-Info", CID2S_Split_Info)
{
    SET_CLASS_MODULE("NCBI-Seq-split");
    ADD_NAMED_MEMBER("bioseqs-info", m_Bioseqs_info, STL_list_set, (STL_CRef, (CLASS, (CID2S_Bioseqs_Info))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("chunks", m_Chunks, STL_list_set, (STL_CRef, (CLASS, (CID2S_Chunk_Info))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("skeleton", m_Skeleton, CSeq_entry)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CID2S_Split_Info_Base::CID2S_Split_Info_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CID2S_Split_Info_Base::~CID2S_Split_Info_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

