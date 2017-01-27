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

/// @file UserFormat_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'objprt.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OBJPRT_USERFORMAT_BASE_HPP
#define OBJECTS_OBJPRT_USERFORMAT_BASE_HPP

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
class NCBI_OBJPRT_EXPORT CUserFormat_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CUserFormat_Base(void);
    // destructor
    virtual ~CUserFormat_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TPrintfunc;
    typedef string TDefaultfunc;

    // getters
    // setters

    /// mandatory
    /// typedef string TPrintfunc
    ///  Check whether the Printfunc data member has been assigned a value.
    bool IsSetPrintfunc(void) const;
    /// Check whether it is safe or not to call GetPrintfunc method.
    bool CanGetPrintfunc(void) const;
    void ResetPrintfunc(void);
    const TPrintfunc& GetPrintfunc(void) const;
    void SetPrintfunc(const TPrintfunc& value);
    TPrintfunc& SetPrintfunc(void);

    /// optional
    /// typedef string TDefaultfunc
    ///  Check whether the Defaultfunc data member has been assigned a value.
    bool IsSetDefaultfunc(void) const;
    /// Check whether it is safe or not to call GetDefaultfunc method.
    bool CanGetDefaultfunc(void) const;
    void ResetDefaultfunc(void);
    const TDefaultfunc& GetDefaultfunc(void) const;
    void SetDefaultfunc(const TDefaultfunc& value);
    TDefaultfunc& SetDefaultfunc(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CUserFormat_Base(const CUserFormat_Base&);
    CUserFormat_Base& operator=(const CUserFormat_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Printfunc;
    string m_Defaultfunc;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CUserFormat_Base::IsSetPrintfunc(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CUserFormat_Base::CanGetPrintfunc(void) const
{
    return IsSetPrintfunc();
}

inline
const CUserFormat_Base::TPrintfunc& CUserFormat_Base::GetPrintfunc(void) const
{
    if (!CanGetPrintfunc()) {
        ThrowUnassigned(0);
    }
    return m_Printfunc;
}

inline
void CUserFormat_Base::SetPrintfunc(const CUserFormat_Base::TPrintfunc& value)
{
    m_Printfunc = value;
    m_set_State[0] |= 0x3;
}

inline
CUserFormat_Base::TPrintfunc& CUserFormat_Base::SetPrintfunc(void)
{
#ifdef _DEBUG
    if (!IsSetPrintfunc()) {
        m_Printfunc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Printfunc;
}

inline
bool CUserFormat_Base::IsSetDefaultfunc(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CUserFormat_Base::CanGetDefaultfunc(void) const
{
    return IsSetDefaultfunc();
}

inline
const CUserFormat_Base::TDefaultfunc& CUserFormat_Base::GetDefaultfunc(void) const
{
    if (!CanGetDefaultfunc()) {
        ThrowUnassigned(1);
    }
    return m_Defaultfunc;
}

inline
void CUserFormat_Base::SetDefaultfunc(const CUserFormat_Base::TDefaultfunc& value)
{
    m_Defaultfunc = value;
    m_set_State[0] |= 0xc;
}

inline
CUserFormat_Base::TDefaultfunc& CUserFormat_Base::SetDefaultfunc(void)
{
#ifdef _DEBUG
    if (!IsSetDefaultfunc()) {
        m_Defaultfunc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Defaultfunc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OBJPRT_USERFORMAT_BASE_HPP
