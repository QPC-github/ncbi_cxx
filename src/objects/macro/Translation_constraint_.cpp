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
#include <objects/macro/Translation_constraint.hpp>
#include <objects/macro/Quantity_constraint.hpp>
#include <objects/macro/String_constraint_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTranslation_constraint_Base::ResetActual_strings(void)
{
    if ( !m_Actual_strings ) {
        m_Actual_strings.Reset(new TActual_strings());
        return;
    }
    (*m_Actual_strings).Reset();
}

void CTranslation_constraint_Base::SetActual_strings(CTranslation_constraint_Base::TActual_strings& value)
{
    m_Actual_strings.Reset(&value);
}

void CTranslation_constraint_Base::ResetTransl_strings(void)
{
    if ( !m_Transl_strings ) {
        m_Transl_strings.Reset(new TTransl_strings());
        return;
    }
    (*m_Transl_strings).Reset();
}

void CTranslation_constraint_Base::SetTransl_strings(CTranslation_constraint_Base::TTransl_strings& value)
{
    m_Transl_strings.Reset(&value);
}

void CTranslation_constraint_Base::ResetNum_mismatches(void)
{
    m_Num_mismatches.Reset();
}

void CTranslation_constraint_Base::SetNum_mismatches(CTranslation_constraint_Base::TNum_mismatches& value)
{
    m_Num_mismatches.Reset(&value);
}

CTranslation_constraint_Base::TNum_mismatches& CTranslation_constraint_Base::SetNum_mismatches(void)
{
    if ( !m_Num_mismatches )
        m_Num_mismatches.Reset(new ncbi::objects::CQuantity_constraint());
    return (*m_Num_mismatches);
}

void CTranslation_constraint_Base::Reset(void)
{
    ResetActual_strings();
    ResetTransl_strings();
    ResetInternal_stops();
    ResetNum_mismatches();
}

BEGIN_NAMED_BASE_CLASS_INFO("Translation-constraint", CTranslation_constraint)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("actual-strings", m_Actual_strings, CString_constraint_set);
    ADD_NAMED_REF_MEMBER("transl-strings", m_Transl_strings, CString_constraint_set);
    ADD_NAMED_ENUM_MEMBER("internal-stops", m_Internal_stops, EMatch_type_constraint)->SetDefault(new TInternal_stops(eMatch_type_constraint_dont_care))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("num-mismatches", m_Num_mismatches, CQuantity_constraint)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CTranslation_constraint_Base::CTranslation_constraint_Base(void)
    : m_Internal_stops(eMatch_type_constraint_dont_care)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetActual_strings();
        ResetTransl_strings();
    }
}

// destructor
CTranslation_constraint_Base::~CTranslation_constraint_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

