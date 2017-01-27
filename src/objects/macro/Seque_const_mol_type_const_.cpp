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
 *   'macro.asn'.
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
#include <objects/macro/Seque_const_mol_type_const.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSequence_constraint_mol_type_constraint_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CSequence_constraint_mol_type_constraint_Base::ResetSelection(void)
{
    m_choice = e_not_set;
}

void CSequence_constraint_mol_type_constraint_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Rna:
        m_Rna = (ncbi::objects::ESequence_constraint_rnamol)(0);
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CSequence_constraint_mol_type_constraint_Base::sm_SelectionNames[] = {
    "not set",
    "any",
    "nucleotide",
    "dna",
    "rna",
    "protein"
};

NCBI_NS_STD::string CSequence_constraint_mol_type_constraint_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CSequence_constraint_mol_type_constraint_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Sequence-constraint-mol-type-constraint", CSequence_constraint_mol_type_constraint)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_NULL_CHOICE_VARIANT("any", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("nucleotide", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("dna", null, ());
    ADD_NAMED_ENUM_CHOICE_VARIANT("rna", m_Rna, ESequence_constraint_rnamol);
    ADD_NAMED_NULL_CHOICE_VARIANT("protein", null, ());
}
END_CHOICE_INFO

// constructor
CSequence_constraint_mol_type_constraint_Base::CSequence_constraint_mol_type_constraint_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CSequence_constraint_mol_type_constraint_Base::~CSequence_constraint_mol_type_constraint_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

