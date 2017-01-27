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

/// @file InvalidIdList_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'epost.dtd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef epost__OBJTOOLS_EUTILS_EPOST_INVALIDIDLIST_BASE_HPP
#define epost__OBJTOOLS_EUTILS_EPOST_INVALIDIDLIST_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

#ifndef BEGIN_epost_SCOPE
#  define BEGIN_epost_SCOPE BEGIN_SCOPE(epost)
#  define END_epost_SCOPE END_SCOPE(epost)
#endif
BEGIN_epost_SCOPE // namespace epost::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CInvalidIdList_Base : public NCBI_NS_NCBI::CSerialObject
{
    typedef NCBI_NS_NCBI::CSerialObject Tparent;
public:
    // constructor
    CInvalidIdList_Base(void);
    // destructor
    virtual ~CInvalidIdList_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TId;

    // getters
    // setters

    /// \d+ 
    /// mandatory
    /// typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    TId& SetId(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CInvalidIdList_Base(const CInvalidIdList_Base&);
    CInvalidIdList_Base& operator=(const CInvalidIdList_Base&);

    // data
    Uint4 m_set_State[1];
    NCBI_NS_STD::list< NCBI_NS_STD::string > m_Id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CInvalidIdList_Base::IsSetId(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CInvalidIdList_Base::CanGetId(void) const
{
    return true;
}

inline
const CInvalidIdList_Base::TId& CInvalidIdList_Base::GetId(void) const
{
    return m_Id;
}

inline
CInvalidIdList_Base::TId& CInvalidIdList_Base::SetId(void)
{
    m_set_State[0] |= 0x1;
    return m_Id;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_epost_SCOPE // namespace epost::


#endif // epost__OBJTOOLS_EUTILS_EPOST_INVALIDIDLIST_BASE_HPP