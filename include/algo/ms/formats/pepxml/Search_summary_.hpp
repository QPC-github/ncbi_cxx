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

/// @file Search_summary_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pepXML.xsd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef ALGO_MS_FORMATS_PEPXML_SEARCH_SUMMARY_BASE_HPP
#define ALGO_MS_FORMATS_PEPXML_SEARCH_SUMMARY_BASE_HPP

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
class CAminoacid_modification;
class CEnzymatic_search_constraint;
class CParameter;
class CSearch_database;
class CSequence_search_constraint;
class CTerminal_modification;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///Database search settings 
class NCBI_PEPXML_EXPORT CSearch_summary_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSearch_summary_Base(void);
    // destructor
    virtual ~CSearch_summary_Base(void);

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
    
        enum EAttlist_precursor_mass_type {
            eAttlist_precursor_mass_type_monoisotopic = 1,
            eAttlist_precursor_mass_type_average      = 2
        };
        
        /// Access to EAttlist_precursor_mass_type's attributes (values, names) as defined in spec
        static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EAttlist_precursor_mass_type)(void);
        
        enum EAttlist_fragment_mass_type {
            eAttlist_fragment_mass_type_monoisotopic = 1,
            eAttlist_fragment_mass_type_average      = 2
        };
        
        /// Access to EAttlist_fragment_mass_type's attributes (values, names) as defined in spec
        static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EAttlist_fragment_mass_type)(void);
        
        // types
        typedef string TBase_name;
        typedef string TSearch_engine;
        typedef EAttlist_precursor_mass_type TPrecursor_mass_type;
        typedef EAttlist_fragment_mass_type TFragment_mass_type;
        typedef string TOut_data_type;
        typedef string TOut_data;
        typedef int TSearch_id;
    
        // getters
        // setters
    
        /// mass_types are (monoisotopic | average)  
        /// mandatory
        /// typedef string TBase_name
        ///  Check whether the Base_name data member has been assigned a value.
        bool IsSetBase_name(void) const;
        /// Check whether it is safe or not to call GetBase_name method.
        bool CanGetBase_name(void) const;
        void ResetBase_name(void);
        const TBase_name& GetBase_name(void) const;
        void SetBase_name(const TBase_name& value);
        TBase_name& SetBase_name(void);
    
        /// mandatory
        /// typedef string TSearch_engine
        ///  Check whether the Search_engine data member has been assigned a value.
        bool IsSetSearch_engine(void) const;
        /// Check whether it is safe or not to call GetSearch_engine method.
        bool CanGetSearch_engine(void) const;
        void ResetSearch_engine(void);
        const TSearch_engine& GetSearch_engine(void) const;
        void SetSearch_engine(const TSearch_engine& value);
        TSearch_engine& SetSearch_engine(void);
    
        /// mandatory
        /// typedef EAttlist_precursor_mass_type TPrecursor_mass_type
        ///  Check whether the Precursor_mass_type data member has been assigned a value.
        bool IsSetPrecursor_mass_type(void) const;
        /// Check whether it is safe or not to call GetPrecursor_mass_type method.
        bool CanGetPrecursor_mass_type(void) const;
        void ResetPrecursor_mass_type(void);
        TPrecursor_mass_type GetPrecursor_mass_type(void) const;
        void SetPrecursor_mass_type(TPrecursor_mass_type value);
        TPrecursor_mass_type& SetPrecursor_mass_type(void);
    
        /// mandatory
        /// typedef EAttlist_fragment_mass_type TFragment_mass_type
        ///  Check whether the Fragment_mass_type data member has been assigned a value.
        bool IsSetFragment_mass_type(void) const;
        /// Check whether it is safe or not to call GetFragment_mass_type method.
        bool CanGetFragment_mass_type(void) const;
        void ResetFragment_mass_type(void);
        TFragment_mass_type GetFragment_mass_type(void) const;
        void SetFragment_mass_type(TFragment_mass_type value);
        TFragment_mass_type& SetFragment_mass_type(void);
    
        /// optional
        /// typedef string TOut_data_type
        ///  Check whether the Out_data_type data member has been assigned a value.
        bool IsSetOut_data_type(void) const;
        /// Check whether it is safe or not to call GetOut_data_type method.
        bool CanGetOut_data_type(void) const;
        void ResetOut_data_type(void);
        const TOut_data_type& GetOut_data_type(void) const;
        void SetOut_data_type(const TOut_data_type& value);
        TOut_data_type& SetOut_data_type(void);
    
        /// optional
        /// typedef string TOut_data
        ///  Check whether the Out_data data member has been assigned a value.
        bool IsSetOut_data(void) const;
        /// Check whether it is safe or not to call GetOut_data method.
        bool CanGetOut_data(void) const;
        void ResetOut_data(void);
        const TOut_data& GetOut_data(void) const;
        void SetOut_data(const TOut_data& value);
        TOut_data& SetOut_data(void);
    
        /// mandatory
        /// typedef int TSearch_id
        ///  Check whether the Search_id data member has been assigned a value.
        bool IsSetSearch_id(void) const;
        /// Check whether it is safe or not to call GetSearch_id method.
        bool CanGetSearch_id(void) const;
        void ResetSearch_id(void);
        TSearch_id GetSearch_id(void) const;
        void SetSearch_id(TSearch_id value);
        TSearch_id& SetSearch_id(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_Base_name;
        string m_Search_engine;
        EAttlist_precursor_mass_type m_Precursor_mass_type;
        EAttlist_fragment_mass_type m_Fragment_mass_type;
        string m_Out_data_type;
        string m_Out_data;
        int m_Search_id;
    };
    // types
    typedef C_Attlist TAttlist;
    typedef CSearch_database TSearch_database;
    typedef CEnzymatic_search_constraint TEnzymatic_search_constraint;
    typedef list< CRef< CSequence_search_constraint > > TSequence_search_constraint;
    typedef list< CRef< CAminoacid_modification > > TAminoacid_modification;
    typedef list< CRef< CTerminal_modification > > TTerminal_modification;
    typedef list< CRef< CParameter > > TParameter;

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

    /// optional
    /// typedef CSearch_database TSearch_database
    ///  Check whether the Search_database data member has been assigned a value.
    bool IsSetSearch_database(void) const;
    /// Check whether it is safe or not to call GetSearch_database method.
    bool CanGetSearch_database(void) const;
    void ResetSearch_database(void);
    const TSearch_database& GetSearch_database(void) const;
    void SetSearch_database(TSearch_database& value);
    TSearch_database& SetSearch_database(void);

    /// optional
    /// typedef CEnzymatic_search_constraint TEnzymatic_search_constraint
    ///  Check whether the Enzymatic_search_constraint data member has been assigned a value.
    bool IsSetEnzymatic_search_constraint(void) const;
    /// Check whether it is safe or not to call GetEnzymatic_search_constraint method.
    bool CanGetEnzymatic_search_constraint(void) const;
    void ResetEnzymatic_search_constraint(void);
    const TEnzymatic_search_constraint& GetEnzymatic_search_constraint(void) const;
    void SetEnzymatic_search_constraint(TEnzymatic_search_constraint& value);
    TEnzymatic_search_constraint& SetEnzymatic_search_constraint(void);

    /// optional
    /// typedef list< CRef< CSequence_search_constraint > > TSequence_search_constraint
    ///  Check whether the Sequence_search_constraint data member has been assigned a value.
    bool IsSetSequence_search_constraint(void) const;
    /// Check whether it is safe or not to call GetSequence_search_constraint method.
    bool CanGetSequence_search_constraint(void) const;
    void ResetSequence_search_constraint(void);
    const TSequence_search_constraint& GetSequence_search_constraint(void) const;
    TSequence_search_constraint& SetSequence_search_constraint(void);

    /// optional
    /// typedef list< CRef< CAminoacid_modification > > TAminoacid_modification
    ///  Check whether the Aminoacid_modification data member has been assigned a value.
    bool IsSetAminoacid_modification(void) const;
    /// Check whether it is safe or not to call GetAminoacid_modification method.
    bool CanGetAminoacid_modification(void) const;
    void ResetAminoacid_modification(void);
    const TAminoacid_modification& GetAminoacid_modification(void) const;
    TAminoacid_modification& SetAminoacid_modification(void);

    /// optional
    /// typedef list< CRef< CTerminal_modification > > TTerminal_modification
    ///  Check whether the Terminal_modification data member has been assigned a value.
    bool IsSetTerminal_modification(void) const;
    /// Check whether it is safe or not to call GetTerminal_modification method.
    bool CanGetTerminal_modification(void) const;
    void ResetTerminal_modification(void);
    const TTerminal_modification& GetTerminal_modification(void) const;
    TTerminal_modification& SetTerminal_modification(void);

    /// optional
    /// typedef list< CRef< CParameter > > TParameter
    ///  Check whether the Parameter data member has been assigned a value.
    bool IsSetParameter(void) const;
    /// Check whether it is safe or not to call GetParameter method.
    bool CanGetParameter(void) const;
    void ResetParameter(void);
    const TParameter& GetParameter(void) const;
    TParameter& SetParameter(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSearch_summary_Base(const CSearch_summary_Base&);
    CSearch_summary_Base& operator=(const CSearch_summary_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
    CRef< TSearch_database > m_Search_database;
    CRef< TEnzymatic_search_constraint > m_Enzymatic_search_constraint;
    list< CRef< CSequence_search_constraint > > m_Sequence_search_constraint;
    list< CRef< CAminoacid_modification > > m_Aminoacid_modification;
    list< CRef< CTerminal_modification > > m_Terminal_modification;
    list< CRef< CParameter > > m_Parameter;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSearch_summary_Base::C_Attlist::IsSetBase_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetBase_name(void) const
{
    return IsSetBase_name();
}

inline
const CSearch_summary_Base::C_Attlist::TBase_name& CSearch_summary_Base::C_Attlist::GetBase_name(void) const
{
    if (!CanGetBase_name()) {
        ThrowUnassigned(0);
    }
    return m_Base_name;
}

inline
void CSearch_summary_Base::C_Attlist::SetBase_name(const CSearch_summary_Base::C_Attlist::TBase_name& value)
{
    m_Base_name = value;
    m_set_State[0] |= 0x3;
}

inline
CSearch_summary_Base::C_Attlist::TBase_name& CSearch_summary_Base::C_Attlist::SetBase_name(void)
{
#ifdef _DEBUG
    if (!IsSetBase_name()) {
        m_Base_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Base_name;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetSearch_engine(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetSearch_engine(void) const
{
    return IsSetSearch_engine();
}

inline
const CSearch_summary_Base::C_Attlist::TSearch_engine& CSearch_summary_Base::C_Attlist::GetSearch_engine(void) const
{
    if (!CanGetSearch_engine()) {
        ThrowUnassigned(1);
    }
    return m_Search_engine;
}

inline
void CSearch_summary_Base::C_Attlist::SetSearch_engine(const CSearch_summary_Base::C_Attlist::TSearch_engine& value)
{
    m_Search_engine = value;
    m_set_State[0] |= 0xc;
}

inline
CSearch_summary_Base::C_Attlist::TSearch_engine& CSearch_summary_Base::C_Attlist::SetSearch_engine(void)
{
#ifdef _DEBUG
    if (!IsSetSearch_engine()) {
        m_Search_engine = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Search_engine;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetPrecursor_mass_type(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetPrecursor_mass_type(void) const
{
    return IsSetPrecursor_mass_type();
}

inline
void CSearch_summary_Base::C_Attlist::ResetPrecursor_mass_type(void)
{
    m_Precursor_mass_type = (EAttlist_precursor_mass_type)(0);
    m_set_State[0] &= ~0x30;
}

inline
CSearch_summary_Base::C_Attlist::TPrecursor_mass_type CSearch_summary_Base::C_Attlist::GetPrecursor_mass_type(void) const
{
    if (!CanGetPrecursor_mass_type()) {
        ThrowUnassigned(2);
    }
    return m_Precursor_mass_type;
}

inline
void CSearch_summary_Base::C_Attlist::SetPrecursor_mass_type(CSearch_summary_Base::C_Attlist::TPrecursor_mass_type value)
{
    m_Precursor_mass_type = value;
    m_set_State[0] |= 0x30;
}

inline
CSearch_summary_Base::C_Attlist::TPrecursor_mass_type& CSearch_summary_Base::C_Attlist::SetPrecursor_mass_type(void)
{
#ifdef _DEBUG
    if (!IsSetPrecursor_mass_type()) {
        memset(&m_Precursor_mass_type,UnassignedByte(),sizeof(m_Precursor_mass_type));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Precursor_mass_type;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetFragment_mass_type(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetFragment_mass_type(void) const
{
    return IsSetFragment_mass_type();
}

inline
void CSearch_summary_Base::C_Attlist::ResetFragment_mass_type(void)
{
    m_Fragment_mass_type = (EAttlist_fragment_mass_type)(0);
    m_set_State[0] &= ~0xc0;
}

inline
CSearch_summary_Base::C_Attlist::TFragment_mass_type CSearch_summary_Base::C_Attlist::GetFragment_mass_type(void) const
{
    if (!CanGetFragment_mass_type()) {
        ThrowUnassigned(3);
    }
    return m_Fragment_mass_type;
}

inline
void CSearch_summary_Base::C_Attlist::SetFragment_mass_type(CSearch_summary_Base::C_Attlist::TFragment_mass_type value)
{
    m_Fragment_mass_type = value;
    m_set_State[0] |= 0xc0;
}

inline
CSearch_summary_Base::C_Attlist::TFragment_mass_type& CSearch_summary_Base::C_Attlist::SetFragment_mass_type(void)
{
#ifdef _DEBUG
    if (!IsSetFragment_mass_type()) {
        memset(&m_Fragment_mass_type,UnassignedByte(),sizeof(m_Fragment_mass_type));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Fragment_mass_type;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetOut_data_type(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetOut_data_type(void) const
{
    return IsSetOut_data_type();
}

inline
const CSearch_summary_Base::C_Attlist::TOut_data_type& CSearch_summary_Base::C_Attlist::GetOut_data_type(void) const
{
    if (!CanGetOut_data_type()) {
        ThrowUnassigned(4);
    }
    return m_Out_data_type;
}

inline
void CSearch_summary_Base::C_Attlist::SetOut_data_type(const CSearch_summary_Base::C_Attlist::TOut_data_type& value)
{
    m_Out_data_type = value;
    m_set_State[0] |= 0x300;
}

inline
CSearch_summary_Base::C_Attlist::TOut_data_type& CSearch_summary_Base::C_Attlist::SetOut_data_type(void)
{
#ifdef _DEBUG
    if (!IsSetOut_data_type()) {
        m_Out_data_type = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Out_data_type;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetOut_data(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetOut_data(void) const
{
    return IsSetOut_data();
}

inline
const CSearch_summary_Base::C_Attlist::TOut_data& CSearch_summary_Base::C_Attlist::GetOut_data(void) const
{
    if (!CanGetOut_data()) {
        ThrowUnassigned(5);
    }
    return m_Out_data;
}

inline
void CSearch_summary_Base::C_Attlist::SetOut_data(const CSearch_summary_Base::C_Attlist::TOut_data& value)
{
    m_Out_data = value;
    m_set_State[0] |= 0xc00;
}

inline
CSearch_summary_Base::C_Attlist::TOut_data& CSearch_summary_Base::C_Attlist::SetOut_data(void)
{
#ifdef _DEBUG
    if (!IsSetOut_data()) {
        m_Out_data = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Out_data;
}

inline
bool CSearch_summary_Base::C_Attlist::IsSetSearch_id(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CSearch_summary_Base::C_Attlist::CanGetSearch_id(void) const
{
    return IsSetSearch_id();
}

inline
void CSearch_summary_Base::C_Attlist::ResetSearch_id(void)
{
    m_Search_id = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CSearch_summary_Base::C_Attlist::TSearch_id CSearch_summary_Base::C_Attlist::GetSearch_id(void) const
{
    if (!CanGetSearch_id()) {
        ThrowUnassigned(6);
    }
    return m_Search_id;
}

inline
void CSearch_summary_Base::C_Attlist::SetSearch_id(CSearch_summary_Base::C_Attlist::TSearch_id value)
{
    m_Search_id = value;
    m_set_State[0] |= 0x3000;
}

inline
CSearch_summary_Base::C_Attlist::TSearch_id& CSearch_summary_Base::C_Attlist::SetSearch_id(void)
{
#ifdef _DEBUG
    if (!IsSetSearch_id()) {
        memset(&m_Search_id,UnassignedByte(),sizeof(m_Search_id));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Search_id;
}

inline
bool CSearch_summary_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CSearch_summary_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CSearch_summary_Base::TAttlist& CSearch_summary_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CSearch_summary_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CSearch_summary_Base::TAttlist& CSearch_summary_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    return (*m_Attlist);
}

inline
bool CSearch_summary_Base::CanGetSearch_database(void) const
{
    return false;
}

inline
const CSearch_summary_Base::TSearch_database& CSearch_summary_Base::GetSearch_database(void) const
{
    return (*m_Search_database);
}

inline
bool CSearch_summary_Base::CanGetEnzymatic_search_constraint(void) const
{
    return false;
}

inline
const CSearch_summary_Base::TEnzymatic_search_constraint& CSearch_summary_Base::GetEnzymatic_search_constraint(void) const
{
    return (*m_Enzymatic_search_constraint);
}

inline
bool CSearch_summary_Base::IsSetSequence_search_constraint(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CSearch_summary_Base::CanGetSequence_search_constraint(void) const
{
    return true;
}

inline
const CSearch_summary_Base::TSequence_search_constraint& CSearch_summary_Base::GetSequence_search_constraint(void) const
{
    return m_Sequence_search_constraint;
}

inline
CSearch_summary_Base::TSequence_search_constraint& CSearch_summary_Base::SetSequence_search_constraint(void)
{
    m_set_State[0] |= 0x40;
    return m_Sequence_search_constraint;
}

inline
bool CSearch_summary_Base::IsSetAminoacid_modification(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CSearch_summary_Base::CanGetAminoacid_modification(void) const
{
    return true;
}

inline
const CSearch_summary_Base::TAminoacid_modification& CSearch_summary_Base::GetAminoacid_modification(void) const
{
    return m_Aminoacid_modification;
}

inline
CSearch_summary_Base::TAminoacid_modification& CSearch_summary_Base::SetAminoacid_modification(void)
{
    m_set_State[0] |= 0x100;
    return m_Aminoacid_modification;
}

inline
bool CSearch_summary_Base::IsSetTerminal_modification(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CSearch_summary_Base::CanGetTerminal_modification(void) const
{
    return true;
}

inline
const CSearch_summary_Base::TTerminal_modification& CSearch_summary_Base::GetTerminal_modification(void) const
{
    return m_Terminal_modification;
}

inline
CSearch_summary_Base::TTerminal_modification& CSearch_summary_Base::SetTerminal_modification(void)
{
    m_set_State[0] |= 0x400;
    return m_Terminal_modification;
}

inline
bool CSearch_summary_Base::IsSetParameter(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CSearch_summary_Base::CanGetParameter(void) const
{
    return true;
}

inline
const CSearch_summary_Base::TParameter& CSearch_summary_Base::GetParameter(void) const
{
    return m_Parameter;
}

inline
CSearch_summary_Base::TParameter& CSearch_summary_Base::SetParameter(void)
{
    m_set_State[0] |= 0x1000;
    return m_Parameter;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_MS_FORMATS_PEPXML_SEARCH_SUMMARY_BASE_HPP
