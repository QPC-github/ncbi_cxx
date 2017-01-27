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

/// @file CDSGenePr_constraint_field_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_BASE_HPP
#define OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/CDSGeneProt_field.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CCDSGeneProt_constraint_field_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCDSGeneProt_constraint_field_Base(void);
    // destructor
    virtual ~CCDSGeneProt_constraint_field_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,  ///< No variant selected
        e_Field
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 2 ///< == e_Field+1
    };

    /// Reset the whole object
    virtual void Reset(void);

    /// Reset the selection (set it to e_not_set).
    virtual void ResetSelection(void);

    /// Which variant is currently selected.
    E_Choice Which(void) const;

    /// Verify selection, throw exception if it differs from the expected.
    void CheckSelected(E_Choice index) const;

    /// Throw 'InvalidSelection' exception.
    NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;

    /// Retrieve selection name (for diagnostic purposes).
    static string SelectionName(E_Choice index);

    /// Select the requested variant if needed.
    void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
    /// Select the requested variant if needed,
    /// allocating CObject variants from memory pool.
    void Select(E_Choice index,
                EResetVariant reset,
                CObjectMemoryPool* pool);

    // types
    typedef ECDSGeneProt_field TField;

    // getters
    // setters

    // typedef ECDSGeneProt_field TField
    bool IsField(void) const;
    TField GetField(void) const;
    TField& SetField(void);
    void SetField(TField value);


private:
    // copy constructor and assignment operator
    CCDSGeneProt_constraint_field_Base(const CCDSGeneProt_constraint_field_Base& );
    CCDSGeneProt_constraint_field_Base& operator=(const CCDSGeneProt_constraint_field_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        TField m_Field;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CCDSGeneProt_constraint_field_Base::E_Choice CCDSGeneProt_constraint_field_Base::Which(void) const
{
    return m_choice;
}

inline
void CCDSGeneProt_constraint_field_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CCDSGeneProt_constraint_field_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CCDSGeneProt_constraint_field_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CCDSGeneProt_constraint_field_Base::IsField(void) const
{
    return m_choice == e_Field;
}

inline
CCDSGeneProt_constraint_field_Base::TField CCDSGeneProt_constraint_field_Base::GetField(void) const
{
    CheckSelected(e_Field);
    return m_Field;
}

inline
CCDSGeneProt_constraint_field_Base::TField& CCDSGeneProt_constraint_field_Base::SetField(void)
{
    Select(e_Field, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Field;
}

inline
void CCDSGeneProt_constraint_field_Base::SetField(CCDSGeneProt_constraint_field_Base::TField value)
{
    Select(e_Field, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Field = value;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_BASE_HPP
