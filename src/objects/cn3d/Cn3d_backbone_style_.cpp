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
 *   'cn3d.asn'.
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
#include <objects/cn3d/Cn3d_backbone_style.hpp>
#include <objects/cn3d/Cn3d_color.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCn3d_backbone_style_Base::ResetUser_color(void)
{
    if ( !m_User_color ) {
        m_User_color.Reset(new TUser_color());
        return;
    }
    (*m_User_color).Reset();
}

void CCn3d_backbone_style_Base::SetUser_color(CCn3d_backbone_style_Base::TUser_color& value)
{
    m_User_color.Reset(&value);
}

void CCn3d_backbone_style_Base::Reset(void)
{
    ResetType();
    ResetStyle();
    ResetColor_scheme();
    ResetUser_color();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cn3d-backbone-style", CCn3d_backbone_style)
{
    SET_CLASS_MODULE("NCBI-Cn3d");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, ECn3d_backbone_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("style", m_Style, ECn3d_drawing_style)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("color-scheme", m_Color_scheme, ECn3d_color_scheme)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("user-color", m_User_color, CCn3d_color);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CCn3d_backbone_style_Base::CCn3d_backbone_style_Base(void)
    : m_Type((ncbi::objects::ECn3d_backbone_type)(0)), m_Style((ncbi::objects::ECn3d_drawing_style)(0)), m_Color_scheme((ncbi::objects::ECn3d_color_scheme)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetUser_color();
    }
}

// destructor
CCn3d_backbone_style_Base::~CCn3d_backbone_style_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

