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
#include <objects/remap/RMReply.hpp>
#include <objects/remap/Remap_result.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CRMReply_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CRMReply_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Maps_to_builds:
        m_Maps_to_builds.Destruct();
        break;
    case e_Maps_from_builds:
        m_Maps_from_builds.Destruct();
        break;
    case e_All_builds:
        m_All_builds.Destruct();
        break;
    case e_Error:
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

void CRMReply_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Remap:
        (m_object = new(pool) ncbi::objects::CRemap_result())->AddReference();
        break;
    case e_Maps_to_builds:
        m_Maps_to_builds.Construct();
        break;
    case e_Maps_from_builds:
        m_Maps_from_builds.Construct();
        break;
    case e_All_builds:
        m_All_builds.Construct();
        break;
    case e_Error:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CRMReply_Base::sm_SelectionNames[] = {
    "not set",
    "error",
    "remap",
    "maps-to-builds",
    "maps-from-builds",
    "all-builds"
};

NCBI_NS_STD::string CRMReply_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CRMReply_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CRMReply_Base::SetError(const CRMReply_Base::TError& value)
{
    Select(e_Error, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CRMReply_Base::TRemap& CRMReply_Base::GetRemap(void) const
{
    CheckSelected(e_Remap);
    return *static_cast<const TRemap*>(m_object);
}

CRMReply_Base::TRemap& CRMReply_Base::SetRemap(void)
{
    Select(e_Remap, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TRemap*>(m_object);
}

void CRMReply_Base::SetRemap(CRMReply_Base::TRemap& value)
{
    TRemap* ptr = &value;
    if ( m_choice != e_Remap || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Remap;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("RMReply", CRMReply)
{
    SET_CHOICE_MODULE("NCBI-Remap");
    ADD_NAMED_BUF_CHOICE_VARIANT("error", m_string, STD, (string));
    ADD_NAMED_REF_CHOICE_VARIANT("remap", m_object, CRemap_result);
    ADD_NAMED_BUF_CHOICE_VARIANT("maps-to-builds", m_Maps_to_builds, STL_list, (STD, (string)));
    ADD_NAMED_BUF_CHOICE_VARIANT("maps-from-builds", m_Maps_from_builds, STL_list, (STD, (string)));
    ADD_NAMED_BUF_CHOICE_VARIANT("all-builds", m_All_builds, STL_list, (STD, (string)));
}
END_CHOICE_INFO

// constructor
CRMReply_Base::CRMReply_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CRMReply_Base::~CRMReply_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

