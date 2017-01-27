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
 *   'macro.asn'.
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
#include <objects/macro/Location_choice.hpp>
#include <objects/macro/Location_interval.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CLocation_choice_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CLocation_choice_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Interval:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CLocation_choice_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Interval:
        (m_object = new(pool) ncbi::objects::CLocation_interval())->AddReference();
        break;
    case e_Point:
        m_Point = 0;
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CLocation_choice_Base::sm_SelectionNames[] = {
    "not set",
    "interval",
    "whole-sequence",
    "point"
};

NCBI_NS_STD::string CLocation_choice_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CLocation_choice_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CLocation_choice_Base::TInterval& CLocation_choice_Base::GetInterval(void) const
{
    CheckSelected(e_Interval);
    return *static_cast<const TInterval*>(m_object);
}

CLocation_choice_Base::TInterval& CLocation_choice_Base::SetInterval(void)
{
    Select(e_Interval, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TInterval*>(m_object);
}

void CLocation_choice_Base::SetInterval(CLocation_choice_Base::TInterval& value)
{
    TInterval* ptr = &value;
    if ( m_choice != e_Interval || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Interval;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Location-choice", CLocation_choice)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_REF_CHOICE_VARIANT("interval", m_object, CLocation_interval);
    ADD_NAMED_NULL_CHOICE_VARIANT("whole-sequence", null, ());
    ADD_NAMED_STD_CHOICE_VARIANT("point", m_Point);
}
END_CHOICE_INFO

// constructor
CLocation_choice_Base::CLocation_choice_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CLocation_choice_Base::~CLocation_choice_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

