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
#include <objects/taxon1/Taxon1_resp.hpp>
#include <objects/taxon1/Taxon1_data.hpp>
#include <objects/taxon1/Taxon1_error.hpp>
#include <objects/taxon1/Taxon1_info.hpp>
#include <objects/taxon1/Taxon1_name.hpp>
#include <objects/taxon1/Taxon2_data.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTaxon1_resp_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CTaxon1_resp_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Findname:
        m_Findname.Destruct();
        break;
    case e_Getorgnames:
        m_Getorgnames.Destruct();
        break;
    case e_Getcde:
        m_Getcde.Destruct();
        break;
    case e_Getranks:
        m_Getranks.Destruct();
        break;
    case e_Getdivs:
        m_Getdivs.Destruct();
        break;
    case e_Getgcs:
        m_Getgcs.Destruct();
        break;
    case e_Getlineage:
        m_Getlineage.Destruct();
        break;
    case e_Getchildren:
        m_Getchildren.Destruct();
        break;
    case e_Getorgmod:
        m_Getorgmod.Destruct();
        break;
    case e_Taxachildren:
        m_Taxachildren.Destruct();
        break;
    case e_Taxalineage:
        m_Taxalineage.Destruct();
        break;
    case e_Getproptypes:
        m_Getproptypes.Destruct();
        break;
    case e_Getorgprop:
        m_Getorgprop.Destruct();
        break;
    case e_Searchname:
        m_Searchname.Destruct();
        break;
    case e_Dumpnames4class:
        m_Dumpnames4class.Destruct();
        break;
    case e_Error:
    case e_Getbyid:
    case e_Lookup:
    case e_Taxabyid:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CTaxon1_resp_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Error:
        (m_object = new(pool) ncbi::objects::CTaxon1_error())->AddReference();
        break;
    case e_Findname:
        m_Findname.Construct();
        break;
    case e_Getdesignator:
        m_Getdesignator = 0;
        break;
    case e_Getunique:
        m_Getunique = 0;
        break;
    case e_Getidbyorg:
        m_Getidbyorg = 0;
        break;
    case e_Getorgnames:
        m_Getorgnames.Construct();
        break;
    case e_Getcde:
        m_Getcde.Construct();
        break;
    case e_Getranks:
        m_Getranks.Construct();
        break;
    case e_Getdivs:
        m_Getdivs.Construct();
        break;
    case e_Getgcs:
        m_Getgcs.Construct();
        break;
    case e_Getlineage:
        m_Getlineage.Construct();
        break;
    case e_Getchildren:
        m_Getchildren.Construct();
        break;
    case e_Getbyid:
        (m_object = new(pool) ncbi::objects::CTaxon1_data())->AddReference();
        break;
    case e_Lookup:
        (m_object = new(pool) ncbi::objects::CTaxon1_data())->AddReference();
        break;
    case e_Getorgmod:
        m_Getorgmod.Construct();
        break;
    case e_Id4gi:
        m_Id4gi = 0;
        break;
    case e_Taxabyid:
        (m_object = new(pool) ncbi::objects::CTaxon2_data())->AddReference();
        break;
    case e_Taxachildren:
        m_Taxachildren.Construct();
        break;
    case e_Taxalineage:
        m_Taxalineage.Construct();
        break;
    case e_Maxtaxid:
        m_Maxtaxid = 0;
        break;
    case e_Getproptypes:
        m_Getproptypes.Construct();
        break;
    case e_Getorgprop:
        m_Getorgprop.Construct();
        break;
    case e_Searchname:
        m_Searchname.Construct();
        break;
    case e_Dumpnames4class:
        m_Dumpnames4class.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CTaxon1_resp_Base::sm_SelectionNames[] = {
    "not set",
    "error",
    "init",
    "findname",
    "getdesignator",
    "getunique",
    "getidbyorg",
    "getorgnames",
    "getcde",
    "getranks",
    "getdivs",
    "getgcs",
    "getlineage",
    "getchildren",
    "getbyid",
    "lookup",
    "getorgmod",
    "fini",
    "id4gi",
    "taxabyid",
    "taxachildren",
    "taxalineage",
    "maxtaxid",
    "getproptypes",
    "getorgprop",
    "searchname",
    "dumpnames4class"
};

NCBI_NS_STD::string CTaxon1_resp_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CTaxon1_resp_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CTaxon1_resp_Base::TError& CTaxon1_resp_Base::GetError(void) const
{
    CheckSelected(e_Error);
    return *static_cast<const TError*>(m_object);
}

CTaxon1_resp_Base::TError& CTaxon1_resp_Base::SetError(void)
{
    Select(e_Error, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TError*>(m_object);
}

void CTaxon1_resp_Base::SetError(CTaxon1_resp_Base::TError& value)
{
    TError* ptr = &value;
    if ( m_choice != e_Error || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Error;
    }
}

const CTaxon1_resp_Base::TGetbyid& CTaxon1_resp_Base::GetGetbyid(void) const
{
    CheckSelected(e_Getbyid);
    return *static_cast<const TGetbyid*>(m_object);
}

CTaxon1_resp_Base::TGetbyid& CTaxon1_resp_Base::SetGetbyid(void)
{
    Select(e_Getbyid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGetbyid*>(m_object);
}

void CTaxon1_resp_Base::SetGetbyid(CTaxon1_resp_Base::TGetbyid& value)
{
    TGetbyid* ptr = &value;
    if ( m_choice != e_Getbyid || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Getbyid;
    }
}

const CTaxon1_resp_Base::TLookup& CTaxon1_resp_Base::GetLookup(void) const
{
    CheckSelected(e_Lookup);
    return *static_cast<const TLookup*>(m_object);
}

CTaxon1_resp_Base::TLookup& CTaxon1_resp_Base::SetLookup(void)
{
    Select(e_Lookup, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TLookup*>(m_object);
}

void CTaxon1_resp_Base::SetLookup(CTaxon1_resp_Base::TLookup& value)
{
    TLookup* ptr = &value;
    if ( m_choice != e_Lookup || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Lookup;
    }
}

const CTaxon1_resp_Base::TTaxabyid& CTaxon1_resp_Base::GetTaxabyid(void) const
{
    CheckSelected(e_Taxabyid);
    return *static_cast<const TTaxabyid*>(m_object);
}

CTaxon1_resp_Base::TTaxabyid& CTaxon1_resp_Base::SetTaxabyid(void)
{
    Select(e_Taxabyid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTaxabyid*>(m_object);
}

void CTaxon1_resp_Base::SetTaxabyid(CTaxon1_resp_Base::TTaxabyid& value)
{
    TTaxabyid* ptr = &value;
    if ( m_choice != e_Taxabyid || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Taxabyid;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Taxon1-resp", CTaxon1_resp)
{
    SET_CHOICE_MODULE("NCBI-Taxon1");
    ADD_NAMED_REF_CHOICE_VARIANT("error", m_object, CTaxon1_error);
    ADD_NAMED_NULL_CHOICE_VARIANT("init", null, ());
    ADD_NAMED_BUF_CHOICE_VARIANT("findname", m_Findname, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_name))));
    ADD_NAMED_STD_CHOICE_VARIANT("getdesignator", m_Getdesignator);
    ADD_NAMED_STD_CHOICE_VARIANT("getunique", m_Getunique);
    ADD_NAMED_STD_CHOICE_VARIANT("getidbyorg", m_Getidbyorg);
    ADD_NAMED_BUF_CHOICE_VARIANT("getorgnames", m_Getorgnames, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_name))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getcde", m_Getcde, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getranks", m_Getranks, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getdivs", m_Getdivs, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getgcs", m_Getgcs, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getlineage", m_Getlineage, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getchildren", m_Getchildren, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_REF_CHOICE_VARIANT("getbyid", m_object, CTaxon1_data);
    ADD_NAMED_REF_CHOICE_VARIANT("lookup", m_object, CTaxon1_data);
    ADD_NAMED_BUF_CHOICE_VARIANT("getorgmod", m_Getorgmod, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_NULL_CHOICE_VARIANT("fini", null, ());
    ADD_NAMED_STD_CHOICE_VARIANT("id4gi", m_Id4gi);
    ADD_NAMED_REF_CHOICE_VARIANT("taxabyid", m_object, CTaxon2_data);
    ADD_NAMED_BUF_CHOICE_VARIANT("taxachildren", m_Taxachildren, STL_list, (STL_CRef, (CLASS, (CTaxon1_name))));
    ADD_NAMED_BUF_CHOICE_VARIANT("taxalineage", m_Taxalineage, STL_list, (STL_CRef, (CLASS, (CTaxon1_name))));
    ADD_NAMED_STD_CHOICE_VARIANT("maxtaxid", m_Maxtaxid);
    ADD_NAMED_BUF_CHOICE_VARIANT("getproptypes", m_Getproptypes, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("getorgprop", m_Getorgprop, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_info))));
    ADD_NAMED_BUF_CHOICE_VARIANT("searchname", m_Searchname, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_name))));
    ADD_NAMED_BUF_CHOICE_VARIANT("dumpnames4class", m_Dumpnames4class, STL_list_set, (STL_CRef, (CLASS, (CTaxon1_name))));
}
END_CHOICE_INFO

// constructor
CTaxon1_resp_Base::CTaxon1_resp_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CTaxon1_resp_Base::~CTaxon1_resp_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

