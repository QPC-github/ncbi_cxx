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
#include <objects/pcsubstance/PC_StereoTrigonalBiPyramid.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_StereoTrigonalBiPyramid_Base::Reset(void)
{
    ResetCenter();
    ResetAbove();
    ResetBelow();
    ResetTop();
    ResetBottom();
    ResetRight();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-StereoTrigonalBiPyramid", CPC_StereoTrigonalBiPyramid)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_STD_MEMBER("center", m_Center)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("above", m_Above)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("below", m_Below)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("top", m_Top)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("bottom", m_Bottom)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("right", m_Right)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPC_StereoTrigonalBiPyramid_Base::CPC_StereoTrigonalBiPyramid_Base(void)
    : m_Center(0), m_Above(0), m_Below(0), m_Top(0), m_Bottom(0), m_Right(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_StereoTrigonalBiPyramid_Base::~CPC_StereoTrigonalBiPyramid_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

