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
 *   'linkout.dtd'.
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
#include <objtools/eutils/linkout/Strip.hpp>
#include <objtools/eutils/linkout/Apad.hpp>
#include <objtools/eutils/linkout/Normalize.hpp>
#include <objtools/eutils/linkout/Pad.hpp>
#include <objtools/eutils/linkout/Subs.hpp>
#include <objtools/eutils/linkout/Tolower.hpp>
#include <objtools/eutils/linkout/Toupper.hpp>
BEGIN_linkout_SCOPE // namespace linkout::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CStrip_Base::C_Attlist::, EAttlist_what, false)
{
    SET_ENUM_INTERNAL_NAME("strip.Attlist", "what");
    SET_ENUM_MODULE("linkout");
    ADD_ENUM_VALUE("spaces", eAttlist_what_spaces);
    ADD_ENUM_VALUE("letters", eAttlist_what_letters);
    ADD_ENUM_VALUE("nondigits", eAttlist_what_nondigits);
    ADD_ENUM_VALUE("digits", eAttlist_what_digits);
}
END_ENUM_INFO

void CStrip_Base::C_Attlist::Reset(void)
{
    ResetWhat();
}

BEGIN_NAMED_CLASS_INFO("", CStrip_Base::C_Attlist)
{
    SET_INTERNAL_NAME("strip", "Attlist");
    SET_CLASS_MODULE("linkout");
    ADD_NAMED_ENUM_MEMBER("what", m_What, EAttlist_what)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CStrip_Base::C_Attlist::C_Attlist(void)
    : m_What((EAttlist_what)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CStrip_Base::C_Attlist::~C_Attlist(void)
{
}


void CStrip_Base::C_E_Strip::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CStrip_Base::C_E_Strip::ResetSelection(void)
{
    switch ( m_choice ) {
    case e__CharData:
        m_string.Destruct();
        break;
    case e_Pad:
    case e_Apad:
    case e_Subs:
    case e_Toupper:
    case e_Tolower:
    case e_Strip:
    case e_Normalize:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CStrip_Base::C_E_Strip::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Pad:
        (m_object = new(pool) linkout::CPad())->AddReference();
        break;
    case e_Apad:
        (m_object = new(pool) linkout::CApad())->AddReference();
        break;
    case e_Subs:
        (m_object = new(pool) linkout::CSubs())->AddReference();
        break;
    case e_Toupper:
        (m_object = new(pool) linkout::CToupper())->AddReference();
        break;
    case e_Tolower:
        (m_object = new(pool) linkout::CTolower())->AddReference();
        break;
    case e_Strip:
        (m_object = new(pool) linkout::CStrip())->AddReference();
        break;
    case e_Normalize:
        (m_object = new(pool) linkout::CNormalize())->AddReference();
        break;
    case e__CharData:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CStrip_Base::C_E_Strip::sm_SelectionNames[] = {
    "not set",
    "_CharData",
    "pad",
    "apad",
    "subs",
    "toupper",
    "tolower",
    "strip",
    "normalize"
};

NCBI_NS_STD::string CStrip_Base::C_E_Strip::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CStrip_Base::C_E_Strip::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CStrip_Base::C_E_Strip::Set_CharData(const CStrip_Base::C_E_Strip::T_CharData& value)
{
    Select(e__CharData, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CStrip_Base::C_E_Strip::TPad& CStrip_Base::C_E_Strip::GetPad(void) const
{
    CheckSelected(e_Pad);
    return *static_cast<const TPad*>(m_object);
}

CStrip_Base::C_E_Strip::TPad& CStrip_Base::C_E_Strip::SetPad(void)
{
    Select(e_Pad, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TPad*>(m_object);
}

void CStrip_Base::C_E_Strip::SetPad(CStrip_Base::C_E_Strip::TPad& value)
{
    TPad* ptr = &value;
    if ( m_choice != e_Pad || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Pad;
    }
}

const CStrip_Base::C_E_Strip::TApad& CStrip_Base::C_E_Strip::GetApad(void) const
{
    CheckSelected(e_Apad);
    return *static_cast<const TApad*>(m_object);
}

CStrip_Base::C_E_Strip::TApad& CStrip_Base::C_E_Strip::SetApad(void)
{
    Select(e_Apad, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TApad*>(m_object);
}

void CStrip_Base::C_E_Strip::SetApad(CStrip_Base::C_E_Strip::TApad& value)
{
    TApad* ptr = &value;
    if ( m_choice != e_Apad || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Apad;
    }
}

const CStrip_Base::C_E_Strip::TSubs& CStrip_Base::C_E_Strip::GetSubs(void) const
{
    CheckSelected(e_Subs);
    return *static_cast<const TSubs*>(m_object);
}

CStrip_Base::C_E_Strip::TSubs& CStrip_Base::C_E_Strip::SetSubs(void)
{
    Select(e_Subs, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSubs*>(m_object);
}

void CStrip_Base::C_E_Strip::SetSubs(CStrip_Base::C_E_Strip::TSubs& value)
{
    TSubs* ptr = &value;
    if ( m_choice != e_Subs || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Subs;
    }
}

const CStrip_Base::C_E_Strip::TToupper& CStrip_Base::C_E_Strip::GetToupper(void) const
{
    CheckSelected(e_Toupper);
    return *static_cast<const TToupper*>(m_object);
}

CStrip_Base::C_E_Strip::TToupper& CStrip_Base::C_E_Strip::SetToupper(void)
{
    Select(e_Toupper, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TToupper*>(m_object);
}

void CStrip_Base::C_E_Strip::SetToupper(CStrip_Base::C_E_Strip::TToupper& value)
{
    TToupper* ptr = &value;
    if ( m_choice != e_Toupper || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Toupper;
    }
}

const CStrip_Base::C_E_Strip::TTolower& CStrip_Base::C_E_Strip::GetTolower(void) const
{
    CheckSelected(e_Tolower);
    return *static_cast<const TTolower*>(m_object);
}

CStrip_Base::C_E_Strip::TTolower& CStrip_Base::C_E_Strip::SetTolower(void)
{
    Select(e_Tolower, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTolower*>(m_object);
}

void CStrip_Base::C_E_Strip::SetTolower(CStrip_Base::C_E_Strip::TTolower& value)
{
    TTolower* ptr = &value;
    if ( m_choice != e_Tolower || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Tolower;
    }
}

const CStrip_Base::C_E_Strip::TStrip& CStrip_Base::C_E_Strip::GetStrip(void) const
{
    CheckSelected(e_Strip);
    return *static_cast<const TStrip*>(m_object);
}

CStrip_Base::C_E_Strip::TStrip& CStrip_Base::C_E_Strip::SetStrip(void)
{
    Select(e_Strip, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TStrip*>(m_object);
}

void CStrip_Base::C_E_Strip::SetStrip(CStrip_Base::C_E_Strip::TStrip& value)
{
    TStrip* ptr = &value;
    if ( m_choice != e_Strip || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Strip;
    }
}

const CStrip_Base::C_E_Strip::TNormalize& CStrip_Base::C_E_Strip::GetNormalize(void) const
{
    CheckSelected(e_Normalize);
    return *static_cast<const TNormalize*>(m_object);
}

CStrip_Base::C_E_Strip::TNormalize& CStrip_Base::C_E_Strip::SetNormalize(void)
{
    Select(e_Normalize, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TNormalize*>(m_object);
}

void CStrip_Base::C_E_Strip::SetNormalize(CStrip_Base::C_E_Strip::TNormalize& value)
{
    TNormalize* ptr = &value;
    if ( m_choice != e_Normalize || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Normalize;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CStrip_Base::C_E_Strip)
{
    SET_INTERNAL_NAME("strip.strip", "E");
    SET_CHOICE_MODULE("linkout");
    ADD_NAMED_BUF_CHOICE_VARIANT("_CharData", m_string, STD, (NCBI_NS_STD::string))->SetNoPrefix()->SetNotag();
    ADD_NAMED_REF_CHOICE_VARIANT("pad", m_object, CPad)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("apad", m_object, CApad)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("subs", m_object, CSubs)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("toupper", m_object, CToupper)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("tolower", m_object, CTolower)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("strip", m_object, CStrip)->SetNoPrefix();
    ADD_NAMED_REF_CHOICE_VARIANT("normalize", m_object, CNormalize)->SetNoPrefix();
}
END_CHOICE_INFO

// constructor
CStrip_Base::C_E_Strip::C_E_Strip(void)
    : m_choice(e_not_set)
{
}

// destructor
CStrip_Base::C_E_Strip::~C_E_Strip(void)
{
    Reset();
}


void CStrip_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CStrip_Base::SetAttlist(CStrip_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
}

void CStrip_Base::ResetStrip(void)
{
    m_Strip.clear();
    m_set_State[0] &= ~0xc;
}

void CStrip_Base::Reset(void)
{
    ResetAttlist();
    ResetStrip();
}

BEGIN_NAMED_BASE_CLASS_INFO("strip", CStrip)
{
    SET_CLASS_MODULE("linkout");
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_MEMBER("strip", m_Strip, STL_list, (STL_CRef, (CLASS, (C_E_Strip))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix()->SetNotag();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CStrip_Base::CStrip_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
    }
}

// destructor
CStrip_Base::~CStrip_Base(void)
{
}



END_linkout_SCOPE // namespace linkout::

