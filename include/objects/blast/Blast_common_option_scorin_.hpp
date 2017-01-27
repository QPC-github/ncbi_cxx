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

/// @file Blast_common_option_scorin_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'blast.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BLAST_BLAST_COMMON_OPTION_SCORIN_BASE_HPP
#define OBJECTS_BLAST_BLAST_COMMON_OPTION_SCORIN_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_BLAST_EXPORT CBlast4_common_options_scoring_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBlast4_common_options_scoring_Base(void);
    // destructor
    virtual ~CBlast4_common_options_scoring_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TMatrix_name;
    typedef int TGap_opening_penalty;
    typedef int TGap_extension_penalty;
    typedef int TMatch_reward;
    typedef int TMismatch_penalty;

    // getters
    // setters

    /// e.g.: BLOSUM62, PAM30, etc
    /// optional
    /// typedef string TMatrix_name
    ///  Check whether the Matrix_name data member has been assigned a value.
    bool IsSetMatrix_name(void) const;
    /// Check whether it is safe or not to call GetMatrix_name method.
    bool CanGetMatrix_name(void) const;
    void ResetMatrix_name(void);
    const TMatrix_name& GetMatrix_name(void) const;
    void SetMatrix_name(const TMatrix_name& value);
    TMatrix_name& SetMatrix_name(void);

    /// optional
    /// typedef int TGap_opening_penalty
    ///  Check whether the Gap_opening_penalty data member has been assigned a value.
    bool IsSetGap_opening_penalty(void) const;
    /// Check whether it is safe or not to call GetGap_opening_penalty method.
    bool CanGetGap_opening_penalty(void) const;
    void ResetGap_opening_penalty(void);
    TGap_opening_penalty GetGap_opening_penalty(void) const;
    void SetGap_opening_penalty(TGap_opening_penalty value);
    TGap_opening_penalty& SetGap_opening_penalty(void);

    /// optional
    /// typedef int TGap_extension_penalty
    ///  Check whether the Gap_extension_penalty data member has been assigned a value.
    bool IsSetGap_extension_penalty(void) const;
    /// Check whether it is safe or not to call GetGap_extension_penalty method.
    bool CanGetGap_extension_penalty(void) const;
    void ResetGap_extension_penalty(void);
    TGap_extension_penalty GetGap_extension_penalty(void) const;
    void SetGap_extension_penalty(TGap_extension_penalty value);
    TGap_extension_penalty& SetGap_extension_penalty(void);

    /// optional
    /// typedef int TMatch_reward
    ///  Check whether the Match_reward data member has been assigned a value.
    bool IsSetMatch_reward(void) const;
    /// Check whether it is safe or not to call GetMatch_reward method.
    bool CanGetMatch_reward(void) const;
    void ResetMatch_reward(void);
    TMatch_reward GetMatch_reward(void) const;
    void SetMatch_reward(TMatch_reward value);
    TMatch_reward& SetMatch_reward(void);

    /// optional
    /// typedef int TMismatch_penalty
    ///  Check whether the Mismatch_penalty data member has been assigned a value.
    bool IsSetMismatch_penalty(void) const;
    /// Check whether it is safe or not to call GetMismatch_penalty method.
    bool CanGetMismatch_penalty(void) const;
    void ResetMismatch_penalty(void);
    TMismatch_penalty GetMismatch_penalty(void) const;
    void SetMismatch_penalty(TMismatch_penalty value);
    TMismatch_penalty& SetMismatch_penalty(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBlast4_common_options_scoring_Base(const CBlast4_common_options_scoring_Base&);
    CBlast4_common_options_scoring_Base& operator=(const CBlast4_common_options_scoring_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Matrix_name;
    int m_Gap_opening_penalty;
    int m_Gap_extension_penalty;
    int m_Match_reward;
    int m_Mismatch_penalty;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBlast4_common_options_scoring_Base::IsSetMatrix_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBlast4_common_options_scoring_Base::CanGetMatrix_name(void) const
{
    return IsSetMatrix_name();
}

inline
const CBlast4_common_options_scoring_Base::TMatrix_name& CBlast4_common_options_scoring_Base::GetMatrix_name(void) const
{
    if (!CanGetMatrix_name()) {
        ThrowUnassigned(0);
    }
    return m_Matrix_name;
}

inline
void CBlast4_common_options_scoring_Base::SetMatrix_name(const CBlast4_common_options_scoring_Base::TMatrix_name& value)
{
    m_Matrix_name = value;
    m_set_State[0] |= 0x3;
}

inline
CBlast4_common_options_scoring_Base::TMatrix_name& CBlast4_common_options_scoring_Base::SetMatrix_name(void)
{
#ifdef _DEBUG
    if (!IsSetMatrix_name()) {
        m_Matrix_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Matrix_name;
}

inline
bool CBlast4_common_options_scoring_Base::IsSetGap_opening_penalty(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CBlast4_common_options_scoring_Base::CanGetGap_opening_penalty(void) const
{
    return IsSetGap_opening_penalty();
}

inline
void CBlast4_common_options_scoring_Base::ResetGap_opening_penalty(void)
{
    m_Gap_opening_penalty = 0;
    m_set_State[0] &= ~0xc;
}

inline
CBlast4_common_options_scoring_Base::TGap_opening_penalty CBlast4_common_options_scoring_Base::GetGap_opening_penalty(void) const
{
    if (!CanGetGap_opening_penalty()) {
        ThrowUnassigned(1);
    }
    return m_Gap_opening_penalty;
}

inline
void CBlast4_common_options_scoring_Base::SetGap_opening_penalty(CBlast4_common_options_scoring_Base::TGap_opening_penalty value)
{
    m_Gap_opening_penalty = value;
    m_set_State[0] |= 0xc;
}

inline
CBlast4_common_options_scoring_Base::TGap_opening_penalty& CBlast4_common_options_scoring_Base::SetGap_opening_penalty(void)
{
#ifdef _DEBUG
    if (!IsSetGap_opening_penalty()) {
        memset(&m_Gap_opening_penalty,UnassignedByte(),sizeof(m_Gap_opening_penalty));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Gap_opening_penalty;
}

inline
bool CBlast4_common_options_scoring_Base::IsSetGap_extension_penalty(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CBlast4_common_options_scoring_Base::CanGetGap_extension_penalty(void) const
{
    return IsSetGap_extension_penalty();
}

inline
void CBlast4_common_options_scoring_Base::ResetGap_extension_penalty(void)
{
    m_Gap_extension_penalty = 0;
    m_set_State[0] &= ~0x30;
}

inline
CBlast4_common_options_scoring_Base::TGap_extension_penalty CBlast4_common_options_scoring_Base::GetGap_extension_penalty(void) const
{
    if (!CanGetGap_extension_penalty()) {
        ThrowUnassigned(2);
    }
    return m_Gap_extension_penalty;
}

inline
void CBlast4_common_options_scoring_Base::SetGap_extension_penalty(CBlast4_common_options_scoring_Base::TGap_extension_penalty value)
{
    m_Gap_extension_penalty = value;
    m_set_State[0] |= 0x30;
}

inline
CBlast4_common_options_scoring_Base::TGap_extension_penalty& CBlast4_common_options_scoring_Base::SetGap_extension_penalty(void)
{
#ifdef _DEBUG
    if (!IsSetGap_extension_penalty()) {
        memset(&m_Gap_extension_penalty,UnassignedByte(),sizeof(m_Gap_extension_penalty));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Gap_extension_penalty;
}

inline
bool CBlast4_common_options_scoring_Base::IsSetMatch_reward(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CBlast4_common_options_scoring_Base::CanGetMatch_reward(void) const
{
    return IsSetMatch_reward();
}

inline
void CBlast4_common_options_scoring_Base::ResetMatch_reward(void)
{
    m_Match_reward = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CBlast4_common_options_scoring_Base::TMatch_reward CBlast4_common_options_scoring_Base::GetMatch_reward(void) const
{
    if (!CanGetMatch_reward()) {
        ThrowUnassigned(3);
    }
    return m_Match_reward;
}

inline
void CBlast4_common_options_scoring_Base::SetMatch_reward(CBlast4_common_options_scoring_Base::TMatch_reward value)
{
    m_Match_reward = value;
    m_set_State[0] |= 0xc0;
}

inline
CBlast4_common_options_scoring_Base::TMatch_reward& CBlast4_common_options_scoring_Base::SetMatch_reward(void)
{
#ifdef _DEBUG
    if (!IsSetMatch_reward()) {
        memset(&m_Match_reward,UnassignedByte(),sizeof(m_Match_reward));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Match_reward;
}

inline
bool CBlast4_common_options_scoring_Base::IsSetMismatch_penalty(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CBlast4_common_options_scoring_Base::CanGetMismatch_penalty(void) const
{
    return IsSetMismatch_penalty();
}

inline
void CBlast4_common_options_scoring_Base::ResetMismatch_penalty(void)
{
    m_Mismatch_penalty = 0;
    m_set_State[0] &= ~0x300;
}

inline
CBlast4_common_options_scoring_Base::TMismatch_penalty CBlast4_common_options_scoring_Base::GetMismatch_penalty(void) const
{
    if (!CanGetMismatch_penalty()) {
        ThrowUnassigned(4);
    }
    return m_Mismatch_penalty;
}

inline
void CBlast4_common_options_scoring_Base::SetMismatch_penalty(CBlast4_common_options_scoring_Base::TMismatch_penalty value)
{
    m_Mismatch_penalty = value;
    m_set_State[0] |= 0x300;
}

inline
CBlast4_common_options_scoring_Base::TMismatch_penalty& CBlast4_common_options_scoring_Base::SetMismatch_penalty(void)
{
#ifdef _DEBUG
    if (!IsSetMismatch_penalty()) {
        memset(&m_Mismatch_penalty,UnassignedByte(),sizeof(m_Mismatch_penalty));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Mismatch_penalty;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLAST_BLAST_COMMON_OPTION_SCORIN_BASE_HPP