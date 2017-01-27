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
 *   'taxon1.asn'.
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
#include <objects/taxon1/Taxon1_error.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CTaxon1_error_Base::, ELevel, false)
{
    SET_ENUM_INTERNAL_NAME("Taxon1-error", "level");
    SET_ENUM_MODULE("NCBI-Taxon1");
    ADD_ENUM_VALUE("none", eLevel_none);
    ADD_ENUM_VALUE("info", eLevel_info);
    ADD_ENUM_VALUE("warn", eLevel_warn);
    ADD_ENUM_VALUE("error", eLevel_error);
    ADD_ENUM_VALUE("fatal", eLevel_fatal);
}
END_ENUM_INFO

void CTaxon1_error_Base::ResetMsg(void)
{
    m_Msg.erase();
    m_set_State[0] &= ~0xc;
}

void CTaxon1_error_Base::Reset(void)
{
    ResetLevel();
    ResetMsg();
}

BEGIN_NAMED_BASE_CLASS_INFO("Taxon1-error", CTaxon1_error)
{
    SET_CLASS_MODULE("NCBI-Taxon1");
    ADD_NAMED_ENUM_MEMBER("level", m_Level, ELevel)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("msg", m_Msg)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CTaxon1_error_Base::CTaxon1_error_Base(void)
    : m_Level((ELevel)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CTaxon1_error_Base::~CTaxon1_error_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

