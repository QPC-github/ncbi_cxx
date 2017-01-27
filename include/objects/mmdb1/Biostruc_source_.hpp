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

/// @file Biostruc_source_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB1_BIOSTRUC_SOURCE_BASE_HPP
#define OBJECTS_MMDB1_BIOSTRUC_SOURCE_BASE_HPP

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
class CBiostruc_id;
class CDate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// The origin of a biostruc is a reference to another database.  PDB release 
/// date and PDB-assigned id codes are recorded here, as are the PDB-assigned 
/// entry date and replacement history.
class NCBI_MMDB1_EXPORT CBiostruc_source_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBiostruc_source_Base(void);
    // destructor
    virtual ~CBiostruc_source_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_MMDB1_EXPORT C_Version_of_database : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Version_of_database(void);
        // destructor
        ~C_Version_of_database(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,   ///< No variant selected
            e_Release_date,
            e_Release_code
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 3 ///< == e_Release_code+1
        };
    
        /// Reset the whole object
        void Reset(void);
    
        /// Reset the selection (set it to e_not_set).
        void ResetSelection(void);
    
        /// Which variant is currently selected.
        E_Choice Which(void) const;
    
        /// Verify selection, throw exception if it differs from the expected.
        void CheckSelected(E_Choice index) const;
    
        /// Throw 'InvalidSelection' exception.
        NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;
    
        /// Retrieve selection name (for diagnostic purposes).
        static string SelectionName(E_Choice index);
    
        /// Select the requested variant if needed.
        void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
        /// Select the requested variant if needed,
        /// allocating CObject variants from memory pool.
        void Select(E_Choice index,
                    EResetVariant reset,
                    CObjectMemoryPool* pool);
    
        // types
        typedef CDate TRelease_date;
        typedef string TRelease_code;
    
        // getters
        // setters
    
        // typedef CDate TRelease_date
        bool IsRelease_date(void) const;
        const TRelease_date& GetRelease_date(void) const;
        TRelease_date& SetRelease_date(void);
        void SetRelease_date(TRelease_date& value);
    
        // typedef string TRelease_code
        bool IsRelease_code(void) const;
        const TRelease_code& GetRelease_code(void) const;
        TRelease_code& SetRelease_code(void);
        void SetRelease_code(const TRelease_code& value);
    
    
    private:
        // copy constructor and assignment operator
        C_Version_of_database(const C_Version_of_database& );
        C_Version_of_database& operator=(const C_Version_of_database& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        union {
            NCBI_NS_NCBI::CUnionBuffer<NCBI_NS_STD::string> m_string;
            NCBI_NS_NCBI::CSerialObject *m_object;
        };
    };
    // types
    typedef string TName_of_database;
    typedef C_Version_of_database TVersion_of_database;
    typedef CBiostruc_id TDatabase_entry_id;
    typedef CDate TDatabase_entry_date;
    typedef list< string > TDatabase_entry_history;

    // getters
    // setters

    /// mandatory
    /// typedef string TName_of_database
    ///  Check whether the Name_of_database data member has been assigned a value.
    bool IsSetName_of_database(void) const;
    /// Check whether it is safe or not to call GetName_of_database method.
    bool CanGetName_of_database(void) const;
    void ResetName_of_database(void);
    const TName_of_database& GetName_of_database(void) const;
    void SetName_of_database(const TName_of_database& value);
    TName_of_database& SetName_of_database(void);

    /// optional
    /// typedef C_Version_of_database TVersion_of_database
    ///  Check whether the Version_of_database data member has been assigned a value.
    bool IsSetVersion_of_database(void) const;
    /// Check whether it is safe or not to call GetVersion_of_database method.
    bool CanGetVersion_of_database(void) const;
    void ResetVersion_of_database(void);
    const TVersion_of_database& GetVersion_of_database(void) const;
    void SetVersion_of_database(TVersion_of_database& value);
    TVersion_of_database& SetVersion_of_database(void);

    /// mandatory
    /// typedef CBiostruc_id TDatabase_entry_id
    ///  Check whether the Database_entry_id data member has been assigned a value.
    bool IsSetDatabase_entry_id(void) const;
    /// Check whether it is safe or not to call GetDatabase_entry_id method.
    bool CanGetDatabase_entry_id(void) const;
    void ResetDatabase_entry_id(void);
    const TDatabase_entry_id& GetDatabase_entry_id(void) const;
    void SetDatabase_entry_id(TDatabase_entry_id& value);
    TDatabase_entry_id& SetDatabase_entry_id(void);

    /// mandatory
    /// typedef CDate TDatabase_entry_date
    ///  Check whether the Database_entry_date data member has been assigned a value.
    bool IsSetDatabase_entry_date(void) const;
    /// Check whether it is safe or not to call GetDatabase_entry_date method.
    bool CanGetDatabase_entry_date(void) const;
    void ResetDatabase_entry_date(void);
    const TDatabase_entry_date& GetDatabase_entry_date(void) const;
    void SetDatabase_entry_date(TDatabase_entry_date& value);
    TDatabase_entry_date& SetDatabase_entry_date(void);

    /// optional
    /// typedef list< string > TDatabase_entry_history
    ///  Check whether the Database_entry_history data member has been assigned a value.
    bool IsSetDatabase_entry_history(void) const;
    /// Check whether it is safe or not to call GetDatabase_entry_history method.
    bool CanGetDatabase_entry_history(void) const;
    void ResetDatabase_entry_history(void);
    const TDatabase_entry_history& GetDatabase_entry_history(void) const;
    TDatabase_entry_history& SetDatabase_entry_history(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBiostruc_source_Base(const CBiostruc_source_Base&);
    CBiostruc_source_Base& operator=(const CBiostruc_source_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Name_of_database;
    CRef< TVersion_of_database > m_Version_of_database;
    CRef< TDatabase_entry_id > m_Database_entry_id;
    CRef< TDatabase_entry_date > m_Database_entry_date;
    list< string > m_Database_entry_history;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CBiostruc_source_Base::C_Version_of_database::E_Choice CBiostruc_source_Base::C_Version_of_database::Which(void) const
{
    return m_choice;
}

inline
void CBiostruc_source_Base::C_Version_of_database::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CBiostruc_source_Base::C_Version_of_database::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CBiostruc_source_Base::C_Version_of_database::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CBiostruc_source_Base::C_Version_of_database::IsRelease_date(void) const
{
    return m_choice == e_Release_date;
}

inline
bool CBiostruc_source_Base::C_Version_of_database::IsRelease_code(void) const
{
    return m_choice == e_Release_code;
}

inline
const CBiostruc_source_Base::C_Version_of_database::TRelease_code& CBiostruc_source_Base::C_Version_of_database::GetRelease_code(void) const
{
    CheckSelected(e_Release_code);
    return *m_string;
}

inline
CBiostruc_source_Base::C_Version_of_database::TRelease_code& CBiostruc_source_Base::C_Version_of_database::SetRelease_code(void)
{
    Select(e_Release_code, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_string;
}

inline
bool CBiostruc_source_Base::IsSetName_of_database(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBiostruc_source_Base::CanGetName_of_database(void) const
{
    return IsSetName_of_database();
}

inline
const CBiostruc_source_Base::TName_of_database& CBiostruc_source_Base::GetName_of_database(void) const
{
    if (!CanGetName_of_database()) {
        ThrowUnassigned(0);
    }
    return m_Name_of_database;
}

inline
void CBiostruc_source_Base::SetName_of_database(const CBiostruc_source_Base::TName_of_database& value)
{
    m_Name_of_database = value;
    m_set_State[0] |= 0x3;
}

inline
CBiostruc_source_Base::TName_of_database& CBiostruc_source_Base::SetName_of_database(void)
{
#ifdef _DEBUG
    if (!IsSetName_of_database()) {
        m_Name_of_database = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Name_of_database;
}

inline
bool CBiostruc_source_Base::IsSetVersion_of_database(void) const
{
    return m_Version_of_database.NotEmpty();
}

inline
bool CBiostruc_source_Base::CanGetVersion_of_database(void) const
{
    return IsSetVersion_of_database();
}

inline
const CBiostruc_source_Base::TVersion_of_database& CBiostruc_source_Base::GetVersion_of_database(void) const
{
    if (!CanGetVersion_of_database()) {
        ThrowUnassigned(1);
    }
    return (*m_Version_of_database);
}

inline
bool CBiostruc_source_Base::IsSetDatabase_entry_id(void) const
{
    return m_Database_entry_id.NotEmpty();
}

inline
bool CBiostruc_source_Base::CanGetDatabase_entry_id(void) const
{
    return true;
}

inline
const CBiostruc_source_Base::TDatabase_entry_id& CBiostruc_source_Base::GetDatabase_entry_id(void) const
{
    if ( !m_Database_entry_id ) {
        const_cast<CBiostruc_source_Base*>(this)->ResetDatabase_entry_id();
    }
    return (*m_Database_entry_id);
}

inline
CBiostruc_source_Base::TDatabase_entry_id& CBiostruc_source_Base::SetDatabase_entry_id(void)
{
    if ( !m_Database_entry_id ) {
        ResetDatabase_entry_id();
    }
    return (*m_Database_entry_id);
}

inline
bool CBiostruc_source_Base::IsSetDatabase_entry_date(void) const
{
    return m_Database_entry_date.NotEmpty();
}

inline
bool CBiostruc_source_Base::CanGetDatabase_entry_date(void) const
{
    return true;
}

inline
const CBiostruc_source_Base::TDatabase_entry_date& CBiostruc_source_Base::GetDatabase_entry_date(void) const
{
    if ( !m_Database_entry_date ) {
        const_cast<CBiostruc_source_Base*>(this)->ResetDatabase_entry_date();
    }
    return (*m_Database_entry_date);
}

inline
CBiostruc_source_Base::TDatabase_entry_date& CBiostruc_source_Base::SetDatabase_entry_date(void)
{
    if ( !m_Database_entry_date ) {
        ResetDatabase_entry_date();
    }
    return (*m_Database_entry_date);
}

inline
bool CBiostruc_source_Base::IsSetDatabase_entry_history(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CBiostruc_source_Base::CanGetDatabase_entry_history(void) const
{
    return true;
}

inline
const CBiostruc_source_Base::TDatabase_entry_history& CBiostruc_source_Base::GetDatabase_entry_history(void) const
{
    return m_Database_entry_history;
}

inline
CBiostruc_source_Base::TDatabase_entry_history& CBiostruc_source_Base::SetDatabase_entry_history(void)
{
    m_set_State[0] |= 0x100;
    return m_Database_entry_history;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB1_BIOSTRUC_SOURCE_BASE_HPP