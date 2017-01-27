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
 *   'seqset.asn'.
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
#include <objects/seqset/Bioseq_set.hpp>
#include <objects/general/Date.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/seq/Seq_annot.hpp>
#include <objects/seq/Seq_descr.hpp>
#include <objects/seqset/Seq_entry.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CBioseq_set_Base::, EClass, false)
{
    SET_ENUM_INTERNAL_NAME("Bioseq-set", "class");
    SET_ENUM_MODULE("NCBI-Seqset");
    ADD_ENUM_VALUE("not-set", eClass_not_set);
    ADD_ENUM_VALUE("nuc-prot", eClass_nuc_prot);
    ADD_ENUM_VALUE("segset", eClass_segset);
    ADD_ENUM_VALUE("conset", eClass_conset);
    ADD_ENUM_VALUE("parts", eClass_parts);
    ADD_ENUM_VALUE("gibb", eClass_gibb);
    ADD_ENUM_VALUE("gi", eClass_gi);
    ADD_ENUM_VALUE("genbank", eClass_genbank);
    ADD_ENUM_VALUE("pir", eClass_pir);
    ADD_ENUM_VALUE("pub-set", eClass_pub_set);
    ADD_ENUM_VALUE("equiv", eClass_equiv);
    ADD_ENUM_VALUE("swissprot", eClass_swissprot);
    ADD_ENUM_VALUE("pdb-entry", eClass_pdb_entry);
    ADD_ENUM_VALUE("mut-set", eClass_mut_set);
    ADD_ENUM_VALUE("pop-set", eClass_pop_set);
    ADD_ENUM_VALUE("phy-set", eClass_phy_set);
    ADD_ENUM_VALUE("eco-set", eClass_eco_set);
    ADD_ENUM_VALUE("gen-prod-set", eClass_gen_prod_set);
    ADD_ENUM_VALUE("wgs-set", eClass_wgs_set);
    ADD_ENUM_VALUE("named-annot", eClass_named_annot);
    ADD_ENUM_VALUE("named-annot-prod", eClass_named_annot_prod);
    ADD_ENUM_VALUE("read-set", eClass_read_set);
    ADD_ENUM_VALUE("paired-end-reads", eClass_paired_end_reads);
    ADD_ENUM_VALUE("small-genome-set", eClass_small_genome_set);
    ADD_ENUM_VALUE("other", eClass_other);
}
END_ENUM_INFO

void CBioseq_set_Base::ResetId(void)
{
    m_Id.Reset();
}

void CBioseq_set_Base::SetId(CBioseq_set_Base::TId& value)
{
    m_Id.Reset(&value);
}

CBioseq_set_Base::TId& CBioseq_set_Base::SetId(void)
{
    if ( !m_Id )
        m_Id.Reset(new ncbi::objects::CObject_id());
    return (*m_Id);
}

void CBioseq_set_Base::ResetColl(void)
{
    m_Coll.Reset();
}

void CBioseq_set_Base::SetColl(CBioseq_set_Base::TColl& value)
{
    m_Coll.Reset(&value);
}

CBioseq_set_Base::TColl& CBioseq_set_Base::SetColl(void)
{
    if ( !m_Coll )
        m_Coll.Reset(new ncbi::objects::CDbtag());
    return (*m_Coll);
}

void CBioseq_set_Base::ResetRelease(void)
{
    m_Release.erase();
    m_set_State[0] &= ~0x300;
}

void CBioseq_set_Base::ResetDate(void)
{
    m_Date.Reset();
}

void CBioseq_set_Base::SetDate(CBioseq_set_Base::TDate& value)
{
    m_Date.Reset(&value);
}

CBioseq_set_Base::TDate& CBioseq_set_Base::SetDate(void)
{
    if ( !m_Date )
        m_Date.Reset(new ncbi::objects::CDate());
    return (*m_Date);
}

void CBioseq_set_Base::ResetDescr(void)
{
    m_Descr.Reset();
}

void CBioseq_set_Base::SetDescr(CBioseq_set_Base::TDescr& value)
{
    m_Descr.Reset(&value);
}

CBioseq_set_Base::TDescr& CBioseq_set_Base::SetDescr(void)
{
    if ( !m_Descr )
        m_Descr.Reset(new ncbi::objects::CSeq_descr());
    return (*m_Descr);
}

void CBioseq_set_Base::ResetSeq_set(void)
{
    m_Seq_set.clear();
    m_set_State[0] &= ~0xc000;
}

void CBioseq_set_Base::ResetAnnot(void)
{
    m_Annot.clear();
    m_set_State[0] &= ~0x30000;
}

void CBioseq_set_Base::Reset(void)
{
    ResetId();
    ResetColl();
    ResetLevel();
    ResetClass();
    ResetRelease();
    ResetDate();
    ResetDescr();
    ResetSeq_set();
    ResetAnnot();
}

BEGIN_NAMED_BASE_CLASS_INFO("Bioseq-set", CBioseq_set)
{
    SET_CLASS_MODULE("NCBI-Seqset");
    ADD_NAMED_REF_MEMBER("id", m_Id, CObject_id)->SetOptional();
    ADD_NAMED_REF_MEMBER("coll", m_Coll, CDbtag)->SetOptional();
    ADD_NAMED_STD_MEMBER("level", m_Level)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("class", m_Class, EClass)->SetDefault(new TClass(eClass_not_set))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("release", m_Release)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("date", m_Date, CDate)->SetOptional();
    ADD_NAMED_REF_MEMBER("descr", m_Descr, CSeq_descr)->SetOptional();
    ADD_NAMED_MEMBER("seq-set", m_Seq_set, STL_list, (STL_CRef, (CLASS, (CSeq_entry))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("annot", m_Annot, STL_list_set, (STL_CRef, (CLASS, (CSeq_annot))))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CBioseq_set_Base::CBioseq_set_Base(void)
    : m_Level(0), m_Class(eClass_not_set)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CBioseq_set_Base::~CBioseq_set_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

