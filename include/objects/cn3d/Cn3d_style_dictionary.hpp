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

/// @file Cn3d_style_dictionary.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'cn3d.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Cn3d_style_dictionary_.hpp


#ifndef OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_HPP
#define OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_HPP


// generated includes
#include <objects/cn3d/Cn3d_style_dictionary_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_CN3D_EXPORT CCn3d_style_dictionary : public CCn3d_style_dictionary_Base
{
    typedef CCn3d_style_dictionary_Base Tparent;
public:
    // constructor
    CCn3d_style_dictionary(void);
    // destructor
    ~CCn3d_style_dictionary(void);

private:
    // Prohibit copy constructor and assignment operator
    CCn3d_style_dictionary(const CCn3d_style_dictionary& value);
    CCn3d_style_dictionary& operator=(const CCn3d_style_dictionary& value);

};

/////////////////// CCn3d_style_dictionary inline methods

// constructor
inline
CCn3d_style_dictionary::CCn3d_style_dictionary(void)
{
}


/////////////////// end of CCn3d_style_dictionary inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_HPP
/* Original file checksum: lines: 86, chars: 2626, CRC32: e023aa9c */
