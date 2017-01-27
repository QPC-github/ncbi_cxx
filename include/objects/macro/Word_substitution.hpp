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

/// @file Word_substitution.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Word_substitution_.hpp


#ifndef OBJECTS_MACRO_WORD_SUBSTITUTION_HPP
#define OBJECTS_MACRO_WORD_SUBSTITUTION_HPP


// generated includes
#include <objects/macro/Word_substitution_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class CWord_substitution : public CWord_substitution_Base
{
    typedef CWord_substitution_Base Tparent;
public:
    // constructor
    CWord_substitution(void);
    // destructor
    ~CWord_substitution(void);

private:
    // Prohibit copy constructor and assignment operator
    CWord_substitution(const CWord_substitution& value);
    CWord_substitution& operator=(const CWord_substitution& value);

};

/////////////////// CWord_substitution inline methods

// constructor
inline
CWord_substitution::CWord_substitution(void)
{
}


/////////////////// end of CWord_substitution inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_WORD_SUBSTITUTION_HPP
/* Original file checksum: lines: 86, chars: 2538, CRC32: ccc9d630 */
