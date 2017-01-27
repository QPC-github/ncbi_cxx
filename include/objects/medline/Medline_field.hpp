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

/// @file Medline_field.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'medline.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Medline_field_.hpp


#ifndef OBJECTS_MEDLINE_MEDLINE_FIELD_HPP
#define OBJECTS_MEDLINE_MEDLINE_FIELD_HPP


// generated includes
#include <objects/medline/Medline_field_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_MEDLINE_EXPORT CMedline_field : public CMedline_field_Base
{
    typedef CMedline_field_Base Tparent;
public:
    // constructor
    CMedline_field(void);
    // destructor
    ~CMedline_field(void);

private:
    // Prohibit copy constructor and assignment operator
    CMedline_field(const CMedline_field& value);
    CMedline_field& operator=(const CMedline_field& value);

};

/////////////////// CMedline_field inline methods

// constructor
inline
CMedline_field::CMedline_field(void)
{
}


/////////////////// end of CMedline_field inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MEDLINE_MEDLINE_FIELD_HPP
/* Original file checksum: lines: 86, chars: 2492, CRC32: 1336b256 */
