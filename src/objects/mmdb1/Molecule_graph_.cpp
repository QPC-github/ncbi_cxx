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
#include <objects/mmdb1/Molecule_graph.hpp>
#include <objects/mmdb1/Biomol_descr.hpp>
#include <objects/mmdb1/Inter_residue_bond.hpp>
#include <objects/mmdb1/Residue.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMolecule_graph_Base::ResetDescr(void)
{
    m_Descr.clear();
    m_set_State[0] &= ~0xc;
}

void CMolecule_graph_Base::ResetSeq_id(void)
{
    m_Seq_id.Reset();
}

void CMolecule_graph_Base::SetSeq_id(CMolecule_graph_Base::TSeq_id& value)
{
    m_Seq_id.Reset(&value);
}

CMolecule_graph_Base::TSeq_id& CMolecule_graph_Base::SetSeq_id(void)
{
    if ( !m_Seq_id )
        m_Seq_id.Reset(new ncbi::objects::CSeq_id());
    return (*m_Seq_id);
}

void CMolecule_graph_Base::ResetResidue_sequence(void)
{
    m_Residue_sequence.clear();
    m_set_State[0] &= ~0xc0;
}

void CMolecule_graph_Base::ResetInter_residue_bonds(void)
{
    m_Inter_residue_bonds.clear();
    m_set_State[0] &= ~0x300;
}

void CMolecule_graph_Base::Reset(void)
{
    ResetId();
    ResetDescr();
    ResetSeq_id();
    ResetResidue_sequence();
    ResetInter_residue_bonds();
    ResetSid();
}

BEGIN_NAMED_BASE_CLASS_INFO("Molecule-graph", CMolecule_graph)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_MEMBER("id", m_Id, CLASS, (CMolecule_id))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("descr", m_Descr, STL_list, (STL_CRef, (CLASS, (CBiomol_descr))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("seq-id", m_Seq_id, CSeq_id)->SetOptional();
    ADD_NAMED_MEMBER("residue-sequence", m_Residue_sequence, STL_list, (STL_CRef, (CLASS, (CResidue))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("inter-residue-bonds", m_Inter_residue_bonds, STL_list, (STL_CRef, (CLASS, (CInter_residue_bond))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("sid", m_Sid, CLASS, (CPCSubstance_id))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CMolecule_graph_Base::CMolecule_graph_Base(void)
    : m_Id(CMolecule_id(0)), m_Sid(CPCSubstance_id(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMolecule_graph_Base::~CMolecule_graph_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
