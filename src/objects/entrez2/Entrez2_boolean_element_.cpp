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
 *   'entrez2.asn'.
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
#include <objects/entrez2/Entrez2_boolean_element.hpp>
#include <objects/entrez2/Entrez2_boolean_term.hpp>
#include <objects/entrez2/Entrez2_id_list.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CEntrez2_boolean_element_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CEntrez2_boolean_element_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Str:
    case e_Key:
        m_string.Destruct();
        break;
    case e_Term:
    case e_Ids:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CEntrez2_boolean_element_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Op:
        m_Op = (int)(0);
        break;
    case e_Term:
        (m_object = new(pool) ncbi::objects::CEntrez2_boolean_term())->AddReference();
        break;
    case e_Ids:
        (m_object = new(pool) ncbi::objects::CEntrez2_id_list())->AddReference();
        break;
    case e_Str:
    case e_Key:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CEntrez2_boolean_element_Base::sm_SelectionNames[] = {
    "not set",
    "str",
    "op",
    "term",
    "ids",
    "key"
};

NCBI_NS_STD::string CEntrez2_boolean_element_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CEntrez2_boolean_element_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CEntrez2_boolean_element_Base::SetStr(const CEntrez2_boolean_element_Base::TStr& value)
{
    Select(e_Str, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CEntrez2_boolean_element_Base::TTerm& CEntrez2_boolean_element_Base::GetTerm(void) const
{
    CheckSelected(e_Term);
    return *static_cast<const TTerm*>(m_object);
}

CEntrez2_boolean_element_Base::TTerm& CEntrez2_boolean_element_Base::SetTerm(void)
{
    Select(e_Term, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTerm*>(m_object);
}

void CEntrez2_boolean_element_Base::SetTerm(CEntrez2_boolean_element_Base::TTerm& value)
{
    TTerm* ptr = &value;
    if ( m_choice != e_Term || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Term;
    }
}

const CEntrez2_boolean_element_Base::TIds& CEntrez2_boolean_element_Base::GetIds(void) const
{
    CheckSelected(e_Ids);
    return *static_cast<const TIds*>(m_object);
}

CEntrez2_boolean_element_Base::TIds& CEntrez2_boolean_element_Base::SetIds(void)
{
    Select(e_Ids, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TIds*>(m_object);
}

void CEntrez2_boolean_element_Base::SetIds(CEntrez2_boolean_element_Base::TIds& value)
{
    TIds* ptr = &value;
    if ( m_choice != e_Ids || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Ids;
    }
}

void CEntrez2_boolean_element_Base::SetKey(const CEntrez2_boolean_element_Base::TKey& value)
{
    Select(e_Key, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Entrez2-boolean-element", CEntrez2_boolean_element)
{
    SET_CHOICE_MODULE("NCBI-Entrez2");
    ADD_NAMED_BUF_CHOICE_VARIANT("str", m_string, STD, (string));
    ADD_NAMED_ENUM_CHOICE_VARIANT("op", m_Op, EEntrez2_operator);
    ADD_NAMED_REF_CHOICE_VARIANT("term", m_object, CEntrez2_boolean_term);
    ADD_NAMED_REF_CHOICE_VARIANT("ids", m_object, CEntrez2_id_list);
    ADD_NAMED_BUF_CHOICE_VARIANT("key", m_string, STD, (string));
}
END_CHOICE_INFO

// constructor
CEntrez2_boolean_element_Base::CEntrez2_boolean_element_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CEntrez2_boolean_element_Base::~CEntrez2_boolean_element_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

