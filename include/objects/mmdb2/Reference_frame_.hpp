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

/// @file Reference_frame_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB2_REFERENCE_FRAME_BASE_HPP
#define OBJECTS_MMDB2_REFERENCE_FRAME_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CBiostruc_id;
class CTransform;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// An external reference frame is a pointer to another biostruc, with an 
/// optional operator to rotate and translate coordinates into its model space.
/// This item is intended for representation of homology-derived model 
/// structures, and is not present for structures from PDB.
class NCBI_MMDB2_EXPORT CReference_frame_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CReference_frame_Base(void);
    // destructor
    virtual ~CReference_frame_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CBiostruc_id TBiostruc_id;
    typedef CTransform TRotation_translation;

    // getters
    // setters

    /// mandatory
    /// typedef CBiostruc_id TBiostruc_id
    ///  Check whether the Biostruc_id data member has been assigned a value.
    bool IsSetBiostruc_id(void) const;
    /// Check whether it is safe or not to call GetBiostruc_id method.
    bool CanGetBiostruc_id(void) const;
    void ResetBiostruc_id(void);
    const TBiostruc_id& GetBiostruc_id(void) const;
    void SetBiostruc_id(TBiostruc_id& value);
    TBiostruc_id& SetBiostruc_id(void);

    /// optional
    /// typedef CTransform TRotation_translation
    ///  Check whether the Rotation_translation data member has been assigned a value.
    bool IsSetRotation_translation(void) const;
    /// Check whether it is safe or not to call GetRotation_translation method.
    bool CanGetRotation_translation(void) const;
    void ResetRotation_translation(void);
    const TRotation_translation& GetRotation_translation(void) const;
    void SetRotation_translation(TRotation_translation& value);
    TRotation_translation& SetRotation_translation(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CReference_frame_Base(const CReference_frame_Base&);
    CReference_frame_Base& operator=(const CReference_frame_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TBiostruc_id > m_Biostruc_id;
    CRef< TRotation_translation > m_Rotation_translation;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CReference_frame_Base::IsSetBiostruc_id(void) const
{
    return m_Biostruc_id.NotEmpty();
}

inline
bool CReference_frame_Base::CanGetBiostruc_id(void) const
{
    return true;
}

inline
const CReference_frame_Base::TBiostruc_id& CReference_frame_Base::GetBiostruc_id(void) const
{
    if ( !m_Biostruc_id ) {
        const_cast<CReference_frame_Base*>(this)->ResetBiostruc_id();
    }
    return (*m_Biostruc_id);
}

inline
CReference_frame_Base::TBiostruc_id& CReference_frame_Base::SetBiostruc_id(void)
{
    if ( !m_Biostruc_id ) {
        ResetBiostruc_id();
    }
    return (*m_Biostruc_id);
}

inline
bool CReference_frame_Base::IsSetRotation_translation(void) const
{
    return m_Rotation_translation.NotEmpty();
}

inline
bool CReference_frame_Base::CanGetRotation_translation(void) const
{
    return IsSetRotation_translation();
}

inline
const CReference_frame_Base::TRotation_translation& CReference_frame_Base::GetRotation_translation(void) const
{
    if (!CanGetRotation_translation()) {
        ThrowUnassigned(1);
    }
    return (*m_Rotation_translation);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB2_REFERENCE_FRAME_BASE_HPP
