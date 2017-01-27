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
 *   'seq.asn'.
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
#include <objects/seq/Seq_inst.hpp>
#include <objects/general/Int_fuzz.hpp>
#include <objects/seq/Seq_data.hpp>
#include <objects/seq/Seq_ext.hpp>
#include <objects/seq/Seq_hist.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_inst_Base::, ERepr, false)
{
    SET_ENUM_INTERNAL_NAME("Seq-inst", "repr");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("not-set", eRepr_not_set);
    ADD_ENUM_VALUE("virtual", eRepr_virtual);
    ADD_ENUM_VALUE("raw", eRepr_raw);
    ADD_ENUM_VALUE("seg", eRepr_seg);
    ADD_ENUM_VALUE("const", eRepr_const);
    ADD_ENUM_VALUE("ref", eRepr_ref);
    ADD_ENUM_VALUE("consen", eRepr_consen);
    ADD_ENUM_VALUE("map", eRepr_map);
    ADD_ENUM_VALUE("delta", eRepr_delta);
    ADD_ENUM_VALUE("other", eRepr_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_inst_Base::, EMol, false)
{
    SET_ENUM_INTERNAL_NAME("Seq-inst", "mol");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("not-set", eMol_not_set);
    ADD_ENUM_VALUE("dna", eMol_dna);
    ADD_ENUM_VALUE("rna", eMol_rna);
    ADD_ENUM_VALUE("aa", eMol_aa);
    ADD_ENUM_VALUE("na", eMol_na);
    ADD_ENUM_VALUE("other", eMol_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_inst_Base::, ETopology, false)
{
    SET_ENUM_INTERNAL_NAME("Seq-inst", "topology");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("not-set", eTopology_not_set);
    ADD_ENUM_VALUE("linear", eTopology_linear);
    ADD_ENUM_VALUE("circular", eTopology_circular);
    ADD_ENUM_VALUE("tandem", eTopology_tandem);
    ADD_ENUM_VALUE("other", eTopology_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_inst_Base::, EStrand, false)
{
    SET_ENUM_INTERNAL_NAME("Seq-inst", "strand");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("not-set", eStrand_not_set);
    ADD_ENUM_VALUE("ss", eStrand_ss);
    ADD_ENUM_VALUE("ds", eStrand_ds);
    ADD_ENUM_VALUE("mixed", eStrand_mixed);
    ADD_ENUM_VALUE("other", eStrand_other);
}
END_ENUM_INFO

void CSeq_inst_Base::ResetFuzz(void)
{
    m_Fuzz.Reset();
}

void CSeq_inst_Base::SetFuzz(CSeq_inst_Base::TFuzz& value)
{
    m_Fuzz.Reset(&value);
}

CSeq_inst_Base::TFuzz& CSeq_inst_Base::SetFuzz(void)
{
    if ( !m_Fuzz )
        m_Fuzz.Reset(new ncbi::objects::CInt_fuzz());
    return (*m_Fuzz);
}

void CSeq_inst_Base::ResetSeq_data(void)
{
    m_Seq_data.Reset();
}

void CSeq_inst_Base::SetSeq_data(CSeq_inst_Base::TSeq_data& value)
{
    m_Seq_data.Reset(&value);
}

CSeq_inst_Base::TSeq_data& CSeq_inst_Base::SetSeq_data(void)
{
    if ( !m_Seq_data )
        m_Seq_data.Reset(new ncbi::objects::CSeq_data());
    return (*m_Seq_data);
}

void CSeq_inst_Base::ResetExt(void)
{
    m_Ext.Reset();
}

void CSeq_inst_Base::SetExt(CSeq_inst_Base::TExt& value)
{
    m_Ext.Reset(&value);
}

CSeq_inst_Base::TExt& CSeq_inst_Base::SetExt(void)
{
    if ( !m_Ext )
        m_Ext.Reset(new ncbi::objects::CSeq_ext());
    return (*m_Ext);
}

void CSeq_inst_Base::ResetHist(void)
{
    m_Hist.Reset();
}

void CSeq_inst_Base::SetHist(CSeq_inst_Base::THist& value)
{
    m_Hist.Reset(&value);
}

CSeq_inst_Base::THist& CSeq_inst_Base::SetHist(void)
{
    if ( !m_Hist )
        m_Hist.Reset(new ncbi::objects::CSeq_hist());
    return (*m_Hist);
}

void CSeq_inst_Base::Reset(void)
{
    ResetRepr();
    ResetMol();
    ResetLength();
    ResetFuzz();
    ResetTopology();
    ResetStrand();
    ResetSeq_data();
    ResetExt();
    ResetHist();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-inst", CSeq_inst)
{
    SET_CLASS_MODULE("NCBI-Sequence");
    ADD_NAMED_ENUM_MEMBER("repr", m_Repr, ERepr)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("mol", m_Mol, EMol)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("length", m_Length)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("fuzz", m_Fuzz, CInt_fuzz)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("topology", m_Topology, ETopology)->SetDefault(new TTopology(eTopology_linear))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("strand", m_Strand, EStrand)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("seq-data", m_Seq_data, CSeq_data)->SetOptional();
    ADD_NAMED_REF_MEMBER("ext", m_Ext, CSeq_ext)->SetOptional();
    ADD_NAMED_REF_MEMBER("hist", m_Hist, CSeq_hist)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CSeq_inst_Base::CSeq_inst_Base(void)
    : m_Repr((ERepr)(0)), m_Mol((EMol)(0)), m_Length(0), m_Topology(eTopology_linear), m_Strand((EStrand)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSeq_inst_Base::~CSeq_inst_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
