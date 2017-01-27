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

/// @file TMgr_TrackAttrValueRequest_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TRACKMGR_TMGR_TRACKATTRVALUEREQUEST_BASE_HPP
#define OBJECTS_TRACKMGR_TMGR_TRACKATTRVALUEREQUEST_BASE_HPP

// extra headers
#include <objects/trackmgr/trackmgr_export.h>

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CTMgr_AttrRequest;
class CTMgr_ValueRequest;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TRACKMGR_EXPORT CTMgr_TrackAttrValueRequest_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTMgr_TrackAttrValueRequest_Base(void);
    // destructor
    virtual ~CTMgr_TrackAttrValueRequest_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CTMgr_AttrRequest TAttr_list;
    typedef CTMgr_ValueRequest TValue_list;

    // getters
    // setters

    /// request all track type names
    /// optional
    ///  Check whether the Track_type_list data member has been assigned a value.
    bool IsSetTrack_type_list(void) const;
    /// Check whether it is safe or not to call GetTrack_type_list method.
    bool CanGetTrack_type_list(void) const;
    void ResetTrack_type_list(void);
    void SetTrack_type_list(void);

    /// request attributes associated
    /// with all or some track types
    /// optional
    /// typedef CTMgr_AttrRequest TAttr_list
    ///  Check whether the Attr_list data member has been assigned a value.
    bool IsSetAttr_list(void) const;
    /// Check whether it is safe or not to call GetAttr_list method.
    bool CanGetAttr_list(void) const;
    void ResetAttr_list(void);
    const TAttr_list& GetAttr_list(void) const;
    void SetAttr_list(TAttr_list& value);
    TAttr_list& SetAttr_list(void);

    /// request values associated with
    /// attribute list
    /// optional
    /// typedef CTMgr_ValueRequest TValue_list
    ///  Check whether the Value_list data member has been assigned a value.
    bool IsSetValue_list(void) const;
    /// Check whether it is safe or not to call GetValue_list method.
    bool CanGetValue_list(void) const;
    void ResetValue_list(void);
    const TValue_list& GetValue_list(void) const;
    void SetValue_list(TValue_list& value);
    TValue_list& SetValue_list(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTMgr_TrackAttrValueRequest_Base(const CTMgr_TrackAttrValueRequest_Base&);
    CTMgr_TrackAttrValueRequest_Base& operator=(const CTMgr_TrackAttrValueRequest_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttr_list > m_Attr_list;
    CRef< TValue_list > m_Value_list;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTMgr_TrackAttrValueRequest_Base::IsSetTrack_type_list(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTMgr_TrackAttrValueRequest_Base::CanGetTrack_type_list(void) const
{
    return false;
}

inline
void CTMgr_TrackAttrValueRequest_Base::ResetTrack_type_list(void)
{
    m_set_State[0] &= ~0x3;
}

inline
void CTMgr_TrackAttrValueRequest_Base::SetTrack_type_list(void)
{
    m_set_State[0] |= 0x3;
}

inline
bool CTMgr_TrackAttrValueRequest_Base::IsSetAttr_list(void) const
{
    return m_Attr_list.NotEmpty();
}

inline
bool CTMgr_TrackAttrValueRequest_Base::CanGetAttr_list(void) const
{
    return IsSetAttr_list();
}

inline
const CTMgr_TrackAttrValueRequest_Base::TAttr_list& CTMgr_TrackAttrValueRequest_Base::GetAttr_list(void) const
{
    if (!CanGetAttr_list()) {
        ThrowUnassigned(1);
    }
    return (*m_Attr_list);
}

inline
bool CTMgr_TrackAttrValueRequest_Base::IsSetValue_list(void) const
{
    return m_Value_list.NotEmpty();
}

inline
bool CTMgr_TrackAttrValueRequest_Base::CanGetValue_list(void) const
{
    return IsSetValue_list();
}

inline
const CTMgr_TrackAttrValueRequest_Base::TValue_list& CTMgr_TrackAttrValueRequest_Base::GetValue_list(void) const
{
    if (!CanGetValue_list()) {
        ThrowUnassigned(2);
    }
    return (*m_Value_list);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_TRACKATTRVALUEREQUEST_BASE_HPP
