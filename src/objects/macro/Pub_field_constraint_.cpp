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
#include <objects/macro/Pub_field_constraint.hpp>
#include <objects/macro/String_constraint.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPub_field_constraint_Base::ResetConstraint(void)
{
    if ( !m_Constraint ) {
        m_Constraint.Reset(new TConstraint());
        return;
    }
    (*m_Constraint).Reset();
}

void CPub_field_constraint_Base::SetConstraint(CPub_field_constraint_Base::TConstraint& value)
{
    m_Constraint.Reset(&value);
}

void CPub_field_constraint_Base::Reset(void)
{
    ResetField();
    ResetConstraint();
}

BEGIN_NAMED_BASE_CLASS_INFO("Pub-field-constraint", CPub_field_constraint)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_ENUM_MEMBER("field", m_Field, EPublication_field)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("constraint", m_Constraint, CString_constraint);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPub_field_constraint_Base::CPub_field_constraint_Base(void)
    : m_Field((ncbi::objects::EPublication_field)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetConstraint();
    }
}

// destructor
CPub_field_constraint_Base::~CPub_field_constraint_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

