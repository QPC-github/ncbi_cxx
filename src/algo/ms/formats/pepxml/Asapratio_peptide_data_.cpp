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
#include <algo/ms/formats/pepxml/Asapratio_peptide_data.hpp>
#include <algo/ms/formats/pepxml/Asapratio_contribution.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CAsapratio_peptide_data_Base::C_Attlist::Reset(void)
{
    ResetStatus();
    ResetCidIndex();
    ResetLight_mass();
    ResetHeavy_mass();
    ResetArea_flag();
}

BEGIN_NAMED_CLASS_INFO("", CAsapratio_peptide_data_Base::C_Attlist)
{
    SET_INTERNAL_NAME("asapratio_peptide_data", "Attlist");
    SET_CLASS_MODULE("pepXML");
    ADD_NAMED_STD_MEMBER("status", m_Status)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("cidIndex", m_CidIndex)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("light_mass", m_Light_mass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("heavy_mass", m_Heavy_mass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("area_flag", m_Area_flag)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CAsapratio_peptide_data_Base::C_Attlist::C_Attlist(void)
    : m_Status(0), m_CidIndex(0), m_Light_mass(0), m_Heavy_mass(0), m_Area_flag(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CAsapratio_peptide_data_Base::C_Attlist::~C_Attlist(void)
{
}


void CAsapratio_peptide_data_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CAsapratio_peptide_data_Base::SetAttlist(CAsapratio_peptide_data_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
}

void CAsapratio_peptide_data_Base::ResetAsapratio_contribution(void)
{
    m_Asapratio_contribution.clear();
    m_set_State[0] &= ~0xc;
}

void CAsapratio_peptide_data_Base::Reset(void)
{
    ResetAttlist();
    ResetAsapratio_contribution();
}

BEGIN_NAMED_BASE_CLASS_INFO("asapratio_peptide_data", CAsapratio_peptide_data)
{
    SET_CLASS_MODULE("pepXML");
    SET_NAMESPACE("http://regis-web.systemsbiology.net/pepXML")->SetNsQualified(true);
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_MEMBER("asapratio_contribution", m_Asapratio_contribution, STL_list, (STL_CRef, (CLASS, (CAsapratio_contribution))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CAsapratio_peptide_data_Base::CAsapratio_peptide_data_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
    }
}

// destructor
CAsapratio_peptide_data_Base::~CAsapratio_peptide_data_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

