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

/// @file Mim_cit.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'mim.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Mim_cit_.hpp


#ifndef OBJECTS_MIM_MIM_CIT_HPP
#define OBJECTS_MIM_MIM_CIT_HPP


// generated includes
#include <objects/mim/Mim_cit_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_MIM_EXPORT CMim_cit : public CMim_cit_Base
{
    typedef CMim_cit_Base Tparent;
public:
    // constructor
    CMim_cit(void);
    // destructor
    ~CMim_cit(void);

private:
    // Prohibit copy constructor and assignment operator
    CMim_cit(const CMim_cit& value);
    CMim_cit& operator=(const CMim_cit& value);

};

/////////////////// CMim_cit inline methods

// constructor
inline
CMim_cit::CMim_cit(void)
{
}


/////////////////// end of CMim_cit inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MIM_MIM_CIT_HPP
/* Original file checksum: lines: 86, chars: 2354, CRC32: bb535cc3 */