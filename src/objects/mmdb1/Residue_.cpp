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
#include <objects/mmdb1/Residue.hpp>
#include <objects/mmdb1/Residue_graph_pntr.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CResidue_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0xc;
}

void CResidue_Base::ResetResidue_graph(void)
{
    if ( !m_Residue_graph ) {
        m_Residue_graph.Reset(new TResidue_graph());
        return;
    }
    (*m_Residue_graph).Reset();
}

void CResidue_Base::SetResidue_graph(CResidue_Base::TResidue_graph& value)
{
    m_Residue_graph.Reset(&value);
}

void CResidue_Base::Reset(void)
{
    ResetId();
    ResetName();
    ResetResidue_graph();
}

BEGIN_NAMED_BASE_CLASS_INFO("Residue", CResidue)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_MEMBER("id", m_Id, CLASS, (CResidue_id))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("residue-graph", m_Residue_graph, CResidue_graph_pntr);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CResidue_Base::CResidue_Base(void)
    : m_Id(CResidue_id(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetResidue_graph();
    }
}

// destructor
CResidue_Base::~CResidue_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

