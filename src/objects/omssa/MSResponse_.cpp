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
 *   'omssa.asn'.
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
#include <objects/omssa/MSResponse.hpp>
#include <objects/omssa/MSBioseqSet.hpp>
#include <objects/omssa/MSHitSet.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMSResponse_Base::ResetHitsets(void)
{
    m_Hitsets.clear();
    m_set_State[0] &= ~0x3;
}

void CMSResponse_Base::ResetRid(void)
{
    m_Rid.erase();
    m_set_State[0] &= ~0x30;
}

void CMSResponse_Base::ResetVersion(void)
{
    m_Version.erase();
    m_set_State[0] &= ~0x300;
}

void CMSResponse_Base::ResetEmail(void)
{
    m_Email.erase();
    m_set_State[0] &= ~0xc00;
}

void CMSResponse_Base::ResetBioseqs(void)
{
    m_Bioseqs.Reset();
}

void CMSResponse_Base::SetBioseqs(CMSResponse_Base::TBioseqs& value)
{
    m_Bioseqs.Reset(&value);
}

CMSResponse_Base::TBioseqs& CMSResponse_Base::SetBioseqs(void)
{
    if ( !m_Bioseqs )
        m_Bioseqs.Reset(new ncbi::objects::CMSBioseqSet());
    return (*m_Bioseqs);
}

void CMSResponse_Base::Reset(void)
{
    ResetHitsets();
    ResetScale();
    ResetRid();
    ResetError();
    ResetVersion();
    ResetEmail();
    ResetDbversion();
    ResetBioseqs();
}

BEGIN_NAMED_BASE_CLASS_INFO("MSResponse", CMSResponse)
{
    SET_CLASS_MODULE("OMSSA");
    ADD_NAMED_MEMBER("hitsets", m_Hitsets, STL_vector, (STL_CRef, (CLASS, (CMSHitSet))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("scale", m_Scale)->SetDefault(new TScale(100))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rid", m_Rid)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("error", m_Error, EMSResponseError)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("version", m_Version)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("email", m_Email)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("dbversion", m_Dbversion)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("bioseqs", m_Bioseqs, CMSBioseqSet)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CMSResponse_Base::CMSResponse_Base(void)
    : m_Scale(100), m_Error((int)(0)), m_Dbversion(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMSResponse_Base::~CMSResponse_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

