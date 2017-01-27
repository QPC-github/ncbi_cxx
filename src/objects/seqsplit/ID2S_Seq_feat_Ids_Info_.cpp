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
#include <objects/seqsplit/ID2S_Seq_feat_Ids_Info.hpp>
#include <objects/seqsplit/ID2S_Feat_type_Info.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2S_Seq_feat_Ids_Info_Base::ResetFeat_types(void)
{
    m_Feat_types.clear();
    m_set_State[0] &= ~0x3;
}

void CID2S_Seq_feat_Ids_Info_Base::ResetXref_types(void)
{
    m_Xref_types.clear();
    m_set_State[0] &= ~0xc;
}

void CID2S_Seq_feat_Ids_Info_Base::ResetLocal_ids(void)
{
    m_Local_ids.clear();
    m_set_State[0] &= ~0x30;
}

void CID2S_Seq_feat_Ids_Info_Base::ResetLocal_str_ids(void)
{
    m_Local_str_ids.clear();
    m_set_State[0] &= ~0xc0;
}

void CID2S_Seq_feat_Ids_Info_Base::Reset(void)
{
    ResetFeat_types();
    ResetXref_types();
    ResetLocal_ids();
    ResetLocal_str_ids();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2S-Seq-feat-Ids-Info", CID2S_Seq_feat_Ids_Info)
{
    SET_CLASS_MODULE("NCBI-Seq-split");
    ADD_NAMED_MEMBER("feat-types", m_Feat_types, STL_list_set, (STL_CRef, (CLASS, (CID2S_Feat_type_Info))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("xref-types", m_Xref_types, STL_list_set, (STL_CRef, (CLASS, (CID2S_Feat_type_Info))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("local-ids", m_Local_ids, STL_vector_set, (STD, (int)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("local-str-ids", m_Local_str_ids, STL_list_set, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CID2S_Seq_feat_Ids_Info_Base::CID2S_Seq_feat_Ids_Info_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CID2S_Seq_feat_Ids_Info_Base::~CID2S_Seq_feat_Ids_Info_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

