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
#include <objects/macro/Remove_outside_action.hpp>
#include <objects/macro/Field_type.hpp>
#include <objects/macro/Text_portion.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CRemove_outside_action_Base::ResetPortion(void)
{
    if ( !m_Portion ) {
        m_Portion.Reset(new TPortion());
        return;
    }
    (*m_Portion).Reset();
}

void CRemove_outside_action_Base::SetPortion(CRemove_outside_action_Base::TPortion& value)
{
    m_Portion.Reset(&value);
}

void CRemove_outside_action_Base::ResetField(void)
{
    if ( !m_Field ) {
        m_Field.Reset(new TField());
        return;
    }
    (*m_Field).Reset();
}

void CRemove_outside_action_Base::SetField(CRemove_outside_action_Base::TField& value)
{
    m_Field.Reset(&value);
}

void CRemove_outside_action_Base::Reset(void)
{
    ResetPortion();
    ResetField();
    ResetRemove_if_not_found();
}

BEGIN_NAMED_BASE_CLASS_INFO("Remove-outside-action", CRemove_outside_action)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("portion", m_Portion, CText_portion);
    ADD_NAMED_REF_MEMBER("field", m_Field, CField_type);
    ADD_NAMED_STD_MEMBER("remove-if-not-found", m_Remove_if_not_found)->SetDefault(new TRemove_if_not_found(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CRemove_outside_action_Base::CRemove_outside_action_Base(void)
    : m_Remove_if_not_found(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetPortion();
        ResetField();
    }
}

// destructor
CRemove_outside_action_Base::~CRemove_outside_action_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

