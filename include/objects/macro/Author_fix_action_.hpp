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

/// @file Author_fix_action_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_AUTHOR_FIX_ACTION_BASE_HPP
#define OBJECTS_MACRO_AUTHOR_FIX_ACTION_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/Author_fix_type.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CConstraint_choice_set;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CAuthor_fix_action_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CAuthor_fix_action_Base(void);
    // destructor
    virtual ~CAuthor_fix_action_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef EAuthor_fix_type TFix_type;
    typedef CConstraint_choice_set TConstraint;

    // getters
    // setters

    /// mandatory
    /// typedef EAuthor_fix_type TFix_type
    ///  Check whether the Fix_type data member has been assigned a value.
    bool IsSetFix_type(void) const;
    /// Check whether it is safe or not to call GetFix_type method.
    bool CanGetFix_type(void) const;
    void ResetFix_type(void);
    TFix_type GetFix_type(void) const;
    void SetFix_type(TFix_type value);
    TFix_type& SetFix_type(void);

    /// optional
    /// typedef CConstraint_choice_set TConstraint
    ///  Check whether the Constraint data member has been assigned a value.
    bool IsSetConstraint(void) const;
    /// Check whether it is safe or not to call GetConstraint method.
    bool CanGetConstraint(void) const;
    void ResetConstraint(void);
    const TConstraint& GetConstraint(void) const;
    void SetConstraint(TConstraint& value);
    TConstraint& SetConstraint(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CAuthor_fix_action_Base(const CAuthor_fix_action_Base&);
    CAuthor_fix_action_Base& operator=(const CAuthor_fix_action_Base&);

    // data
    Uint4 m_set_State[1];
    EAuthor_fix_type m_Fix_type;
    CRef< TConstraint > m_Constraint;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CAuthor_fix_action_Base::IsSetFix_type(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CAuthor_fix_action_Base::CanGetFix_type(void) const
{
    return IsSetFix_type();
}

inline
void CAuthor_fix_action_Base::ResetFix_type(void)
{
    m_Fix_type = (ncbi::objects::EAuthor_fix_type)(0);
    m_set_State[0] &= ~0x3;
}

inline
CAuthor_fix_action_Base::TFix_type CAuthor_fix_action_Base::GetFix_type(void) const
{
    if (!CanGetFix_type()) {
        ThrowUnassigned(0);
    }
    return m_Fix_type;
}

inline
void CAuthor_fix_action_Base::SetFix_type(CAuthor_fix_action_Base::TFix_type value)
{
    m_Fix_type = value;
    m_set_State[0] |= 0x3;
}

inline
CAuthor_fix_action_Base::TFix_type& CAuthor_fix_action_Base::SetFix_type(void)
{
#ifdef _DEBUG
    if (!IsSetFix_type()) {
        memset(&m_Fix_type,UnassignedByte(),sizeof(m_Fix_type));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Fix_type;
}

inline
bool CAuthor_fix_action_Base::IsSetConstraint(void) const
{
    return m_Constraint.NotEmpty();
}

inline
bool CAuthor_fix_action_Base::CanGetConstraint(void) const
{
    return IsSetConstraint();
}

inline
const CAuthor_fix_action_Base::TConstraint& CAuthor_fix_action_Base::GetConstraint(void) const
{
    if (!CanGetConstraint()) {
        ThrowUnassigned(1);
    }
    return (*m_Constraint);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_AUTHOR_FIX_ACTION_BASE_HPP