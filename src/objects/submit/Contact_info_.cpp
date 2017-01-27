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
 *   'submit.asn'.
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
#include <objects/submit/Contact_info.hpp>
#include <objects/biblio/Author.hpp>
#include <objects/general/Object_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CContact_info_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0x3;
}

void CContact_info_Base::ResetAddress(void)
{
    m_Address.clear();
    m_set_State[0] &= ~0xc;
}

void CContact_info_Base::ResetPhone(void)
{
    m_Phone.erase();
    m_set_State[0] &= ~0x30;
}

void CContact_info_Base::ResetFax(void)
{
    m_Fax.erase();
    m_set_State[0] &= ~0xc0;
}

void CContact_info_Base::ResetEmail(void)
{
    m_Email.erase();
    m_set_State[0] &= ~0x300;
}

void CContact_info_Base::ResetTelex(void)
{
    m_Telex.erase();
    m_set_State[0] &= ~0xc00;
}

void CContact_info_Base::ResetOwner_id(void)
{
    m_Owner_id.Reset();
}

void CContact_info_Base::SetOwner_id(CContact_info_Base::TOwner_id& value)
{
    m_Owner_id.Reset(&value);
}

CContact_info_Base::TOwner_id& CContact_info_Base::SetOwner_id(void)
{
    if ( !m_Owner_id )
        m_Owner_id.Reset(new ncbi::objects::CObject_id());
    return (*m_Owner_id);
}

void CContact_info_Base::ResetPassword(void)
{
    m_Password.clear();
    m_set_State[0] &= ~0xc000;
}

void CContact_info_Base::ResetLast_name(void)
{
    m_Last_name.erase();
    m_set_State[0] &= ~0x30000;
}

void CContact_info_Base::ResetFirst_name(void)
{
    m_First_name.erase();
    m_set_State[0] &= ~0xc0000;
}

void CContact_info_Base::ResetMiddle_initial(void)
{
    m_Middle_initial.erase();
    m_set_State[0] &= ~0x300000;
}

void CContact_info_Base::ResetContact(void)
{
    m_Contact.Reset();
}

void CContact_info_Base::SetContact(CContact_info_Base::TContact& value)
{
    m_Contact.Reset(&value);
}

CContact_info_Base::TContact& CContact_info_Base::SetContact(void)
{
    if ( !m_Contact )
        m_Contact.Reset(new ncbi::objects::CAuthor());
    return (*m_Contact);
}

void CContact_info_Base::Reset(void)
{
    ResetName();
    ResetAddress();
    ResetPhone();
    ResetFax();
    ResetEmail();
    ResetTelex();
    ResetOwner_id();
    ResetPassword();
    ResetLast_name();
    ResetFirst_name();
    ResetMiddle_initial();
    ResetContact();
}

BEGIN_NAMED_BASE_CLASS_INFO("Contact-info", CContact_info)
{
    SET_CLASS_MODULE("NCBI-Submit");
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("address", m_Address, STL_list, (STD, (string)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("phone", m_Phone)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("fax", m_Fax)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("email", m_Email)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("telex", m_Telex)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("owner-id", m_Owner_id, CObject_id)->SetOptional();
    ADD_NAMED_MEMBER("password", m_Password, STL_CHAR_vector, (char))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("last-name", m_Last_name)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("first-name", m_First_name)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("middle-initial", m_Middle_initial)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("contact", m_Contact, CAuthor)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CContact_info_Base::CContact_info_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CContact_info_Base::~CContact_info_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

