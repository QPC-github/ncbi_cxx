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

/// @file Search_database_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_SEARCH_DATABASE_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_SEARCH_DATABASE_BASE_HPP

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
class NCBI_PEPXML_EXPORT CSearch_database_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSearch_database_Base(void);
    // destructor
    virtual ~CSearch_database_Base(void);

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
    
        enum EAttlist_type {
            eAttlist_type_AA = 1,
            eAttlist_type_NA = 2
        };
        
        /// Access to EAttlist_type's attributes (values, names) as defined in spec
        static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EAttlist_type)(void);
        
        // types
        typedef string TLocal_path;
        typedef string TURL;
        typedef string TDatabase_name;
        typedef string TOrig_database_url;
        typedef string TDatabase_release_date;
        typedef string TDatabase_release_identifier;
        typedef int TSize_in_db_entries;
        typedef int TSize_of_residues;
        typedef EAttlist_type TType;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef string TLocal_path
        ///  Check whether the Local_path data member has been assigned a value.
        bool IsSetLocal_path(void) const;
        /// Check whether it is safe or not to call GetLocal_path method.
        bool CanGetLocal_path(void) const;
        void ResetLocal_path(void);
        const TLocal_path& GetLocal_path(void) const;
        void SetLocal_path(const TLocal_path& value);
        TLocal_path& SetLocal_path(void);
    
        /// optional
        /// typedef string TURL
        ///  Check whether the URL data member has been assigned a value.
        bool IsSetURL(void) const;
        /// Check whether it is safe or not to call GetURL method.
        bool CanGetURL(void) const;
        void ResetURL(void);
        const TURL& GetURL(void) const;
        void SetURL(const TURL& value);
        TURL& SetURL(void);
    
        /// optional
        /// typedef string TDatabase_name
        ///  Check whether the Database_name data member has been assigned a value.
        bool IsSetDatabase_name(void) const;
        /// Check whether it is safe or not to call GetDatabase_name method.
        bool CanGetDatabase_name(void) const;
        void ResetDatabase_name(void);
        const TDatabase_name& GetDatabase_name(void) const;
        void SetDatabase_name(const TDatabase_name& value);
        TDatabase_name& SetDatabase_name(void);
    
        /// optional
        /// typedef string TOrig_database_url
        ///  Check whether the Orig_database_url data member has been assigned a value.
        bool IsSetOrig_database_url(void) const;
        /// Check whether it is safe or not to call GetOrig_database_url method.
        bool CanGetOrig_database_url(void) const;
        void ResetOrig_database_url(void);
        const TOrig_database_url& GetOrig_database_url(void) const;
        void SetOrig_database_url(const TOrig_database_url& value);
        TOrig_database_url& SetOrig_database_url(void);
    
        /// optional
        /// typedef string TDatabase_release_date
        ///  Check whether the Database_release_date data member has been assigned a value.
        bool IsSetDatabase_release_date(void) const;
        /// Check whether it is safe or not to call GetDatabase_release_date method.
        bool CanGetDatabase_release_date(void) const;
        void ResetDatabase_release_date(void);
        const TDatabase_release_date& GetDatabase_release_date(void) const;
        void SetDatabase_release_date(const TDatabase_release_date& value);
        TDatabase_release_date& SetDatabase_release_date(void);
    
        /// optional
        /// typedef string TDatabase_release_identifier
        ///  Check whether the Database_release_identifier data member has been assigned a value.
        bool IsSetDatabase_release_identifier(void) const;
        /// Check whether it is safe or not to call GetDatabase_release_identifier method.
        bool CanGetDatabase_release_identifier(void) const;
        void ResetDatabase_release_identifier(void);
        const TDatabase_release_identifier& GetDatabase_release_identifier(void) const;
        void SetDatabase_release_identifier(const TDatabase_release_identifier& value);
        TDatabase_release_identifier& SetDatabase_release_identifier(void);
    
        /// optional
        /// typedef int TSize_in_db_entries
        ///  Check whether the Size_in_db_entries data member has been assigned a value.
        bool IsSetSize_in_db_entries(void) const;
        /// Check whether it is safe or not to call GetSize_in_db_entries method.
        bool CanGetSize_in_db_entries(void) const;
        void ResetSize_in_db_entries(void);
        TSize_in_db_entries GetSize_in_db_entries(void) const;
        void SetSize_in_db_entries(TSize_in_db_entries value);
        TSize_in_db_entries& SetSize_in_db_entries(void);
    
        /// optional
        /// typedef int TSize_of_residues
        ///  Check whether the Size_of_residues data member has been assigned a value.
        bool IsSetSize_of_residues(void) const;
        /// Check whether it is safe or not to call GetSize_of_residues method.
        bool CanGetSize_of_residues(void) const;
        void ResetSize_of_residues(void);
        TSize_of_residues GetSize_of_residues(void) const;
        void SetSize_of_residues(TSize_of_residues value);
        TSize_of_residues& SetSize_of_residues(void);
    
        ///Database type (AA=amino acid, NA=nucleic acid)
        /// mandatory
        /// typedef EAttlist_type TType
        ///  Check whether the Type data member has been assigned a value.
        bool IsSetType(void) const;
        /// Check whether it is safe or not to call GetType method.
        bool CanGetType(void) const;
        void ResetType(void);
        TType GetType(void) const;
        void SetType(TType value);
        TType& SetType(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Local_path;
        string m_URL;
        string m_Database_name;
        string m_Orig_database_url;
        string m_Database_release_date;
        string m_Database_release_identifier;
        int m_Size_in_db_entries;
        int m_Size_of_residues;
        EAttlist_type m_Type;
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
    ///  Check whether the Search_database data member has been assigned a value.
    bool IsSetSearch_database(void) const;
    /// Check whether it is safe or not to call GetSearch_database method.
    bool CanGetSearch_database(void) const;
    void ResetSearch_database(void);
    void SetSearch_database(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSearch_database_Base(const CSearch_database_Base&);
    CSearch_database_Base& operator=(const CSearch_database_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSearch_database_Base::C_Attlist::IsSetLocal_path(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetLocal_path(void) const
{
    return IsSetLocal_path();
}

inline
const CSearch_database_Base::C_Attlist::TLocal_path& CSearch_database_Base::C_Attlist::GetLocal_path(void) const
{
    if (!CanGetLocal_path()) {
        ThrowUnassigned(0);
    }
    return m_Local_path;
}

inline
void CSearch_database_Base::C_Attlist::SetLocal_path(const CSearch_database_Base::C_Attlist::TLocal_path& value)
{
    m_Local_path = value;
    m_set_State[0] |= 0x3;
}

inline
CSearch_database_Base::C_Attlist::TLocal_path& CSearch_database_Base::C_Attlist::SetLocal_path(void)
{
#ifdef _DEBUG
    if (!IsSetLocal_path()) {
        m_Local_path = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Local_path;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetURL(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetURL(void) const
{
    return IsSetURL();
}

inline
const CSearch_database_Base::C_Attlist::TURL& CSearch_database_Base::C_Attlist::GetURL(void) const
{
    if (!CanGetURL()) {
        ThrowUnassigned(1);
    }
    return m_URL;
}

inline
void CSearch_database_Base::C_Attlist::SetURL(const CSearch_database_Base::C_Attlist::TURL& value)
{
    m_URL = value;
    m_set_State[0] |= 0xc;
}

inline
CSearch_database_Base::C_Attlist::TURL& CSearch_database_Base::C_Attlist::SetURL(void)
{
#ifdef _DEBUG
    if (!IsSetURL()) {
        m_URL = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_URL;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetDatabase_name(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetDatabase_name(void) const
{
    return IsSetDatabase_name();
}

inline
const CSearch_database_Base::C_Attlist::TDatabase_name& CSearch_database_Base::C_Attlist::GetDatabase_name(void) const
{
    if (!CanGetDatabase_name()) {
        ThrowUnassigned(2);
    }
    return m_Database_name;
}

inline
void CSearch_database_Base::C_Attlist::SetDatabase_name(const CSearch_database_Base::C_Attlist::TDatabase_name& value)
{
    m_Database_name = value;
    m_set_State[0] |= 0x30;
}

inline
CSearch_database_Base::C_Attlist::TDatabase_name& CSearch_database_Base::C_Attlist::SetDatabase_name(void)
{
#ifdef _DEBUG
    if (!IsSetDatabase_name()) {
        m_Database_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Database_name;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetOrig_database_url(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetOrig_database_url(void) const
{
    return IsSetOrig_database_url();
}

inline
const CSearch_database_Base::C_Attlist::TOrig_database_url& CSearch_database_Base::C_Attlist::GetOrig_database_url(void) const
{
    if (!CanGetOrig_database_url()) {
        ThrowUnassigned(3);
    }
    return m_Orig_database_url;
}

inline
void CSearch_database_Base::C_Attlist::SetOrig_database_url(const CSearch_database_Base::C_Attlist::TOrig_database_url& value)
{
    m_Orig_database_url = value;
    m_set_State[0] |= 0xc0;
}

inline
CSearch_database_Base::C_Attlist::TOrig_database_url& CSearch_database_Base::C_Attlist::SetOrig_database_url(void)
{
#ifdef _DEBUG
    if (!IsSetOrig_database_url()) {
        m_Orig_database_url = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Orig_database_url;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetDatabase_release_date(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetDatabase_release_date(void) const
{
    return IsSetDatabase_release_date();
}

inline
const CSearch_database_Base::C_Attlist::TDatabase_release_date& CSearch_database_Base::C_Attlist::GetDatabase_release_date(void) const
{
    if (!CanGetDatabase_release_date()) {
        ThrowUnassigned(4);
    }
    return m_Database_release_date;
}

inline
void CSearch_database_Base::C_Attlist::SetDatabase_release_date(const CSearch_database_Base::C_Attlist::TDatabase_release_date& value)
{
    m_Database_release_date = value;
    m_set_State[0] |= 0x300;
}

inline
CSearch_database_Base::C_Attlist::TDatabase_release_date& CSearch_database_Base::C_Attlist::SetDatabase_release_date(void)
{
#ifdef _DEBUG
    if (!IsSetDatabase_release_date()) {
        m_Database_release_date = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Database_release_date;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetDatabase_release_identifier(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetDatabase_release_identifier(void) const
{
    return IsSetDatabase_release_identifier();
}

inline
const CSearch_database_Base::C_Attlist::TDatabase_release_identifier& CSearch_database_Base::C_Attlist::GetDatabase_release_identifier(void) const
{
    if (!CanGetDatabase_release_identifier()) {
        ThrowUnassigned(5);
    }
    return m_Database_release_identifier;
}

inline
void CSearch_database_Base::C_Attlist::SetDatabase_release_identifier(const CSearch_database_Base::C_Attlist::TDatabase_release_identifier& value)
{
    m_Database_release_identifier = value;
    m_set_State[0] |= 0xc00;
}

inline
CSearch_database_Base::C_Attlist::TDatabase_release_identifier& CSearch_database_Base::C_Attlist::SetDatabase_release_identifier(void)
{
#ifdef _DEBUG
    if (!IsSetDatabase_release_identifier()) {
        m_Database_release_identifier = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Database_release_identifier;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetSize_in_db_entries(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetSize_in_db_entries(void) const
{
    return IsSetSize_in_db_entries();
}

inline
void CSearch_database_Base::C_Attlist::ResetSize_in_db_entries(void)
{
    m_Size_in_db_entries = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CSearch_database_Base::C_Attlist::TSize_in_db_entries CSearch_database_Base::C_Attlist::GetSize_in_db_entries(void) const
{
    if (!CanGetSize_in_db_entries()) {
        ThrowUnassigned(6);
    }
    return m_Size_in_db_entries;
}

inline
void CSearch_database_Base::C_Attlist::SetSize_in_db_entries(CSearch_database_Base::C_Attlist::TSize_in_db_entries value)
{
    m_Size_in_db_entries = value;
    m_set_State[0] |= 0x3000;
}

inline
CSearch_database_Base::C_Attlist::TSize_in_db_entries& CSearch_database_Base::C_Attlist::SetSize_in_db_entries(void)
{
#ifdef _DEBUG
    if (!IsSetSize_in_db_entries()) {
        memset(&m_Size_in_db_entries,UnassignedByte(),sizeof(m_Size_in_db_entries));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Size_in_db_entries;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetSize_of_residues(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetSize_of_residues(void) const
{
    return IsSetSize_of_residues();
}

inline
void CSearch_database_Base::C_Attlist::ResetSize_of_residues(void)
{
    m_Size_of_residues = 0;
    m_set_State[0] &= ~0xc000;
}

inline
CSearch_database_Base::C_Attlist::TSize_of_residues CSearch_database_Base::C_Attlist::GetSize_of_residues(void) const
{
    if (!CanGetSize_of_residues()) {
        ThrowUnassigned(7);
    }
    return m_Size_of_residues;
}

inline
void CSearch_database_Base::C_Attlist::SetSize_of_residues(CSearch_database_Base::C_Attlist::TSize_of_residues value)
{
    m_Size_of_residues = value;
    m_set_State[0] |= 0xc000;
}

inline
CSearch_database_Base::C_Attlist::TSize_of_residues& CSearch_database_Base::C_Attlist::SetSize_of_residues(void)
{
#ifdef _DEBUG
    if (!IsSetSize_of_residues()) {
        memset(&m_Size_of_residues,UnassignedByte(),sizeof(m_Size_of_residues));
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Size_of_residues;
}

inline
bool CSearch_database_Base::C_Attlist::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30000) != 0);
}

inline
bool CSearch_database_Base::C_Attlist::CanGetType(void) const
{
    return IsSetType();
}

inline
void CSearch_database_Base::C_Attlist::ResetType(void)
{
    m_Type = (EAttlist_type)(0);
    m_set_State[0] &= ~0x30000;
}

inline
CSearch_database_Base::C_Attlist::TType CSearch_database_Base::C_Attlist::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(8);
    }
    return m_Type;
}

inline
void CSearch_database_Base::C_Attlist::SetType(CSearch_database_Base::C_Attlist::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0x30000;
}

inline
CSearch_database_Base::C_Attlist::TType& CSearch_database_Base::C_Attlist::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x10000;
    return m_Type;
}

inline
bool CSearch_database_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CSearch_database_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CSearch_database_Base::TAttlist& CSearch_database_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CSearch_database_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CSearch_database_Base::TAttlist& CSearch_database_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    SetSearch_database();
    return (*m_Attlist);
}

inline
bool CSearch_database_Base::IsSetSearch_database(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSearch_database_Base::CanGetSearch_database(void) const
{
    return false;
}

inline
void CSearch_database_Base::ResetSearch_database(void)
{
    m_set_State[0] &= ~0xc;
}

inline
void CSearch_database_Base::SetSearch_database(void)
{
    m_set_State[0] |= 0xc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_SEARCH_DATABASE_BASE_HPP