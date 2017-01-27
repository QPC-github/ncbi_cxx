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
 *   'valid.asn'.
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
#include <objects/valid/Dependent_field_rule.hpp>
#include <objects/valid/Field_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CDependent_field_rule_Base::ResetMatch_name(void)
{
    m_Match_name.erase();
    m_set_State[0] &= ~0x3;
}

void CDependent_field_rule_Base::ResetValue_constraint(void)
{
    m_Value_constraint.erase();
    m_set_State[0] &= ~0xc;
}

void CDependent_field_rule_Base::ResetOther_fields(void)
{
    m_Other_fields.Reset();
}

void CDependent_field_rule_Base::SetOther_fields(CDependent_field_rule_Base::TOther_fields& value)
{
    m_Other_fields.Reset(&value);
}

CDependent_field_rule_Base::TOther_fields& CDependent_field_rule_Base::SetOther_fields(void)
{
    if ( !m_Other_fields )
        m_Other_fields.Reset(new ncbi::objects::CField_set());
    return (*m_Other_fields);
}

void CDependent_field_rule_Base::ResetDisallowed_fields(void)
{
    m_Disallowed_fields.Reset();
}

void CDependent_field_rule_Base::SetDisallowed_fields(CDependent_field_rule_Base::TDisallowed_fields& value)
{
    m_Disallowed_fields.Reset(&value);
}

CDependent_field_rule_Base::TDisallowed_fields& CDependent_field_rule_Base::SetDisallowed_fields(void)
{
    if ( !m_Disallowed_fields )
        m_Disallowed_fields.Reset(new ncbi::objects::CField_set());
    return (*m_Disallowed_fields);
}

void CDependent_field_rule_Base::Reset(void)
{
    ResetMatch_name();
    ResetValue_constraint();
    ResetInvert_match();
    ResetOther_fields();
    ResetDisallowed_fields();
}

BEGIN_NAMED_BASE_CLASS_INFO("Dependent-field-rule", CDependent_field_rule)
{
    SET_CLASS_MODULE("NCBI-Structured-comment-validation");
    ADD_NAMED_STD_MEMBER("match-name", m_Match_name)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("value-constraint", m_Value_constraint)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("invert-match", m_Invert_match)->SetDefault(new TInvert_match(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("other-fields", m_Other_fields, CField_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("disallowed-fields", m_Disallowed_fields, CField_set)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CDependent_field_rule_Base::CDependent_field_rule_Base(void)
    : m_Invert_match(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CDependent_field_rule_Base::~CDependent_field_rule_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

