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
 *   'seq.asn'.
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
#include <objects/seq/Seq_ext.hpp>
#include <objects/seq/Delta_ext.hpp>
#include <objects/seq/Map_ext.hpp>
#include <objects/seq/Ref_ext.hpp>
#include <objects/seq/Seg_ext.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSeq_ext_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CSeq_ext_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Seg:
    case e_Ref:
    case e_Map:
    case e_Delta:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CSeq_ext_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Seg:
        (m_object = new(pool) ncbi::objects::CSeg_ext())->AddReference();
        break;
    case e_Ref:
        (m_object = new(pool) ncbi::objects::CRef_ext())->AddReference();
        break;
    case e_Map:
        (m_object = new(pool) ncbi::objects::CMap_ext())->AddReference();
        break;
    case e_Delta:
        (m_object = new(pool) ncbi::objects::CDelta_ext())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CSeq_ext_Base::sm_SelectionNames[] = {
    "not set",
    "seg",
    "ref",
    "map",
    "delta"
};

NCBI_NS_STD::string CSeq_ext_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CSeq_ext_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CSeq_ext_Base::TSeg& CSeq_ext_Base::GetSeg(void) const
{
    CheckSelected(e_Seg);
    return *static_cast<const TSeg*>(m_object);
}

CSeq_ext_Base::TSeg& CSeq_ext_Base::SetSeg(void)
{
    Select(e_Seg, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSeg*>(m_object);
}

void CSeq_ext_Base::SetSeg(CSeq_ext_Base::TSeg& value)
{
    TSeg* ptr = &value;
    if ( m_choice != e_Seg || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Seg;
    }
}

const CSeq_ext_Base::TRef& CSeq_ext_Base::GetRef(void) const
{
    CheckSelected(e_Ref);
    return *static_cast<const TRef*>(m_object);
}

CSeq_ext_Base::TRef& CSeq_ext_Base::SetRef(void)
{
    Select(e_Ref, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TRef*>(m_object);
}

void CSeq_ext_Base::SetRef(CSeq_ext_Base::TRef& value)
{
    TRef* ptr = &value;
    if ( m_choice != e_Ref || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Ref;
    }
}

const CSeq_ext_Base::TMap& CSeq_ext_Base::GetMap(void) const
{
    CheckSelected(e_Map);
    return *static_cast<const TMap*>(m_object);
}

CSeq_ext_Base::TMap& CSeq_ext_Base::SetMap(void)
{
    Select(e_Map, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMap*>(m_object);
}

void CSeq_ext_Base::SetMap(CSeq_ext_Base::TMap& value)
{
    TMap* ptr = &value;
    if ( m_choice != e_Map || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Map;
    }
}

const CSeq_ext_Base::TDelta& CSeq_ext_Base::GetDelta(void) const
{
    CheckSelected(e_Delta);
    return *static_cast<const TDelta*>(m_object);
}

CSeq_ext_Base::TDelta& CSeq_ext_Base::SetDelta(void)
{
    Select(e_Delta, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TDelta*>(m_object);
}

void CSeq_ext_Base::SetDelta(CSeq_ext_Base::TDelta& value)
{
    TDelta* ptr = &value;
    if ( m_choice != e_Delta || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Delta;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Seq-ext", CSeq_ext)
{
    SET_CHOICE_MODULE("NCBI-Sequence");
    ADD_NAMED_REF_CHOICE_VARIANT("seg", m_object, CSeg_ext);
    ADD_NAMED_REF_CHOICE_VARIANT("ref", m_object, CRef_ext);
    ADD_NAMED_REF_CHOICE_VARIANT("map", m_object, CMap_ext);
    ADD_NAMED_REF_CHOICE_VARIANT("delta", m_object, CDelta_ext);
}
END_CHOICE_INFO

// constructor
CSeq_ext_Base::CSeq_ext_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CSeq_ext_Base::~CSeq_ext_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

