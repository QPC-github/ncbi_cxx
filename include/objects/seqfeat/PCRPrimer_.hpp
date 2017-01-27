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

/// @file PCRPrimer_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqfeat.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQFEAT_PCRPRIMER_BASE_HPP
#define OBJECTS_SEQFEAT_PCRPRIMER_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/seqfeat/PCRPrimerName.hpp>
#include <objects/seqfeat/PCRPrimerSeq.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQFEAT_EXPORT CPCRPrimer_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPCRPrimer_Base(void);
    // destructor
    virtual ~CPCRPrimer_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CPCRPrimerSeq TSeq;
    typedef CPCRPrimerName TName;

    // getters
    // setters

    /// optional
    /// typedef CPCRPrimerSeq TSeq
    ///  Check whether the Seq data member has been assigned a value.
    bool IsSetSeq(void) const;
    /// Check whether it is safe or not to call GetSeq method.
    bool CanGetSeq(void) const;
    void ResetSeq(void);
    const TSeq& GetSeq(void) const;
    void SetSeq(const TSeq& value);
    TSeq& SetSeq(void);

    /// optional
    /// typedef CPCRPrimerName TName
    ///  Check whether the Name data member has been assigned a value.
    bool IsSetName(void) const;
    /// Check whether it is safe or not to call GetName method.
    bool CanGetName(void) const;
    void ResetName(void);
    const TName& GetName(void) const;
    void SetName(const TName& value);
    TName& SetName(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPCRPrimer_Base(const CPCRPrimer_Base&);
    CPCRPrimer_Base& operator=(const CPCRPrimer_Base&);

    // data
    Uint4 m_set_State[1];
    CPCRPrimerSeq m_Seq;
    CPCRPrimerName m_Name;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPCRPrimer_Base::IsSetSeq(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPCRPrimer_Base::CanGetSeq(void) const
{
    return IsSetSeq();
}

inline
const CPCRPrimer_Base::TSeq& CPCRPrimer_Base::GetSeq(void) const
{
    if (!CanGetSeq()) {
        ThrowUnassigned(0);
    }
    return m_Seq;
}

inline
void CPCRPrimer_Base::SetSeq(const CPCRPrimer_Base::TSeq& value)
{
    m_Seq = value;
    m_set_State[0] |= 0x3;
}

inline
CPCRPrimer_Base::TSeq& CPCRPrimer_Base::SetSeq(void)
{
    m_set_State[0] |= 0x1;
    return m_Seq;
}

inline
bool CPCRPrimer_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPCRPrimer_Base::CanGetName(void) const
{
    return IsSetName();
}

inline
const CPCRPrimer_Base::TName& CPCRPrimer_Base::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(1);
    }
    return m_Name;
}

inline
void CPCRPrimer_Base::SetName(const CPCRPrimer_Base::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0xc;
}

inline
CPCRPrimer_Base::TName& CPCRPrimer_Base::SetName(void)
{
    m_set_State[0] |= 0x4;
    return m_Name;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQFEAT_PCRPRIMER_BASE_HPP