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
#include <algo/ms/formats/pepxml/Sequence_search_constraint.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSequence_search_constraint_Base::C_Attlist::ResetSequence(void)
{
    m_Sequence.erase();
    m_set_State[0] &= ~0x3;
}

void CSequence_search_constraint_Base::C_Attlist::Reset(void)
{
    ResetSequence();
}

BEGIN_NAMED_CLASS_INFO("", CSequence_search_constraint_Base::C_Attlist)
{
    SET_INTERNAL_NAME("sequence_search_constraint", "Attlist");
    SET_CLASS_MODULE("pepXML");
    ADD_NAMED_STD_MEMBER("sequence", m_Sequence)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CSequence_search_constraint_Base::C_Attlist::C_Attlist(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSequence_search_constraint_Base::C_Attlist::~C_Attlist(void)
{
}


void CSequence_search_constraint_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CSequence_search_constraint_Base::SetAttlist(CSequence_search_constraint_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
    SetSequence_search_constraint();
}

void CSequence_search_constraint_Base::Reset(void)
{
    ResetAttlist();
    ResetSequence_search_constraint();
}

BEGIN_NAMED_BASE_CLASS_INFO("sequence_search_constraint", CSequence_search_constraint)
{
    SET_CLASS_MODULE("pepXML");
    SET_NAMESPACE("http://regis-web.systemsbiology.net/pepXML")->SetNsQualified(true);
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_NULL_MEMBER("sequence_search_constraint", null, ())->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix()->SetNotag();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSequence_search_constraint_Base::CSequence_search_constraint_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
    }
}

// destructor
CSequence_search_constraint_Base::~CSequence_search_constraint_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

