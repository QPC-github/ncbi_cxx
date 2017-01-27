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
 *   'macro.asn'.
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
#include <objects/macro/Apply_feature_action.hpp>
#include <objects/macro/Feat_qual_legal_set.hpp>
#include <objects/macro/Location_choice.hpp>
#include <objects/macro/Sequence_list_choice.hpp>
#include <objects/macro/Source_qual_val_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CApply_feature_action_Base::ResetLocation(void)
{
    if ( !m_Location ) {
        m_Location.Reset(new TLocation());
        return;
    }
    (*m_Location).Reset();
}

void CApply_feature_action_Base::SetLocation(CApply_feature_action_Base::TLocation& value)
{
    m_Location.Reset(&value);
}

void CApply_feature_action_Base::ResetSeq_list(void)
{
    if ( !m_Seq_list ) {
        m_Seq_list.Reset(new TSeq_list());
        return;
    }
    (*m_Seq_list).Reset();
}

void CApply_feature_action_Base::SetSeq_list(CApply_feature_action_Base::TSeq_list& value)
{
    m_Seq_list.Reset(&value);
}

void CApply_feature_action_Base::ResetFields(void)
{
    m_Fields.Reset();
}

void CApply_feature_action_Base::SetFields(CApply_feature_action_Base::TFields& value)
{
    m_Fields.Reset(&value);
}

CApply_feature_action_Base::TFields& CApply_feature_action_Base::SetFields(void)
{
    if ( !m_Fields )
        m_Fields.Reset(new ncbi::objects::CFeat_qual_legal_set());
    return (*m_Fields);
}

void CApply_feature_action_Base::ResetSrc_fields(void)
{
    m_Src_fields.Reset();
}

void CApply_feature_action_Base::SetSrc_fields(CApply_feature_action_Base::TSrc_fields& value)
{
    m_Src_fields.Reset(&value);
}

CApply_feature_action_Base::TSrc_fields& CApply_feature_action_Base::SetSrc_fields(void)
{
    if ( !m_Src_fields )
        m_Src_fields.Reset(new ncbi::objects::CSource_qual_val_set());
    return (*m_Src_fields);
}

void CApply_feature_action_Base::Reset(void)
{
    ResetType();
    ResetPartial5();
    ResetPartial3();
    ResetPlus_strand();
    ResetLocation();
    ResetSeq_list();
    ResetAdd_redundant();
    ResetAdd_mrna();
    ResetApply_to_parts();
    ResetOnly_seg_num();
    ResetFields();
    ResetSrc_fields();
}

BEGIN_NAMED_BASE_CLASS_INFO("Apply-feature-action", CApply_feature_action)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EMacro_feature_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("partial5", m_Partial5)->SetDefault(new TPartial5(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("partial3", m_Partial3)->SetDefault(new TPartial3(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("plus-strand", m_Plus_strand)->SetDefault(new TPlus_strand(true))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("location", m_Location, CLocation_choice);
    ADD_NAMED_REF_MEMBER("seq-list", m_Seq_list, CSequence_list_choice);
    ADD_NAMED_STD_MEMBER("add-redundant", m_Add_redundant)->SetDefault(new TAdd_redundant(true))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("add-mrna", m_Add_mrna)->SetDefault(new TAdd_mrna(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("apply-to-parts", m_Apply_to_parts)->SetDefault(new TApply_to_parts(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("only-seg-num", m_Only_seg_num)->SetDefault(new TOnly_seg_num(-1))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("fields", m_Fields, CFeat_qual_legal_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("src-fields", m_Src_fields, CSource_qual_val_set)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CApply_feature_action_Base::CApply_feature_action_Base(void)
    : m_Type((ncbi::objects::EMacro_feature_type)(0)), m_Partial5(false), m_Partial3(false), m_Plus_strand(true), m_Add_redundant(true), m_Add_mrna(false), m_Apply_to_parts(false), m_Only_seg_num(-1)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetLocation();
        ResetSeq_list();
    }
}

// destructor
CApply_feature_action_Base::~CApply_feature_action_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

