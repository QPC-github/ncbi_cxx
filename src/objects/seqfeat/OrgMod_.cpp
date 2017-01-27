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
#include <objects/seqfeat/OrgMod.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", COrgMod_Base::, ESubtype, true)
{
    SET_ENUM_INTERNAL_NAME("OrgMod", "subtype");
    SET_ENUM_MODULE("NCBI-Organism");
    ADD_ENUM_VALUE("strain", eSubtype_strain);
    ADD_ENUM_VALUE("substrain", eSubtype_substrain);
    ADD_ENUM_VALUE("type", eSubtype_type);
    ADD_ENUM_VALUE("subtype", eSubtype_subtype);
    ADD_ENUM_VALUE("variety", eSubtype_variety);
    ADD_ENUM_VALUE("serotype", eSubtype_serotype);
    ADD_ENUM_VALUE("serogroup", eSubtype_serogroup);
    ADD_ENUM_VALUE("serovar", eSubtype_serovar);
    ADD_ENUM_VALUE("cultivar", eSubtype_cultivar);
    ADD_ENUM_VALUE("pathovar", eSubtype_pathovar);
    ADD_ENUM_VALUE("chemovar", eSubtype_chemovar);
    ADD_ENUM_VALUE("biovar", eSubtype_biovar);
    ADD_ENUM_VALUE("biotype", eSubtype_biotype);
    ADD_ENUM_VALUE("group", eSubtype_group);
    ADD_ENUM_VALUE("subgroup", eSubtype_subgroup);
    ADD_ENUM_VALUE("isolate", eSubtype_isolate);
    ADD_ENUM_VALUE("common", eSubtype_common);
    ADD_ENUM_VALUE("acronym", eSubtype_acronym);
    ADD_ENUM_VALUE("dosage", eSubtype_dosage);
    ADD_ENUM_VALUE("nat-host", eSubtype_nat_host);
    ADD_ENUM_VALUE("sub-species", eSubtype_sub_species);
    ADD_ENUM_VALUE("specimen-voucher", eSubtype_specimen_voucher);
    ADD_ENUM_VALUE("authority", eSubtype_authority);
    ADD_ENUM_VALUE("forma", eSubtype_forma);
    ADD_ENUM_VALUE("forma-specialis", eSubtype_forma_specialis);
    ADD_ENUM_VALUE("ecotype", eSubtype_ecotype);
    ADD_ENUM_VALUE("synonym", eSubtype_synonym);
    ADD_ENUM_VALUE("anamorph", eSubtype_anamorph);
    ADD_ENUM_VALUE("teleomorph", eSubtype_teleomorph);
    ADD_ENUM_VALUE("breed", eSubtype_breed);
    ADD_ENUM_VALUE("gb-acronym", eSubtype_gb_acronym);
    ADD_ENUM_VALUE("gb-anamorph", eSubtype_gb_anamorph);
    ADD_ENUM_VALUE("gb-synonym", eSubtype_gb_synonym);
    ADD_ENUM_VALUE("culture-collection", eSubtype_culture_collection);
    ADD_ENUM_VALUE("bio-material", eSubtype_bio_material);
    ADD_ENUM_VALUE("metagenome-source", eSubtype_metagenome_source);
    ADD_ENUM_VALUE("old-lineage", eSubtype_old_lineage);
    ADD_ENUM_VALUE("old-name", eSubtype_old_name);
    ADD_ENUM_VALUE("other", eSubtype_other);
}
END_ENUM_INFO

void COrgMod_Base::ResetSubname(void)
{
    m_Subname.erase();
    m_set_State[0] &= ~0xc;
}

void COrgMod_Base::ResetAttrib(void)
{
    m_Attrib.erase();
    m_set_State[0] &= ~0x30;
}

void COrgMod_Base::Reset(void)
{
    ResetSubtype();
    ResetSubname();
    ResetAttrib();
}

BEGIN_NAMED_BASE_CLASS_INFO("OrgMod", COrgMod)
{
    SET_CLASS_MODULE("NCBI-Organism");
    ADD_NAMED_ENUM_MEMBER("subtype", m_Subtype, ESubtype)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("subname", m_Subname)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("attrib", m_Attrib)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
COrgMod_Base::COrgMod_Base(void)
    : m_Subtype((ESubtype)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
COrgMod_Base::~COrgMod_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

