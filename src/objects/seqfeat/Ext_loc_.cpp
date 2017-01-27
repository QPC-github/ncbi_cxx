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
 *   'seqfeat.asn'.
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
#include <objects/seqfeat/Ext_loc.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/seqloc/Seq_loc.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CExt_loc_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CExt_loc_Base::SetId(CExt_loc_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CExt_loc_Base::ResetLocation(void)
{
    if ( !m_Location ) {
        m_Location.Reset(new TLocation());
        return;
    }
    (*m_Location).Reset();
}

void CExt_loc_Base::SetLocation(CExt_loc_Base::TLocation& value)
{
    m_Location.Reset(&value);
}

void CExt_loc_Base::Reset(void)
{
    ResetId();
    ResetLocation();
}

BEGIN_NAMED_BASE_CLASS_INFO("Ext-loc", CExt_loc)
{
    SET_CLASS_MODULE("NCBI-Variation");
    ADD_NAMED_REF_MEMBER("id", m_Id, CObject_id);
    ADD_NAMED_REF_MEMBER("location", m_Location, CSeq_loc);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CExt_loc_Base::CExt_loc_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
        ResetLocation();
    }
}

// destructor
CExt_loc_Base::~CExt_loc_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

