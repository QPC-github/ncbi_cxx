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

/// @file Blast_db_mask_info.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'blastdb.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Blast_db_mask_info_.hpp


#ifndef OBJECTS_BLASTDB_BLAST_DB_MASK_INFO_HPP
#define OBJECTS_BLASTDB_BLAST_DB_MASK_INFO_HPP


// generated includes
#include <objects/blastdb/Blast_db_mask_info_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_BLASTDB_EXPORT CBlast_db_mask_info : public CBlast_db_mask_info_Base
{
    typedef CBlast_db_mask_info_Base Tparent;
public:
    // constructor
    CBlast_db_mask_info(void);
    // destructor
    ~CBlast_db_mask_info(void);

private:
    // Prohibit copy constructor and assignment operator
    CBlast_db_mask_info(const CBlast_db_mask_info& value);
    CBlast_db_mask_info& operator=(const CBlast_db_mask_info& value);

};

/////////////////// CBlast_db_mask_info inline methods

// constructor
inline
CBlast_db_mask_info::CBlast_db_mask_info(void)
{
}


/////////////////// end of CBlast_db_mask_info inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLASTDB_BLAST_DB_MASK_INFO_HPP
/* Original file checksum: lines: 86, chars: 2587, CRC32: 9ac9f0e */
