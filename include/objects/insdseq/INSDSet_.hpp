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

/// @file INSDSet_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'insdseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_INSDSEQ_INSDSET_BASE_HPP
#define OBJECTS_INSDSEQ_INSDSET_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CINSDSeq;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///  INSDSeq provides the elements of a sequence as presented in the
///    GenBank/EMBL/DDBJ-style flatfile formats, with a small amount of
///    additional structure.
///    Although this single perspective of the three flatfile formats
///    provides a useful simplification, it hides to some extent the
///    details of the actual data underlying those formats. Nevertheless,
///    the XML version of INSD-Seq is being provided with
///    the hopes that it will prove useful to those who bulk-process
///    sequence data at the flatfile-format level of detail. Further 
///    documentation regarding the content and conventions of those formats 
///    can be found at:
///
///    URLs for the DDBJ, EMBL, and GenBank Feature Table Document:
///    http://www.ddbj.nig.ac.jp/FT/full_index.html
///    http://www.ebi.ac.uk/embl/Documentation/FT_definitions/feature_table.html
///    http://www.ncbi.nlm.nih.gov/projects/collab/FT/index.html
///
///    URLs for DDBJ, EMBL, and GenBank Release Notes :
///    ftp://ftp.ddbj.nig.ac.jp/database/ddbj/ddbjrel.txt
///    http://www.ebi.ac.uk/embl/Documentation/Release_notes/current/relnotes.html
///    ftp://ftp.ncbi.nih.gov/genbank/gbrel.txt
///
///    Because INSDSeq is a compromise, a number of pragmatic decisions have
///    been made:
///
///  In pursuit of simplicity and familiarity a number of fields do not
///    have full substructure defined here where there is already a
///    standard flatfile format string. For example:
///
///   Dates:      DD-MON-YYYY (eg 10-JUN-2003)
///
///   Author:     LastName, Initials  (eg Smith, J.N.)
///            or Lastname Initials   (eg Smith J.N.)
///
///   Journal:    JournalName Volume (issue), page-range (year)
///            or JournalName Volume(issue):page-range(year)
///            eg Appl. Environ. Microbiol. 61 (4), 1646-1648 (1995)
///               Appl. Environ. Microbiol. 61(4):1646-1648(1995).
///
///  FeatureLocations are representated as in the flatfile feature table,
///    but FeatureIntervals may also be provided as a convenience
///
///  FeatureQualifiers are represented as in the flatfile feature table.
///
///  Primary has a string that represents a table to construct
///    a third party (TPA) sequence.
///
///  other-seqids can have strings with the "vertical bar format" sequence
///    identifiers used in BLAST for example, when they are non-INSD types.
///
///  Currently in flatfile format you only see Accession numbers, but there 
///    are others, like patents, submitter clone names, etc which will 
///    appear here
///
///  There are also a number of elements that could have been more exactly
///    specified, but in the interest of simplicity have been simply left as
///    optional. For example:
///
///  All publicly accessible sequence records in INSDSeq format will
///    include accession and accession.version. However, these elements are 
///    optional in optional in INSDSeq so that this format can also be used   
///    for non-public sequence data, prior to the assignment of accessions and 
///    version numbers. In such cases, records will have only "other-seqids".
///
///  sequences will normally all have "sequence" filled in. But contig records
///    will have a "join" statement in the "contig" slot, and no "sequence".
///    We also may consider a retrieval option with no sequence of any kind
///    and no feature table to quickly check minimal values.
///
///  Four (optional) elements are specific to records represented via the EMBL
///    sequence database: INSDSeq_update-release, INSDSeq_create-release,
///    INSDSeq_entry-version, and INSDSeq_database-reference.
///
///  One (optional) element is specific to records originating at the GenBank
///    and DDBJ sequence databases: INSDSeq_segment.
///
///********
class NCBI_INSDSEQ_EXPORT CINSDSet_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CINSDSet_Base(void);
    // destructor
    virtual ~CINSDSet_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CINSDSeq > > Tdata;

    // getters
    // setters

    /// mandatory
    /// typedef list< CRef< CINSDSeq > > Tdata
    ///  Check whether the  data member has been assigned a value.
    bool IsSet(void) const;
    /// Check whether it is safe or not to call Get method.
    bool CanGet(void) const;
    void Reset(void);
    const Tdata& Get(void) const;
    Tdata& Set(void);
    /// Conversion operator to 'const Tdata' type.
    operator const Tdata& (void) const;

    /// Conversion operator to 'Tdata' type.
    operator Tdata& (void);




private:
    // Prohibit copy constructor and assignment operator
    CINSDSet_Base(const CINSDSet_Base&);
    CINSDSet_Base& operator=(const CINSDSet_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CINSDSeq > > m_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CINSDSet_Base::IsSet(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CINSDSet_Base::CanGet(void) const
{
    return true;
}

inline
const CINSDSet_Base::Tdata& CINSDSet_Base::Get(void) const
{
    return m_data;
}

inline
CINSDSet_Base::Tdata& CINSDSet_Base::Set(void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

inline
CINSDSet_Base::operator const CINSDSet_Base::Tdata& (void) const
{
    return m_data;
}

inline
CINSDSet_Base::operator CINSDSet_Base::Tdata& (void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_INSDSEQ_INSDSET_BASE_HPP
