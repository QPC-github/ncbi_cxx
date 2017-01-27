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
#include <objects/seq/Seq_annot.hpp>
#include <objects/seq/Annot_descr.hpp>
#include <objects/seq/Annot_id.hpp>
#include <objects/seqalign/Seq_align.hpp>
#include <objects/seqfeat/Seq_feat.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seqloc/Seq_loc.hpp>
#include <objects/seqres/Seq_graph.hpp>
#include <objects/seqtable/Seq_table.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_annot_Base::, EDb, true)
{
    SET_ENUM_INTERNAL_NAME("Seq-annot", "db");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("genbank", eDb_genbank);
    ADD_ENUM_VALUE("embl", eDb_embl);
    ADD_ENUM_VALUE("ddbj", eDb_ddbj);
    ADD_ENUM_VALUE("pir", eDb_pir);
    ADD_ENUM_VALUE("sp", eDb_sp);
    ADD_ENUM_VALUE("bbone", eDb_bbone);
    ADD_ENUM_VALUE("pdb", eDb_pdb);
    ADD_ENUM_VALUE("other", eDb_other);
}
END_ENUM_INFO

void CSeq_annot_Base::C_Data::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CSeq_annot_Base::C_Data::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Ftable:
        m_Ftable.Destruct();
        break;
    case e_Align:
        m_Align.Destruct();
        break;
    case e_Graph:
        m_Graph.Destruct();
        break;
    case e_Ids:
        m_Ids.Destruct();
        break;
    case e_Locs:
        m_Locs.Destruct();
        break;
    case e_Seq_table:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CSeq_annot_Base::C_Data::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Ftable:
        m_Ftable.Construct();
        break;
    case e_Align:
        m_Align.Construct();
        break;
    case e_Graph:
        m_Graph.Construct();
        break;
    case e_Ids:
        m_Ids.Construct();
        break;
    case e_Locs:
        m_Locs.Construct();
        break;
    case e_Seq_table:
        (m_object = new(pool) ncbi::objects::CSeq_table())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CSeq_annot_Base::C_Data::sm_SelectionNames[] = {
    "not set",
    "ftable",
    "align",
    "graph",
    "ids",
    "locs",
    "seq-table"
};

NCBI_NS_STD::string CSeq_annot_Base::C_Data::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CSeq_annot_Base::C_Data::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CSeq_annot_Base::C_Data::TSeq_table& CSeq_annot_Base::C_Data::GetSeq_table(void) const
{
    CheckSelected(e_Seq_table);
    return *static_cast<const TSeq_table*>(m_object);
}

CSeq_annot_Base::C_Data::TSeq_table& CSeq_annot_Base::C_Data::SetSeq_table(void)
{
    Select(e_Seq_table, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSeq_table*>(m_object);
}

void CSeq_annot_Base::C_Data::SetSeq_table(CSeq_annot_Base::C_Data::TSeq_table& value)
{
    TSeq_table* ptr = &value;
    if ( m_choice != e_Seq_table || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Seq_table;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CSeq_annot_Base::C_Data)
{
    SET_INTERNAL_NAME("Seq-annot", "data");
    SET_CHOICE_MODULE("NCBI-Sequence");
    ADD_NAMED_BUF_CHOICE_VARIANT("ftable", m_Ftable, STL_list_set, (STL_CRef, (CLASS, (CSeq_feat))));
    ADD_NAMED_BUF_CHOICE_VARIANT("align", m_Align, STL_list_set, (STL_CRef, (CLASS, (CSeq_align))));
    ADD_NAMED_BUF_CHOICE_VARIANT("graph", m_Graph, STL_list_set, (STL_CRef, (CLASS, (CSeq_graph))));
    ADD_NAMED_BUF_CHOICE_VARIANT("ids", m_Ids, STL_list_set, (STL_CRef, (CLASS, (CSeq_id))));
    ADD_NAMED_BUF_CHOICE_VARIANT("locs", m_Locs, STL_list_set, (STL_CRef, (CLASS, (CSeq_loc))));
    ADD_NAMED_REF_CHOICE_VARIANT("seq-table", m_object, CSeq_table);
}
END_CHOICE_INFO

// constructor
CSeq_annot_Base::C_Data::C_Data(void)
    : m_choice(e_not_set)
{
}

// destructor
CSeq_annot_Base::C_Data::~C_Data(void)
{
    Reset();
}


void CSeq_annot_Base::ResetId(void)
{
    m_Id.clear();
    m_set_State[0] &= ~0x3;
}

void CSeq_annot_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0x30;
}

void CSeq_annot_Base::ResetDesc(void)
{
    m_Desc.Reset();
}

void CSeq_annot_Base::SetDesc(CSeq_annot_Base::TDesc& value)
{
    m_Desc.Reset(&value);
}

CSeq_annot_Base::TDesc& CSeq_annot_Base::SetDesc(void)
{
    if ( !m_Desc )
        m_Desc.Reset(new ncbi::objects::CAnnot_descr());
    return (*m_Desc);
}

void CSeq_annot_Base::ResetData(void)
{
    if ( !m_Data ) {
        m_Data.Reset(new TData());
        return;
    }
    (*m_Data).Reset();
}

void CSeq_annot_Base::SetData(CSeq_annot_Base::TData& value)
{
    m_Data.Reset(&value);
}

void CSeq_annot_Base::Reset(void)
{
    ResetId();
    ResetDb();
    ResetName();
    ResetDesc();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-annot", CSeq_annot)
{
    SET_CLASS_MODULE("NCBI-Sequence");
    ADD_NAMED_MEMBER("id", m_Id, STL_list_set, (STL_CRef, (CLASS, (CAnnot_id))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("db", m_Db, EDb)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("desc", m_Desc, CAnnot_descr)->SetOptional();
    ADD_NAMED_REF_MEMBER("data", m_Data, C_Data);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSeq_annot_Base::CSeq_annot_Base(void)
    : m_Db((EDb)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetData();
    }
}

// destructor
CSeq_annot_Base::~CSeq_annot_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

