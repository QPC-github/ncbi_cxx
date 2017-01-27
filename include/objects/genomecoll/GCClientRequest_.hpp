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

/// @file GCClientRequest_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gencoll_client.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GENOMECOLL_GCCLIENTREQUEST_BASE_HPP
#define OBJECTS_GENOMECOLL_GCCLIENTREQUEST_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CGCClient_GetAssemblyRequest;
class CGCClient_ValidateChrTypeLocRequest;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CGCClientRequest_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGCClientRequest_Base(void);
    // destructor
    virtual ~CGCClientRequest_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,        ///< No variant selected
        e_Get_assembly,
        e_Get_chrtype_valid
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 3 ///< == e_Get_chrtype_valid+1
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
    typedef CGCClient_GetAssemblyRequest TGet_assembly;
    typedef CGCClient_ValidateChrTypeLocRequest TGet_chrtype_valid;

    // getters
    // setters

    // typedef CGCClient_GetAssemblyRequest TGet_assembly
    bool IsGet_assembly(void) const;
    const TGet_assembly& GetGet_assembly(void) const;
    TGet_assembly& SetGet_assembly(void);
    void SetGet_assembly(TGet_assembly& value);

    // typedef CGCClient_ValidateChrTypeLocRequest TGet_chrtype_valid
    bool IsGet_chrtype_valid(void) const;
    const TGet_chrtype_valid& GetGet_chrtype_valid(void) const;
    TGet_chrtype_valid& SetGet_chrtype_valid(void);
    void SetGet_chrtype_valid(TGet_chrtype_valid& value);


private:
    // copy constructor and assignment operator
    CGCClientRequest_Base(const CGCClientRequest_Base& );
    CGCClientRequest_Base& operator=(const CGCClientRequest_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    NCBI_NS_NCBI::CSerialObject *m_object;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CGCClientRequest_Base::E_Choice CGCClientRequest_Base::Which(void) const
{
    return m_choice;
}

inline
void CGCClientRequest_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CGCClientRequest_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CGCClientRequest_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CGCClientRequest_Base::IsGet_assembly(void) const
{
    return m_choice == e_Get_assembly;
}

inline
bool CGCClientRequest_Base::IsGet_chrtype_valid(void) const
{
    return m_choice == e_Get_chrtype_valid;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GENOMECOLL_GCCLIENTREQUEST_BASE_HPP
