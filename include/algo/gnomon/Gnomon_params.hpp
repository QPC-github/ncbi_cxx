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

/// @file Gnomon_params.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'gnomon.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Gnomon_params_.hpp


#ifndef ALGO_GNOMON_GNOMON_PARAMS_HPP
#define ALGO_GNOMON_GNOMON_PARAMS_HPP


// generated includes
#include <algo/gnomon/Gnomon_params_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_XALGOGNOMON_EXPORT CGnomon_params : public CGnomon_params_Base
{
    typedef CGnomon_params_Base Tparent;
public:
    // constructor
    CGnomon_params(void);
    // destructor
    ~CGnomon_params(void);

private:
    // Prohibit copy constructor and assignment operator
    CGnomon_params(const CGnomon_params& value);
    CGnomon_params& operator=(const CGnomon_params& value);

};

/////////////////// CGnomon_params inline methods

// constructor
inline
CGnomon_params::CGnomon_params(void)
{
}


/////////////////// end of CGnomon_params inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // ALGO_GNOMON_GNOMON_PARAMS_HPP
/* Original file checksum: lines: 86, chars: 2479, CRC32: 35257fd4 */
