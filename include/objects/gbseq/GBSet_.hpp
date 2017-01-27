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

/// @file GBSet_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBSEQ_GBSET_BASE_HPP
#define OBJECTS_GBSEQ_GBSET_BASE_HPP

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
class CGBSeq;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///********
///  GBSeq represents the elements in a GenBank style report
///    of a sequence with some small additions to structure and support
///    for protein (GenPept) versions of GenBank format as seen in
///    Entrez. While this represents the simplification, reduction of
///    detail, and flattening to a single sequence perspective of GenBank
///    format (compared with the full ASN.1 or XML from which GenBank and
///    this format is derived at NCBI), it is presented in ASN.1 or XML for
///    automated parsing and processing. It is hoped that this compromise
///    will be useful for those bulk processing at the GenBank format level
///    of detail today. Since it is a compromise, a number of pragmatic
///    decisions have been made.
///
///  In pursuit of simplicity and familiarity a number of
///    fields do not have full substructure defined here where there is
///    already a standard GenBank format string. For example:
///
///   Date  DD-Mon-YYYY
///   Authors   LastName, Intials (with periods)
///   Journal   JounalName Volume (issue), page-range (year)
///   FeatureLocations as per GenBank feature table, but FeatureIntervals
///    may also be provided as a convenience
///   FeatureQualifiers  as per GenBank feature table
///   Primary has a string that represents a table to construct
///    a third party (TPA) sequence.
///   other-seqids can have strings with the "vertical bar format" sequence
///    identifiers used in BLAST for example, when they are non-genbank types.
///    Currently in GenBank format you only see GI, but there are others, like
///    patents, submitter clone names, etc which will appear here, as they
///    always have in the ASN.1 format, and full XML format.
///   source-db is a formatted text block for peptides in GenPept format that
///    carries information from the source protein database.
///
///  There are also a number of elements that could have been
///   more exactly specified, but in the interest of simplicity
///   have been simply left as options. For example..
///
///  accession and accession.version will always appear in a GenBank record
///   they are optional because this format can also be used for non-GenBank
///   sequences, and in that case will have only "other-seqids".
///
///  sequences will normally all have "sequence" filled in. But contig records
///    will have a "join" statement in the "contig" slot, and no "sequence".
///    We also may consider a retrieval option with no sequence of any kind
///     and no feature table to quickly check minimal values.
///
///  a reference may have an author list, or be from a consortium, or both.
///
///  some fields, such as taxonomy, do appear as separate elements in GenBank
///    format but without a specific linetype (in GenBank format this comes
///    under ORGANISM). Another example is the separation of primary accession
///    from the list of secondary accessions. In GenBank format primary
///    accession is just the first one on the list that includes all secondaries
///    after it.
///
///  create-date deserves special comment. The date you see on the right hand
///    side of the LOCUS line in GenBank format is actually the last date the
///    the record was modified (or the update-date). The date the record was
///    first submitted to GenBank appears in the first submission citation in
///    the reference section. Internally in the databases and ASN.1 NCBI keeps
///    the first date the record was released into the sequence database at
///    NCBI as create-date. For records from EMBL, which supports create-date,
///    it is the date provided by EMBL. For DDBJ records, which do not supply
///    a create-date (same as GenBank format) the create-date is the first date
///    NCBI saw the record from DDBJ. For older GenBank records, before NCBI
///    took responsibility for GenBank, it is just the first date NCBI saw the
///    record. Create-date can be very useful, so we expose it here, but users
///    must understand it is only an approximation and comes from many sources,
///    and with many exceptions and caveats. It does NOT tell you the first
///    date the public might have seen this record and thus is NOT an accurate
///    measure for legal issues of precedence.
///
///********
class NCBI_GBSEQ_EXPORT CGBSet_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGBSet_Base(void);
    // destructor
    virtual ~CGBSet_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CGBSeq > > Tdata;

    // getters
    // setters

    /// mandatory
    /// typedef list< CRef< CGBSeq > > Tdata
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
    CGBSet_Base(const CGBSet_Base&);
    CGBSet_Base& operator=(const CGBSet_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CGBSeq > > m_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGBSet_Base::IsSet(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGBSet_Base::CanGet(void) const
{
    return true;
}

inline
const CGBSet_Base::Tdata& CGBSet_Base::Get(void) const
{
    return m_data;
}

inline
CGBSet_Base::Tdata& CGBSet_Base::Set(void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

inline
CGBSet_Base::operator const CGBSet_Base::Tdata& (void) const
{
    return m_data;
}

inline
CGBSet_Base::operator CGBSet_Base::Tdata& (void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBSEQ_GBSET_BASE_HPP
