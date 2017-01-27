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
 *   'omssa.asn'.
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
#include <objects/omssa/MSRequest.hpp>
#include <objects/omssa/MSModSpecSet.hpp>
#include <objects/omssa/MSSearchSettings.hpp>
#include <objects/omssa/MSSearchSettingsSet.hpp>
#include <objects/omssa/MSSpectrumset.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMSRequest_Base::ResetSpectra(void)
{
    if ( !m_Spectra ) {
        m_Spectra.Reset(new TSpectra());
        return;
    }
    (*m_Spectra).Reset();
}

void CMSRequest_Base::SetSpectra(CMSRequest_Base::TSpectra& value)
{
    m_Spectra.Reset(&value);
}

void CMSRequest_Base::ResetSettings(void)
{
    if ( !m_Settings ) {
        m_Settings.Reset(new TSettings());
        return;
    }
    (*m_Settings).Reset();
}

void CMSRequest_Base::SetSettings(CMSRequest_Base::TSettings& value)
{
    m_Settings.Reset(&value);
}

void CMSRequest_Base::ResetRid(void)
{
    m_Rid.erase();
    m_set_State[0] &= ~0x30;
}

void CMSRequest_Base::ResetMoresettings(void)
{
    m_Moresettings.Reset();
}

void CMSRequest_Base::SetMoresettings(CMSRequest_Base::TMoresettings& value)
{
    m_Moresettings.Reset(&value);
}

CMSRequest_Base::TMoresettings& CMSRequest_Base::SetMoresettings(void)
{
    if ( !m_Moresettings )
        m_Moresettings.Reset(new ncbi::objects::CMSSearchSettingsSet());
    return (*m_Moresettings);
}

void CMSRequest_Base::ResetModset(void)
{
    m_Modset.Reset();
}

void CMSRequest_Base::SetModset(CMSRequest_Base::TModset& value)
{
    m_Modset.Reset(&value);
}

CMSRequest_Base::TModset& CMSRequest_Base::SetModset(void)
{
    if ( !m_Modset )
        m_Modset.Reset(new ncbi::objects::CMSModSpecSet());
    return (*m_Modset);
}

void CMSRequest_Base::Reset(void)
{
    ResetSpectra();
    ResetSettings();
    ResetRid();
    ResetMoresettings();
    ResetModset();
}

BEGIN_NAMED_BASE_CLASS_INFO("MSRequest", CMSRequest)
{
    SET_CLASS_MODULE("OMSSA");
    ADD_NAMED_REF_MEMBER("spectra", m_Spectra, CMSSpectrumset);
    ADD_NAMED_REF_MEMBER("settings", m_Settings, CMSSearchSettings);
    ADD_NAMED_STD_MEMBER("rid", m_Rid)->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("moresettings", m_Moresettings, CMSSearchSettingsSet)->SetOptional();
    ADD_NAMED_REF_MEMBER("modset", m_Modset, CMSModSpecSet)->SetOptional();
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CMSRequest_Base::CMSRequest_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSpectra();
        ResetSettings();
    }
}

// destructor
CMSRequest_Base::~CMSRequest_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

