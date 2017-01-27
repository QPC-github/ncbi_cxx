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

/// @file EHistoryItem_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'ehistory.dtd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ehistory__OBJTOOLS_EUTILS_EHISTORY_EHISTORYITEM_BASE_HPP
#define ehistory__OBJTOOLS_EUTILS_EHISTORY_EHISTORYITEM_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

#ifndef BEGIN_ehistory_SCOPE
#  define BEGIN_ehistory_SCOPE BEGIN_SCOPE(ehistory)
#  define END_ehistory_SCOPE END_SCOPE(ehistory)
#endif
BEGIN_ehistory_SCOPE // namespace ehistory::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CEHistoryItem_Base : public NCBI_NS_NCBI::CSerialObject
{
    typedef NCBI_NS_NCBI::CSerialObject Tparent;
public:
    // constructor
    CEHistoryItem_Base(void);
    // destructor
    virtual ~CEHistoryItem_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_EUTILS_EXPORT C_E : public NCBI_NS_NCBI::CSerialObject
    {
        typedef NCBI_NS_NCBI::CSerialObject Tparent;
    public:
        // constructor
        C_E(void);
        // destructor
        ~C_E(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
        // types
        typedef NCBI_NS_STD::string TQueryKey;
        typedef NCBI_NS_STD::string TQueryName;
        typedef NCBI_NS_STD::string TDbName;
        typedef NCBI_NS_STD::string TTitle;
        typedef NCBI_NS_STD::string TTime;
        typedef NCBI_NS_STD::string TCount;
    
        // getters
        // setters
    
        /// \d+ 
        /// mandatory
        /// typedef NCBI_NS_STD::string TQueryKey
        ///  Check whether the QueryKey data member has been assigned a value.
        bool IsSetQueryKey(void) const;
        /// Check whether it is safe or not to call GetQueryKey method.
        bool CanGetQueryKey(void) const;
        void ResetQueryKey(void);
        const TQueryKey& GetQueryKey(void) const;
        void SetQueryKey(const TQueryKey& value);
        TQueryKey& SetQueryKey(void);
    
        /// .* 
        /// mandatory
        /// typedef NCBI_NS_STD::string TQueryName
        ///  Check whether the QueryName data member has been assigned a value.
        bool IsSetQueryName(void) const;
        /// Check whether it is safe or not to call GetQueryName method.
        bool CanGetQueryName(void) const;
        void ResetQueryName(void);
        const TQueryName& GetQueryName(void) const;
        void SetQueryName(const TQueryName& value);
        TQueryName& SetQueryName(void);
    
        /// .+ 
        /// mandatory
        /// typedef NCBI_NS_STD::string TDbName
        ///  Check whether the DbName data member has been assigned a value.
        bool IsSetDbName(void) const;
        /// Check whether it is safe or not to call GetDbName method.
        bool CanGetDbName(void) const;
        void ResetDbName(void);
        const TDbName& GetDbName(void) const;
        void SetDbName(const TDbName& value);
        TDbName& SetDbName(void);
    
        /// .+ 
        /// mandatory
        /// typedef NCBI_NS_STD::string TTitle
        ///  Check whether the Title data member has been assigned a value.
        bool IsSetTitle(void) const;
        /// Check whether it is safe or not to call GetTitle method.
        bool CanGetTitle(void) const;
        void ResetTitle(void);
        const TTitle& GetTitle(void) const;
        void SetTitle(const TTitle& value);
        TTitle& SetTitle(void);
    
        /// PmTime 
        /// mandatory
        /// typedef NCBI_NS_STD::string TTime
        ///  Check whether the Time data member has been assigned a value.
        bool IsSetTime(void) const;
        /// Check whether it is safe or not to call GetTime method.
        bool CanGetTime(void) const;
        void ResetTime(void);
        const TTime& GetTime(void) const;
        void SetTime(const TTime& value);
        TTime& SetTime(void);
    
        /// \d+ 
        /// mandatory
        /// typedef NCBI_NS_STD::string TCount
        ///  Check whether the Count data member has been assigned a value.
        bool IsSetCount(void) const;
        /// Check whether it is safe or not to call GetCount method.
        bool CanGetCount(void) const;
        void ResetCount(void);
        const TCount& GetCount(void) const;
        void SetCount(const TCount& value);
        TCount& SetCount(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_E(const C_E&);
        C_E& operator=(const C_E&);
    
        // data
        Uint4 m_set_State[1];
        NCBI_NS_STD::string m_QueryKey;
        NCBI_NS_STD::string m_QueryName;
        NCBI_NS_STD::string m_DbName;
        NCBI_NS_STD::string m_Title;
        NCBI_NS_STD::string m_Time;
        NCBI_NS_STD::string m_Count;
    };
    // types
    typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_E > > Tdata;

    // getters
    // setters

    /// mandatory
    /// typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_E > > Tdata
    ///  Check whether the  data member has been assigned a value.
    bool IsSet(void) const;
    /// Check whether it is safe or not to call Get method.
    bool CanGet(void) const;
    void Reset(void);
    const Tdata& Get(void) const;
    Tdata& Set(void);
    /// Conversion operator to 'const Tdata' type.
    operator const Tdata& (void) const;

    /// Conversion operator to 'Tdata' type.
    operator Tdata& (void);




private:
    // Prohibit copy constructor and assignment operator
    CEHistoryItem_Base(const CEHistoryItem_Base&);
    CEHistoryItem_Base& operator=(const CEHistoryItem_Base&);

    // data
    Uint4 m_set_State[1];
    NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_E > > m_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEHistoryItem_Base::C_E::IsSetQueryKey(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetQueryKey(void) const
{
    return IsSetQueryKey();
}

inline
const CEHistoryItem_Base::C_E::TQueryKey& CEHistoryItem_Base::C_E::GetQueryKey(void) const
{
    if (!CanGetQueryKey()) {
        ThrowUnassigned(0);
    }
    return m_QueryKey;
}

inline
void CEHistoryItem_Base::C_E::SetQueryKey(const CEHistoryItem_Base::C_E::TQueryKey& value)
{
    m_QueryKey = value;
    m_set_State[0] |= 0x3;
}

inline
CEHistoryItem_Base::C_E::TQueryKey& CEHistoryItem_Base::C_E::SetQueryKey(void)
{
#ifdef _DEBUG
    if (!IsSetQueryKey()) {
        m_QueryKey = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_QueryKey;
}

inline
bool CEHistoryItem_Base::C_E::IsSetQueryName(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetQueryName(void) const
{
    return IsSetQueryName();
}

inline
const CEHistoryItem_Base::C_E::TQueryName& CEHistoryItem_Base::C_E::GetQueryName(void) const
{
    if (!CanGetQueryName()) {
        ThrowUnassigned(1);
    }
    return m_QueryName;
}

inline
void CEHistoryItem_Base::C_E::SetQueryName(const CEHistoryItem_Base::C_E::TQueryName& value)
{
    m_QueryName = value;
    m_set_State[0] |= 0xc;
}

inline
CEHistoryItem_Base::C_E::TQueryName& CEHistoryItem_Base::C_E::SetQueryName(void)
{
#ifdef _DEBUG
    if (!IsSetQueryName()) {
        m_QueryName = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_QueryName;
}

inline
bool CEHistoryItem_Base::C_E::IsSetDbName(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetDbName(void) const
{
    return IsSetDbName();
}

inline
const CEHistoryItem_Base::C_E::TDbName& CEHistoryItem_Base::C_E::GetDbName(void) const
{
    if (!CanGetDbName()) {
        ThrowUnassigned(2);
    }
    return m_DbName;
}

inline
void CEHistoryItem_Base::C_E::SetDbName(const CEHistoryItem_Base::C_E::TDbName& value)
{
    m_DbName = value;
    m_set_State[0] |= 0x30;
}

inline
CEHistoryItem_Base::C_E::TDbName& CEHistoryItem_Base::C_E::SetDbName(void)
{
#ifdef _DEBUG
    if (!IsSetDbName()) {
        m_DbName = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_DbName;
}

inline
bool CEHistoryItem_Base::C_E::IsSetTitle(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetTitle(void) const
{
    return IsSetTitle();
}

inline
const CEHistoryItem_Base::C_E::TTitle& CEHistoryItem_Base::C_E::GetTitle(void) const
{
    if (!CanGetTitle()) {
        ThrowUnassigned(3);
    }
    return m_Title;
}

inline
void CEHistoryItem_Base::C_E::SetTitle(const CEHistoryItem_Base::C_E::TTitle& value)
{
    m_Title = value;
    m_set_State[0] |= 0xc0;
}

inline
CEHistoryItem_Base::C_E::TTitle& CEHistoryItem_Base::C_E::SetTitle(void)
{
#ifdef _DEBUG
    if (!IsSetTitle()) {
        m_Title = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Title;
}

inline
bool CEHistoryItem_Base::C_E::IsSetTime(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetTime(void) const
{
    return IsSetTime();
}

inline
const CEHistoryItem_Base::C_E::TTime& CEHistoryItem_Base::C_E::GetTime(void) const
{
    if (!CanGetTime()) {
        ThrowUnassigned(4);
    }
    return m_Time;
}

inline
void CEHistoryItem_Base::C_E::SetTime(const CEHistoryItem_Base::C_E::TTime& value)
{
    m_Time = value;
    m_set_State[0] |= 0x300;
}

inline
CEHistoryItem_Base::C_E::TTime& CEHistoryItem_Base::C_E::SetTime(void)
{
#ifdef _DEBUG
    if (!IsSetTime()) {
        m_Time = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Time;
}

inline
bool CEHistoryItem_Base::C_E::IsSetCount(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CEHistoryItem_Base::C_E::CanGetCount(void) const
{
    return IsSetCount();
}

inline
const CEHistoryItem_Base::C_E::TCount& CEHistoryItem_Base::C_E::GetCount(void) const
{
    if (!CanGetCount()) {
        ThrowUnassigned(5);
    }
    return m_Count;
}

inline
void CEHistoryItem_Base::C_E::SetCount(const CEHistoryItem_Base::C_E::TCount& value)
{
    m_Count = value;
    m_set_State[0] |= 0xc00;
}

inline
CEHistoryItem_Base::C_E::TCount& CEHistoryItem_Base::C_E::SetCount(void)
{
#ifdef _DEBUG
    if (!IsSetCount()) {
        m_Count = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Count;
}

inline
bool CEHistoryItem_Base::IsSet(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CEHistoryItem_Base::CanGet(void) const
{
    return true;
}

inline
const CEHistoryItem_Base::Tdata& CEHistoryItem_Base::Get(void) const
{
    return m_data;
}

inline
CEHistoryItem_Base::Tdata& CEHistoryItem_Base::Set(void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

inline
CEHistoryItem_Base::operator const CEHistoryItem_Base::Tdata& (void) const
{
    return m_data;
}

inline
CEHistoryItem_Base::operator CEHistoryItem_Base::Tdata& (void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_ehistory_SCOPE // namespace ehistory::


#endif // ehistory__OBJTOOLS_EUTILS_EHISTORY_EHISTORYITEM_BASE_HPP