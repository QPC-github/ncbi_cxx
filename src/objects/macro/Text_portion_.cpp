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
#include <objects/macro/Text_portion.hpp>
#include <objects/macro/Text_marker.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CText_portion_Base::ResetLeft_marker(void)
{
    m_Left_marker.Reset();
}

void CText_portion_Base::SetLeft_marker(CText_portion_Base::TLeft_marker& value)
{
    m_Left_marker.Reset(&value);
}

CText_portion_Base::TLeft_marker& CText_portion_Base::SetLeft_marker(void)
{
    if ( !m_Left_marker )
        m_Left_marker.Reset(new ncbi::objects::CText_marker());
    return (*m_Left_marker);
}

void CText_portion_Base::ResetRight_marker(void)
{
    m_Right_marker.Reset();
}

void CText_portion_Base::SetRight_marker(CText_portion_Base::TRight_marker& value)
{
    m_Right_marker.Reset(&value);
}

CText_portion_Base::TRight_marker& CText_portion_Base::SetRight_marker(void)
{
    if ( !m_Right_marker )
        m_Right_marker.Reset(new ncbi::objects::CText_marker());
    return (*m_Right_marker);
}

void CText_portion_Base::Reset(void)
{
    ResetLeft_marker();
    ResetInclude_left();
    ResetRight_marker();
    ResetInclude_right();
    ResetInside();
    ResetCase_sensitive();
    ResetWhole_word();
}

BEGIN_NAMED_BASE_CLASS_INFO("Text-portion", CText_portion)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("left-marker", m_Left_marker, CText_marker)->SetOptional();
    ADD_NAMED_STD_MEMBER("include-left", m_Include_left)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("right-marker", m_Right_marker, CText_marker)->SetOptional();
    ADD_NAMED_STD_MEMBER("include-right", m_Include_right)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("inside", m_Inside)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("case-sensitive", m_Case_sensitive)->SetDefault(new TCase_sensitive(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("whole-word", m_Whole_word)->SetDefault(new TWhole_word(false))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CText_portion_Base::CText_portion_Base(void)
    : m_Include_left(0), m_Include_right(0), m_Inside(0), m_Case_sensitive(false), m_Whole_word(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CText_portion_Base::~CText_portion_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

