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
 *   'mmdb1.asn'.
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
#include <objects/mmdb1/Biostruc_annot_set.hpp>
#include <objects/mmdb1/Biostruc_descr.hpp>
#include <objects/mmdb1/Biostruc_id.hpp>
#include <objects/mmdb3/Biostruc_feature_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_annot_set_Base::ResetId(void)
{
    m_Id.clear();
    m_set_State[0] &= ~0x3;
}

void CBiostruc_annot_set_Base::ResetDescr(void)
{
    m_Descr.clear();
    m_set_State[0] &= ~0xc;
}

void CBiostruc_annot_set_Base::ResetFeatures(void)
{
    m_Features.clear();
    m_set_State[0] &= ~0x30;
}

void CBiostruc_annot_set_Base::Reset(void)
{
    ResetId();
    ResetDescr();
    ResetFeatures();
}

BEGIN_NAMED_BASE_CLASS_INFO("Biostruc-annot-set", CBiostruc_annot_set)
{
    SET_CLASS_MODULE("MMDB");
    ADD_NAMED_MEMBER("id", m_Id, STL_list, (STL_CRef, (CLASS, (CBiostruc_id))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("descr", m_Descr, STL_list, (STL_CRef, (CLASS, (CBiostruc_descr))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("features", m_Features, STL_list, (STL_CRef, (CLASS, (CBiostruc_feature_set))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CBiostruc_annot_set_Base::CBiostruc_annot_set_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CBiostruc_annot_set_Base::~CBiostruc_annot_set_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

