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
#include <objects/macro/Suspect_rule.hpp>
#include <objects/macro/Constraint_choice_set.hpp>
#include <objects/macro/Replace_rule.hpp>
#include <objects/macro/Search_func.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSuspect_rule_Base::ResetFind(void)
{
    if ( !m_Find ) {
        m_Find.Reset(new TFind());
        return;
    }
    (*m_Find).Reset();
}

void CSuspect_rule_Base::SetFind(CSuspect_rule_Base::TFind& value)
{
    m_Find.Reset(&value);
}

void CSuspect_rule_Base::ResetExcept(void)
{
    m_Except.Reset();
}

void CSuspect_rule_Base::SetExcept(CSuspect_rule_Base::TExcept& value)
{
    m_Except.Reset(&value);
}

CSuspect_rule_Base::TExcept& CSuspect_rule_Base::SetExcept(void)
{
    if ( !m_Except )
        m_Except.Reset(new ncbi::objects::CSearch_func());
    return (*m_Except);
}

void CSuspect_rule_Base::ResetFeat_constraint(void)
{
    m_Feat_constraint.Reset();
}

void CSuspect_rule_Base::SetFeat_constraint(CSuspect_rule_Base::TFeat_constraint& value)
{
    m_Feat_constraint.Reset(&value);
}

CSuspect_rule_Base::TFeat_constraint& CSuspect_rule_Base::SetFeat_constraint(void)
{
    if ( !m_Feat_constraint )
        m_Feat_constraint.Reset(new ncbi::objects::CConstraint_choice_set());
    return (*m_Feat_constraint);
}

void CSuspect_rule_Base::ResetReplace(void)
{
    m_Replace.Reset();
}

void CSuspect_rule_Base::SetReplace(CSuspect_rule_Base::TReplace& value)
{
    m_Replace.Reset(&value);
}

CSuspect_rule_Base::TReplace& CSuspect_rule_Base::SetReplace(void)
{
    if ( !m_Replace )
        m_Replace.Reset(new ncbi::objects::CReplace_rule());
    return (*m_Replace);
}

void CSuspect_rule_Base::ResetDescription(void)
{
    m_Description.erase();
    m_set_State[0] &= ~0xc00;
}

void CSuspect_rule_Base::Reset(void)
{
    ResetFind();
    ResetExcept();
    ResetFeat_constraint();
    ResetRule_type();
    ResetReplace();
    ResetDescription();
}

BEGIN_NAMED_BASE_CLASS_INFO("Suspect-rule", CSuspect_rule)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("find", m_Find, CSearch_func);
    ADD_NAMED_REF_MEMBER("except", m_Except, CSearch_func)->SetOptional();
    ADD_NAMED_REF_MEMBER("feat-constraint", m_Feat_constraint, CConstraint_choice_set)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("rule-type", m_Rule_type, EFix_type)->SetDefault(new TRule_type(eFix_type_none))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("replace", m_Replace, CReplace_rule)->SetOptional();
    ADD_NAMED_STD_MEMBER("description", m_Description)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSuspect_rule_Base::CSuspect_rule_Base(void)
    : m_Rule_type(eFix_type_none)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetFind();
    }
}

// destructor
CSuspect_rule_Base::~CSuspect_rule_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

