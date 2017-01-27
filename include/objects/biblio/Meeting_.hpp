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

/// @file Meeting_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'biblio.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BIBLIO_MEETING_BASE_HPP
#define OBJECTS_BIBLIO_MEETING_BASE_HPP

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


// forward declarations
class CAffil;
class CDate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_BIBLIO_EXPORT CMeeting_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMeeting_Base(void);
    // destructor
    virtual ~CMeeting_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TNumber;
    typedef CDate TDate;
    typedef CAffil TPlace;

    // getters
    // setters

    /// mandatory
    /// typedef string TNumber
    ///  Check whether the Number data member has been assigned a value.
    bool IsSetNumber(void) const;
    /// Check whether it is safe or not to call GetNumber method.
    bool CanGetNumber(void) const;
    void ResetNumber(void);
    const TNumber& GetNumber(void) const;
    void SetNumber(const TNumber& value);
    TNumber& SetNumber(void);

    /// mandatory
    /// typedef CDate TDate
    ///  Check whether the Date data member has been assigned a value.
    bool IsSetDate(void) const;
    /// Check whether it is safe or not to call GetDate method.
    bool CanGetDate(void) const;
    void ResetDate(void);
    const TDate& GetDate(void) const;
    void SetDate(TDate& value);
    TDate& SetDate(void);

    /// optional
    /// typedef CAffil TPlace
    ///  Check whether the Place data member has been assigned a value.
    bool IsSetPlace(void) const;
    /// Check whether it is safe or not to call GetPlace method.
    bool CanGetPlace(void) const;
    void ResetPlace(void);
    const TPlace& GetPlace(void) const;
    void SetPlace(TPlace& value);
    TPlace& SetPlace(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMeeting_Base(const CMeeting_Base&);
    CMeeting_Base& operator=(const CMeeting_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Number;
    CRef< TDate > m_Date;
    CRef< TPlace > m_Place;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMeeting_Base::IsSetNumber(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMeeting_Base::CanGetNumber(void) const
{
    return IsSetNumber();
}

inline
const CMeeting_Base::TNumber& CMeeting_Base::GetNumber(void) const
{
    if (!CanGetNumber()) {
        ThrowUnassigned(0);
    }
    return m_Number;
}

inline
void CMeeting_Base::SetNumber(const CMeeting_Base::TNumber& value)
{
    m_Number = value;
    m_set_State[0] |= 0x3;
}

inline
CMeeting_Base::TNumber& CMeeting_Base::SetNumber(void)
{
#ifdef _DEBUG
    if (!IsSetNumber()) {
        m_Number = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Number;
}

inline
bool CMeeting_Base::IsSetDate(void) const
{
    return m_Date.NotEmpty();
}

inline
bool CMeeting_Base::CanGetDate(void) const
{
    return true;
}

inline
const CMeeting_Base::TDate& CMeeting_Base::GetDate(void) const
{
    if ( !m_Date ) {
        const_cast<CMeeting_Base*>(this)->ResetDate();
    }
    return (*m_Date);
}

inline
CMeeting_Base::TDate& CMeeting_Base::SetDate(void)
{
    if ( !m_Date ) {
        ResetDate();
    }
    return (*m_Date);
}

inline
bool CMeeting_Base::IsSetPlace(void) const
{
    return m_Place.NotEmpty();
}

inline
bool CMeeting_Base::CanGetPlace(void) const
{
    return IsSetPlace();
}

inline
const CMeeting_Base::TPlace& CMeeting_Base::GetPlace(void) const
{
    if (!CanGetPlace()) {
        ThrowUnassigned(2);
    }
    return (*m_Place);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BIBLIO_MEETING_BASE_HPP
