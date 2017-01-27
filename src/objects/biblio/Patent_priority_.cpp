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
 *   'biblio.asn'.
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
#include <objects/biblio/Patent_priority.hpp>
#include <objects/general/Date.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPatent_priority_Base::ResetCountry(void)
{
    m_Country.erase();
    m_set_State[0] &= ~0x3;
}

void CPatent_priority_Base::ResetNumber(void)
{
    m_Number.erase();
    m_set_State[0] &= ~0xc;
}

void CPatent_priority_Base::ResetDate(void)
{
    if ( !m_Date ) {
        m_Date.Reset(new TDate());
        return;
    }
    (*m_Date).Reset();
}

void CPatent_priority_Base::SetDate(CPatent_priority_Base::TDate& value)
{
    m_Date.Reset(&value);
}

void CPatent_priority_Base::Reset(void)
{
    ResetCountry();
    ResetNumber();
    ResetDate();
}

BEGIN_NAMED_BASE_CLASS_INFO("Patent-priority", CPatent_priority)
{
    SET_CLASS_MODULE("NCBI-Biblio");
    ADD_NAMED_STD_MEMBER("country", m_Country)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("number", m_Number)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("date", m_Date, CDate);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPatent_priority_Base::CPatent_priority_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetDate();
    }
}

// destructor
CPatent_priority_Base::~CPatent_priority_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

