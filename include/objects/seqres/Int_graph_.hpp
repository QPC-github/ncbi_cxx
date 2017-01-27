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

/// @file Int_graph_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqres.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQRES_INT_GRAPH_BASE_HPP
#define OBJECTS_SEQRES_INT_GRAPH_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQRES_EXPORT CInt_graph_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CInt_graph_Base(void);
    // destructor
    virtual ~CInt_graph_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TMax;
    typedef int TMin;
    typedef int TAxis;
    typedef vector< int > TValues;

    // getters
    // setters

    /// mandatory
    /// typedef int TMax
    ///  Check whether the Max data member has been assigned a value.
    bool IsSetMax(void) const;
    /// Check whether it is safe or not to call GetMax method.
    bool CanGetMax(void) const;
    void ResetMax(void);
    TMax GetMax(void) const;
    void SetMax(TMax value);
    TMax& SetMax(void);

    /// mandatory
    /// typedef int TMin
    ///  Check whether the Min data member has been assigned a value.
    bool IsSetMin(void) const;
    /// Check whether it is safe or not to call GetMin method.
    bool CanGetMin(void) const;
    void ResetMin(void);
    TMin GetMin(void) const;
    void SetMin(TMin value);
    TMin& SetMin(void);

    /// mandatory
    /// typedef int TAxis
    ///  Check whether the Axis data member has been assigned a value.
    bool IsSetAxis(void) const;
    /// Check whether it is safe or not to call GetAxis method.
    bool CanGetAxis(void) const;
    void ResetAxis(void);
    TAxis GetAxis(void) const;
    void SetAxis(TAxis value);
    TAxis& SetAxis(void);

    /// mandatory
    /// typedef vector< int > TValues
    ///  Check whether the Values data member has been assigned a value.
    bool IsSetValues(void) const;
    /// Check whether it is safe or not to call GetValues method.
    bool CanGetValues(void) const;
    void ResetValues(void);
    const TValues& GetValues(void) const;
    TValues& SetValues(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CInt_graph_Base(const CInt_graph_Base&);
    CInt_graph_Base& operator=(const CInt_graph_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Max;
    int m_Min;
    int m_Axis;
    vector< int > m_Values;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CInt_graph_Base::IsSetMax(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CInt_graph_Base::CanGetMax(void) const
{
    return IsSetMax();
}

inline
void CInt_graph_Base::ResetMax(void)
{
    m_Max = 0;
    m_set_State[0] &= ~0x3;
}

inline
CInt_graph_Base::TMax CInt_graph_Base::GetMax(void) const
{
    if (!CanGetMax()) {
        ThrowUnassigned(0);
    }
    return m_Max;
}

inline
void CInt_graph_Base::SetMax(CInt_graph_Base::TMax value)
{
    m_Max = value;
    m_set_State[0] |= 0x3;
}

inline
CInt_graph_Base::TMax& CInt_graph_Base::SetMax(void)
{
#ifdef _DEBUG
    if (!IsSetMax()) {
        memset(&m_Max,UnassignedByte(),sizeof(m_Max));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Max;
}

inline
bool CInt_graph_Base::IsSetMin(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CInt_graph_Base::CanGetMin(void) const
{
    return IsSetMin();
}

inline
void CInt_graph_Base::ResetMin(void)
{
    m_Min = 0;
    m_set_State[0] &= ~0xc;
}

inline
CInt_graph_Base::TMin CInt_graph_Base::GetMin(void) const
{
    if (!CanGetMin()) {
        ThrowUnassigned(1);
    }
    return m_Min;
}

inline
void CInt_graph_Base::SetMin(CInt_graph_Base::TMin value)
{
    m_Min = value;
    m_set_State[0] |= 0xc;
}

inline
CInt_graph_Base::TMin& CInt_graph_Base::SetMin(void)
{
#ifdef _DEBUG
    if (!IsSetMin()) {
        memset(&m_Min,UnassignedByte(),sizeof(m_Min));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Min;
}

inline
bool CInt_graph_Base::IsSetAxis(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CInt_graph_Base::CanGetAxis(void) const
{
    return IsSetAxis();
}

inline
void CInt_graph_Base::ResetAxis(void)
{
    m_Axis = 0;
    m_set_State[0] &= ~0x30;
}

inline
CInt_graph_Base::TAxis CInt_graph_Base::GetAxis(void) const
{
    if (!CanGetAxis()) {
        ThrowUnassigned(2);
    }
    return m_Axis;
}

inline
void CInt_graph_Base::SetAxis(CInt_graph_Base::TAxis value)
{
    m_Axis = value;
    m_set_State[0] |= 0x30;
}

inline
CInt_graph_Base::TAxis& CInt_graph_Base::SetAxis(void)
{
#ifdef _DEBUG
    if (!IsSetAxis()) {
        memset(&m_Axis,UnassignedByte(),sizeof(m_Axis));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Axis;
}

inline
bool CInt_graph_Base::IsSetValues(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CInt_graph_Base::CanGetValues(void) const
{
    return true;
}

inline
const CInt_graph_Base::TValues& CInt_graph_Base::GetValues(void) const
{
    return m_Values;
}

inline
CInt_graph_Base::TValues& CInt_graph_Base::SetValues(void)
{
    m_set_State[0] |= 0x40;
    return m_Values;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQRES_INT_GRAPH_BASE_HPP
