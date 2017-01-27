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

/// @file Rule.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'linkout.dtd'.
///
/// New methods or data members can be added to it if needed.
/// See also: Rule_.hpp


#ifndef linkout__OBJTOOLS_EUTILS_LINKOUT_RULE_HPP
#define linkout__OBJTOOLS_EUTILS_LINKOUT_RULE_HPP


// generated includes
#include <objtools/eutils/linkout/Rule_.hpp>

// generated classes

BEGIN_linkout_SCOPE // namespace linkout::

/////////////////////////////////////////////////////////////////////////////
class NCBI_EUTILS_EXPORT CRule : public CRule_Base
{
    typedef CRule_Base Tparent;
public:
    // constructor
    CRule(void);
    // destructor
    ~CRule(void);

private:
    // Prohibit copy constructor and assignment operator
    CRule(const CRule& value);
    CRule& operator=(const CRule& value);

};

/////////////////// CRule inline methods

// constructor
inline
CRule::CRule(void)
{
}


/////////////////// end of CRule inline methods


END_linkout_SCOPE // namespace linkout::


#endif // linkout__OBJTOOLS_EUTILS_LINKOUT_RULE_HPP
/* Original file checksum: lines: 82, chars: 2337, CRC32: 1123086d */
