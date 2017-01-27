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

/// @file Pub_field_special_constrai_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_PUB_FIELD_SPECIAL_CONSTRAI_BASE_HPP
#define OBJECTS_MACRO_PUB_FIELD_SPECIAL_CONSTRAI_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/Publication_field.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CPub_field_special_constraint_type;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CPub_field_special_constraint_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPub_field_special_constraint_Base(void);
    // destructor
    virtual ~CPub_field_special_constraint_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef EPublication_field TField;
    typedef CPub_field_special_constraint_type TConstraint;

    // getters
    // setters

    /// mandatory
    /// typedef EPublication_field TField
    ///  Check whether the Field data member has been assigned a value.
    bool IsSetField(void) const;
    /// Check whether it is safe or not to call GetField method.
    bool CanGetField(void) const;
    void ResetField(void);
    TField GetField(void) const;
    void SetField(TField value);
    TField& SetField(void);

    /// mandatory
    /// typedef CPub_field_special_constraint_type TConstraint
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
    CPub_field_special_constraint_Base(const CPub_field_special_constraint_Base&);
    CPub_field_special_constraint_Base& operator=(const CPub_field_special_constraint_Base&);

    // data
    Uint4 m_set_State[1];
    EPublication_field m_Field;
    CRef< TConstraint > m_Constraint;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPub_field_special_constraint_Base::IsSetField(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPub_field_special_constraint_Base::CanGetField(void) const
{
    return IsSetField();
}

inline
void CPub_field_special_constraint_Base::ResetField(void)
{
    m_Field = (ncbi::objects::EPublication_field)(0);
    m_set_State[0] &= ~0x3;
}

inline
CPub_field_special_constraint_Base::TField CPub_field_special_constraint_Base::GetField(void) const
{
    if (!CanGetField()) {
        ThrowUnassigned(0);
    }
    return m_Field;
}

inline
void CPub_field_special_constraint_Base::SetField(CPub_field_special_constraint_Base::TField value)
{
    m_Field = value;
    m_set_State[0] |= 0x3;
}

inline
CPub_field_special_constraint_Base::TField& CPub_field_special_constraint_Base::SetField(void)
{
#ifdef _DEBUG
    if (!IsSetField()) {
        memset(&m_Field,UnassignedByte(),sizeof(m_Field));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Field;
}

inline
bool CPub_field_special_constraint_Base::IsSetConstraint(void) const
{
    return m_Constraint.NotEmpty();
}

inline
bool CPub_field_special_constraint_Base::CanGetConstraint(void) const
{
    return true;
}

inline
const CPub_field_special_constraint_Base::TConstraint& CPub_field_special_constraint_Base::GetConstraint(void) const
{
    if ( !m_Constraint ) {
        const_cast<CPub_field_special_constraint_Base*>(this)->ResetConstraint();
    }
    return (*m_Constraint);
}

inline
CPub_field_special_constraint_Base::TConstraint& CPub_field_special_constraint_Base::SetConstraint(void)
{
    if ( !m_Constraint ) {
        ResetConstraint();
    }
    return (*m_Constraint);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_PUB_FIELD_SPECIAL_CONSTRAI_BASE_HPP
