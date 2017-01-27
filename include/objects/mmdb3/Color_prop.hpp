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

/// @file Color_prop.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'mmdb3.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Color_prop_.hpp


#ifndef OBJECTS_MMDB3_COLOR_PROP_HPP
#define OBJECTS_MMDB3_COLOR_PROP_HPP


// generated includes
#include <objects/mmdb3/Color_prop_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_MMDB3_EXPORT CColor_prop : public CColor_prop_Base
{
    typedef CColor_prop_Base Tparent;
public:
    // constructor
    CColor_prop(void);
    // destructor
    ~CColor_prop(void);

private:
    // Prohibit copy constructor and assignment operator
    CColor_prop(const CColor_prop& value);
    CColor_prop& operator=(const CColor_prop& value);

};

/////////////////// CColor_prop inline methods

// constructor
inline
CColor_prop::CColor_prop(void)
{
}


/////////////////// end of CColor_prop inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB3_COLOR_PROP_HPP
/* Original file checksum: lines: 86, chars: 2423, CRC32: a68cb16a */
