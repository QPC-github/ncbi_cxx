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
 *   'remap.asn'.
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
#include <objects/remap/RMRequest.hpp>
#include <objects/remap/Remap_query.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CRMRequest_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CRMRequest_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Maps_to_builds:
    case e_Maps_from_builds:
        m_string.Destruct();
        break;
    case e_Remap:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CRMRequest_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Remap:
        (m_object = new(pool) ncbi::objects::CRemap_query())->AddReference();
        break;
    case e_Maps_to_builds:
    case e_Maps_from_builds:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CRMRequest_Base::sm_SelectionNames[] = {
    "not set",
    "remap",
    "maps-to-builds",
    "maps-from-builds",
    "all-builds"
};

NCBI_NS_STD::string CRMRequest_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CRMRequest_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CRMRequest_Base::TRemap& CRMRequest_Base::GetRemap(void) const
{
    CheckSelected(e_Remap);
    return *static_cast<const TRemap*>(m_object);
}

CRMRequest_Base::TRemap& CRMRequest_Base::SetRemap(void)
{
    Select(e_Remap, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TRemap*>(m_object);
}

void CRMRequest_Base::SetRemap(CRMRequest_Base::TRemap& value)
{
    TRemap* ptr = &value;
    if ( m_choice != e_Remap || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Remap;
    }
}

void CRMRequest_Base::SetMaps_to_builds(const CRMRequest_Base::TMaps_to_builds& value)
{
    Select(e_Maps_to_builds, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CRMRequest_Base::SetMaps_from_builds(const CRMRequest_Base::TMaps_from_builds& value)
{
    Select(e_Maps_from_builds, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("RMRequest", CRMRequest)
{
    SET_CHOICE_MODULE("NCBI-Remap");
    ADD_NAMED_REF_CHOICE_VARIANT("remap", m_object, CRemap_query);
    ADD_NAMED_BUF_CHOICE_VARIANT("maps-to-builds", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("maps-from-builds", m_string, STD, (string));
    ADD_NAMED_NULL_CHOICE_VARIANT("all-builds", null, ());
}
END_CHOICE_INFO

// constructor
CRMRequest_Base::CRMRequest_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CRMRequest_Base::~CRMRequest_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

