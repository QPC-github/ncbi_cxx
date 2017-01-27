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
 *   'pepXML.xsd'.
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
#include <algo/ms/formats/pepxml/Msms_run_summary.hpp>
#include <algo/ms/formats/pepxml/Analysis_timestamp.hpp>
#include <algo/ms/formats/pepxml/Sample_enzyme.hpp>
#include <algo/ms/formats/pepxml/Search_summary.hpp>
#include <algo/ms/formats/pepxml/Spectrum_query.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMsms_run_summary_Base::C_Attlist::ResetBase_name(void)
{
    m_Base_name.erase();
    m_set_State[0] &= ~0x3;
}

void CMsms_run_summary_Base::C_Attlist::ResetRaw_data_type(void)
{
    m_Raw_data_type.erase();
    m_set_State[0] &= ~0xc;
}

void CMsms_run_summary_Base::C_Attlist::ResetRaw_data(void)
{
    m_Raw_data.erase();
    m_set_State[0] &= ~0x30;
}

void CMsms_run_summary_Base::C_Attlist::ResetMsManufacturer(void)
{
    m_MsManufacturer.erase();
    m_set_State[0] &= ~0xc0;
}

void CMsms_run_summary_Base::C_Attlist::ResetMsModel(void)
{
    m_MsModel.erase();
    m_set_State[0] &= ~0x300;
}

void CMsms_run_summary_Base::C_Attlist::ResetMsIonization(void)
{
    m_MsIonization.erase();
    m_set_State[0] &= ~0xc00;
}

void CMsms_run_summary_Base::C_Attlist::ResetMsMassAnalyzer(void)
{
    m_MsMassAnalyzer.erase();
    m_set_State[0] &= ~0x3000;
}

void CMsms_run_summary_Base::C_Attlist::ResetMsDetector(void)
{
    m_MsDetector.erase();
    m_set_State[0] &= ~0xc000;
}

void CMsms_run_summary_Base::C_Attlist::Reset(void)
{
    ResetBase_name();
    ResetRaw_data_type();
    ResetRaw_data();
    ResetMsManufacturer();
    ResetMsModel();
    ResetMsIonization();
    ResetMsMassAnalyzer();
    ResetMsDetector();
}

BEGIN_NAMED_CLASS_INFO("", CMsms_run_summary_Base::C_Attlist)
{
    SET_INTERNAL_NAME("msms_run_summary", "Attlist");
    SET_CLASS_MODULE("pepXML");
    ADD_NAMED_STD_MEMBER("base_name", m_Base_name)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("raw_data_type", m_Raw_data_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("raw_data", m_Raw_data)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("msManufacturer", m_MsManufacturer)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("msModel", m_MsModel)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("msIonization", m_MsIonization)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("msMassAnalyzer", m_MsMassAnalyzer)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("msDetector", m_MsDetector)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CMsms_run_summary_Base::C_Attlist::C_Attlist(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMsms_run_summary_Base::C_Attlist::~C_Attlist(void)
{
}


void CMsms_run_summary_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CMsms_run_summary_Base::SetAttlist(CMsms_run_summary_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
}

void CMsms_run_summary_Base::ResetSample_enzyme(void)
{
    if ( !m_Sample_enzyme ) {
        m_Sample_enzyme.Reset(new TSample_enzyme());
        return;
    }
    (*m_Sample_enzyme).Reset();
}

void CMsms_run_summary_Base::SetSample_enzyme(CMsms_run_summary_Base::TSample_enzyme& value)
{
    m_Sample_enzyme.Reset(&value);
}

void CMsms_run_summary_Base::ResetSearch_summary(void)
{
    m_Search_summary.clear();
    m_set_State[0] &= ~0x30;
}

void CMsms_run_summary_Base::ResetAnalysis_timestamp(void)
{
    m_Analysis_timestamp.clear();
    m_set_State[0] &= ~0xc0;
}

void CMsms_run_summary_Base::ResetSpectrum_query(void)
{
    m_Spectrum_query.clear();
    m_set_State[0] &= ~0x300;
}

void CMsms_run_summary_Base::Reset(void)
{
    ResetAttlist();
    ResetSample_enzyme();
    ResetSearch_summary();
    ResetAnalysis_timestamp();
    ResetSpectrum_query();
}

BEGIN_NAMED_BASE_CLASS_INFO("msms_run_summary", CMsms_run_summary)
{
    SET_CLASS_MODULE("pepXML");
    SET_NAMESPACE("http://regis-web.systemsbiology.net/pepXML")->SetNsQualified(true);
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_REF_MEMBER("sample_enzyme", m_Sample_enzyme, CSample_enzyme)->SetNoPrefix();
    ADD_NAMED_MEMBER("search_summary", m_Search_summary, STL_list, (STL_CRef, (CLASS, (CSearch_summary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_MEMBER("analysis_timestamp", m_Analysis_timestamp, STL_list, (STL_CRef, (CLASS, (CAnalysis_timestamp))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_MEMBER("spectrum_query", m_Spectrum_query, STL_list, (STL_CRef, (CLASS, (CSpectrum_query))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CMsms_run_summary_Base::CMsms_run_summary_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
        ResetSample_enzyme();
    }
}

// destructor
CMsms_run_summary_Base::~CMsms_run_summary_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

