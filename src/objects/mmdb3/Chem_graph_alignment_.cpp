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
#include <objects/mmdb3/Chem_graph_alignment.hpp>
#include <objects/mmdb1/Biostruc_id.hpp>
#include <objects/mmdb3/Align_stats.hpp>
#include <objects/mmdb3/Chem_graph_pntrs.hpp>
#include <objects/mmdb3/Transform.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CChem_graph_alignment_Base::ResetBiostruc_ids(void)
{
    m_Biostruc_ids.clear();
    m_set_State[0] &= ~0xc;
}

void CChem_graph_alignment_Base::ResetAlignment(void)
{
    m_Alignment.clear();
    m_set_State[0] &= ~0x30;
}

void CChem_graph_alignment_Base::ResetDomain(void)
{
    m_Domain.clear();
    m_set_State[0] &= ~0xc0;
}

void CChem_graph_alignment_Base::ResetTransform(void)
{
    m_Transform.clear();
    m_set_State[0] &= ~0x300;
}

void CChem_graph_alignment_Base::ResetAligndata(void)
{
    m_Aligndata.clear();
    m_set_State[0] &= ~0xc00;
}

void CChem_graph_alignment_Base::Reset(void)
{
    ResetDimension();
    ResetBiostruc_ids();
    ResetAlignment();
    ResetDomain();
    ResetTransform();
    ResetAligndata();
}

BEGIN_NAMED_BASE_CLASS_INFO("Chem-graph-alignment", CChem_graph_alignment)
{
    SET_CLASS_MODULE("MMDB-Features");
    ADD_NAMED_STD_MEMBER("dimension", m_Dimension)->SetDefault(new TDimension(2))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("biostruc-ids", m_Biostruc_ids, STL_list, (STL_CRef, (CLASS, (CBiostruc_id))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("alignment", m_Alignment, STL_list, (STL_CRef, (CLASS, (CChem_graph_pntrs))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("domain", m_Domain, STL_list, (STL_CRef, (CLASS, (CChem_graph_pntrs))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("transform", m_Transform, STL_list, (STL_CRef, (CLASS, (CTransform))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("aligndata", m_Aligndata, STL_list, (STL_CRef, (CLASS, (CAlign_stats))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CChem_graph_alignment_Base::CChem_graph_alignment_Base(void)
    : m_Dimension(2)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CChem_graph_alignment_Base::~CChem_graph_alignment_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

