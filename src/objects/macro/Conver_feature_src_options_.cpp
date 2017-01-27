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
#include <objects/macro/Conver_feature_src_options.hpp>
#include <objects/macro/Convert_from_CDS_options.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CConvert_feature_src_options_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CConvert_feature_src_options_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Cds:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CConvert_feature_src_options_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Cds:
        (m_object = new(pool) ncbi::objects::CConvert_from_CDS_options())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CConvert_feature_src_options_Base::sm_SelectionNames[] = {
    "not set",
    "cds"
};

NCBI_NS_STD::string CConvert_feature_src_options_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CConvert_feature_src_options_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CConvert_feature_src_options_Base::TCds& CConvert_feature_src_options_Base::GetCds(void) const
{
    CheckSelected(e_Cds);
    return *static_cast<const TCds*>(m_object);
}

CConvert_feature_src_options_Base::TCds& CConvert_feature_src_options_Base::SetCds(void)
{
    Select(e_Cds, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCds*>(m_object);
}

void CConvert_feature_src_options_Base::SetCds(CConvert_feature_src_options_Base::TCds& value)
{
    TCds* ptr = &value;
    if ( m_choice != e_Cds || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Cds;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Convert-feature-src-options", CConvert_feature_src_options)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_REF_CHOICE_VARIANT("cds", m_object, CConvert_from_CDS_options);
}
END_CHOICE_INFO

// constructor
CConvert_feature_src_options_Base::CConvert_feature_src_options_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CConvert_feature_src_options_Base::~CConvert_feature_src_options_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

