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

/// @file ErrorList.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'esearch.dtd'.
///
/// New methods or data members can be added to it if needed.
/// See also: ErrorList_.hpp


#ifndef esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_HPP
#define esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_HPP


// generated includes
#include <objtools/eutils/esearch/ErrorList_.hpp>

// generated classes

BEGIN_esearch_SCOPE // namespace esearch::

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CErrorList : public CErrorList_Base
{
    typedef CErrorList_Base Tparent;
public:
    // constructor
    CErrorList(void);
    // destructor
    ~CErrorList(void);

private:
    // Prohibit copy constructor and assignment operator
    CErrorList(const CErrorList& value);
    CErrorList& operator=(const CErrorList& value);

};

/////////////////// CErrorList inline methods

// constructor
inline
CErrorList::CErrorList(void)
{
}


/////////////////// end of CErrorList inline methods


END_esearch_SCOPE // namespace esearch::


#endif // esearch__OBJTOOLS_EUTILS_ESEARCH_ERRORLIST_HPP
/* Original file checksum: lines: 82, chars: 2432, CRC32: 95e771b8 */
