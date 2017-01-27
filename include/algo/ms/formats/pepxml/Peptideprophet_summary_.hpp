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
 */

/// @file Peptideprophet_summary_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_PEPTIDEPROPHET_SUMMARY_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_PEPTIDEPROPHET_SUMMARY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CDistribution_point;
class CError_point;
class CInputfile;
class CMixture_model;
class CRoc_data_point;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///Summary information for PeptideProphet analysis 
class NCBI_PEPXML_EXPORT CPeptideprophet_summary_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPeptideprophet_summary_Base(void);
    // destructor
    virtual ~CPeptideprophet_summary_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_PEPXML_EXPORT C_Attlist : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Attlist(void);
        // destructor
        ~C_Attlist(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
        // types
        typedef string TVersion;
        typedef string TAuthor;
        typedef double TMin_prob;
        typedef string TOptions;
        typedef double TEst_tot_num_correct;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef string TVersion
        ///  Check whether the Version data member has been assigned a value.
        bool IsSetVersion(void) const;
        /// Check whether it is safe or not to call GetVersion method.
        bool CanGetVersion(void) const;
        void ResetVersion(void);
        const TVersion& GetVersion(void) const;
        void SetVersion(const TVersion& value);
        TVersion& SetVersion(void);
    
        /// mandatory
        /// typedef string TAuthor
        ///  Check whether the Author data member has been assigned a value.
        bool IsSetAuthor(void) const;
        /// Check whether it is safe or not to call GetAuthor method.
        bool CanGetAuthor(void) const;
        void ResetAuthor(void);
        const TAuthor& GetAuthor(void) const;
        void SetAuthor(const TAuthor& value);
        TAuthor& SetAuthor(void);
    
        /// mandatory
        /// typedef double TMin_prob
        ///  Check whether the Min_prob data member has been assigned a value.
        bool IsSetMin_prob(void) const;
        /// Check whether it is safe or not to call GetMin_prob method.
        bool CanGetMin_prob(void) const;
        void ResetMin_prob(void);
        TMin_prob GetMin_prob(void) const;
        void SetMin_prob(TMin_prob value);
        TMin_prob& SetMin_prob(void);
    
        /// optional
        /// typedef string TOptions
        ///  Check whether the Options data member has been assigned a value.
        bool IsSetOptions(void) const;
        /// Check whether it is safe or not to call GetOptions method.
        bool CanGetOptions(void) const;
        void ResetOptions(void);
        const TOptions& GetOptions(void) const;
        void SetOptions(const TOptions& value);
        TOptions& SetOptions(void);
    
        /// optional
        /// typedef double TEst_tot_num_correct
        ///  Check whether the Est_tot_num_correct data member has been assigned a value.
        bool IsSetEst_tot_num_correct(void) const;
        /// Check whether it is safe or not to call GetEst_tot_num_correct method.
        bool CanGetEst_tot_num_correct(void) const;
        void ResetEst_tot_num_correct(void);
        TEst_tot_num_correct GetEst_tot_num_correct(void) const;
        void SetEst_tot_num_correct(TEst_tot_num_correct value);
        TEst_tot_num_correct& SetEst_tot_num_correct(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Version;
        string m_Author;
        double m_Min_prob;
        string m_Options;
        double m_Est_tot_num_correct;
    };
    // types
    typedef C_Attlist TAttlist;
    typedef list< CRef< CInputfile > > TInputfile;
    typedef list< CRef< CRoc_data_point > > TRoc_data_point;
    typedef list< CRef< CError_point > > TError_point;
    typedef list< CRef< CDistribution_point > > TDistribution_point;
    typedef list< CRef< CMixture_model > > TMixture_model;

    // getters
    // setters

    /// mandatory
    /// typedef C_Attlist TAttlist
    ///  Check whether the Attlist data member has been assigned a value.
    bool IsSetAttlist(void) const;
    /// Check whether it is safe or not to call GetAttlist method.
    bool CanGetAttlist(void) const;
    void ResetAttlist(void);
    const TAttlist& GetAttlist(void) const;
    void SetAttlist(TAttlist& value);
    TAttlist& SetAttlist(void);

    /// mandatory
    /// typedef list< CRef< CInputfile > > TInputfile
    ///  Check whether the Inputfile data member has been assigned a value.
    bool IsSetInputfile(void) const;
    /// Check whether it is safe or not to call GetInputfile method.
    bool CanGetInputfile(void) const;
    void ResetInputfile(void);
    const TInputfile& GetInputfile(void) const;
    TInputfile& SetInputfile(void);

    /// optional
    /// typedef list< CRef< CRoc_data_point > > TRoc_data_point
    ///  Check whether the Roc_data_point data member has been assigned a value.
    bool IsSetRoc_data_point(void) const;
    /// Check whether it is safe or not to call GetRoc_data_point method.
    bool CanGetRoc_data_point(void) const;
    void ResetRoc_data_point(void);
    const TRoc_data_point& GetRoc_data_point(void) const;
    TRoc_data_point& SetRoc_data_point(void);

    /// optional
    /// typedef list< CRef< CError_point > > TError_point
    ///  Check whether the Error_point data member has been assigned a value.
    bool IsSetError_point(void) const;
    /// Check whether it is safe or not to call GetError_point method.
    bool CanGetError_point(void) const;
    void ResetError_point(void);
    const TError_point& GetError_point(void) const;
    TError_point& SetError_point(void);

    /// optional
    /// typedef list< CRef< CDistribution_point > > TDistribution_point
    ///  Check whether the Distribution_point data member has been assigned a value.
    bool IsSetDistribution_point(void) const;
    /// Check whether it is safe or not to call GetDistribution_point method.
    bool CanGetDistribution_point(void) const;
    void ResetDistribution_point(void);
    const TDistribution_point& GetDistribution_point(void) const;
    TDistribution_point& SetDistribution_point(void);

    /// optional
    /// typedef list< CRef< CMixture_model > > TMixture_model
    ///  Check whether the Mixture_model data member has been assigned a value.
    bool IsSetMixture_model(void) const;
    /// Check whether it is safe or not to call GetMixture_model method.
    bool CanGetMixture_model(void) const;
    void ResetMixture_model(void);
    const TMixture_model& GetMixture_model(void) const;
    TMixture_model& SetMixture_model(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPeptideprophet_summary_Base(const CPeptideprophet_summary_Base&);
    CPeptideprophet_summary_Base& operator=(const CPeptideprophet_summary_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
    list< CRef< CInputfile > > m_Inputfile;
    list< CRef< CRoc_data_point > > m_Roc_data_point;
    list< CRef< CError_point > > m_Error_point;
    list< CRef< CDistribution_point > > m_Distribution_point;
    list< CRef< CMixture_model > > m_Mixture_model;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPeptideprophet_summary_Base::C_Attlist::IsSetVersion(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::CanGetVersion(void) const
{
    return IsSetVersion();
}

inline
const CPeptideprophet_summary_Base::C_Attlist::TVersion& CPeptideprophet_summary_Base::C_Attlist::GetVersion(void) const
{
    if (!CanGetVersion()) {
        ThrowUnassigned(0);
    }
    return m_Version;
}

inline
void CPeptideprophet_summary_Base::C_Attlist::SetVersion(const CPeptideprophet_summary_Base::C_Attlist::TVersion& value)
{
    m_Version = value;
    m_set_State[0] |= 0x3;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TVersion& CPeptideprophet_summary_Base::C_Attlist::SetVersion(void)
{
#ifdef _DEBUG
    if (!IsSetVersion()) {
        m_Version = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Version;
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::IsSetAuthor(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::CanGetAuthor(void) const
{
    return IsSetAuthor();
}

inline
const CPeptideprophet_summary_Base::C_Attlist::TAuthor& CPeptideprophet_summary_Base::C_Attlist::GetAuthor(void) const
{
    if (!CanGetAuthor()) {
        ThrowUnassigned(1);
    }
    return m_Author;
}

inline
void CPeptideprophet_summary_Base::C_Attlist::SetAuthor(const CPeptideprophet_summary_Base::C_Attlist::TAuthor& value)
{
    m_Author = value;
    m_set_State[0] |= 0xc;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TAuthor& CPeptideprophet_summary_Base::C_Attlist::SetAuthor(void)
{
#ifdef _DEBUG
    if (!IsSetAuthor()) {
        m_Author = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Author;
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::IsSetMin_prob(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::CanGetMin_prob(void) const
{
    return IsSetMin_prob();
}

inline
void CPeptideprophet_summary_Base::C_Attlist::ResetMin_prob(void)
{
    m_Min_prob = 0;
    m_set_State[0] &= ~0x30;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TMin_prob CPeptideprophet_summary_Base::C_Attlist::GetMin_prob(void) const
{
    if (!CanGetMin_prob()) {
        ThrowUnassigned(2);
    }
    return m_Min_prob;
}

inline
void CPeptideprophet_summary_Base::C_Attlist::SetMin_prob(CPeptideprophet_summary_Base::C_Attlist::TMin_prob value)
{
    m_Min_prob = value;
    m_set_State[0] |= 0x30;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TMin_prob& CPeptideprophet_summary_Base::C_Attlist::SetMin_prob(void)
{
#ifdef _DEBUG
    if (!IsSetMin_prob()) {
        memset(&m_Min_prob,UnassignedByte(),sizeof(m_Min_prob));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Min_prob;
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::IsSetOptions(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::CanGetOptions(void) const
{
    return IsSetOptions();
}

inline
const CPeptideprophet_summary_Base::C_Attlist::TOptions& CPeptideprophet_summary_Base::C_Attlist::GetOptions(void) const
{
    if (!CanGetOptions()) {
        ThrowUnassigned(3);
    }
    return m_Options;
}

inline
void CPeptideprophet_summary_Base::C_Attlist::SetOptions(const CPeptideprophet_summary_Base::C_Attlist::TOptions& value)
{
    m_Options = value;
    m_set_State[0] |= 0xc0;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TOptions& CPeptideprophet_summary_Base::C_Attlist::SetOptions(void)
{
#ifdef _DEBUG
    if (!IsSetOptions()) {
        m_Options = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Options;
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::IsSetEst_tot_num_correct(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CPeptideprophet_summary_Base::C_Attlist::CanGetEst_tot_num_correct(void) const
{
    return IsSetEst_tot_num_correct();
}

inline
void CPeptideprophet_summary_Base::C_Attlist::ResetEst_tot_num_correct(void)
{
    m_Est_tot_num_correct = 0;
    m_set_State[0] &= ~0x300;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TEst_tot_num_correct CPeptideprophet_summary_Base::C_Attlist::GetEst_tot_num_correct(void) const
{
    if (!CanGetEst_tot_num_correct()) {
        ThrowUnassigned(4);
    }
    return m_Est_tot_num_correct;
}

inline
void CPeptideprophet_summary_Base::C_Attlist::SetEst_tot_num_correct(CPeptideprophet_summary_Base::C_Attlist::TEst_tot_num_correct value)
{
    m_Est_tot_num_correct = value;
    m_set_State[0] |= 0x300;
}

inline
CPeptideprophet_summary_Base::C_Attlist::TEst_tot_num_correct& CPeptideprophet_summary_Base::C_Attlist::SetEst_tot_num_correct(void)
{
#ifdef _DEBUG
    if (!IsSetEst_tot_num_correct()) {
        memset(&m_Est_tot_num_correct,UnassignedByte(),sizeof(m_Est_tot_num_correct));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Est_tot_num_correct;
}

inline
bool CPeptideprophet_summary_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CPeptideprophet_summary_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TAttlist& CPeptideprophet_summary_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CPeptideprophet_summary_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CPeptideprophet_summary_Base::TAttlist& CPeptideprophet_summary_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    return (*m_Attlist);
}

inline
bool CPeptideprophet_summary_Base::IsSetInputfile(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPeptideprophet_summary_Base::CanGetInputfile(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TInputfile& CPeptideprophet_summary_Base::GetInputfile(void) const
{
    return m_Inputfile;
}

inline
CPeptideprophet_summary_Base::TInputfile& CPeptideprophet_summary_Base::SetInputfile(void)
{
    m_set_State[0] |= 0x4;
    return m_Inputfile;
}

inline
bool CPeptideprophet_summary_Base::IsSetRoc_data_point(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CPeptideprophet_summary_Base::CanGetRoc_data_point(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TRoc_data_point& CPeptideprophet_summary_Base::GetRoc_data_point(void) const
{
    return m_Roc_data_point;
}

inline
CPeptideprophet_summary_Base::TRoc_data_point& CPeptideprophet_summary_Base::SetRoc_data_point(void)
{
    m_set_State[0] |= 0x10;
    return m_Roc_data_point;
}

inline
bool CPeptideprophet_summary_Base::IsSetError_point(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CPeptideprophet_summary_Base::CanGetError_point(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TError_point& CPeptideprophet_summary_Base::GetError_point(void) const
{
    return m_Error_point;
}

inline
CPeptideprophet_summary_Base::TError_point& CPeptideprophet_summary_Base::SetError_point(void)
{
    m_set_State[0] |= 0x40;
    return m_Error_point;
}

inline
bool CPeptideprophet_summary_Base::IsSetDistribution_point(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CPeptideprophet_summary_Base::CanGetDistribution_point(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TDistribution_point& CPeptideprophet_summary_Base::GetDistribution_point(void) const
{
    return m_Distribution_point;
}

inline
CPeptideprophet_summary_Base::TDistribution_point& CPeptideprophet_summary_Base::SetDistribution_point(void)
{
    m_set_State[0] |= 0x100;
    return m_Distribution_point;
}

inline
bool CPeptideprophet_summary_Base::IsSetMixture_model(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CPeptideprophet_summary_Base::CanGetMixture_model(void) const
{
    return true;
}

inline
const CPeptideprophet_summary_Base::TMixture_model& CPeptideprophet_summary_Base::GetMixture_model(void) const
{
    return m_Mixture_model;
}

inline
CPeptideprophet_summary_Base::TMixture_model& CPeptideprophet_summary_Base::SetMixture_model(void)
{
    m_set_State[0] |= 0x400;
    return m_Mixture_model;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_PEPTIDEPROPHET_SUMMARY_BASE_HPP
