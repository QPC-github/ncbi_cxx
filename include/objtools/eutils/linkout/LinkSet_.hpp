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

/// @file LinkSet_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'linkout.dtd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef linkout__OBJTOOLS_EUTILS_LINKOUT_LINKSET_BASE_HPP
#define linkout__OBJTOOLS_EUTILS_LINKOUT_LINKSET_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

#ifndef BEGIN_linkout_SCOPE
#  define BEGIN_linkout_SCOPE BEGIN_SCOPE(linkout)
#  define END_linkout_SCOPE END_SCOPE(linkout)
#endif
BEGIN_linkout_SCOPE // namespace linkout::


// forward declarations
class CLink;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// End of Privider group 
class NCBI_EUTILS_EXPORT CLinkSet_Base : public NCBI_NS_NCBI::CSerialObject
{
    typedef NCBI_NS_NCBI::CSerialObject Tparent;
public:
    // constructor
    CLinkSet_Base(void);
    // destructor
    virtual ~CLinkSet_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< CLink > > TLink;

    // getters
    // setters

    /// mandatory
    /// typedef NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< CLink > > TLink
    ///  Check whether the Link data member has been assigned a value.
    bool IsSetLink(void) const;
    /// Check whether it is safe or not to call GetLink method.
    bool CanGetLink(void) const;
    void ResetLink(void);
    const TLink& GetLink(void) const;
    TLink& SetLink(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CLinkSet_Base(const CLinkSet_Base&);
    CLinkSet_Base& operator=(const CLinkSet_Base&);

    // data
    Uint4 m_set_State[1];
    NCBI_NS_STD::list< NCBI_NS_NCBI::CRef< CLink > > m_Link;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CLinkSet_Base::IsSetLink(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CLinkSet_Base::CanGetLink(void) const
{
    return true;
}

inline
const CLinkSet_Base::TLink& CLinkSet_Base::GetLink(void) const
{
    return m_Link;
}

inline
CLinkSet_Base::TLink& CLinkSet_Base::SetLink(void)
{
    m_set_State[0] |= 0x1;
    return m_Link;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_linkout_SCOPE // namespace linkout::


#endif // linkout__OBJTOOLS_EUTILS_LINKOUT_LINKSET_BASE_HPP
