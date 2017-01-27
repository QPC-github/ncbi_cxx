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
#include <objects/macro/Rna_feat_type.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CRna_feat_type_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CRna_feat_type_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_NcRNA:
        m_string.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CRna_feat_type_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_NcRNA:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CRna_feat_type_Base::sm_SelectionNames[] = {
    "not set",
    "any",
    "preRNA",
    "mRNA",
    "tRNA",
    "rRNA",
    "ncRNA",
    "tmRNA",
    "miscRNA"
};

NCBI_NS_STD::string CRna_feat_type_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CRna_feat_type_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CRna_feat_type_Base::SetNcRNA(const CRna_feat_type_Base::TNcRNA& value)
{
    Select(e_NcRNA, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Rna-feat-type", CRna_feat_type)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_NULL_CHOICE_VARIANT("any", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("preRNA", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("mRNA", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("tRNA", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("rRNA", null, ());
    ADD_NAMED_BUF_CHOICE_VARIANT("ncRNA", m_string, STD, (string));
    ADD_NAMED_NULL_CHOICE_VARIANT("tmRNA", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("miscRNA", null, ());
}
END_CHOICE_INFO

// constructor
CRna_feat_type_Base::CRna_feat_type_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CRna_feat_type_Base::~CRna_feat_type_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

