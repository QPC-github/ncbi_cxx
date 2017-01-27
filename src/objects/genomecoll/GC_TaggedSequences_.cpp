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
 *   'genome_collection.asn'.
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
#include <objects/genomecoll/GC_TaggedSequences.hpp>
#include <objects/genomecoll/GC_Sequence.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGC_TaggedSequences_Base::, EState, true)
{
    SET_ENUM_INTERNAL_NAME("GC-TaggedSequences", "state");
    SET_ENUM_MODULE("NCBI-GenomeCollection");
    ADD_ENUM_VALUE("not-set", eState_not_set);
    ADD_ENUM_VALUE("placed", eState_placed);
    ADD_ENUM_VALUE("unlocalized", eState_unlocalized);
    ADD_ENUM_VALUE("unplaced", eState_unplaced);
    ADD_ENUM_VALUE("aligned", eState_aligned);
    ADD_ENUM_VALUE("bits", eState_bits);
}
END_ENUM_INFO

void CGC_TaggedSequences_Base::ResetSeqs(void)
{
    m_Seqs.clear();
    m_set_State[0] &= ~0xc;
}

void CGC_TaggedSequences_Base::Reset(void)
{
    ResetState();
    ResetSeqs();
}

BEGIN_NAMED_BASE_CLASS_INFO("GC-TaggedSequences", CGC_TaggedSequences)
{
    SET_CLASS_MODULE("NCBI-GenomeCollection");
    ADD_NAMED_ENUM_MEMBER("state", m_State, EState)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("seqs", m_Seqs, STL_list_set, (STL_CRef, (CLASS, (CGC_Sequence))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CGC_TaggedSequences_Base::CGC_TaggedSequences_Base(void)
    : m_State((EState)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGC_TaggedSequences_Base::~CGC_TaggedSequences_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

