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

/// @file Cit_let_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'biblio.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BIBLIO_CIT_LET_BASE_HPP
#define OBJECTS_BIBLIO_CIT_LET_BASE_HPP

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
class CCit_book;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// letter, thesis, or manuscript
class NCBI_BIBLIO_EXPORT CCit_let_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCit_let_Base(void);
    // destructor
    virtual ~CCit_let_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum EType {
        eType_manuscript = 1,
        eType_letter     = 2,
        eType_thesis     = 3
    };
    
    /// Access to EType's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EType)(void);
    
    // types
    typedef CCit_book TCit;
    typedef string TMan_id;
    typedef EType TType;

    // getters
    // setters

    /// same fields as a book
    /// mandatory
    /// typedef CCit_book TCit
    ///  Check whether the Cit data member has been assigned a value.
    bool IsSetCit(void) const;
    /// Check whether it is safe or not to call GetCit method.
    bool CanGetCit(void) const;
    void ResetCit(void);
    const TCit& GetCit(void) const;
    void SetCit(TCit& value);
    TCit& SetCit(void);

    /// Manuscript identifier
    /// optional
    /// typedef string TMan_id
    ///  Check whether the Man_id data member has been assigned a value.
    bool IsSetMan_id(void) const;
    /// Check whether it is safe or not to call GetMan_id method.
    bool CanGetMan_id(void) const;
    void ResetMan_id(void);
    const TMan_id& GetMan_id(void) const;
    void SetMan_id(const TMan_id& value);
    TMan_id& SetMan_id(void);

    /// optional
    /// typedef EType TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    TType GetType(void) const;
    void SetType(TType value);
    TType& SetType(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCit_let_Base(const CCit_let_Base&);
    CCit_let_Base& operator=(const CCit_let_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TCit > m_Cit;
    string m_Man_id;
    EType m_Type;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCit_let_Base::IsSetCit(void) const
{
    return m_Cit.NotEmpty();
}

inline
bool CCit_let_Base::CanGetCit(void) const
{
    return true;
}

inline
const CCit_let_Base::TCit& CCit_let_Base::GetCit(void) const
{
    if ( !m_Cit ) {
        const_cast<CCit_let_Base*>(this)->ResetCit();
    }
    return (*m_Cit);
}

inline
CCit_let_Base::TCit& CCit_let_Base::SetCit(void)
{
    if ( !m_Cit ) {
        ResetCit();
    }
    return (*m_Cit);
}

inline
bool CCit_let_Base::IsSetMan_id(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCit_let_Base::CanGetMan_id(void) const
{
    return IsSetMan_id();
}

inline
const CCit_let_Base::TMan_id& CCit_let_Base::GetMan_id(void) const
{
    if (!CanGetMan_id()) {
        ThrowUnassigned(1);
    }
    return m_Man_id;
}

inline
void CCit_let_Base::SetMan_id(const CCit_let_Base::TMan_id& value)
{
    m_Man_id = value;
    m_set_State[0] |= 0xc;
}

inline
CCit_let_Base::TMan_id& CCit_let_Base::SetMan_id(void)
{
#ifdef _DEBUG
    if (!IsSetMan_id()) {
        m_Man_id = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Man_id;
}

inline
bool CCit_let_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CCit_let_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
void CCit_let_Base::ResetType(void)
{
    m_Type = (EType)(0);
    m_set_State[0] &= ~0x30;
}

inline
CCit_let_Base::TType CCit_let_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(2);
    }
    return m_Type;
}

inline
void CCit_let_Base::SetType(CCit_let_Base::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0x30;
}

inline
CCit_let_Base::TType& CCit_let_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Type;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BIBLIO_CIT_LET_BASE_HPP
