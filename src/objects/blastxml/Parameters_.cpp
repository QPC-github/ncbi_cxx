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
 *   'blastxml.asn'.
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
#include <objects/blastxml/Parameters.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CParameters_Base::ResetMatrix(void)
{
    m_Matrix.erase();
    m_set_State[0] &= ~0x3;
}

void CParameters_Base::ResetFilter(void)
{
    m_Filter.erase();
    m_set_State[0] &= ~0xc000;
}

void CParameters_Base::ResetPattern(void)
{
    m_Pattern.erase();
    m_set_State[0] &= ~0x30000;
}

void CParameters_Base::ResetEntrez_query(void)
{
    m_Entrez_query.erase();
    m_set_State[0] &= ~0xc0000;
}

void CParameters_Base::Reset(void)
{
    ResetMatrix();
    ResetExpect();
    ResetInclude();
    ResetSc_match();
    ResetSc_mismatch();
    ResetGap_open();
    ResetGap_extend();
    ResetFilter();
    ResetPattern();
    ResetEntrez_query();
}

BEGIN_NAMED_BASE_CLASS_INFO("Parameters", CParameters)
{
    SET_CLASS_MODULE("NCBI-BlastOutput");
    ADD_NAMED_STD_MEMBER("matrix", m_Matrix)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("expect", m_Expect)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("include", m_Include)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("sc-match", m_Sc_match)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("sc-mismatch", m_Sc_mismatch)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("gap-open", m_Gap_open)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("gap-extend", m_Gap_extend)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("filter", m_Filter)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("pattern", m_Pattern)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("entrez-query", m_Entrez_query)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CParameters_Base::CParameters_Base(void)
    : m_Expect(0), m_Include(0), m_Sc_match(0), m_Sc_mismatch(0), m_Gap_open(0), m_Gap_extend(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CParameters_Base::~CParameters_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

