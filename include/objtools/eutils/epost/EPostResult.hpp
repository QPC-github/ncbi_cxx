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

/// @file EPostResult.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'epost.dtd'.
///
/// New methods or data members can be added to it if needed.
/// See also: EPostResult_.hpp


#ifndef epost__OBJTOOLS_EUTILS_EPOST_EPOSTRESULT_HPP
#define epost__OBJTOOLS_EUTILS_EPOST_EPOSTRESULT_HPP


// generated includes
#include <objtools/eutils/epost/EPostResult_.hpp>

// generated classes

BEGIN_epost_SCOPE // namespace epost::

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CEPostResult : public CEPostResult_Base
{
    typedef CEPostResult_Base Tparent;
public:
    // constructor
    CEPostResult(void);
    // destructor
    ~CEPostResult(void);

private:
    // Prohibit copy constructor and assignment operator
    CEPostResult(const CEPostResult& value);
    CEPostResult& operator=(const CEPostResult& value);

};

/////////////////// CEPostResult inline methods

// constructor
inline
CEPostResult::CEPostResult(void)
{
}


/////////////////// end of CEPostResult inline methods


END_epost_SCOPE // namespace epost::


#endif // epost__OBJTOOLS_EUTILS_EPOST_EPOSTRESULT_HPP
/* Original file checksum: lines: 82, chars: 2446, CRC32: f0c227f */
