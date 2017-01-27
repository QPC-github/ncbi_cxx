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
 *   'seqsplit.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/seqsplit/NCBI_Seq_split_module.hpp>
#include <objects/seqsplit/ID2S_Bioseq_Ids.hpp>
#include <objects/seqsplit/ID2S_Bioseq_Info.hpp>
#include <objects/seqsplit/ID2S_Bioseq_place_Info.hpp>
#include <objects/seqsplit/ID2S_Bioseq_set_Ids.hpp>
#include <objects/seqsplit/ID2S_Bioseqs_Info.hpp>
#include <objects/seqsplit/ID2S_Chunk.hpp>
#include <objects/seqsplit/ID2S_Chunk_Content.hpp>
#include <objects/seqsplit/ID2S_Chunk_Data.hpp>
#include <objects/seqsplit/ID2S_Chunk_Info.hpp>
#include <objects/seqsplit/ID2S_Feat_type_Info.hpp>
#include <objects/seqsplit/ID2S_Gi_Interval.hpp>
#include <objects/seqsplit/ID2S_Gi_Ints.hpp>
#include <objects/seqsplit/ID2S_Gi_Range.hpp>
#include <objects/seqsplit/ID2S_Interval.hpp>
#include <objects/seqsplit/ID2S_Seq_annot_Info.hpp>
#include <objects/seqsplit/ID2S_Seq_annot_place_Info.hpp>
#include <objects/seqsplit/ID2S_Seq_assembly_Info.hpp>
#include <objects/seqsplit/ID2S_Seq_descr_Info.hpp>
#include <objects/seqsplit/ID2S_Seq_feat_Ids_Info.hpp>
#include <objects/seqsplit/ID2S_Seq_id_Interval.hpp>
#include <objects/seqsplit/ID2S_Seq_id_Ints.hpp>
#include <objects/seqsplit/ID2S_Seq_loc.hpp>
#include <objects/seqsplit/ID2S_Sequence_Piece.hpp>
#include <objects/seqsplit/ID2S_Split_Info.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_Seq_split_RegisterModuleClasses(void)
{
    ncbi::objects::CID2S_Bioseq_Ids::GetTypeInfo();
    ncbi::objects::CID2S_Bioseq_Info::GetTypeInfo();
    ncbi::objects::CID2S_Bioseq_place_Info::GetTypeInfo();
    ncbi::objects::CID2S_Bioseq_set_Ids::GetTypeInfo();
    ncbi::objects::CID2S_Bioseqs_Info::GetTypeInfo();
    ncbi::objects::CID2S_Chunk::GetTypeInfo();
    ncbi::objects::CID2S_Chunk_Content::GetTypeInfo();
    ncbi::objects::CID2S_Chunk_Data::GetTypeInfo();
    ncbi::objects::CID2S_Chunk_Info::GetTypeInfo();
    ncbi::objects::CID2S_Feat_type_Info::GetTypeInfo();
    ncbi::objects::CID2S_Gi_Interval::GetTypeInfo();
    ncbi::objects::CID2S_Gi_Ints::GetTypeInfo();
    ncbi::objects::CID2S_Gi_Range::GetTypeInfo();
    ncbi::objects::CID2S_Interval::GetTypeInfo();
    ncbi::objects::CID2S_Seq_annot_Info::GetTypeInfo();
    ncbi::objects::CID2S_Seq_annot_place_Info::GetTypeInfo();
    ncbi::objects::CID2S_Seq_assembly_Info::GetTypeInfo();
    ncbi::objects::CID2S_Seq_descr_Info::GetTypeInfo();
    ncbi::objects::CID2S_Seq_feat_Ids_Info::GetTypeInfo();
    ncbi::objects::CID2S_Seq_id_Interval::GetTypeInfo();
    ncbi::objects::CID2S_Seq_id_Ints::GetTypeInfo();
    ncbi::objects::CID2S_Seq_loc::GetTypeInfo();
    ncbi::objects::CID2S_Sequence_Piece::GetTypeInfo();
    ncbi::objects::CID2S_Split_Info::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

