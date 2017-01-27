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

/// @file Filter_Value_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'we_cpp.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef SERIAL_TEST_FILTER_VALUE_BASE_HPP
#define SERIAL_TEST_FILTER_VALUE_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Filters definition
class CFilter_Value_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CFilter_Value_Base(void);
    // destructor
    virtual ~CFilter_Value_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TName;
    typedef string TValue;

    // getters
    // setters

    /// filter field name
    /// mandatory
    /// typedef string TName
    ///  Check whether the Name data member has been assigned a value.
    bool IsSetName(void) const;
    /// Check whether it is safe or not to call GetName method.
    bool CanGetName(void) const;
    void ResetName(void);
    const TName& GetName(void) const;
    void SetName(const TName& value);
    TName& SetName(void);

    /// filter value
    /// mandatory
    /// typedef string TValue
    ///  Check whether the Value data member has been assigned a value.
    bool IsSetValue(void) const;
    /// Check whether it is safe or not to call GetValue method.
    bool CanGetValue(void) const;
    void ResetValue(void);
    const TValue& GetValue(void) const;
    void SetValue(const TValue& value);
    TValue& SetValue(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CFilter_Value_Base(const CFilter_Value_Base&);
    CFilter_Value_Base& operator=(const CFilter_Value_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Name;
    string m_Value;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CFilter_Value_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CFilter_Value_Base::CanGetName(void) const
{
    return IsSetName();
}

inline
const CFilter_Value_Base::TName& CFilter_Value_Base::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(0);
    }
    return m_Name;
}

inline
void CFilter_Value_Base::SetName(const CFilter_Value_Base::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0x3;
}

inline
CFilter_Value_Base::TName& CFilter_Value_Base::SetName(void)
{
#ifdef _DEBUG
    if (!IsSetName()) {
        m_Name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Name;
}

inline
bool CFilter_Value_Base::IsSetValue(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CFilter_Value_Base::CanGetValue(void) const
{
    return IsSetValue();
}

inline
const CFilter_Value_Base::TValue& CFilter_Value_Base::GetValue(void) const
{
    if (!CanGetValue()) {
        ThrowUnassigned(1);
    }
    return m_Value;
}

inline
void CFilter_Value_Base::SetValue(const CFilter_Value_Base::TValue& value)
{
    m_Value = value;
    m_set_State[0] |= 0xc;
}

inline
CFilter_Value_Base::TValue& CFilter_Value_Base::SetValue(void)
{
#ifdef _DEBUG
    if (!IsSetValue()) {
        m_Value = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Value;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // SERIAL_TEST_FILTER_VALUE_BASE_HPP
