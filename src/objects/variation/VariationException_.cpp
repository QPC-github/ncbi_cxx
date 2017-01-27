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
#include <objects/variation/VariationException.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CVariationException_Base::, ECode, true)
{
    SET_ENUM_INTERNAL_NAME("VariationException", "code");
    SET_ENUM_MODULE("NCBI-VariationPackage");
    ADD_ENUM_VALUE("hgvs-parsing", eCode_hgvs_parsing);
    ADD_ENUM_VALUE("hgvs-exon-boundary", eCode_hgvs_exon_boundary);
    ADD_ENUM_VALUE("inconsistent-consequence", eCode_inconsistent_consequence);
    ADD_ENUM_VALUE("inconsistent-asserted-allele", eCode_inconsistent_asserted_allele);
    ADD_ENUM_VALUE("no-mapping", eCode_no_mapping);
    ADD_ENUM_VALUE("partial-mapping", eCode_partial_mapping);
    ADD_ENUM_VALUE("split-mapping", eCode_split_mapping);
    ADD_ENUM_VALUE("mismatches-in-mapping", eCode_mismatches_in_mapping);
    ADD_ENUM_VALUE("inconsistent-asserted-moltype", eCode_inconsistent_asserted_moltype);
    ADD_ENUM_VALUE("bioseq-state", eCode_bioseq_state);
    ADD_ENUM_VALUE("ambiguous-sequence", eCode_ambiguous_sequence);
    ADD_ENUM_VALUE("ref-same-as-variant", eCode_ref_same_as_variant);
    ADD_ENUM_VALUE("seqfetch-too-long", eCode_seqfetch_too_long);
    ADD_ENUM_VALUE("seqfetch-intronic", eCode_seqfetch_intronic);
    ADD_ENUM_VALUE("seqfetch-invalid", eCode_seqfetch_invalid);
}
END_ENUM_INFO

void CVariationException_Base::ResetMessage(void)
{
    m_Message.erase();
    m_set_State[0] &= ~0xc;
}

void CVariationException_Base::Reset(void)
{
    ResetCode();
    ResetMessage();
}

BEGIN_NAMED_BASE_CLASS_INFO("VariationException", CVariationException)
{
    SET_CLASS_MODULE("NCBI-VariationPackage");
    ADD_NAMED_ENUM_MEMBER("code", m_Code, ECode)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("message", m_Message)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CVariationException_Base::CVariationException_Base(void)
    : m_Code((ECode)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CVariationException_Base::~CVariationException_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

