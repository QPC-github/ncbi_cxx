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
#include <objects/pcsubstance/PC_Count.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_Count_Base::Reset(void)
{
    ResetHeavy_atom();
    ResetAtom_chiral();
    ResetAtom_chiral_def();
    ResetAtom_chiral_undef();
    ResetBond_chiral();
    ResetBond_chiral_def();
    ResetBond_chiral_undef();
    ResetIsotope_atom();
    ResetCovalent_unit();
    ResetTautomers();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-Count", CPC_Count)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_STD_MEMBER("heavy-atom", m_Heavy_atom)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("atom-chiral", m_Atom_chiral)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("atom-chiral-def", m_Atom_chiral_def)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("atom-chiral-undef", m_Atom_chiral_undef)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("bond-chiral", m_Bond_chiral)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("bond-chiral-def", m_Bond_chiral_def)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("bond-chiral-undef", m_Bond_chiral_undef)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("isotope-atom", m_Isotope_atom)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("covalent-unit", m_Covalent_unit)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("tautomers", m_Tautomers)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPC_Count_Base::CPC_Count_Base(void)
    : m_Heavy_atom(0), m_Atom_chiral(0), m_Atom_chiral_def(0), m_Atom_chiral_undef(0), m_Bond_chiral(0), m_Bond_chiral_def(0), m_Bond_chiral_undef(0), m_Isotope_atom(0), m_Covalent_unit(0), m_Tautomers(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_Count_Base::~CPC_Count_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

