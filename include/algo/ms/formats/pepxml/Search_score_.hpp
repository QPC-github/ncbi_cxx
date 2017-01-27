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

/// @file Search_score_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_SEARCH_SCORE_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_SEARCH_SCORE_BASE_HPP

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
class NCBI_PEPXML_EXPORT CSearch_score_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSearch_score_Base(void);
    // destructor
    virtual ~CSearch_score_Base(void);

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
        typedef string TName;
        typedef string TValue;
        typedef string TType;
    
        // getters
        // setters
    
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
    
        /// optional
        /// typedef string TType
        ///  Check whether the Type data member has been assigned a value.
        bool IsSetType(void) const;
        /// Check whether it is safe or not to call GetType method.
        bool CanGetType(void) const;
        void ResetType(void);
        const TType& GetType(void) const;
        void SetType(const TType& value);
        TType& SetType(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Name;
        string m_Value;
        string m_Type;
    };
    // types
    typedef C_Attlist TAttlist;

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
    ///  Check whether the Search_score data member has been assigned a value.
    bool IsSetSearch_score(void) const;
    /// Check whether it is safe or not to call GetSearch_score method.
    bool CanGetSearch_score(void) const;
    void ResetSearch_score(void);
    void SetSearch_score(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSearch_score_Base(const CSearch_score_Base&);
    CSearch_score_Base& operator=(const CSearch_score_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSearch_score_Base::C_Attlist::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSearch_score_Base::C_Attlist::CanGetName(void) const
{
    return IsSetName();
}

inline
const CSearch_score_Base::C_Attlist::TName& CSearch_score_Base::C_Attlist::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(0);
    }
    return m_Name;
}

inline
void CSearch_score_Base::C_Attlist::SetName(const CSearch_score_Base::C_Attlist::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0x3;
}

inline
CSearch_score_Base::C_Attlist::TName& CSearch_score_Base::C_Attlist::SetName(void)
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
bool CSearch_score_Base::C_Attlist::IsSetValue(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSearch_score_Base::C_Attlist::CanGetValue(void) const
{
    return IsSetValue();
}

inline
const CSearch_score_Base::C_Attlist::TValue& CSearch_score_Base::C_Attlist::GetValue(void) const
{
    if (!CanGetValue()) {
        ThrowUnassigned(1);
    }
    return m_Value;
}

inline
void CSearch_score_Base::C_Attlist::SetValue(const CSearch_score_Base::C_Attlist::TValue& value)
{
    m_Value = value;
    m_set_State[0] |= 0xc;
}

inline
CSearch_score_Base::C_Attlist::TValue& CSearch_score_Base::C_Attlist::SetValue(void)
{
#ifdef _DEBUG
    if (!IsSetValue()) {
        m_Value = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Value;
}

inline
bool CSearch_score_Base::C_Attlist::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CSearch_score_Base::C_Attlist::CanGetType(void) const
{
    return IsSetType();
}

inline
const CSearch_score_Base::C_Attlist::TType& CSearch_score_Base::C_Attlist::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(2);
    }
    return m_Type;
}

inline
void CSearch_score_Base::C_Attlist::SetType(const CSearch_score_Base::C_Attlist::TType& value)
{
    m_Type = value;
    m_set_State[0] |= 0x30;
}

inline
CSearch_score_Base::C_Attlist::TType& CSearch_score_Base::C_Attlist::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        m_Type = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Type;
}

inline
bool CSearch_score_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CSearch_score_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CSearch_score_Base::TAttlist& CSearch_score_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CSearch_score_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CSearch_score_Base::TAttlist& CSearch_score_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    SetSearch_score();
    return (*m_Attlist);
}

inline
bool CSearch_score_Base::IsSetSearch_score(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSearch_score_Base::CanGetSearch_score(void) const
{
    return false;
}

inline
void CSearch_score_Base::ResetSearch_score(void)
{
    m_set_State[0] &= ~0xc;
}

inline
void CSearch_score_Base::SetSearch_score(void)
{
    m_set_State[0] |= 0xc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_SEARCH_SCORE_BASE_HPP
