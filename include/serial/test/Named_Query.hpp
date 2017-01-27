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

/// @file Named_Query.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'we_cpp.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Named_Query_.hpp


#ifndef SERIAL_TEST_NAMED_QUERY_HPP
#define SERIAL_TEST_NAMED_QUERY_HPP


// generated includes
#include <serial/test/Named_Query_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class CNamed_Query : public CNamed_Query_Base
{
    typedef CNamed_Query_Base Tparent;
public:
    // constructor
    CNamed_Query(void);
    // destructor
    ~CNamed_Query(void);

private:
    // Prohibit copy constructor and assignment operator
    CNamed_Query(const CNamed_Query& value);
    CNamed_Query& operator=(const CNamed_Query& value);

};

/////////////////// CNamed_Query inline methods

// constructor
inline
CNamed_Query::CNamed_Query(void)
{
}


/////////////////// end of CNamed_Query inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // SERIAL_TEST_NAMED_QUERY_HPP
/* Original file checksum: lines: 86, chars: 2417, CRC32: e3e49837 */
