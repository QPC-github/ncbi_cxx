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
 *   'mmdb3.asn'.
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
#include <objects/mmdb3/Camera.hpp>
#include <objects/mmdb3/GL_matrix.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCamera_Base::ResetModelview(void)
{
    if ( !m_Modelview ) {
        m_Modelview.Reset(new TModelview());
        return;
    }
    (*m_Modelview).Reset();
}

void CCamera_Base::SetModelview(CCamera_Base::TModelview& value)
{
    m_Modelview.Reset(&value);
}

void CCamera_Base::Reset(void)
{
    ResetX();
    ResetY();
    ResetDistance();
    ResetAngle();
    ResetScale();
    ResetModelview();
}

BEGIN_NAMED_BASE_CLASS_INFO("Camera", CCamera)
{
    SET_CLASS_MODULE("MMDB-Features");
    ADD_NAMED_STD_MEMBER("x", m_X)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("y", m_Y)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("distance", m_Distance)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("angle", m_Angle)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("scale", m_Scale)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("modelview", m_Modelview, CGL_matrix);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CCamera_Base::CCamera_Base(void)
    : m_X(0), m_Y(0), m_Distance(0), m_Angle(0), m_Scale(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetModelview();
    }
}

// destructor
CCamera_Base::~CCamera_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

