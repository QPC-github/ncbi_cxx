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
#include <objects/seqfeat/Phenotype.hpp>
#include <objects/general/Dbtag.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CPhenotype_Base::, EClinical_significance, true)
{
    SET_ENUM_INTERNAL_NAME("Phenotype", "clinical-significance");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("unknown", eClinical_significance_unknown);
    ADD_ENUM_VALUE("untested", eClinical_significance_untested);
    ADD_ENUM_VALUE("non-pathogenic", eClinical_significance_non_pathogenic);
    ADD_ENUM_VALUE("probable-non-pathogenic", eClinical_significance_probable_non_pathogenic);
    ADD_ENUM_VALUE("probable-pathogenic", eClinical_significance_probable_pathogenic);
    ADD_ENUM_VALUE("pathogenic", eClinical_significance_pathogenic);
    ADD_ENUM_VALUE("drug-response", eClinical_significance_drug_response);
    ADD_ENUM_VALUE("histocompatibility", eClinical_significance_histocompatibility);
    ADD_ENUM_VALUE("other", eClinical_significance_other);
}
END_ENUM_INFO

void CPhenotype_Base::ResetSource(void)
{
    m_Source.erase();
    m_set_State[0] &= ~0x3;
}

void CPhenotype_Base::ResetTerm(void)
{
    m_Term.erase();
    m_set_State[0] &= ~0xc;
}

void CPhenotype_Base::ResetXref(void)
{
    m_Xref.clear();
    m_set_State[0] &= ~0x30;
}

void CPhenotype_Base::Reset(void)
{
    ResetSource();
    ResetTerm();
    ResetXref();
    ResetClinical_significance();
}

BEGIN_NAMED_BASE_CLASS_INFO("Phenotype", CPhenotype)
{
    SET_CLASS_MODULE("NCBI-Variation");
    ADD_NAMED_STD_MEMBER("source", m_Source)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("term", m_Term)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("xref", m_Xref, STL_list_set, (STL_CRef, (CLASS, (CDbtag))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("clinical-significance", m_Clinical_significance, EClinical_significance)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPhenotype_Base::CPhenotype_Base(void)
    : m_Clinical_significance((EClinical_significance)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPhenotype_Base::~CPhenotype_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

