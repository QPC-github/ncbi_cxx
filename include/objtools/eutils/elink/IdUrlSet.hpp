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

/// @file IdUrlSet.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'elink.dtd'.
///
/// New methods or data members can be added to it if needed.
/// See also: IdUrlSet_.hpp


#ifndef elink__OBJTOOLS_EUTILS_ELINK_IDURLSET_HPP
#define elink__OBJTOOLS_EUTILS_ELINK_IDURLSET_HPP


// generated includes
#include <objtools/eutils/elink/IdUrlSet_.hpp>

// generated classes

BEGIN_elink_SCOPE // namespace elink::

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CIdUrlSet : public CIdUrlSet_Base
{
    typedef CIdUrlSet_Base Tparent;
public:
    // constructor
    CIdUrlSet(void);
    // destructor
    ~CIdUrlSet(void);

private:
    // Prohibit copy constructor and assignment operator
    CIdUrlSet(const CIdUrlSet& value);
    CIdUrlSet& operator=(const CIdUrlSet& value);

};

/////////////////// CIdUrlSet inline methods

// constructor
inline
CIdUrlSet::CIdUrlSet(void)
{
}


/////////////////// end of CIdUrlSet inline methods


END_elink_SCOPE // namespace elink::


#endif // elink__OBJTOOLS_EUTILS_ELINK_IDURLSET_HPP
/* Original file checksum: lines: 82, chars: 2389, CRC32: f2b92a87 */
