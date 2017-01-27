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
#include <objects/seqsplit/ID2S_Chunk_Data.hpp>
#include <objects/seq/Bioseq.hpp>
#include <objects/seq/Seq_annot.hpp>
#include <objects/seq/Seq_descr.hpp>
#include <objects/seqalign/Seq_align.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seqsplit/ID2S_Sequence_Piece.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2S_Chunk_Data_Base::C_Id::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CID2S_Chunk_Data_Base::C_Id::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Seq_id:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CID2S_Chunk_Data_Base::C_Id::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Bioseq_set:
        m_Bioseq_set = 0;
        break;
    case e_Gi:
        m_Gi = 0;
        break;
    case e_Seq_id:
        (m_object = new(pool) ncbi::objects::CSeq_id())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CID2S_Chunk_Data_Base::C_Id::sm_SelectionNames[] = {
    "not set",
    "bioseq-set",
    "gi",
    "seq-id"
};

NCBI_NS_STD::string CID2S_Chunk_Data_Base::C_Id::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CID2S_Chunk_Data_Base::C_Id::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CID2S_Chunk_Data_Base::C_Id::TSeq_id& CID2S_Chunk_Data_Base::C_Id::GetSeq_id(void) const
{
    CheckSelected(e_Seq_id);
    return *static_cast<const TSeq_id*>(m_object);
}

CID2S_Chunk_Data_Base::C_Id::TSeq_id& CID2S_Chunk_Data_Base::C_Id::SetSeq_id(void)
{
    Select(e_Seq_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSeq_id*>(m_object);
}

void CID2S_Chunk_Data_Base::C_Id::SetSeq_id(CID2S_Chunk_Data_Base::C_Id::TSeq_id& value)
{
    TSeq_id* ptr = &value;
    if ( m_choice != e_Seq_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Seq_id;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CID2S_Chunk_Data_Base::C_Id)
{
    SET_INTERNAL_NAME("ID2S-Chunk-Data", "id");
    SET_CHOICE_MODULE("NCBI-Seq-split");
    ADD_NAMED_STD_CHOICE_VARIANT("bioseq-set", m_Bioseq_set);
    ADD_NAMED_STD_CHOICE_VARIANT("gi", m_Gi);
    ADD_NAMED_REF_CHOICE_VARIANT("seq-id", m_object, CSeq_id);
}
END_CHOICE_INFO

// constructor
CID2S_Chunk_Data_Base::C_Id::C_Id(void)
    : m_choice(e_not_set)
{
}

// destructor
CID2S_Chunk_Data_Base::C_Id::~C_Id(void)
{
    Reset();
}


void CID2S_Chunk_Data_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CID2S_Chunk_Data_Base::SetId(CID2S_Chunk_Data_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CID2S_Chunk_Data_Base::ResetDescr(void)
{
    m_Descr.Reset();
}

void CID2S_Chunk_Data_Base::SetDescr(CID2S_Chunk_Data_Base::TDescr& value)
{
    m_Descr.Reset(&value);
}

CID2S_Chunk_Data_Base::TDescr& CID2S_Chunk_Data_Base::SetDescr(void)
{
    if ( !m_Descr )
        m_Descr.Reset(new ncbi::objects::CSeq_descr());
    return (*m_Descr);
}

void CID2S_Chunk_Data_Base::ResetAnnots(void)
{
    m_Annots.clear();
    m_set_State[0] &= ~0x30;
}

void CID2S_Chunk_Data_Base::ResetAssembly(void)
{
    m_Assembly.clear();
    m_set_State[0] &= ~0xc0;
}

void CID2S_Chunk_Data_Base::ResetSeq_map(void)
{
    m_Seq_map.clear();
    m_set_State[0] &= ~0x300;
}

void CID2S_Chunk_Data_Base::ResetSeq_data(void)
{
    m_Seq_data.clear();
    m_set_State[0] &= ~0xc00;
}

void CID2S_Chunk_Data_Base::ResetBioseqs(void)
{
    m_Bioseqs.clear();
    m_set_State[0] &= ~0x3000;
}

void CID2S_Chunk_Data_Base::Reset(void)
{
    ResetId();
    ResetDescr();
    ResetAnnots();
    ResetAssembly();
    ResetSeq_map();
    ResetSeq_data();
    ResetBioseqs();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2S-Chunk-Data", CID2S_Chunk_Data)
{
    SET_CLASS_MODULE("NCBI-Seq-split");
    ADD_NAMED_REF_MEMBER("id", m_Id, C_Id);
    ADD_NAMED_REF_MEMBER("descr", m_Descr, CSeq_descr)->SetOptional();
    ADD_NAMED_MEMBER("annots", m_Annots, STL_list_set, (STL_CRef, (CLASS, (CSeq_annot))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("assembly", m_Assembly, STL_list_set, (STL_CRef, (CLASS, (CSeq_align))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("seq-map", m_Seq_map, STL_list, (STL_CRef, (CLASS, (CID2S_Sequence_Piece))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("seq-data", m_Seq_data, STL_list, (STL_CRef, (CLASS, (CID2S_Sequence_Piece))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("bioseqs", m_Bioseqs, STL_list_set, (STL_CRef, (CLASS, (CBioseq))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CID2S_Chunk_Data_Base::CID2S_Chunk_Data_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
    }
}

// destructor
CID2S_Chunk_Data_Base::~CID2S_Chunk_Data_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
