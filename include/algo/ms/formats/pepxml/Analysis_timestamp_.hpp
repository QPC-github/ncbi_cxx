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

/// @file Analysis_timestamp_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_ANALYSIS_TIMESTAMP_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_ANALYSIS_TIMESTAMP_BASE_HPP

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
class CDatabase_refresh_timestamp;
class CXpressratio_timestamp;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///Reference for analysis applied to current run (time corresponds with analysis_summary/@time, id corresponds with analysis_result/@id) 
class NCBI_PEPXML_EXPORT CAnalysis_timestamp_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CAnalysis_timestamp_Base(void);
    // destructor
    virtual ~CAnalysis_timestamp_Base(void);

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
        typedef string TTime;
        typedef string TAnalysis;
        typedef int TId;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef string TTime
        ///  Check whether the Time data member has been assigned a value.
        bool IsSetTime(void) const;
        /// Check whether it is safe or not to call GetTime method.
        bool CanGetTime(void) const;
        void ResetTime(void);
        const TTime& GetTime(void) const;
        void SetTime(const TTime& value);
        TTime& SetTime(void);
    
        /// mandatory
        /// typedef string TAnalysis
        ///  Check whether the Analysis data member has been assigned a value.
        bool IsSetAnalysis(void) const;
        /// Check whether it is safe or not to call GetAnalysis method.
        bool CanGetAnalysis(void) const;
        void ResetAnalysis(void);
        const TAnalysis& GetAnalysis(void) const;
        void SetAnalysis(const TAnalysis& value);
        TAnalysis& SetAnalysis(void);
    
        /// mandatory
        /// typedef int TId
        ///  Check whether the Id data member has been assigned a value.
        bool IsSetId(void) const;
        /// Check whether it is safe or not to call GetId method.
        bool CanGetId(void) const;
        void ResetId(void);
        TId GetId(void) const;
        void SetId(TId value);
        TId& SetId(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Time;
        string m_Analysis;
        int m_Id;
    };
    // types
    typedef C_Attlist TAttlist;
    typedef list< CRef< CDatabase_refresh_timestamp > > TDatabase_refresh_timestamp;
    typedef list< CRef< CXpressratio_timestamp > > TXpressratio_timestamp;

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

    /// optional
    /// typedef list< CRef< CDatabase_refresh_timestamp > > TDatabase_refresh_timestamp
    ///  Check whether the Database_refresh_timestamp data member has been assigned a value.
    bool IsSetDatabase_refresh_timestamp(void) const;
    /// Check whether it is safe or not to call GetDatabase_refresh_timestamp method.
    bool CanGetDatabase_refresh_timestamp(void) const;
    void ResetDatabase_refresh_timestamp(void);
    const TDatabase_refresh_timestamp& GetDatabase_refresh_timestamp(void) const;
    TDatabase_refresh_timestamp& SetDatabase_refresh_timestamp(void);

    /// optional
    /// typedef list< CRef< CXpressratio_timestamp > > TXpressratio_timestamp
    ///  Check whether the Xpressratio_timestamp data member has been assigned a value.
    bool IsSetXpressratio_timestamp(void) const;
    /// Check whether it is safe or not to call GetXpressratio_timestamp method.
    bool CanGetXpressratio_timestamp(void) const;
    void ResetXpressratio_timestamp(void);
    const TXpressratio_timestamp& GetXpressratio_timestamp(void) const;
    TXpressratio_timestamp& SetXpressratio_timestamp(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CAnalysis_timestamp_Base(const CAnalysis_timestamp_Base&);
    CAnalysis_timestamp_Base& operator=(const CAnalysis_timestamp_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
    list< CRef< CDatabase_refresh_timestamp > > m_Database_refresh_timestamp;
    list< CRef< CXpressratio_timestamp > > m_Xpressratio_timestamp;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CAnalysis_timestamp_Base::C_Attlist::IsSetTime(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CAnalysis_timestamp_Base::C_Attlist::CanGetTime(void) const
{
    return IsSetTime();
}

inline
const CAnalysis_timestamp_Base::C_Attlist::TTime& CAnalysis_timestamp_Base::C_Attlist::GetTime(void) const
{
    if (!CanGetTime()) {
        ThrowUnassigned(0);
    }
    return m_Time;
}

inline
void CAnalysis_timestamp_Base::C_Attlist::SetTime(const CAnalysis_timestamp_Base::C_Attlist::TTime& value)
{
    m_Time = value;
    m_set_State[0] |= 0x3;
}

inline
CAnalysis_timestamp_Base::C_Attlist::TTime& CAnalysis_timestamp_Base::C_Attlist::SetTime(void)
{
#ifdef _DEBUG
    if (!IsSetTime()) {
        m_Time = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Time;
}

inline
bool CAnalysis_timestamp_Base::C_Attlist::IsSetAnalysis(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CAnalysis_timestamp_Base::C_Attlist::CanGetAnalysis(void) const
{
    return IsSetAnalysis();
}

inline
const CAnalysis_timestamp_Base::C_Attlist::TAnalysis& CAnalysis_timestamp_Base::C_Attlist::GetAnalysis(void) const
{
    if (!CanGetAnalysis()) {
        ThrowUnassigned(1);
    }
    return m_Analysis;
}

inline
void CAnalysis_timestamp_Base::C_Attlist::SetAnalysis(const CAnalysis_timestamp_Base::C_Attlist::TAnalysis& value)
{
    m_Analysis = value;
    m_set_State[0] |= 0xc;
}

inline
CAnalysis_timestamp_Base::C_Attlist::TAnalysis& CAnalysis_timestamp_Base::C_Attlist::SetAnalysis(void)
{
#ifdef _DEBUG
    if (!IsSetAnalysis()) {
        m_Analysis = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Analysis;
}

inline
bool CAnalysis_timestamp_Base::C_Attlist::IsSetId(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CAnalysis_timestamp_Base::C_Attlist::CanGetId(void) const
{
    return IsSetId();
}

inline
void CAnalysis_timestamp_Base::C_Attlist::ResetId(void)
{
    m_Id = 0;
    m_set_State[0] &= ~0x30;
}

inline
CAnalysis_timestamp_Base::C_Attlist::TId CAnalysis_timestamp_Base::C_Attlist::GetId(void) const
{
    if (!CanGetId()) {
        ThrowUnassigned(2);
    }
    return m_Id;
}

inline
void CAnalysis_timestamp_Base::C_Attlist::SetId(CAnalysis_timestamp_Base::C_Attlist::TId value)
{
    m_Id = value;
    m_set_State[0] |= 0x30;
}

inline
CAnalysis_timestamp_Base::C_Attlist::TId& CAnalysis_timestamp_Base::C_Attlist::SetId(void)
{
#ifdef _DEBUG
    if (!IsSetId()) {
        memset(&m_Id,UnassignedByte(),sizeof(m_Id));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Id;
}

inline
bool CAnalysis_timestamp_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CAnalysis_timestamp_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CAnalysis_timestamp_Base::TAttlist& CAnalysis_timestamp_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CAnalysis_timestamp_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CAnalysis_timestamp_Base::TAttlist& CAnalysis_timestamp_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    return (*m_Attlist);
}

inline
bool CAnalysis_timestamp_Base::IsSetDatabase_refresh_timestamp(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CAnalysis_timestamp_Base::CanGetDatabase_refresh_timestamp(void) const
{
    return true;
}

inline
const CAnalysis_timestamp_Base::TDatabase_refresh_timestamp& CAnalysis_timestamp_Base::GetDatabase_refresh_timestamp(void) const
{
    return m_Database_refresh_timestamp;
}

inline
CAnalysis_timestamp_Base::TDatabase_refresh_timestamp& CAnalysis_timestamp_Base::SetDatabase_refresh_timestamp(void)
{
    m_set_State[0] |= 0x4;
    return m_Database_refresh_timestamp;
}

inline
bool CAnalysis_timestamp_Base::IsSetXpressratio_timestamp(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CAnalysis_timestamp_Base::CanGetXpressratio_timestamp(void) const
{
    return true;
}

inline
const CAnalysis_timestamp_Base::TXpressratio_timestamp& CAnalysis_timestamp_Base::GetXpressratio_timestamp(void) const
{
    return m_Xpressratio_timestamp;
}

inline
CAnalysis_timestamp_Base::TXpressratio_timestamp& CAnalysis_timestamp_Base::SetXpressratio_timestamp(void)
{
    m_set_State[0] |= 0x10;
    return m_Xpressratio_timestamp;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_ANALYSIS_TIMESTAMP_BASE_HPP