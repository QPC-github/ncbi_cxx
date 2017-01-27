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

/// @file ID1server_maxcomplex_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'id1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ID1_ID1SERVER_MAXCOMPLEX_BASE_HPP
#define OBJECTS_ID1_ID1SERVER_MAXCOMPLEX_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <objects/id1/Entry_complexities.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
///  Complexity stuff will be for ID1
class NCBI_ID1_EXPORT CID1server_maxcomplex_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID1server_maxcomplex_Base(void);
    // destructor
    virtual ~CID1server_maxcomplex_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TMaxplex;
    typedef int TGi;
    typedef int TEnt;
    typedef string TSat;

    // getters
    // setters

    /// mandatory
    /// typedef int TMaxplex
    ///  Check whether the Maxplex data member has been assigned a value.
    bool IsSetMaxplex(void) const;
    /// Check whether it is safe or not to call GetMaxplex method.
    bool CanGetMaxplex(void) const;
    void ResetMaxplex(void);
    TMaxplex GetMaxplex(void) const;
    void SetMaxplex(TMaxplex value);
    TMaxplex& SetMaxplex(void);

    /// mandatory
    /// typedef int TGi
    ///  Check whether the Gi data member has been assigned a value.
    bool IsSetGi(void) const;
    /// Check whether it is safe or not to call GetGi method.
    bool CanGetGi(void) const;
    void ResetGi(void);
    TGi GetGi(void) const;
    void SetGi(TGi value);
    TGi& SetGi(void);

    /// needed when you want to retrieve a given ent
    /// optional
    /// typedef int TEnt
    ///  Check whether the Ent data member has been assigned a value.
    bool IsSetEnt(void) const;
    /// Check whether it is safe or not to call GetEnt method.
    bool CanGetEnt(void) const;
    void ResetEnt(void);
    TEnt GetEnt(void) const;
    void SetEnt(TEnt value);
    TEnt& SetEnt(void);

    /// satellite 0-id,1-dbEST
    /// optional
    /// typedef string TSat
    ///  Check whether the Sat data member has been assigned a value.
    bool IsSetSat(void) const;
    /// Check whether it is safe or not to call GetSat method.
    bool CanGetSat(void) const;
    void ResetSat(void);
    const TSat& GetSat(void) const;
    void SetSat(const TSat& value);
    TSat& SetSat(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID1server_maxcomplex_Base(const CID1server_maxcomplex_Base&);
    CID1server_maxcomplex_Base& operator=(const CID1server_maxcomplex_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Maxplex;
    int m_Gi;
    int m_Ent;
    string m_Sat;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID1server_maxcomplex_Base::IsSetMaxplex(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CID1server_maxcomplex_Base::CanGetMaxplex(void) const
{
    return IsSetMaxplex();
}

inline
void CID1server_maxcomplex_Base::ResetMaxplex(void)
{
    m_Maxplex = (int)(0);
    m_set_State[0] &= ~0x3;
}

inline
CID1server_maxcomplex_Base::TMaxplex CID1server_maxcomplex_Base::GetMaxplex(void) const
{
    if (!CanGetMaxplex()) {
        ThrowUnassigned(0);
    }
    return m_Maxplex;
}

inline
void CID1server_maxcomplex_Base::SetMaxplex(CID1server_maxcomplex_Base::TMaxplex value)
{
    m_Maxplex = value;
    m_set_State[0] |= 0x3;
}

inline
CID1server_maxcomplex_Base::TMaxplex& CID1server_maxcomplex_Base::SetMaxplex(void)
{
#ifdef _DEBUG
    if (!IsSetMaxplex()) {
        memset(&m_Maxplex,UnassignedByte(),sizeof(m_Maxplex));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Maxplex;
}

inline
bool CID1server_maxcomplex_Base::IsSetGi(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CID1server_maxcomplex_Base::CanGetGi(void) const
{
    return IsSetGi();
}

inline
void CID1server_maxcomplex_Base::ResetGi(void)
{
    m_Gi = 0;
    m_set_State[0] &= ~0xc;
}

inline
CID1server_maxcomplex_Base::TGi CID1server_maxcomplex_Base::GetGi(void) const
{
    if (!CanGetGi()) {
        ThrowUnassigned(1);
    }
    return m_Gi;
}

inline
void CID1server_maxcomplex_Base::SetGi(CID1server_maxcomplex_Base::TGi value)
{
    m_Gi = value;
    m_set_State[0] |= 0xc;
}

inline
CID1server_maxcomplex_Base::TGi& CID1server_maxcomplex_Base::SetGi(void)
{
#ifdef _DEBUG
    if (!IsSetGi()) {
        memset(&m_Gi,UnassignedByte(),sizeof(m_Gi));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Gi;
}

inline
bool CID1server_maxcomplex_Base::IsSetEnt(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CID1server_maxcomplex_Base::CanGetEnt(void) const
{
    return IsSetEnt();
}

inline
void CID1server_maxcomplex_Base::ResetEnt(void)
{
    m_Ent = 0;
    m_set_State[0] &= ~0x30;
}

inline
CID1server_maxcomplex_Base::TEnt CID1server_maxcomplex_Base::GetEnt(void) const
{
    if (!CanGetEnt()) {
        ThrowUnassigned(2);
    }
    return m_Ent;
}

inline
void CID1server_maxcomplex_Base::SetEnt(CID1server_maxcomplex_Base::TEnt value)
{
    m_Ent = value;
    m_set_State[0] |= 0x30;
}

inline
CID1server_maxcomplex_Base::TEnt& CID1server_maxcomplex_Base::SetEnt(void)
{
#ifdef _DEBUG
    if (!IsSetEnt()) {
        memset(&m_Ent,UnassignedByte(),sizeof(m_Ent));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Ent;
}

inline
bool CID1server_maxcomplex_Base::IsSetSat(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CID1server_maxcomplex_Base::CanGetSat(void) const
{
    return IsSetSat();
}

inline
const CID1server_maxcomplex_Base::TSat& CID1server_maxcomplex_Base::GetSat(void) const
{
    if (!CanGetSat()) {
        ThrowUnassigned(3);
    }
    return m_Sat;
}

inline
void CID1server_maxcomplex_Base::SetSat(const CID1server_maxcomplex_Base::TSat& value)
{
    m_Sat = value;
    m_set_State[0] |= 0xc0;
}

inline
CID1server_maxcomplex_Base::TSat& CID1server_maxcomplex_Base::SetSat(void)
{
#ifdef _DEBUG
    if (!IsSetSat()) {
        m_Sat = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Sat;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID1_ID1SERVER_MAXCOMPLEX_BASE_HPP
