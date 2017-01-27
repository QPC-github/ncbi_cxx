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

/// @file ID2_Blob_Seq_id_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'id2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ID2_ID2_BLOB_SEQ_ID_BASE_HPP
#define OBJECTS_ID2_ID2_BLOB_SEQ_ID_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSeq_id;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ID2_EXPORT CID2_Blob_Seq_id_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2_Blob_Seq_id_Base(void);
    // destructor
    virtual ~CID2_Blob_Seq_id_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CSeq_id TSeq_id;

    // getters
    // setters

    /// mandatory
    /// typedef CSeq_id TSeq_id
    ///  Check whether the Seq_id data member has been assigned a value.
    bool IsSetSeq_id(void) const;
    /// Check whether it is safe or not to call GetSeq_id method.
    bool CanGetSeq_id(void) const;
    void ResetSeq_id(void);
    const TSeq_id& GetSeq_id(void) const;
    void SetSeq_id(TSeq_id& value);
    TSeq_id& SetSeq_id(void);

    /// this Seq-id is replaced by sequence in another blob
    /// optional
    ///  Check whether the Replaced data member has been assigned a value.
    bool IsSetReplaced(void) const;
    /// Check whether it is safe or not to call GetReplaced method.
    bool CanGetReplaced(void) const;
    void ResetReplaced(void);
    void SetReplaced(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2_Blob_Seq_id_Base(const CID2_Blob_Seq_id_Base&);
    CID2_Blob_Seq_id_Base& operator=(const CID2_Blob_Seq_id_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TSeq_id > m_Seq_id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID2_Blob_Seq_id_Base::IsSetSeq_id(void) const
{
    return m_Seq_id.NotEmpty();
}

inline
bool CID2_Blob_Seq_id_Base::CanGetSeq_id(void) const
{
    return true;
}

inline
const CID2_Blob_Seq_id_Base::TSeq_id& CID2_Blob_Seq_id_Base::GetSeq_id(void) const
{
    if ( !m_Seq_id ) {
        const_cast<CID2_Blob_Seq_id_Base*>(this)->ResetSeq_id();
    }
    return (*m_Seq_id);
}

inline
CID2_Blob_Seq_id_Base::TSeq_id& CID2_Blob_Seq_id_Base::SetSeq_id(void)
{
    if ( !m_Seq_id ) {
        ResetSeq_id();
    }
    return (*m_Seq_id);
}

inline
bool CID2_Blob_Seq_id_Base::IsSetReplaced(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CID2_Blob_Seq_id_Base::CanGetReplaced(void) const
{
    return false;
}

inline
void CID2_Blob_Seq_id_Base::ResetReplaced(void)
{
    m_set_State[0] &= ~0xc;
}

inline
void CID2_Blob_Seq_id_Base::SetReplaced(void)
{
    m_set_State[0] |= 0xc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID2_ID2_BLOB_SEQ_ID_BASE_HPP
