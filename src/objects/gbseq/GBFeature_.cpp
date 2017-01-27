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
 *   'gbseq.asn'.
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
#include <objects/gbseq/GBFeature.hpp>
#include <objects/gbseq/GBInterval.hpp>
#include <objects/gbseq/GBQualifier.hpp>
#include <objects/gbseq/GBXref.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CGBFeature_Base::ResetKey(void)
{
    m_Key.erase();
    m_set_State[0] &= ~0x3;
}

void CGBFeature_Base::ResetLocation(void)
{
    m_Location.erase();
    m_set_State[0] &= ~0xc;
}

void CGBFeature_Base::ResetIntervals(void)
{
    m_Intervals.clear();
    m_set_State[0] &= ~0x30;
}

void CGBFeature_Base::ResetOperator(void)
{
    m_Operator.erase();
    m_set_State[0] &= ~0xc0;
}

void CGBFeature_Base::ResetQuals(void)
{
    m_Quals.clear();
    m_set_State[0] &= ~0x3000;
}

void CGBFeature_Base::ResetXrefs(void)
{
    m_Xrefs.clear();
    m_set_State[0] &= ~0xc000;
}

void CGBFeature_Base::Reset(void)
{
    ResetKey();
    ResetLocation();
    ResetIntervals();
    ResetOperator();
    ResetPartial5();
    ResetPartial3();
    ResetQuals();
    ResetXrefs();
}

BEGIN_NAMED_BASE_CLASS_INFO("GBFeature", CGBFeature)
{
    SET_CLASS_MODULE("NCBI-GBSeq");
    ADD_NAMED_STD_MEMBER("key", m_Key)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("location", m_Location)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("intervals", m_Intervals, STL_list, (STL_CRef, (CLASS, (CGBInterval))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("operator", m_Operator)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("partial5", m_Partial5)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("partial3", m_Partial3)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("quals", m_Quals, STL_list, (STL_CRef, (CLASS, (CGBQualifier))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("xrefs", m_Xrefs, STL_list, (STL_CRef, (CLASS, (CGBXref))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CGBFeature_Base::CGBFeature_Base(void)
    : m_Partial5(0), m_Partial3(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGBFeature_Base::~CGBFeature_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

