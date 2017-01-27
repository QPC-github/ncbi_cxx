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
 *   'variation.asn'.
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
#include <objects/variation/VariationMethod.hpp>
#include <objects/seqloc/Seq_loc.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CVariationMethod_Base::, EMethod_E, true)
{
    SET_ENUM_INTERNAL_NAME("VariationMethod.method", "E");
    SET_ENUM_MODULE("NCBI-VariationPackage");
    ADD_ENUM_VALUE("unknown", eMethod_E_unknown);
    ADD_ENUM_VALUE("bac-acgh", eMethod_E_bac_acgh);
    ADD_ENUM_VALUE("computational", eMethod_E_computational);
    ADD_ENUM_VALUE("curated", eMethod_E_curated);
    ADD_ENUM_VALUE("digital-array", eMethod_E_digital_array);
    ADD_ENUM_VALUE("expression-array", eMethod_E_expression_array);
    ADD_ENUM_VALUE("fish", eMethod_E_fish);
    ADD_ENUM_VALUE("flanking-sequence", eMethod_E_flanking_sequence);
    ADD_ENUM_VALUE("maph", eMethod_E_maph);
    ADD_ENUM_VALUE("mcd-analysis", eMethod_E_mcd_analysis);
    ADD_ENUM_VALUE("mlpa", eMethod_E_mlpa);
    ADD_ENUM_VALUE("oea-assembly", eMethod_E_oea_assembly);
    ADD_ENUM_VALUE("oligo-acgh", eMethod_E_oligo_acgh);
    ADD_ENUM_VALUE("paired-end", eMethod_E_paired_end);
    ADD_ENUM_VALUE("pcr", eMethod_E_pcr);
    ADD_ENUM_VALUE("qpcr", eMethod_E_qpcr);
    ADD_ENUM_VALUE("read-depth", eMethod_E_read_depth);
    ADD_ENUM_VALUE("roma", eMethod_E_roma);
    ADD_ENUM_VALUE("rt-pcr", eMethod_E_rt_pcr);
    ADD_ENUM_VALUE("sage", eMethod_E_sage);
    ADD_ENUM_VALUE("sequence-alignment", eMethod_E_sequence_alignment);
    ADD_ENUM_VALUE("sequencing", eMethod_E_sequencing);
    ADD_ENUM_VALUE("snp-array", eMethod_E_snp_array);
    ADD_ENUM_VALUE("snp-genoytyping", eMethod_E_snp_genoytyping);
    ADD_ENUM_VALUE("southern", eMethod_E_southern);
    ADD_ENUM_VALUE("western", eMethod_E_western);
    ADD_ENUM_VALUE("optical-mapping", eMethod_E_optical_mapping);
    ADD_ENUM_VALUE("other", eMethod_E_other);
}
END_ENUM_INFO

void CVariationMethod_Base::ResetMethod(void)
{
    m_Method.clear();
    m_set_State[0] &= ~0x3;
}

void CVariationMethod_Base::ResetReference_location(void)
{
    m_Reference_location.Reset();
}

void CVariationMethod_Base::SetReference_location(CVariationMethod_Base::TReference_location& value)
{
    m_Reference_location.Reset(&value);
}

CVariationMethod_Base::TReference_location& CVariationMethod_Base::SetReference_location(void)
{
    if ( !m_Reference_location )
        m_Reference_location.Reset(new ncbi::objects::CSeq_loc());
    return (*m_Reference_location);
}

void CVariationMethod_Base::Reset(void)
{
    ResetMethod();
    ResetReference_location();
}

BEGIN_NAMED_BASE_CLASS_INFO("VariationMethod", CVariationMethod)
{
    SET_CLASS_MODULE("NCBI-VariationPackage");
    ADD_NAMED_MEMBER("method", m_Method, STL_list_set, (ENUM, (int, EMethod_E)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("reference-location", m_Reference_location, CSeq_loc)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CVariationMethod_Base::CVariationMethod_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CVariationMethod_Base::~CVariationMethod_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

