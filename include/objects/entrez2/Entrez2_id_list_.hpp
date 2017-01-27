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

/// @file Entrez2_id_list_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZ2_ENTREZ2_ID_LIST_BASE_HPP
#define OBJECTS_ENTREZ2_ENTREZ2_ID_LIST_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <vector>
#include <objects/entrez2/Entrez2_db_id.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// list of record UIDs
class NCBI_ENTREZ2_EXPORT CEntrez2_id_list_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CEntrez2_id_list_Base(void);
    // destructor
    virtual ~CEntrez2_id_list_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CEntrez2_db_id TDb;
    typedef int TNum;
    typedef vector< char > TUids;

    // getters
    // setters

    /// the database
    /// mandatory
    /// typedef CEntrez2_db_id TDb
    ///  Check whether the Db data member has been assigned a value.
    bool IsSetDb(void) const;
    /// Check whether it is safe or not to call GetDb method.
    bool CanGetDb(void) const;
    void ResetDb(void);
    const TDb& GetDb(void) const;
    void SetDb(const TDb& value);
    TDb& SetDb(void);

    /// number of uids
    /// mandatory
    /// typedef int TNum
    ///  Check whether the Num data member has been assigned a value.
    bool IsSetNum(void) const;
    /// Check whether it is safe or not to call GetNum method.
    bool CanGetNum(void) const;
    void ResetNum(void);
    TNum GetNum(void) const;
    void SetNum(TNum value);
    TNum& SetNum(void);

    /// coded uids
    /// optional
    /// typedef vector< char > TUids
    ///  Check whether the Uids data member has been assigned a value.
    bool IsSetUids(void) const;
    /// Check whether it is safe or not to call GetUids method.
    bool CanGetUids(void) const;
    void ResetUids(void);
    const TUids& GetUids(void) const;
    TUids& SetUids(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CEntrez2_id_list_Base(const CEntrez2_id_list_Base&);
    CEntrez2_id_list_Base& operator=(const CEntrez2_id_list_Base&);

    // data
    Uint4 m_set_State[1];
    CEntrez2_db_id m_Db;
    int m_Num;
    vector< char > m_Uids;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEntrez2_id_list_Base::IsSetDb(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CEntrez2_id_list_Base::CanGetDb(void) const
{
    return IsSetDb();
}

inline
const CEntrez2_id_list_Base::TDb& CEntrez2_id_list_Base::GetDb(void) const
{
    if (!CanGetDb()) {
        ThrowUnassigned(0);
    }
    return m_Db;
}

inline
void CEntrez2_id_list_Base::SetDb(const CEntrez2_id_list_Base::TDb& value)
{
    m_Db = value;
    m_set_State[0] |= 0x3;
}

inline
CEntrez2_id_list_Base::TDb& CEntrez2_id_list_Base::SetDb(void)
{
    m_set_State[0] |= 0x1;
    return m_Db;
}

inline
bool CEntrez2_id_list_Base::IsSetNum(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEntrez2_id_list_Base::CanGetNum(void) const
{
    return IsSetNum();
}

inline
void CEntrez2_id_list_Base::ResetNum(void)
{
    m_Num = 0;
    m_set_State[0] &= ~0xc;
}

inline
CEntrez2_id_list_Base::TNum CEntrez2_id_list_Base::GetNum(void) const
{
    if (!CanGetNum()) {
        ThrowUnassigned(1);
    }
    return m_Num;
}

inline
void CEntrez2_id_list_Base::SetNum(CEntrez2_id_list_Base::TNum value)
{
    m_Num = value;
    m_set_State[0] |= 0xc;
}

inline
CEntrez2_id_list_Base::TNum& CEntrez2_id_list_Base::SetNum(void)
{
#ifdef _DEBUG
    if (!IsSetNum()) {
        memset(&m_Num,UnassignedByte(),sizeof(m_Num));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Num;
}

inline
bool CEntrez2_id_list_Base::IsSetUids(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CEntrez2_id_list_Base::CanGetUids(void) const
{
    return IsSetUids();
}

inline
const CEntrez2_id_list_Base::TUids& CEntrez2_id_list_Base::GetUids(void) const
{
    if (!CanGetUids()) {
        ThrowUnassigned(2);
    }
    return m_Uids;
}

inline
CEntrez2_id_list_Base::TUids& CEntrez2_id_list_Base::SetUids(void)
{
    m_set_State[0] |= 0x10;
    return m_Uids;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_ENTREZ2_ID_LIST_BASE_HPP
