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

/// @file Fix_pub_caps_action_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_FIX_PUB_CAPS_ACTION_BASE_HPP
#define OBJECTS_MACRO_FIX_PUB_CAPS_ACTION_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CConstraint_choice_set;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CFix_pub_caps_action_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CFix_pub_caps_action_Base(void);
    // destructor
    virtual ~CFix_pub_caps_action_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef bool TTitle;
    typedef bool TAuthors;
    typedef bool TAffiliation;
    typedef bool TAffil_country;
    typedef bool TPunct_only;
    typedef CConstraint_choice_set TConstraint;

    // getters
    // setters

    /// optional
    /// typedef bool TTitle
    ///  Check whether the Title data member has been assigned a value.
    bool IsSetTitle(void) const;
    /// Check whether it is safe or not to call GetTitle method.
    bool CanGetTitle(void) const;
    void ResetTitle(void);
    TTitle GetTitle(void) const;
    void SetTitle(TTitle value);
    TTitle& SetTitle(void);

    /// optional
    /// typedef bool TAuthors
    ///  Check whether the Authors data member has been assigned a value.
    bool IsSetAuthors(void) const;
    /// Check whether it is safe or not to call GetAuthors method.
    bool CanGetAuthors(void) const;
    void ResetAuthors(void);
    TAuthors GetAuthors(void) const;
    void SetAuthors(TAuthors value);
    TAuthors& SetAuthors(void);

    /// optional
    /// typedef bool TAffiliation
    ///  Check whether the Affiliation data member has been assigned a value.
    bool IsSetAffiliation(void) const;
    /// Check whether it is safe or not to call GetAffiliation method.
    bool CanGetAffiliation(void) const;
    void ResetAffiliation(void);
    TAffiliation GetAffiliation(void) const;
    void SetAffiliation(TAffiliation value);
    TAffiliation& SetAffiliation(void);

    /// optional
    /// typedef bool TAffil_country
    ///  Check whether the Affil_country data member has been assigned a value.
    bool IsSetAffil_country(void) const;
    /// Check whether it is safe or not to call GetAffil_country method.
    bool CanGetAffil_country(void) const;
    void ResetAffil_country(void);
    TAffil_country GetAffil_country(void) const;
    void SetAffil_country(TAffil_country value);
    TAffil_country& SetAffil_country(void);

    /// optional with default false
    /// typedef bool TPunct_only
    ///  Check whether the Punct_only data member has been assigned a value.
    bool IsSetPunct_only(void) const;
    /// Check whether it is safe or not to call GetPunct_only method.
    bool CanGetPunct_only(void) const;
    void ResetPunct_only(void);
    void SetDefaultPunct_only(void);
    TPunct_only GetPunct_only(void) const;
    void SetPunct_only(TPunct_only value);
    TPunct_only& SetPunct_only(void);

    /// optional
    /// typedef CConstraint_choice_set TConstraint
    ///  Check whether the Constraint data member has been assigned a value.
    bool IsSetConstraint(void) const;
    /// Check whether it is safe or not to call GetConstraint method.
    bool CanGetConstraint(void) const;
    void ResetConstraint(void);
    const TConstraint& GetConstraint(void) const;
    void SetConstraint(TConstraint& value);
    TConstraint& SetConstraint(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CFix_pub_caps_action_Base(const CFix_pub_caps_action_Base&);
    CFix_pub_caps_action_Base& operator=(const CFix_pub_caps_action_Base&);

    // data
    Uint4 m_set_State[1];
    bool m_Title;
    bool m_Authors;
    bool m_Affiliation;
    bool m_Affil_country;
    bool m_Punct_only;
    CRef< TConstraint > m_Constraint;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CFix_pub_caps_action_Base::IsSetTitle(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CFix_pub_caps_action_Base::CanGetTitle(void) const
{
    return IsSetTitle();
}

inline
void CFix_pub_caps_action_Base::ResetTitle(void)
{
    m_Title = 0;
    m_set_State[0] &= ~0x3;
}

inline
CFix_pub_caps_action_Base::TTitle CFix_pub_caps_action_Base::GetTitle(void) const
{
    if (!CanGetTitle()) {
        ThrowUnassigned(0);
    }
    return m_Title;
}

inline
void CFix_pub_caps_action_Base::SetTitle(CFix_pub_caps_action_Base::TTitle value)
{
    m_Title = value;
    m_set_State[0] |= 0x3;
}

inline
CFix_pub_caps_action_Base::TTitle& CFix_pub_caps_action_Base::SetTitle(void)
{
#ifdef _DEBUG
    if (!IsSetTitle()) {
        memset(&m_Title,UnassignedByte(),sizeof(m_Title));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Title;
}

inline
bool CFix_pub_caps_action_Base::IsSetAuthors(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CFix_pub_caps_action_Base::CanGetAuthors(void) const
{
    return IsSetAuthors();
}

inline
void CFix_pub_caps_action_Base::ResetAuthors(void)
{
    m_Authors = 0;
    m_set_State[0] &= ~0xc;
}

inline
CFix_pub_caps_action_Base::TAuthors CFix_pub_caps_action_Base::GetAuthors(void) const
{
    if (!CanGetAuthors()) {
        ThrowUnassigned(1);
    }
    return m_Authors;
}

inline
void CFix_pub_caps_action_Base::SetAuthors(CFix_pub_caps_action_Base::TAuthors value)
{
    m_Authors = value;
    m_set_State[0] |= 0xc;
}

inline
CFix_pub_caps_action_Base::TAuthors& CFix_pub_caps_action_Base::SetAuthors(void)
{
#ifdef _DEBUG
    if (!IsSetAuthors()) {
        memset(&m_Authors,UnassignedByte(),sizeof(m_Authors));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Authors;
}

inline
bool CFix_pub_caps_action_Base::IsSetAffiliation(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CFix_pub_caps_action_Base::CanGetAffiliation(void) const
{
    return IsSetAffiliation();
}

inline
void CFix_pub_caps_action_Base::ResetAffiliation(void)
{
    m_Affiliation = 0;
    m_set_State[0] &= ~0x30;
}

inline
CFix_pub_caps_action_Base::TAffiliation CFix_pub_caps_action_Base::GetAffiliation(void) const
{
    if (!CanGetAffiliation()) {
        ThrowUnassigned(2);
    }
    return m_Affiliation;
}

inline
void CFix_pub_caps_action_Base::SetAffiliation(CFix_pub_caps_action_Base::TAffiliation value)
{
    m_Affiliation = value;
    m_set_State[0] |= 0x30;
}

inline
CFix_pub_caps_action_Base::TAffiliation& CFix_pub_caps_action_Base::SetAffiliation(void)
{
#ifdef _DEBUG
    if (!IsSetAffiliation()) {
        memset(&m_Affiliation,UnassignedByte(),sizeof(m_Affiliation));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Affiliation;
}

inline
bool CFix_pub_caps_action_Base::IsSetAffil_country(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CFix_pub_caps_action_Base::CanGetAffil_country(void) const
{
    return IsSetAffil_country();
}

inline
void CFix_pub_caps_action_Base::ResetAffil_country(void)
{
    m_Affil_country = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CFix_pub_caps_action_Base::TAffil_country CFix_pub_caps_action_Base::GetAffil_country(void) const
{
    if (!CanGetAffil_country()) {
        ThrowUnassigned(3);
    }
    return m_Affil_country;
}

inline
void CFix_pub_caps_action_Base::SetAffil_country(CFix_pub_caps_action_Base::TAffil_country value)
{
    m_Affil_country = value;
    m_set_State[0] |= 0xc0;
}

inline
CFix_pub_caps_action_Base::TAffil_country& CFix_pub_caps_action_Base::SetAffil_country(void)
{
#ifdef _DEBUG
    if (!IsSetAffil_country()) {
        memset(&m_Affil_country,UnassignedByte(),sizeof(m_Affil_country));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Affil_country;
}

inline
bool CFix_pub_caps_action_Base::IsSetPunct_only(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CFix_pub_caps_action_Base::CanGetPunct_only(void) const
{
    return true;
}

inline
void CFix_pub_caps_action_Base::ResetPunct_only(void)
{
    m_Punct_only = false;
    m_set_State[0] &= ~0x300;
}

inline
void CFix_pub_caps_action_Base::SetDefaultPunct_only(void)
{
    ResetPunct_only();
}

inline
CFix_pub_caps_action_Base::TPunct_only CFix_pub_caps_action_Base::GetPunct_only(void) const
{
    return m_Punct_only;
}

inline
void CFix_pub_caps_action_Base::SetPunct_only(CFix_pub_caps_action_Base::TPunct_only value)
{
    m_Punct_only = value;
    m_set_State[0] |= 0x300;
}

inline
CFix_pub_caps_action_Base::TPunct_only& CFix_pub_caps_action_Base::SetPunct_only(void)
{
#ifdef _DEBUG
    if (!IsSetPunct_only()) {
        memset(&m_Punct_only,UnassignedByte(),sizeof(m_Punct_only));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Punct_only;
}

inline
bool CFix_pub_caps_action_Base::IsSetConstraint(void) const
{
    return m_Constraint.NotEmpty();
}

inline
bool CFix_pub_caps_action_Base::CanGetConstraint(void) const
{
    return IsSetConstraint();
}

inline
const CFix_pub_caps_action_Base::TConstraint& CFix_pub_caps_action_Base::GetConstraint(void) const
{
    if (!CanGetConstraint()) {
        ThrowUnassigned(5);
    }
    return (*m_Constraint);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_FIX_PUB_CAPS_ACTION_BASE_HPP
