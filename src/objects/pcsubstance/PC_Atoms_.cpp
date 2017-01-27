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
 *   'pcsubstance.asn'.
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
#include <objects/pcsubstance/PC_Atoms.hpp>
#include <objects/pcsubstance/PC_AtomInt.hpp>
#include <objects/pcsubstance/PC_AtomRadical.hpp>
#include <objects/pcsubstance/PC_AtomSource.hpp>
#include <objects/pcsubstance/PC_AtomString.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_Atoms_Base::ResetAid(void)
{
    m_Aid.clear();
    m_set_State[0] &= ~0x3;
}

void CPC_Atoms_Base::ResetElement(void)
{
    m_Element.clear();
    m_set_State[0] &= ~0xc;
}

void CPC_Atoms_Base::ResetLabel(void)
{
    m_Label.clear();
    m_set_State[0] &= ~0x30;
}

void CPC_Atoms_Base::ResetIsotope(void)
{
    m_Isotope.clear();
    m_set_State[0] &= ~0xc0;
}

void CPC_Atoms_Base::ResetCharge(void)
{
    m_Charge.clear();
    m_set_State[0] &= ~0x300;
}

void CPC_Atoms_Base::ResetRadical(void)
{
    m_Radical.clear();
    m_set_State[0] &= ~0xc00;
}

void CPC_Atoms_Base::ResetSource(void)
{
    m_Source.clear();
    m_set_State[0] &= ~0x3000;
}

void CPC_Atoms_Base::ResetComment(void)
{
    m_Comment.clear();
    m_set_State[0] &= ~0xc000;
}

void CPC_Atoms_Base::Reset(void)
{
    ResetAid();
    ResetElement();
    ResetLabel();
    ResetIsotope();
    ResetCharge();
    ResetRadical();
    ResetSource();
    ResetComment();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-Atoms", CPC_Atoms)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_MEMBER("aid", m_Aid, STL_vector, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("element", m_Element, STL_vector, (ENUM, (int, EPC_Element)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("label", m_Label, STL_list, (STL_CRef, (CLASS, (CPC_AtomString))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("isotope", m_Isotope, STL_list, (STL_CRef, (CLASS, (CPC_AtomInt))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("charge", m_Charge, STL_list, (STL_CRef, (CLASS, (CPC_AtomInt))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("radical", m_Radical, STL_list, (STL_CRef, (CLASS, (CPC_AtomRadical))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("source", m_Source, STL_list, (STL_CRef, (CLASS, (CPC_AtomSource))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("comment", m_Comment, STL_list, (STL_CRef, (CLASS, (CPC_AtomString))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPC_Atoms_Base::CPC_Atoms_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_Atoms_Base::~CPC_Atoms_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

