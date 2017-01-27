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

/// @file ErrorList_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'esearch.dtd'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_BASE_HPP
#define esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

#ifndef BEGIN_esearch_SCOPE
#  define BEGIN_esearch_SCOPE BEGIN_SCOPE(esearch)
#  define END_esearch_SCOPE END_SCOPE(esearch)
#endif
BEGIN_esearch_SCOPE // namespace esearch::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CErrorList_Base : public NCBI_NS_NCBI::CSerialObject
{
    typedef NCBI_NS_NCBI::CSerialObject Tparent;
public:
    // constructor
    CErrorList_Base(void);
    // destructor
    virtual ~CErrorList_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TPhraseNotFound;
    typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TFieldNotFound;

    // getters
    // setters

    /// .+ 
    /// optional
    /// typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TPhraseNotFound
    ///  Check whether the PhraseNotFound data member has been assigned a value.
    bool IsSetPhraseNotFound(void) const;
    /// Check whether it is safe or not to call GetPhraseNotFound method.
    bool CanGetPhraseNotFound(void) const;
    void ResetPhraseNotFound(void);
    const TPhraseNotFound& GetPhraseNotFound(void) const;
    TPhraseNotFound& SetPhraseNotFound(void);

    /// .+ 
    /// optional
    /// typedef NCBI_NS_STD::list< NCBI_NS_STD::string > TFieldNotFound
    ///  Check whether the FieldNotFound data member has been assigned a value.
    bool IsSetFieldNotFound(void) const;
    /// Check whether it is safe or not to call GetFieldNotFound method.
    bool CanGetFieldNotFound(void) const;
    void ResetFieldNotFound(void);
    const TFieldNotFound& GetFieldNotFound(void) const;
    TFieldNotFound& SetFieldNotFound(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CErrorList_Base(const CErrorList_Base&);
    CErrorList_Base& operator=(const CErrorList_Base&);

    // data
    Uint4 m_set_State[1];
    NCBI_NS_STD::list< NCBI_NS_STD::string > m_PhraseNotFound;
    NCBI_NS_STD::list< NCBI_NS_STD::string > m_FieldNotFound;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CErrorList_Base::IsSetPhraseNotFound(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CErrorList_Base::CanGetPhraseNotFound(void) const
{
    return true;
}

inline
const CErrorList_Base::TPhraseNotFound& CErrorList_Base::GetPhraseNotFound(void) const
{
    return m_PhraseNotFound;
}

inline
CErrorList_Base::TPhraseNotFound& CErrorList_Base::SetPhraseNotFound(void)
{
    m_set_State[0] |= 0x1;
    return m_PhraseNotFound;
}

inline
bool CErrorList_Base::IsSetFieldNotFound(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CErrorList_Base::CanGetFieldNotFound(void) const
{
    return true;
}

inline
const CErrorList_Base::TFieldNotFound& CErrorList_Base::GetFieldNotFound(void) const
{
    return m_FieldNotFound;
}

inline
CErrorList_Base::TFieldNotFound& CErrorList_Base::SetFieldNotFound(void)
{
    m_set_State[0] |= 0x4;
    return m_FieldNotFound;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_esearch_SCOPE // namespace esearch::


#endif // esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_BASE_HPP
