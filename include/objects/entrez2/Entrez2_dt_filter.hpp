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

/// @file Entrez2_dt_filter.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Entrez2_dt_filter_.hpp


#ifndef OBJECTS_ENTREZ2_ENTREZ2_DT_FILTER_HPP
#define OBJECTS_ENTREZ2_ENTREZ2_DT_FILTER_HPP


// generated includes
#include <objects/entrez2/Entrez2_dt_filter_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_ENTREZ2_EXPORT CEntrez2_dt_filter : public CEntrez2_dt_filter_Base
{
    typedef CEntrez2_dt_filter_Base Tparent;
public:
    // constructor
    CEntrez2_dt_filter(void);
    // destructor
    ~CEntrez2_dt_filter(void);

private:
    // Prohibit copy constructor and assignment operator
    CEntrez2_dt_filter(const CEntrez2_dt_filter& value);
    CEntrez2_dt_filter& operator=(const CEntrez2_dt_filter& value);

};

/////////////////// CEntrez2_dt_filter inline methods

// constructor
inline
CEntrez2_dt_filter::CEntrez2_dt_filter(void)
{
}


/////////////////// end of CEntrez2_dt_filter inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_ENTREZ2_DT_FILTER_HPP
/* Original file checksum: lines: 86, chars: 2568, CRC32: 90008a66 */
