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
 *   'scoremat.asn'.
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
#include <objects/scoremat/PssmIntermediateData.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPssmIntermediateData_Base::ResetResFreqsPerPos(void)
{
    m_ResFreqsPerPos.clear();
    m_set_State[0] &= ~0x3;
}

void CPssmIntermediateData_Base::ResetWeightedResFreqsPerPos(void)
{
    m_WeightedResFreqsPerPos.clear();
    m_set_State[0] &= ~0xc;
}

void CPssmIntermediateData_Base::ResetFreqRatios(void)
{
    m_FreqRatios.clear();
    m_set_State[0] &= ~0x30;
}

void CPssmIntermediateData_Base::ResetInformationContent(void)
{
    m_InformationContent.clear();
    m_set_State[0] &= ~0xc0;
}

void CPssmIntermediateData_Base::ResetGaplessColumnWeights(void)
{
    m_GaplessColumnWeights.clear();
    m_set_State[0] &= ~0x300;
}

void CPssmIntermediateData_Base::ResetSigma(void)
{
    m_Sigma.clear();
    m_set_State[0] &= ~0xc00;
}

void CPssmIntermediateData_Base::ResetIntervalSizes(void)
{
    m_IntervalSizes.clear();
    m_set_State[0] &= ~0x3000;
}

void CPssmIntermediateData_Base::ResetNumMatchingSeqs(void)
{
    m_NumMatchingSeqs.clear();
    m_set_State[0] &= ~0xc000;
}

void CPssmIntermediateData_Base::ResetNumIndeptObsr(void)
{
    m_NumIndeptObsr.clear();
    m_set_State[0] &= ~0x30000;
}

void CPssmIntermediateData_Base::Reset(void)
{
    ResetResFreqsPerPos();
    ResetWeightedResFreqsPerPos();
    ResetFreqRatios();
    ResetInformationContent();
    ResetGaplessColumnWeights();
    ResetSigma();
    ResetIntervalSizes();
    ResetNumMatchingSeqs();
    ResetNumIndeptObsr();
}

BEGIN_NAMED_BASE_CLASS_INFO("PssmIntermediateData", CPssmIntermediateData)
{
    SET_CLASS_MODULE("NCBI-ScoreMat");
    ADD_NAMED_MEMBER("resFreqsPerPos", m_ResFreqsPerPos, STL_list, (STD, (int)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("weightedResFreqsPerPos", m_WeightedResFreqsPerPos, STL_list, (STD, (double)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("freqRatios", m_FreqRatios, STL_list, (STD, (double)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("informationContent", m_InformationContent, STL_list, (STD, (double)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("gaplessColumnWeights", m_GaplessColumnWeights, STL_list, (STD, (double)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("sigma", m_Sigma, STL_list, (STD, (double)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("intervalSizes", m_IntervalSizes, STL_list, (STD, (int)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("numMatchingSeqs", m_NumMatchingSeqs, STL_list, (STD, (int)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("numIndeptObsr", m_NumIndeptObsr, STL_list, (STD, (double)))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CPssmIntermediateData_Base::CPssmIntermediateData_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPssmIntermediateData_Base::~CPssmIntermediateData_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

