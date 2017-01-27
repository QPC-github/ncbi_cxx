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

/// @file Tolower_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'linkout.dtd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef linkout__OBJTOOLS_EUTILS_LINKOUT_TOLOWER_BASE_HPP
#define linkout__OBJTOOLS_EUTILS_LINKOUT_TOLOWER_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

#ifndef BEGIN_linkout_SCOPE
#  define BEGIN_linkout_SCOPE BEGIN_SCOPE(linkout)
#  define END_linkout_SCOPE END_SCOPE(linkout)
#endif
BEGIN_linkout_SCOPE // namespace linkout::


// forward declarations
class CApad;
class CNormalize;
class CPad;
class CStrip;
class CSubs;
class CTolower;
class CToupper;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CTolower_Base : public NCBI_NS_NCBI::CSerialObject
{
    typedef NCBI_NS_NCBI::CSerialObject Tparent;
public:
    // constructor
    CTolower_Base(void);
    // destructor
    virtual ~CTolower_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_EUTILS_EXPORT C_Data : public NCBI_NS_NCBI::CSerialObject
    {
        typedef NCBI_NS_NCBI::CSerialObject Tparent;
    public:
        // constructor
        C_Data(void);
        // destructor
        ~C_Data(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,  ///< No variant selected
            e__CharData,
            e_Pad,
            e_Apad,
            e_Subs,
            e_Toupper,
            e_Tolower,
            e_Strip,
            e_Normalize
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 9 ///< == e_Normalize+1
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
        static NCBI_NS_STD::string SelectionName(E_Choice index);
    
        /// Select the requested variant if needed.
        void Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset = NCBI_NS_NCBI::eDoResetVariant);
        /// Select the requested variant if needed,
        /// allocating CObject variants from memory pool.
        void Select(E_Choice index,
                    NCBI_NS_NCBI::EResetVariant reset,
                    NCBI_NS_NCBI::CObjectMemoryPool* pool);
    
        // types
        typedef NCBI_NS_STD::string T_CharData;
        typedef CPad TPad;
        typedef CApad TApad;
        typedef CSubs TSubs;
        typedef CToupper TToupper;
        typedef CTolower TTolower;
        typedef CStrip TStrip;
        typedef CNormalize TNormalize;
    
        // getters
        // setters
    
        // typedef NCBI_NS_STD::string T_CharData
        bool Is_CharData(void) const;
        const T_CharData& Get_CharData(void) const;
        T_CharData& Set_CharData(void);
        void Set_CharData(const T_CharData& value);
    
        // typedef CPad TPad
        bool IsPad(void) const;
        const TPad& GetPad(void) const;
        TPad& SetPad(void);
        void SetPad(TPad& value);
    
        // typedef CApad TApad
        bool IsApad(void) const;
        const TApad& GetApad(void) const;
        TApad& SetApad(void);
        void SetApad(TApad& value);
    
        // typedef CSubs TSubs
        bool IsSubs(void) const;
        const TSubs& GetSubs(void) const;
        TSubs& SetSubs(void);
        void SetSubs(TSubs& value);
    
        // typedef CToupper TToupper
        bool IsToupper(void) const;
        const TToupper& GetToupper(void) const;
        TToupper& SetToupper(void);
        void SetToupper(TToupper& value);
    
        // typedef CTolower TTolower
        bool IsTolower(void) const;
        const TTolower& GetTolower(void) const;
        TTolower& SetTolower(void);
        void SetTolower(TTolower& value);
    
        // typedef CStrip TStrip
        bool IsStrip(void) const;
        const TStrip& GetStrip(void) const;
        TStrip& SetStrip(void);
        void SetStrip(TStrip& value);
    
        // typedef CNormalize TNormalize
        bool IsNormalize(void) const;
        const TNormalize& GetNormalize(void) const;
        TNormalize& SetNormalize(void);
        void SetNormalize(TNormalize& value);
    
    
    private:
        // copy constructor and assignment operator
        C_Data(const C_Data& );
        C_Data& operator=(const C_Data& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        union {
            NCBI_NS_NCBI::CUnionBuffer<NCBI_NS_STD::string> m_string;
            NCBI_NS_NCBI::CSerialObject *m_object;
        };
    };
    // types
    typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_Data > > Tdata;

    // getters
    // setters

    /// mandatory
    /// typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_Data > > Tdata
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
    CTolower_Base(const CTolower_Base&);
    CTolower_Base& operator=(const CTolower_Base&);

    // data
    Uint4 m_set_State[1];
    NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< C_Data > > m_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CTolower_Base::C_Data::E_Choice CTolower_Base::C_Data::Which(void) const
{
    return m_choice;
}

inline
void CTolower_Base::C_Data::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CTolower_Base::C_Data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CTolower_Base::C_Data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CTolower_Base::C_Data::Is_CharData(void) const
{
    return m_choice == e__CharData;
}

inline
const CTolower_Base::C_Data::T_CharData& CTolower_Base::C_Data::Get_CharData(void) const
{
    CheckSelected(e__CharData);
    return *m_string;
}

inline
CTolower_Base::C_Data::T_CharData& CTolower_Base::C_Data::Set_CharData(void)
{
    Select(e__CharData, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_string;
}

inline
bool CTolower_Base::C_Data::IsPad(void) const
{
    return m_choice == e_Pad;
}

inline
bool CTolower_Base::C_Data::IsApad(void) const
{
    return m_choice == e_Apad;
}

inline
bool CTolower_Base::C_Data::IsSubs(void) const
{
    return m_choice == e_Subs;
}

inline
bool CTolower_Base::C_Data::IsToupper(void) const
{
    return m_choice == e_Toupper;
}

inline
bool CTolower_Base::C_Data::IsTolower(void) const
{
    return m_choice == e_Tolower;
}

inline
bool CTolower_Base::C_Data::IsStrip(void) const
{
    return m_choice == e_Strip;
}

inline
bool CTolower_Base::C_Data::IsNormalize(void) const
{
    return m_choice == e_Normalize;
}

inline
bool CTolower_Base::IsSet(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTolower_Base::CanGet(void) const
{
    return true;
}

inline
const CTolower_Base::Tdata& CTolower_Base::Get(void) const
{
    return m_data;
}

inline
CTolower_Base::Tdata& CTolower_Base::Set(void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

inline
CTolower_Base::operator const CTolower_Base::Tdata& (void) const
{
    return m_data;
}

inline
CTolower_Base::operator CTolower_Base::Tdata& (void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_linkout_SCOPE // namespace linkout::


#endif // linkout__OBJTOOLS_EUTILS_LINKOUT_TOLOWER_BASE_HPP