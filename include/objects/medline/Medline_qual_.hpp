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

/// @file Medline_qual_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'medline.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MEDLINE_MEDLINE_QUAL_BASE_HPP
#define OBJECTS_MEDLINE_MEDLINE_QUAL_BASE_HPP

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
class NCBI_MEDLINE_EXPORT CMedline_qual_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMedline_qual_Base(void);
    // destructor
    virtual ~CMedline_qual_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef bool TMp;
    typedef string TSubh;

    // getters
    // setters

    /// TRUE if main point
    /// optional with default false
    /// typedef bool TMp
    ///  Check whether the Mp data member has been assigned a value.
    bool IsSetMp(void) const;
    /// Check whether it is safe or not to call GetMp method.
    bool CanGetMp(void) const;
    void ResetMp(void);
    void SetDefaultMp(void);
    TMp GetMp(void) const;
    void SetMp(TMp value);
    TMp& SetMp(void);

    /// the subheading
    /// mandatory
    /// typedef string TSubh
    ///  Check whether the Subh data member has been assigned a value.
    bool IsSetSubh(void) const;
    /// Check whether it is safe or not to call GetSubh method.
    bool CanGetSubh(void) const;
    void ResetSubh(void);
    const TSubh& GetSubh(void) const;
    void SetSubh(const TSubh& value);
    TSubh& SetSubh(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMedline_qual_Base(const CMedline_qual_Base&);
    CMedline_qual_Base& operator=(const CMedline_qual_Base&);

    // data
    Uint4 m_set_State[1];
    bool m_Mp;
    string m_Subh;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMedline_qual_Base::IsSetMp(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMedline_qual_Base::CanGetMp(void) const
{
    return true;
}

inline
void CMedline_qual_Base::ResetMp(void)
{
    m_Mp = false;
    m_set_State[0] &= ~0x3;
}

inline
void CMedline_qual_Base::SetDefaultMp(void)
{
    ResetMp();
}

inline
CMedline_qual_Base::TMp CMedline_qual_Base::GetMp(void) const
{
    return m_Mp;
}

inline
void CMedline_qual_Base::SetMp(CMedline_qual_Base::TMp value)
{
    m_Mp = value;
    m_set_State[0] |= 0x3;
}

inline
CMedline_qual_Base::TMp& CMedline_qual_Base::SetMp(void)
{
#ifdef _DEBUG
    if (!IsSetMp()) {
        memset(&m_Mp,UnassignedByte(),sizeof(m_Mp));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Mp;
}

inline
bool CMedline_qual_Base::IsSetSubh(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CMedline_qual_Base::CanGetSubh(void) const
{
    return IsSetSubh();
}

inline
const CMedline_qual_Base::TSubh& CMedline_qual_Base::GetSubh(void) const
{
    if (!CanGetSubh()) {
        ThrowUnassigned(1);
    }
    return m_Subh;
}

inline
void CMedline_qual_Base::SetSubh(const CMedline_qual_Base::TSubh& value)
{
    m_Subh = value;
    m_set_State[0] |= 0xc;
}

inline
CMedline_qual_Base::TSubh& CMedline_qual_Base::SetSubh(void)
{
#ifdef _DEBUG
    if (!IsSetSubh()) {
        m_Subh = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Subh;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MEDLINE_MEDLINE_QUAL_BASE_HPP