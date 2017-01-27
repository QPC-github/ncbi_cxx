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

/// @file MSIterativeSettings_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'omssa.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OMSSA_MSITERATIVESETTINGS_BASE_HPP
#define OBJECTS_OMSSA_MSITERATIVESETTINGS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Iterative search settings
class NCBI_OMSSA_EXPORT CMSIterativeSettings_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMSIterativeSettings_Base(void);
    // destructor
    virtual ~CMSIterativeSettings_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef double TResearchthresh;
    typedef double TSubsetthresh;
    typedef double TReplacethresh;

    // getters
    // setters

    /// e-val threshold for re-searching spectra, 0 = always re-search
    /// mandatory
    /// typedef double TResearchthresh
    ///  Check whether the Researchthresh data member has been assigned a value.
    bool IsSetResearchthresh(void) const;
    /// Check whether it is safe or not to call GetResearchthresh method.
    bool CanGetResearchthresh(void) const;
    void ResetResearchthresh(void);
    TResearchthresh GetResearchthresh(void) const;
    void SetResearchthresh(TResearchthresh value);
    TResearchthresh& SetResearchthresh(void);

    /// e-val threshold for picking sequence subset, 0 = all sequences
    /// mandatory
    /// typedef double TSubsetthresh
    ///  Check whether the Subsetthresh data member has been assigned a value.
    bool IsSetSubsetthresh(void) const;
    /// Check whether it is safe or not to call GetSubsetthresh method.
    bool CanGetSubsetthresh(void) const;
    void ResetSubsetthresh(void);
    TSubsetthresh GetSubsetthresh(void) const;
    void SetSubsetthresh(TSubsetthresh value);
    TSubsetthresh& SetSubsetthresh(void);

    /// e-val threshold for replacing hitset, 0 = only if better
    /// mandatory
    /// typedef double TReplacethresh
    ///  Check whether the Replacethresh data member has been assigned a value.
    bool IsSetReplacethresh(void) const;
    /// Check whether it is safe or not to call GetReplacethresh method.
    bool CanGetReplacethresh(void) const;
    void ResetReplacethresh(void);
    TReplacethresh GetReplacethresh(void) const;
    void SetReplacethresh(TReplacethresh value);
    TReplacethresh& SetReplacethresh(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMSIterativeSettings_Base(const CMSIterativeSettings_Base&);
    CMSIterativeSettings_Base& operator=(const CMSIterativeSettings_Base&);

    // data
    Uint4 m_set_State[1];
    double m_Researchthresh;
    double m_Subsetthresh;
    double m_Replacethresh;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMSIterativeSettings_Base::IsSetResearchthresh(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMSIterativeSettings_Base::CanGetResearchthresh(void) const
{
    return IsSetResearchthresh();
}

inline
void CMSIterativeSettings_Base::ResetResearchthresh(void)
{
    m_Researchthresh = 0;
    m_set_State[0] &= ~0x3;
}

inline
CMSIterativeSettings_Base::TResearchthresh CMSIterativeSettings_Base::GetResearchthresh(void) const
{
    if (!CanGetResearchthresh()) {
        ThrowUnassigned(0);
    }
    return m_Researchthresh;
}

inline
void CMSIterativeSettings_Base::SetResearchthresh(CMSIterativeSettings_Base::TResearchthresh value)
{
    m_Researchthresh = value;
    m_set_State[0] |= 0x3;
}

inline
CMSIterativeSettings_Base::TResearchthresh& CMSIterativeSettings_Base::SetResearchthresh(void)
{
#ifdef _DEBUG
    if (!IsSetResearchthresh()) {
        memset(&m_Researchthresh,UnassignedByte(),sizeof(m_Researchthresh));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Researchthresh;
}

inline
bool CMSIterativeSettings_Base::IsSetSubsetthresh(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CMSIterativeSettings_Base::CanGetSubsetthresh(void) const
{
    return IsSetSubsetthresh();
}

inline
void CMSIterativeSettings_Base::ResetSubsetthresh(void)
{
    m_Subsetthresh = 0;
    m_set_State[0] &= ~0xc;
}

inline
CMSIterativeSettings_Base::TSubsetthresh CMSIterativeSettings_Base::GetSubsetthresh(void) const
{
    if (!CanGetSubsetthresh()) {
        ThrowUnassigned(1);
    }
    return m_Subsetthresh;
}

inline
void CMSIterativeSettings_Base::SetSubsetthresh(CMSIterativeSettings_Base::TSubsetthresh value)
{
    m_Subsetthresh = value;
    m_set_State[0] |= 0xc;
}

inline
CMSIterativeSettings_Base::TSubsetthresh& CMSIterativeSettings_Base::SetSubsetthresh(void)
{
#ifdef _DEBUG
    if (!IsSetSubsetthresh()) {
        memset(&m_Subsetthresh,UnassignedByte(),sizeof(m_Subsetthresh));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Subsetthresh;
}

inline
bool CMSIterativeSettings_Base::IsSetReplacethresh(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CMSIterativeSettings_Base::CanGetReplacethresh(void) const
{
    return IsSetReplacethresh();
}

inline
void CMSIterativeSettings_Base::ResetReplacethresh(void)
{
    m_Replacethresh = 0;
    m_set_State[0] &= ~0x30;
}

inline
CMSIterativeSettings_Base::TReplacethresh CMSIterativeSettings_Base::GetReplacethresh(void) const
{
    if (!CanGetReplacethresh()) {
        ThrowUnassigned(2);
    }
    return m_Replacethresh;
}

inline
void CMSIterativeSettings_Base::SetReplacethresh(CMSIterativeSettings_Base::TReplacethresh value)
{
    m_Replacethresh = value;
    m_set_State[0] |= 0x30;
}

inline
CMSIterativeSettings_Base::TReplacethresh& CMSIterativeSettings_Base::SetReplacethresh(void)
{
#ifdef _DEBUG
    if (!IsSetReplacethresh()) {
        memset(&m_Replacethresh,UnassignedByte(),sizeof(m_Replacethresh));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Replacethresh;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OMSSA_MSITERATIVESETTINGS_BASE_HPP