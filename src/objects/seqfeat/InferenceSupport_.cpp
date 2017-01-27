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
 *   'seqfeat.asn'.
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
#include <objects/seqfeat/InferenceSupport.hpp>
#include <objects/seqfeat/EvidenceBasis.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CInferenceSupport_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("InferenceSupport", "type");
    SET_ENUM_MODULE("NCBI-Seqfeat");
    ADD_ENUM_VALUE("not-set", eType_not_set);
    ADD_ENUM_VALUE("similar-to-sequence", eType_similar_to_sequence);
    ADD_ENUM_VALUE("similar-to-aa", eType_similar_to_aa);
    ADD_ENUM_VALUE("similar-to-dna", eType_similar_to_dna);
    ADD_ENUM_VALUE("similar-to-rna", eType_similar_to_rna);
    ADD_ENUM_VALUE("similar-to-mrna", eType_similar_to_mrna);
    ADD_ENUM_VALUE("similiar-to-est", eType_similiar_to_est);
    ADD_ENUM_VALUE("similar-to-other-rna", eType_similar_to_other_rna);
    ADD_ENUM_VALUE("profile", eType_profile);
    ADD_ENUM_VALUE("nucleotide-motif", eType_nucleotide_motif);
    ADD_ENUM_VALUE("protein-motif", eType_protein_motif);
    ADD_ENUM_VALUE("ab-initio-prediction", eType_ab_initio_prediction);
    ADD_ENUM_VALUE("alignment", eType_alignment);
    ADD_ENUM_VALUE("other", eType_other);
}
END_ENUM_INFO

void CInferenceSupport_Base::ResetOther_type(void)
{
    m_Other_type.erase();
    m_set_State[0] &= ~0x30;
}

void CInferenceSupport_Base::ResetBasis(void)
{
    if ( !m_Basis ) {
        m_Basis.Reset(new TBasis());
        return;
    }
    (*m_Basis).Reset();
}

void CInferenceSupport_Base::SetBasis(CInferenceSupport_Base::TBasis& value)
{
    m_Basis.Reset(&value);
}

void CInferenceSupport_Base::ResetPmids(void)
{
    m_Pmids.clear();
    m_set_State[0] &= ~0xc00;
}

void CInferenceSupport_Base::ResetDois(void)
{
    m_Dois.clear();
    m_set_State[0] &= ~0x3000;
}

void CInferenceSupport_Base::Reset(void)
{
    ResetCategory();
    ResetType();
    ResetOther_type();
    ResetSame_species();
    ResetBasis();
    ResetPmids();
    ResetDois();
}

BEGIN_NAMED_BASE_CLASS_INFO("InferenceSupport", CInferenceSupport)
{
    SET_CLASS_MODULE("NCBI-Seqfeat");
    ADD_NAMED_ENUM_MEMBER("category", m_Category, EEvidenceCategory)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetDefault(new TType(eType_not_set))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("other-type", m_Other_type)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("same-species", m_Same_species)->SetDefault(new TSame_species(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("basis", m_Basis, CEvidenceBasis);
    ADD_NAMED_MEMBER("pmids", m_Pmids, STL_list_set, (CLASS, (CPubMedId)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("dois", m_Dois, STL_list_set, (CLASS, (CDOI)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CInferenceSupport_Base::CInferenceSupport_Base(void)
    : m_Category((int)(0)), m_Type(eType_not_set), m_Same_species(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetBasis();
    }
}

// destructor
CInferenceSupport_Base::~CInferenceSupport_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

