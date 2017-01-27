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
 *   'pepXML.xsd'.
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
#include <algo/ms/formats/pepxml/Aminoacid_modification.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CAminoacid_modification_Base::C_Attlist::ResetAminoacid(void)
{
    m_Aminoacid.erase();
    m_set_State[0] &= ~0x3;
}

void CAminoacid_modification_Base::C_Attlist::ResetMassdiff(void)
{
    m_Massdiff.erase();
    m_set_State[0] &= ~0xc;
}

void CAminoacid_modification_Base::C_Attlist::ResetVariable(void)
{
    m_Variable.erase();
    m_set_State[0] &= ~0xc0;
}

void CAminoacid_modification_Base::C_Attlist::ResetPeptide_terminus(void)
{
    m_Peptide_terminus.erase();
    m_set_State[0] &= ~0x300;
}

void CAminoacid_modification_Base::C_Attlist::ResetSymbol(void)
{
    m_Symbol.erase();
    m_set_State[0] &= ~0xc00;
}

void CAminoacid_modification_Base::C_Attlist::ResetBinary(void)
{
    m_Binary.erase();
    m_set_State[0] &= ~0x3000;
}

void CAminoacid_modification_Base::C_Attlist::ResetDescription(void)
{
    m_Description.erase();
    m_set_State[0] &= ~0xc000;
}

void CAminoacid_modification_Base::C_Attlist::Reset(void)
{
    ResetAminoacid();
    ResetMassdiff();
    ResetMass();
    ResetVariable();
    ResetPeptide_terminus();
    ResetSymbol();
    ResetBinary();
    ResetDescription();
}

BEGIN_NAMED_CLASS_INFO("", CAminoacid_modification_Base::C_Attlist)
{
    SET_INTERNAL_NAME("aminoacid_modification", "Attlist");
    SET_CLASS_MODULE("pepXML");
    ADD_NAMED_STD_MEMBER("aminoacid", m_Aminoacid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("massdiff", m_Massdiff)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("mass", m_Mass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("variable", m_Variable)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("peptide_terminus", m_Peptide_terminus)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("symbol", m_Symbol)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("binary", m_Binary)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    ADD_NAMED_STD_MEMBER("description", m_Description)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix();
    info->SetRandomOrder(true);
}
END_CLASS_INFO

// constructor
CAminoacid_modification_Base::C_Attlist::C_Attlist(void)
    : m_Mass(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CAminoacid_modification_Base::C_Attlist::~C_Attlist(void)
{
}


void CAminoacid_modification_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CAminoacid_modification_Base::SetAttlist(CAminoacid_modification_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
    SetAminoacid_modification();
}

void CAminoacid_modification_Base::Reset(void)
{
    ResetAttlist();
    ResetAminoacid_modification();
}

BEGIN_NAMED_BASE_CLASS_INFO("aminoacid_modification", CAminoacid_modification)
{
    SET_CLASS_MODULE("pepXML");
    SET_NAMESPACE("http://regis-web.systemsbiology.net/pepXML")->SetNsQualified(true);
    ADD_NAMED_REF_MEMBER("Attlist", m_Attlist, C_Attlist)->SetNoPrefix()->SetAttlist();
    ADD_NAMED_NULL_MEMBER("aminoacid_modification", null, ())->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetNoPrefix()->SetNotag();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CAminoacid_modification_Base::CAminoacid_modification_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
    }
}

// destructor
CAminoacid_modification_Base::~CAminoacid_modification_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

