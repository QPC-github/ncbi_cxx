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

/// @file TMgr_AssemblySpec_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TRACKMGR_TMGR_ASSEMBLYSPEC_BASE_HPP
#define OBJECTS_TRACKMGR_TMGR_ASSEMBLYSPEC_BASE_HPP

// extra headers
#include <objects/trackmgr/trackmgr_export.h>

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
class NCBI_TRACKMGR_EXPORT CTMgr_AssemblySpec_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTMgr_AssemblySpec_Base(void);
    // destructor
    virtual ~CTMgr_AssemblySpec_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_TRACKMGR_EXPORT C_Name : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Name(void);
        // destructor
        ~C_Name(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
        // types
        typedef int TTax_id;
        typedef string TName;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef int TTax_id
        ///  Check whether the Tax_id data member has been assigned a value.
        bool IsSetTax_id(void) const;
        /// Check whether it is safe or not to call GetTax_id method.
        bool CanGetTax_id(void) const;
        void ResetTax_id(void);
        TTax_id GetTax_id(void) const;
        void SetTax_id(TTax_id value);
        TTax_id& SetTax_id(void);
    
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
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Name(const C_Name&);
        C_Name& operator=(const C_Name&);
    
        // data
        Uint4 m_set_State[1];
        int m_Tax_id;
        string m_Name;
    };

    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,  ///< No variant selected
        e_Name,
        e_Accession
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 3 ///< == e_Accession+1
    };

    /// Reset the whole object
    virtual void Reset(void);

    /// Reset the selection (set it to e_not_set).
    virtual void ResetSelection(void);

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
    typedef C_Name TName;
    typedef string TAccession;

    // getters
    // setters

    // typedef C_Name TName
    bool IsName(void) const;
    const TName& GetName(void) const;
    TName& SetName(void);
    void SetName(TName& value);

    // typedef string TAccession
    bool IsAccession(void) const;
    const TAccession& GetAccession(void) const;
    TAccession& SetAccession(void);
    void SetAccession(const TAccession& value);


private:
    // copy constructor and assignment operator
    CTMgr_AssemblySpec_Base(const CTMgr_AssemblySpec_Base& );
    CTMgr_AssemblySpec_Base& operator=(const CTMgr_AssemblySpec_Base& );
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






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTMgr_AssemblySpec_Base::C_Name::IsSetTax_id(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTMgr_AssemblySpec_Base::C_Name::CanGetTax_id(void) const
{
    return IsSetTax_id();
}

inline
void CTMgr_AssemblySpec_Base::C_Name::ResetTax_id(void)
{
    m_Tax_id = 0;
    m_set_State[0] &= ~0x3;
}

inline
CTMgr_AssemblySpec_Base::C_Name::TTax_id CTMgr_AssemblySpec_Base::C_Name::GetTax_id(void) const
{
    if (!CanGetTax_id()) {
        ThrowUnassigned(0);
    }
    return m_Tax_id;
}

inline
void CTMgr_AssemblySpec_Base::C_Name::SetTax_id(CTMgr_AssemblySpec_Base::C_Name::TTax_id value)
{
    m_Tax_id = value;
    m_set_State[0] |= 0x3;
}

inline
CTMgr_AssemblySpec_Base::C_Name::TTax_id& CTMgr_AssemblySpec_Base::C_Name::SetTax_id(void)
{
#ifdef _DEBUG
    if (!IsSetTax_id()) {
        memset(&m_Tax_id,UnassignedByte(),sizeof(m_Tax_id));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Tax_id;
}

inline
bool CTMgr_AssemblySpec_Base::C_Name::IsSetName(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTMgr_AssemblySpec_Base::C_Name::CanGetName(void) const
{
    return IsSetName();
}

inline
const CTMgr_AssemblySpec_Base::C_Name::TName& CTMgr_AssemblySpec_Base::C_Name::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(1);
    }
    return m_Name;
}

inline
void CTMgr_AssemblySpec_Base::C_Name::SetName(const CTMgr_AssemblySpec_Base::C_Name::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0xc;
}

inline
CTMgr_AssemblySpec_Base::C_Name::TName& CTMgr_AssemblySpec_Base::C_Name::SetName(void)
{
#ifdef _DEBUG
    if (!IsSetName()) {
        m_Name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Name;
}

inline
CTMgr_AssemblySpec_Base::E_Choice CTMgr_AssemblySpec_Base::Which(void) const
{
    return m_choice;
}

inline
void CTMgr_AssemblySpec_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CTMgr_AssemblySpec_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CTMgr_AssemblySpec_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CTMgr_AssemblySpec_Base::IsName(void) const
{
    return m_choice == e_Name;
}

inline
bool CTMgr_AssemblySpec_Base::IsAccession(void) const
{
    return m_choice == e_Accession;
}

inline
const CTMgr_AssemblySpec_Base::TAccession& CTMgr_AssemblySpec_Base::GetAccession(void) const
{
    CheckSelected(e_Accession);
    return *m_string;
}

inline
CTMgr_AssemblySpec_Base::TAccession& CTMgr_AssemblySpec_Base::SetAccession(void)
{
    Select(e_Accession, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_string;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_ASSEMBLYSPEC_BASE_HPP
