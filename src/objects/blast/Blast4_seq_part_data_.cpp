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
 *   'blast.asn'.
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
#include <objects/blast/Blast4_seq_part_data.hpp>
#include <objects/seq/Seq_data.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_seq_part_data_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CBlast4_seq_part_data_Base::SetId(CBlast4_seq_part_data_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CBlast4_seq_part_data_Base::ResetData(void)
{
    if ( !m_Data ) {
        m_Data.Reset(new TData());
        return;
    }
    (*m_Data).Reset();
}

void CBlast4_seq_part_data_Base::SetData(CBlast4_seq_part_data_Base::TData& value)
{
    m_Data.Reset(&value);
}

void CBlast4_seq_part_data_Base::Reset(void)
{
    ResetId();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-seq-part-data", CBlast4_seq_part_data)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_REF_MEMBER("id", m_Id, CSeq_id);
    ADD_NAMED_REF_MEMBER("data", m_Data, CSeq_data);
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CBlast4_seq_part_data_Base::CBlast4_seq_part_data_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
        ResetData();
    }
}

// destructor
CBlast4_seq_part_data_Base::~CBlast4_seq_part_data_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

