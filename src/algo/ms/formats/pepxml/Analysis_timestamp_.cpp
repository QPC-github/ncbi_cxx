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
#include <algo/ms/formats/pepxml/Analysis_timestamp.hpp>
#include <algo/ms/formats/pepxml/Database_refresh_timestamp.hpp>
#include <algo/ms/formats/pepxml/Xpressratio_timestamp.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CAnalysis_timestamp_Base::C_Attlist::ResetTime(void)
{
    m_Time.erase();
    m_set_State[0] &= ~0x3;
}

void CAnalysis_timestamp_Base::C_Attlist::ResetAnalysis(void)
{
    m_Analysis.erase();
    m_set_State[0] &= ~0xc;
}

void CAnalysis_timestamp_Base::C_Attlist::Reset(void)
{
    ResetTime();
    ResetAnalysis();
    ResetId();
}

BEGIN_NAMED_CLASS_INFO("", CAnalysis_timestamp_Base::C_Attlist)
{
    SET_INTERNAL_NAME("analysis_timestamp", "Attlist");
    SET_CLASS_MODULE("pepXML");
    ADD_NAMED_STD_MEMBER("time", m_Time)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("analysis", m_Analysis)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("id", m_Id)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CAnalysis_timestamp_Base::C_Attlist::C_Attlist(void)
    : m_Id(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CAnalysis_timestamp_Base::C_Attlist::~C_Attlist(void)
{
}


void CAnalysis_timestamp_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CAnalysis_timestamp_Base::SetAttlist(CAnalysis_timestamp_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
}

void CAnalysis_timestamp_Base::ResetDatabase_refresh_timestamp(void)
{
    m_Database_refresh_timestamp.clear();
    m_set_State[0] &= ~0xc;
}

void CAnalysis_timestamp_Base::ResetXpressratio_timestamp(void)
{
    m_Xpressratio_timestamp.clear();
    m_set_State[0] &= ~0x30;
}

void CAnalysis_timestamp_Base::Reset(void)
{
    ResetAttlist();
    ResetDatabase_refresh_timestamp();
    ResetXpressratio_timestamp();
}

BEGIN_NAMED_BASE_CLASS_INFO("analysis_timestamp", CAnalysis_timestamp)
{
    SET_CLASS_MODULE("pepXML");
    SET_NAMESPACE("http://regis-web.systemsbiology.net/pepXML")->SetNsQualified(true);
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_MEMBER("database_refresh_timestamp", m_Database_refresh_timestamp, STL_list, (STL_CRef, (CLASS, (CDatabase_refresh_timestamp))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_MEMBER("xpressratio_timestamp", m_Xpressratio_timestamp, STL_list, (STL_CRef, (CLASS, (CXpressratio_timestamp))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CAnalysis_timestamp_Base::CAnalysis_timestamp_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
    }
}

// destructor
CAnalysis_timestamp_Base::~CAnalysis_timestamp_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

