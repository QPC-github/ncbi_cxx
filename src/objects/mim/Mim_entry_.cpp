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
 *   'mim.asn'.
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
#include <objects/mim/Mim_entry.hpp>
#include <objects/mim/Mim_allelic_variant.hpp>
#include <objects/mim/Mim_cit.hpp>
#include <objects/mim/Mim_edit_item.hpp>
#include <objects/mim/Mim_index_term.hpp>
#include <objects/mim/Mim_link.hpp>
#include <objects/mim/Mim_reference.hpp>
#include <objects/mim/Mim_text.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CMim_entry_Base::, EMimType, true)
{
    SET_ENUM_INTERNAL_NAME("Mim-entry", "mimType");
    SET_ENUM_MODULE("NCBI-Mim");
    ADD_ENUM_VALUE("none", eMimType_none);
    ADD_ENUM_VALUE("star", eMimType_star);
    ADD_ENUM_VALUE("caret", eMimType_caret);
    ADD_ENUM_VALUE("pound", eMimType_pound);
    ADD_ENUM_VALUE("plus", eMimType_plus);
    ADD_ENUM_VALUE("perc", eMimType_perc);
}
END_ENUM_INFO

void CMim_entry_Base::ResetMimNumber(void)
{
    m_MimNumber.erase();
    m_set_State[0] &= ~0x3;
}

void CMim_entry_Base::ResetTitle(void)
{
    m_Title.erase();
    m_set_State[0] &= ~0x30;
}

void CMim_entry_Base::ResetCopyright(void)
{
    m_Copyright.erase();
    m_set_State[0] &= ~0xc0;
}

void CMim_entry_Base::ResetSymbol(void)
{
    m_Symbol.erase();
    m_set_State[0] &= ~0x300;
}

void CMim_entry_Base::ResetLocus(void)
{
    m_Locus.erase();
    m_set_State[0] &= ~0xc00;
}

void CMim_entry_Base::ResetSynonyms(void)
{
    m_Synonyms.clear();
    m_set_State[0] &= ~0x3000;
}

void CMim_entry_Base::ResetAliases(void)
{
    m_Aliases.clear();
    m_set_State[0] &= ~0xc000;
}

void CMim_entry_Base::ResetIncluded(void)
{
    m_Included.clear();
    m_set_State[0] &= ~0x30000;
}

void CMim_entry_Base::ResetSeeAlso(void)
{
    m_SeeAlso.clear();
    m_set_State[0] &= ~0xc0000;
}

void CMim_entry_Base::ResetText(void)
{
    m_Text.clear();
    m_set_State[0] &= ~0x300000;
}

void CMim_entry_Base::ResetTextfields(void)
{
    m_Textfields.clear();
    m_set_State[0] &= ~0xc00000;
}

void CMim_entry_Base::ResetSummary(void)
{
    m_Summary.clear();
    m_set_State[0] &= ~0xc000000;
}

void CMim_entry_Base::ResetSummaryAttribution(void)
{
    m_SummaryAttribution.clear();
    m_set_State[0] &= ~0x30000000;
}

void CMim_entry_Base::ResetSummaryEditHistory(void)
{
    m_SummaryEditHistory.clear();
    m_set_State[0] &= ~0xc0000000;
}

void CMim_entry_Base::ResetSummaryCreationDate(void)
{
    m_SummaryCreationDate.Reset();
}

void CMim_entry_Base::SetSummaryCreationDate(CMim_entry_Base::TSummaryCreationDate& value)
{
    m_SummaryCreationDate.Reset(&value);
}

CMim_entry_Base::TSummaryCreationDate& CMim_entry_Base::SetSummaryCreationDate(void)
{
    if ( !m_SummaryCreationDate )
        m_SummaryCreationDate.Reset(new ncbi::objects::CMim_edit_item());
    return (*m_SummaryCreationDate);
}

void CMim_entry_Base::ResetAllelicVariants(void)
{
    m_AllelicVariants.clear();
    m_set_State[1] &= ~0xc;
}

void CMim_entry_Base::ResetClinicalSynopsis(void)
{
    m_ClinicalSynopsis.clear();
    m_set_State[1] &= ~0xc0;
}

void CMim_entry_Base::ResetSynopsisAttribution(void)
{
    m_SynopsisAttribution.clear();
    m_set_State[1] &= ~0x300;
}

void CMim_entry_Base::ResetSynopsisEditHistory(void)
{
    m_SynopsisEditHistory.clear();
    m_set_State[1] &= ~0xc00;
}

void CMim_entry_Base::ResetSynopsisCreationDate(void)
{
    m_SynopsisCreationDate.Reset();
}

void CMim_entry_Base::SetSynopsisCreationDate(CMim_entry_Base::TSynopsisCreationDate& value)
{
    m_SynopsisCreationDate.Reset(&value);
}

CMim_entry_Base::TSynopsisCreationDate& CMim_entry_Base::SetSynopsisCreationDate(void)
{
    if ( !m_SynopsisCreationDate )
        m_SynopsisCreationDate.Reset(new ncbi::objects::CMim_edit_item());
    return (*m_SynopsisCreationDate);
}

void CMim_entry_Base::ResetEditHistory(void)
{
    m_EditHistory.clear();
    m_set_State[1] &= ~0xc000;
}

void CMim_entry_Base::ResetCreationDate(void)
{
    m_CreationDate.Reset();
}

void CMim_entry_Base::SetCreationDate(CMim_entry_Base::TCreationDate& value)
{
    m_CreationDate.Reset(&value);
}

CMim_entry_Base::TCreationDate& CMim_entry_Base::SetCreationDate(void)
{
    if ( !m_CreationDate )
        m_CreationDate.Reset(new ncbi::objects::CMim_edit_item());
    return (*m_CreationDate);
}

void CMim_entry_Base::ResetReferences(void)
{
    m_References.clear();
    m_set_State[1] &= ~0xc0000;
}

void CMim_entry_Base::ResetAttribution(void)
{
    m_Attribution.clear();
    m_set_State[1] &= ~0x300000;
}

void CMim_entry_Base::ResetMedlineLinks(void)
{
    m_MedlineLinks.Reset();
}

void CMim_entry_Base::SetMedlineLinks(CMim_entry_Base::TMedlineLinks& value)
{
    m_MedlineLinks.Reset(&value);
}

CMim_entry_Base::TMedlineLinks& CMim_entry_Base::SetMedlineLinks(void)
{
    if ( !m_MedlineLinks )
        m_MedlineLinks.Reset(new ncbi::objects::CMim_link());
    return (*m_MedlineLinks);
}

void CMim_entry_Base::ResetProteinLinks(void)
{
    m_ProteinLinks.Reset();
}

void CMim_entry_Base::SetProteinLinks(CMim_entry_Base::TProteinLinks& value)
{
    m_ProteinLinks.Reset(&value);
}

CMim_entry_Base::TProteinLinks& CMim_entry_Base::SetProteinLinks(void)
{
    if ( !m_ProteinLinks )
        m_ProteinLinks.Reset(new ncbi::objects::CMim_link());
    return (*m_ProteinLinks);
}

void CMim_entry_Base::ResetNucleotideLinks(void)
{
    m_NucleotideLinks.Reset();
}

void CMim_entry_Base::SetNucleotideLinks(CMim_entry_Base::TNucleotideLinks& value)
{
    m_NucleotideLinks.Reset(&value);
}

CMim_entry_Base::TNucleotideLinks& CMim_entry_Base::SetNucleotideLinks(void)
{
    if ( !m_NucleotideLinks )
        m_NucleotideLinks.Reset(new ncbi::objects::CMim_link());
    return (*m_NucleotideLinks);
}

void CMim_entry_Base::ResetStructureLinks(void)
{
    m_StructureLinks.Reset();
}

void CMim_entry_Base::SetStructureLinks(CMim_entry_Base::TStructureLinks& value)
{
    m_StructureLinks.Reset(&value);
}

CMim_entry_Base::TStructureLinks& CMim_entry_Base::SetStructureLinks(void)
{
    if ( !m_StructureLinks )
        m_StructureLinks.Reset(new ncbi::objects::CMim_link());
    return (*m_StructureLinks);
}

void CMim_entry_Base::ResetGenomeLinks(void)
{
    m_GenomeLinks.Reset();
}

void CMim_entry_Base::SetGenomeLinks(CMim_entry_Base::TGenomeLinks& value)
{
    m_GenomeLinks.Reset(&value);
}

CMim_entry_Base::TGenomeLinks& CMim_entry_Base::SetGenomeLinks(void)
{
    if ( !m_GenomeLinks )
        m_GenomeLinks.Reset(new ncbi::objects::CMim_link());
    return (*m_GenomeLinks);
}

void CMim_entry_Base::Reset(void)
{
    ResetMimNumber();
    ResetMimType();
    ResetTitle();
    ResetCopyright();
    ResetSymbol();
    ResetLocus();
    ResetSynonyms();
    ResetAliases();
    ResetIncluded();
    ResetSeeAlso();
    ResetText();
    ResetTextfields();
    ResetHasSummary();
    ResetSummary();
    ResetSummaryAttribution();
    ResetSummaryEditHistory();
    ResetSummaryCreationDate();
    ResetAllelicVariants();
    ResetHasSynopsis();
    ResetClinicalSynopsis();
    ResetSynopsisAttribution();
    ResetSynopsisEditHistory();
    ResetSynopsisCreationDate();
    ResetEditHistory();
    ResetCreationDate();
    ResetReferences();
    ResetAttribution();
    ResetNumGeneMaps();
    ResetMedlineLinks();
    ResetProteinLinks();
    ResetNucleotideLinks();
    ResetStructureLinks();
    ResetGenomeLinks();
}

BEGIN_NAMED_BASE_CLASS_INFO("Mim-entry", CMim_entry)
{
    SET_CLASS_MODULE("NCBI-Mim");
    ADD_NAMED_STD_MEMBER("mimNumber", m_MimNumber)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("mimType", m_MimType, EMimType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("title", m_Title)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("copyright", m_Copyright)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("symbol", m_Symbol)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("locus", m_Locus)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("synonyms", m_Synonyms, STL_list, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("aliases", m_Aliases, STL_list, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("included", m_Included, STL_list, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("seeAlso", m_SeeAlso, STL_list, (STL_CRef, (CLASS, (CMim_cit))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("text", m_Text, STL_list, (STL_CRef, (CLASS, (CMim_text))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("textfields", m_Textfields, STL_list, (STL_CRef, (CLASS, (CMim_text))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("hasSummary", m_HasSummary)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("summary", m_Summary, STL_list, (STL_CRef, (CLASS, (CMim_text))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("summaryAttribution", m_SummaryAttribution, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("summaryEditHistory", m_SummaryEditHistory, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("summaryCreationDate", m_SummaryCreationDate, CMim_edit_item)->SetOptional();
    ADD_NAMED_MEMBER("allelicVariants", m_AllelicVariants, STL_list, (STL_CRef, (CLASS, (CMim_allelic_variant))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("hasSynopsis", m_HasSynopsis)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("clinicalSynopsis", m_ClinicalSynopsis, STL_list, (STL_CRef, (CLASS, (CMim_index_term))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("synopsisAttribution", m_SynopsisAttribution, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("synopsisEditHistory", m_SynopsisEditHistory, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("synopsisCreationDate", m_SynopsisCreationDate, CMim_edit_item)->SetOptional();
    ADD_NAMED_MEMBER("editHistory", m_EditHistory, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("creationDate", m_CreationDate, CMim_edit_item)->SetOptional();
    ADD_NAMED_MEMBER("references", m_References, STL_list, (STL_CRef, (CLASS, (CMim_reference))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("attribution", m_Attribution, STL_list, (STL_CRef, (CLASS, (CMim_edit_item))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("numGeneMaps", m_NumGeneMaps)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("medlineLinks", m_MedlineLinks, CMim_link)->SetOptional();
    ADD_NAMED_REF_MEMBER("proteinLinks", m_ProteinLinks, CMim_link)->SetOptional();
    ADD_NAMED_REF_MEMBER("nucleotideLinks", m_NucleotideLinks, CMim_link)->SetOptional();
    ADD_NAMED_REF_MEMBER("structureLinks", m_StructureLinks, CMim_link)->SetOptional();
    ADD_NAMED_REF_MEMBER("genomeLinks", m_GenomeLinks, CMim_link)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CMim_entry_Base::CMim_entry_Base(void)
    : m_MimType((EMimType)(0)), m_HasSummary(0), m_HasSynopsis(0), m_NumGeneMaps(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMim_entry_Base::~CMim_entry_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

