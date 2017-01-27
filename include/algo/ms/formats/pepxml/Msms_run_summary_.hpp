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

/// @file Msms_run_summary_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_MSMS_RUN_SUMMARY_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_MSMS_RUN_SUMMARY_BASE_HPP

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
class CAnalysis_timestamp;
class CSample_enzyme;
class CSearch_summary;
class CSpectrum_query;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///Search results for LC/MS/MS run 
class NCBI_PEPXML_EXPORT CMsms_run_summary_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMsms_run_summary_Base(void);
    // destructor
    virtual ~CMsms_run_summary_Base(void);

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
        typedef string TBase_name;
        typedef string TRaw_data_type;
        typedef string TRaw_data;
        typedef string TMsManufacturer;
        typedef string TMsModel;
        typedef string TMsIonization;
        typedef string TMsMassAnalyzer;
        typedef string TMsDetector;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef string TBase_name
        ///  Check whether the Base_name data member has been assigned a value.
        bool IsSetBase_name(void) const;
        /// Check whether it is safe or not to call GetBase_name method.
        bool CanGetBase_name(void) const;
        void ResetBase_name(void);
        const TBase_name& GetBase_name(void) const;
        void SetBase_name(const TBase_name& value);
        TBase_name& SetBase_name(void);
    
        /// mandatory
        /// typedef string TRaw_data_type
        ///  Check whether the Raw_data_type data member has been assigned a value.
        bool IsSetRaw_data_type(void) const;
        /// Check whether it is safe or not to call GetRaw_data_type method.
        bool CanGetRaw_data_type(void) const;
        void ResetRaw_data_type(void);
        const TRaw_data_type& GetRaw_data_type(void) const;
        void SetRaw_data_type(const TRaw_data_type& value);
        TRaw_data_type& SetRaw_data_type(void);
    
        /// mandatory
        /// typedef string TRaw_data
        ///  Check whether the Raw_data data member has been assigned a value.
        bool IsSetRaw_data(void) const;
        /// Check whether it is safe or not to call GetRaw_data method.
        bool CanGetRaw_data(void) const;
        void ResetRaw_data(void);
        const TRaw_data& GetRaw_data(void) const;
        void SetRaw_data(const TRaw_data& value);
        TRaw_data& SetRaw_data(void);
    
        /// optional
        /// typedef string TMsManufacturer
        ///  Check whether the MsManufacturer data member has been assigned a value.
        bool IsSetMsManufacturer(void) const;
        /// Check whether it is safe or not to call GetMsManufacturer method.
        bool CanGetMsManufacturer(void) const;
        void ResetMsManufacturer(void);
        const TMsManufacturer& GetMsManufacturer(void) const;
        void SetMsManufacturer(const TMsManufacturer& value);
        TMsManufacturer& SetMsManufacturer(void);
    
        /// optional
        /// typedef string TMsModel
        ///  Check whether the MsModel data member has been assigned a value.
        bool IsSetMsModel(void) const;
        /// Check whether it is safe or not to call GetMsModel method.
        bool CanGetMsModel(void) const;
        void ResetMsModel(void);
        const TMsModel& GetMsModel(void) const;
        void SetMsModel(const TMsModel& value);
        TMsModel& SetMsModel(void);
    
        /// optional
        /// typedef string TMsIonization
        ///  Check whether the MsIonization data member has been assigned a value.
        bool IsSetMsIonization(void) const;
        /// Check whether it is safe or not to call GetMsIonization method.
        bool CanGetMsIonization(void) const;
        void ResetMsIonization(void);
        const TMsIonization& GetMsIonization(void) const;
        void SetMsIonization(const TMsIonization& value);
        TMsIonization& SetMsIonization(void);
    
        /// optional
        /// typedef string TMsMassAnalyzer
        ///  Check whether the MsMassAnalyzer data member has been assigned a value.
        bool IsSetMsMassAnalyzer(void) const;
        /// Check whether it is safe or not to call GetMsMassAnalyzer method.
        bool CanGetMsMassAnalyzer(void) const;
        void ResetMsMassAnalyzer(void);
        const TMsMassAnalyzer& GetMsMassAnalyzer(void) const;
        void SetMsMassAnalyzer(const TMsMassAnalyzer& value);
        TMsMassAnalyzer& SetMsMassAnalyzer(void);
    
        /// optional
        /// typedef string TMsDetector
        ///  Check whether the MsDetector data member has been assigned a value.
        bool IsSetMsDetector(void) const;
        /// Check whether it is safe or not to call GetMsDetector method.
        bool CanGetMsDetector(void) const;
        void ResetMsDetector(void);
        const TMsDetector& GetMsDetector(void) const;
        void SetMsDetector(const TMsDetector& value);
        TMsDetector& SetMsDetector(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Base_name;
        string m_Raw_data_type;
        string m_Raw_data;
        string m_MsManufacturer;
        string m_MsModel;
        string m_MsIonization;
        string m_MsMassAnalyzer;
        string m_MsDetector;
    };
    // types
    typedef C_Attlist TAttlist;
    typedef CSample_enzyme TSample_enzyme;
    typedef list< CRef< CSearch_summary > > TSearch_summary;
    typedef list< CRef< CAnalysis_timestamp > > TAnalysis_timestamp;
    typedef list< CRef< CSpectrum_query > > TSpectrum_query;

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
    /// typedef CSample_enzyme TSample_enzyme
    ///  Check whether the Sample_enzyme data member has been assigned a value.
    bool IsSetSample_enzyme(void) const;
    /// Check whether it is safe or not to call GetSample_enzyme method.
    bool CanGetSample_enzyme(void) const;
    void ResetSample_enzyme(void);
    const TSample_enzyme& GetSample_enzyme(void) const;
    void SetSample_enzyme(TSample_enzyme& value);
    TSample_enzyme& SetSample_enzyme(void);

    /// mandatory
    /// typedef list< CRef< CSearch_summary > > TSearch_summary
    ///  Check whether the Search_summary data member has been assigned a value.
    bool IsSetSearch_summary(void) const;
    /// Check whether it is safe or not to call GetSearch_summary method.
    bool CanGetSearch_summary(void) const;
    void ResetSearch_summary(void);
    const TSearch_summary& GetSearch_summary(void) const;
    TSearch_summary& SetSearch_summary(void);

    /// optional
    /// typedef list< CRef< CAnalysis_timestamp > > TAnalysis_timestamp
    ///  Check whether the Analysis_timestamp data member has been assigned a value.
    bool IsSetAnalysis_timestamp(void) const;
    /// Check whether it is safe or not to call GetAnalysis_timestamp method.
    bool CanGetAnalysis_timestamp(void) const;
    void ResetAnalysis_timestamp(void);
    const TAnalysis_timestamp& GetAnalysis_timestamp(void) const;
    TAnalysis_timestamp& SetAnalysis_timestamp(void);

    /// optional
    /// typedef list< CRef< CSpectrum_query > > TSpectrum_query
    ///  Check whether the Spectrum_query data member has been assigned a value.
    bool IsSetSpectrum_query(void) const;
    /// Check whether it is safe or not to call GetSpectrum_query method.
    bool CanGetSpectrum_query(void) const;
    void ResetSpectrum_query(void);
    const TSpectrum_query& GetSpectrum_query(void) const;
    TSpectrum_query& SetSpectrum_query(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMsms_run_summary_Base(const CMsms_run_summary_Base&);
    CMsms_run_summary_Base& operator=(const CMsms_run_summary_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
    CRef< TSample_enzyme > m_Sample_enzyme;
    list< CRef< CSearch_summary > > m_Search_summary;
    list< CRef< CAnalysis_timestamp > > m_Analysis_timestamp;
    list< CRef< CSpectrum_query > > m_Spectrum_query;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMsms_run_summary_Base::C_Attlist::IsSetBase_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetBase_name(void) const
{
    return IsSetBase_name();
}

inline
const CMsms_run_summary_Base::C_Attlist::TBase_name& CMsms_run_summary_Base::C_Attlist::GetBase_name(void) const
{
    if (!CanGetBase_name()) {
        ThrowUnassigned(0);
    }
    return m_Base_name;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetBase_name(const CMsms_run_summary_Base::C_Attlist::TBase_name& value)
{
    m_Base_name = value;
    m_set_State[0] |= 0x3;
}

inline
CMsms_run_summary_Base::C_Attlist::TBase_name& CMsms_run_summary_Base::C_Attlist::SetBase_name(void)
{
#ifdef _DEBUG
    if (!IsSetBase_name()) {
        m_Base_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Base_name;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetRaw_data_type(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetRaw_data_type(void) const
{
    return IsSetRaw_data_type();
}

inline
const CMsms_run_summary_Base::C_Attlist::TRaw_data_type& CMsms_run_summary_Base::C_Attlist::GetRaw_data_type(void) const
{
    if (!CanGetRaw_data_type()) {
        ThrowUnassigned(1);
    }
    return m_Raw_data_type;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetRaw_data_type(const CMsms_run_summary_Base::C_Attlist::TRaw_data_type& value)
{
    m_Raw_data_type = value;
    m_set_State[0] |= 0xc;
}

inline
CMsms_run_summary_Base::C_Attlist::TRaw_data_type& CMsms_run_summary_Base::C_Attlist::SetRaw_data_type(void)
{
#ifdef _DEBUG
    if (!IsSetRaw_data_type()) {
        m_Raw_data_type = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Raw_data_type;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetRaw_data(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetRaw_data(void) const
{
    return IsSetRaw_data();
}

inline
const CMsms_run_summary_Base::C_Attlist::TRaw_data& CMsms_run_summary_Base::C_Attlist::GetRaw_data(void) const
{
    if (!CanGetRaw_data()) {
        ThrowUnassigned(2);
    }
    return m_Raw_data;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetRaw_data(const CMsms_run_summary_Base::C_Attlist::TRaw_data& value)
{
    m_Raw_data = value;
    m_set_State[0] |= 0x30;
}

inline
CMsms_run_summary_Base::C_Attlist::TRaw_data& CMsms_run_summary_Base::C_Attlist::SetRaw_data(void)
{
#ifdef _DEBUG
    if (!IsSetRaw_data()) {
        m_Raw_data = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Raw_data;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetMsManufacturer(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetMsManufacturer(void) const
{
    return IsSetMsManufacturer();
}

inline
const CMsms_run_summary_Base::C_Attlist::TMsManufacturer& CMsms_run_summary_Base::C_Attlist::GetMsManufacturer(void) const
{
    if (!CanGetMsManufacturer()) {
        ThrowUnassigned(3);
    }
    return m_MsManufacturer;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetMsManufacturer(const CMsms_run_summary_Base::C_Attlist::TMsManufacturer& value)
{
    m_MsManufacturer = value;
    m_set_State[0] |= 0xc0;
}

inline
CMsms_run_summary_Base::C_Attlist::TMsManufacturer& CMsms_run_summary_Base::C_Attlist::SetMsManufacturer(void)
{
#ifdef _DEBUG
    if (!IsSetMsManufacturer()) {
        m_MsManufacturer = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_MsManufacturer;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetMsModel(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetMsModel(void) const
{
    return IsSetMsModel();
}

inline
const CMsms_run_summary_Base::C_Attlist::TMsModel& CMsms_run_summary_Base::C_Attlist::GetMsModel(void) const
{
    if (!CanGetMsModel()) {
        ThrowUnassigned(4);
    }
    return m_MsModel;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetMsModel(const CMsms_run_summary_Base::C_Attlist::TMsModel& value)
{
    m_MsModel = value;
    m_set_State[0] |= 0x300;
}

inline
CMsms_run_summary_Base::C_Attlist::TMsModel& CMsms_run_summary_Base::C_Attlist::SetMsModel(void)
{
#ifdef _DEBUG
    if (!IsSetMsModel()) {
        m_MsModel = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_MsModel;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetMsIonization(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetMsIonization(void) const
{
    return IsSetMsIonization();
}

inline
const CMsms_run_summary_Base::C_Attlist::TMsIonization& CMsms_run_summary_Base::C_Attlist::GetMsIonization(void) const
{
    if (!CanGetMsIonization()) {
        ThrowUnassigned(5);
    }
    return m_MsIonization;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetMsIonization(const CMsms_run_summary_Base::C_Attlist::TMsIonization& value)
{
    m_MsIonization = value;
    m_set_State[0] |= 0xc00;
}

inline
CMsms_run_summary_Base::C_Attlist::TMsIonization& CMsms_run_summary_Base::C_Attlist::SetMsIonization(void)
{
#ifdef _DEBUG
    if (!IsSetMsIonization()) {
        m_MsIonization = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_MsIonization;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetMsMassAnalyzer(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetMsMassAnalyzer(void) const
{
    return IsSetMsMassAnalyzer();
}

inline
const CMsms_run_summary_Base::C_Attlist::TMsMassAnalyzer& CMsms_run_summary_Base::C_Attlist::GetMsMassAnalyzer(void) const
{
    if (!CanGetMsMassAnalyzer()) {
        ThrowUnassigned(6);
    }
    return m_MsMassAnalyzer;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetMsMassAnalyzer(const CMsms_run_summary_Base::C_Attlist::TMsMassAnalyzer& value)
{
    m_MsMassAnalyzer = value;
    m_set_State[0] |= 0x3000;
}

inline
CMsms_run_summary_Base::C_Attlist::TMsMassAnalyzer& CMsms_run_summary_Base::C_Attlist::SetMsMassAnalyzer(void)
{
#ifdef _DEBUG
    if (!IsSetMsMassAnalyzer()) {
        m_MsMassAnalyzer = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_MsMassAnalyzer;
}

inline
bool CMsms_run_summary_Base::C_Attlist::IsSetMsDetector(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CMsms_run_summary_Base::C_Attlist::CanGetMsDetector(void) const
{
    return IsSetMsDetector();
}

inline
const CMsms_run_summary_Base::C_Attlist::TMsDetector& CMsms_run_summary_Base::C_Attlist::GetMsDetector(void) const
{
    if (!CanGetMsDetector()) {
        ThrowUnassigned(7);
    }
    return m_MsDetector;
}

inline
void CMsms_run_summary_Base::C_Attlist::SetMsDetector(const CMsms_run_summary_Base::C_Attlist::TMsDetector& value)
{
    m_MsDetector = value;
    m_set_State[0] |= 0xc000;
}

inline
CMsms_run_summary_Base::C_Attlist::TMsDetector& CMsms_run_summary_Base::C_Attlist::SetMsDetector(void)
{
#ifdef _DEBUG
    if (!IsSetMsDetector()) {
        m_MsDetector = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_MsDetector;
}

inline
bool CMsms_run_summary_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CMsms_run_summary_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CMsms_run_summary_Base::TAttlist& CMsms_run_summary_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CMsms_run_summary_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CMsms_run_summary_Base::TAttlist& CMsms_run_summary_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    return (*m_Attlist);
}

inline
bool CMsms_run_summary_Base::IsSetSample_enzyme(void) const
{
    return m_Sample_enzyme.NotEmpty();
}

inline
bool CMsms_run_summary_Base::CanGetSample_enzyme(void) const
{
    return true;
}

inline
const CMsms_run_summary_Base::TSample_enzyme& CMsms_run_summary_Base::GetSample_enzyme(void) const
{
    if ( !m_Sample_enzyme ) {
        const_cast<CMsms_run_summary_Base*>(this)->ResetSample_enzyme();
    }
    return (*m_Sample_enzyme);
}

inline
CMsms_run_summary_Base::TSample_enzyme& CMsms_run_summary_Base::SetSample_enzyme(void)
{
    if ( !m_Sample_enzyme ) {
        ResetSample_enzyme();
    }
    return (*m_Sample_enzyme);
}

inline
bool CMsms_run_summary_Base::IsSetSearch_summary(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CMsms_run_summary_Base::CanGetSearch_summary(void) const
{
    return true;
}

inline
const CMsms_run_summary_Base::TSearch_summary& CMsms_run_summary_Base::GetSearch_summary(void) const
{
    return m_Search_summary;
}

inline
CMsms_run_summary_Base::TSearch_summary& CMsms_run_summary_Base::SetSearch_summary(void)
{
    m_set_State[0] |= 0x10;
    return m_Search_summary;
}

inline
bool CMsms_run_summary_Base::IsSetAnalysis_timestamp(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CMsms_run_summary_Base::CanGetAnalysis_timestamp(void) const
{
    return true;
}

inline
const CMsms_run_summary_Base::TAnalysis_timestamp& CMsms_run_summary_Base::GetAnalysis_timestamp(void) const
{
    return m_Analysis_timestamp;
}

inline
CMsms_run_summary_Base::TAnalysis_timestamp& CMsms_run_summary_Base::SetAnalysis_timestamp(void)
{
    m_set_State[0] |= 0x40;
    return m_Analysis_timestamp;
}

inline
bool CMsms_run_summary_Base::IsSetSpectrum_query(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CMsms_run_summary_Base::CanGetSpectrum_query(void) const
{
    return true;
}

inline
const CMsms_run_summary_Base::TSpectrum_query& CMsms_run_summary_Base::GetSpectrum_query(void) const
{
    return m_Spectrum_query;
}

inline
CMsms_run_summary_Base::TSpectrum_query& CMsms_run_summary_Base::SetSpectrum_query(void)
{
    m_set_State[0] |= 0x100;
    return m_Spectrum_query;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_MSMS_RUN_SUMMARY_BASE_HPP