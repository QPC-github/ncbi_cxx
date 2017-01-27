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

/// @file Residue_explicit_pntrs_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb3.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB3_RESIDUE_EXPLICIT_PNTRS_BASE_HPP
#define OBJECTS_MMDB3_RESIDUE_EXPLICIT_PNTRS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <objects/mmdb1/Molecule_id.hpp>
#include <objects/mmdb1/Residue_id.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_MMDB3_EXPORT CResidue_explicit_pntrs_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CResidue_explicit_pntrs_Base(void);
    // destructor
    virtual ~CResidue_explicit_pntrs_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TNumber_of_ptrs;
    typedef list< CMolecule_id > TMolecule_ids;
    typedef list< CResidue_id > TResidue_ids;

    // getters
    // setters

    /// mandatory
    /// typedef int TNumber_of_ptrs
    ///  Check whether the Number_of_ptrs data member has been assigned a value.
    bool IsSetNumber_of_ptrs(void) const;
    /// Check whether it is safe or not to call GetNumber_of_ptrs method.
    bool CanGetNumber_of_ptrs(void) const;
    void ResetNumber_of_ptrs(void);
    TNumber_of_ptrs GetNumber_of_ptrs(void) const;
    void SetNumber_of_ptrs(TNumber_of_ptrs value);
    TNumber_of_ptrs& SetNumber_of_ptrs(void);

    /// mandatory
    /// typedef list< CMolecule_id > TMolecule_ids
    ///  Check whether the Molecule_ids data member has been assigned a value.
    bool IsSetMolecule_ids(void) const;
    /// Check whether it is safe or not to call GetMolecule_ids method.
    bool CanGetMolecule_ids(void) const;
    void ResetMolecule_ids(void);
    const TMolecule_ids& GetMolecule_ids(void) const;
    TMolecule_ids& SetMolecule_ids(void);

    /// mandatory
    /// typedef list< CResidue_id > TResidue_ids
    ///  Check whether the Residue_ids data member has been assigned a value.
    bool IsSetResidue_ids(void) const;
    /// Check whether it is safe or not to call GetResidue_ids method.
    bool CanGetResidue_ids(void) const;
    void ResetResidue_ids(void);
    const TResidue_ids& GetResidue_ids(void) const;
    TResidue_ids& SetResidue_ids(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CResidue_explicit_pntrs_Base(const CResidue_explicit_pntrs_Base&);
    CResidue_explicit_pntrs_Base& operator=(const CResidue_explicit_pntrs_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Number_of_ptrs;
    list< CMolecule_id > m_Molecule_ids;
    list< CResidue_id > m_Residue_ids;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CResidue_explicit_pntrs_Base::IsSetNumber_of_ptrs(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CResidue_explicit_pntrs_Base::CanGetNumber_of_ptrs(void) const
{
    return IsSetNumber_of_ptrs();
}

inline
void CResidue_explicit_pntrs_Base::ResetNumber_of_ptrs(void)
{
    m_Number_of_ptrs = 0;
    m_set_State[0] &= ~0x3;
}

inline
CResidue_explicit_pntrs_Base::TNumber_of_ptrs CResidue_explicit_pntrs_Base::GetNumber_of_ptrs(void) const
{
    if (!CanGetNumber_of_ptrs()) {
        ThrowUnassigned(0);
    }
    return m_Number_of_ptrs;
}

inline
void CResidue_explicit_pntrs_Base::SetNumber_of_ptrs(CResidue_explicit_pntrs_Base::TNumber_of_ptrs value)
{
    m_Number_of_ptrs = value;
    m_set_State[0] |= 0x3;
}

inline
CResidue_explicit_pntrs_Base::TNumber_of_ptrs& CResidue_explicit_pntrs_Base::SetNumber_of_ptrs(void)
{
#ifdef _DEBUG
    if (!IsSetNumber_of_ptrs()) {
        memset(&m_Number_of_ptrs,UnassignedByte(),sizeof(m_Number_of_ptrs));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Number_of_ptrs;
}

inline
bool CResidue_explicit_pntrs_Base::IsSetMolecule_ids(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CResidue_explicit_pntrs_Base::CanGetMolecule_ids(void) const
{
    return true;
}

inline
const CResidue_explicit_pntrs_Base::TMolecule_ids& CResidue_explicit_pntrs_Base::GetMolecule_ids(void) const
{
    return m_Molecule_ids;
}

inline
CResidue_explicit_pntrs_Base::TMolecule_ids& CResidue_explicit_pntrs_Base::SetMolecule_ids(void)
{
    m_set_State[0] |= 0x4;
    return m_Molecule_ids;
}

inline
bool CResidue_explicit_pntrs_Base::IsSetResidue_ids(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CResidue_explicit_pntrs_Base::CanGetResidue_ids(void) const
{
    return true;
}

inline
const CResidue_explicit_pntrs_Base::TResidue_ids& CResidue_explicit_pntrs_Base::GetResidue_ids(void) const
{
    return m_Residue_ids;
}

inline
CResidue_explicit_pntrs_Base::TResidue_ids& CResidue_explicit_pntrs_Base::SetResidue_ids(void)
{
    m_set_State[0] |= 0x10;
    return m_Residue_ids;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB3_RESIDUE_EXPLICIT_PNTRS_BASE_HPP
