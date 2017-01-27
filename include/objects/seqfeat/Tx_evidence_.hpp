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

/// @file Tx_evidence_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqfeat.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQFEAT_TX_EVIDENCE_BASE_HPP
#define OBJECTS_SEQFEAT_TX_EVIDENCE_BASE_HPP

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
class NCBI_SEQFEAT_EXPORT CTx_evidence_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTx_evidence_Base(void);
    // destructor
    virtual ~CTx_evidence_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum EExp_code {
        eExp_code_unknown    =   0,
        eExp_code_rna_seq    =   1,  ///< direct RNA sequencing
        eExp_code_rna_size   =   2,  ///< RNA length measurement
        eExp_code_np_map     =   3,  ///< nuclease protection mapping with homologous sequence ladder
        eExp_code_np_size    =   4,  ///< nuclease protected fragment length measurement
        eExp_code_pe_seq     =   5,  ///< dideoxy RNA sequencing
        eExp_code_cDNA_seq   =   6,  ///< full-length cDNA sequencing
        eExp_code_pe_map     =   7,  ///< primer extension mapping with homologous sequence ladder
        eExp_code_pe_size    =   8,  ///< primer extension product length measurement
        eExp_code_pseudo_seq =   9,  ///< full-length processed pseudogene sequencing
        eExp_code_rev_pe_map =  10,  ///< see NOTE (1) below
        eExp_code_other      = 255
    };
    
    /// Access to EExp_code's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EExp_code)(void);
    
    enum EExpression_system {
        eExpression_system_unknown       =   0,
        eExpression_system_physiological =   1,
        eExpression_system_in_vitro      =   2,
        eExpression_system_oocyte        =   3,
        eExpression_system_transfection  =   4,
        eExpression_system_transgenic    =   5,
        eExpression_system_other         = 255
    };
    
    /// Access to EExpression_system's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EExpression_system)(void);
    
    // types
    typedef EExp_code TExp_code;
    typedef EExpression_system TExpression_system;
    typedef bool TLow_prec_data;
    typedef bool TFrom_homolog;

    // getters
    // setters

    /// mandatory
    /// typedef EExp_code TExp_code
    ///  Check whether the Exp_code data member has been assigned a value.
    bool IsSetExp_code(void) const;
    /// Check whether it is safe or not to call GetExp_code method.
    bool CanGetExp_code(void) const;
    void ResetExp_code(void);
    TExp_code GetExp_code(void) const;
    void SetExp_code(TExp_code value);
    TExp_code& SetExp_code(void);

    /// optional with default eExpression_system_physiological
    /// typedef EExpression_system TExpression_system
    ///  Check whether the Expression_system data member has been assigned a value.
    bool IsSetExpression_system(void) const;
    /// Check whether it is safe or not to call GetExpression_system method.
    bool CanGetExpression_system(void) const;
    void ResetExpression_system(void);
    void SetDefaultExpression_system(void);
    TExpression_system GetExpression_system(void) const;
    void SetExpression_system(TExpression_system value);
    TExpression_system& SetExpression_system(void);

    /// optional with default false
    /// typedef bool TLow_prec_data
    ///  Check whether the Low_prec_data data member has been assigned a value.
    bool IsSetLow_prec_data(void) const;
    /// Check whether it is safe or not to call GetLow_prec_data method.
    bool CanGetLow_prec_data(void) const;
    void ResetLow_prec_data(void);
    void SetDefaultLow_prec_data(void);
    TLow_prec_data GetLow_prec_data(void) const;
    void SetLow_prec_data(TLow_prec_data value);
    TLow_prec_data& SetLow_prec_data(void);

    /// experiment actually done on
    /// optional with default false
    /// typedef bool TFrom_homolog
    ///  Check whether the From_homolog data member has been assigned a value.
    bool IsSetFrom_homolog(void) const;
    /// Check whether it is safe or not to call GetFrom_homolog method.
    bool CanGetFrom_homolog(void) const;
    void ResetFrom_homolog(void);
    void SetDefaultFrom_homolog(void);
    TFrom_homolog GetFrom_homolog(void) const;
    void SetFrom_homolog(TFrom_homolog value);
    TFrom_homolog& SetFrom_homolog(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTx_evidence_Base(const CTx_evidence_Base&);
    CTx_evidence_Base& operator=(const CTx_evidence_Base&);

    // data
    Uint4 m_set_State[1];
    EExp_code m_Exp_code;
    EExpression_system m_Expression_system;
    bool m_Low_prec_data;
    bool m_From_homolog;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTx_evidence_Base::IsSetExp_code(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTx_evidence_Base::CanGetExp_code(void) const
{
    return IsSetExp_code();
}

inline
void CTx_evidence_Base::ResetExp_code(void)
{
    m_Exp_code = (EExp_code)(0);
    m_set_State[0] &= ~0x3;
}

inline
CTx_evidence_Base::TExp_code CTx_evidence_Base::GetExp_code(void) const
{
    if (!CanGetExp_code()) {
        ThrowUnassigned(0);
    }
    return m_Exp_code;
}

inline
void CTx_evidence_Base::SetExp_code(CTx_evidence_Base::TExp_code value)
{
    m_Exp_code = value;
    m_set_State[0] |= 0x3;
}

inline
CTx_evidence_Base::TExp_code& CTx_evidence_Base::SetExp_code(void)
{
#ifdef _DEBUG
    if (!IsSetExp_code()) {
        memset(&m_Exp_code,UnassignedByte(),sizeof(m_Exp_code));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Exp_code;
}

inline
bool CTx_evidence_Base::IsSetExpression_system(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTx_evidence_Base::CanGetExpression_system(void) const
{
    return true;
}

inline
void CTx_evidence_Base::ResetExpression_system(void)
{
    m_Expression_system = eExpression_system_physiological;
    m_set_State[0] &= ~0xc;
}

inline
void CTx_evidence_Base::SetDefaultExpression_system(void)
{
    ResetExpression_system();
}

inline
CTx_evidence_Base::TExpression_system CTx_evidence_Base::GetExpression_system(void) const
{
    return m_Expression_system;
}

inline
void CTx_evidence_Base::SetExpression_system(CTx_evidence_Base::TExpression_system value)
{
    m_Expression_system = value;
    m_set_State[0] |= 0xc;
}

inline
CTx_evidence_Base::TExpression_system& CTx_evidence_Base::SetExpression_system(void)
{
#ifdef _DEBUG
    if (!IsSetExpression_system()) {
        memset(&m_Expression_system,UnassignedByte(),sizeof(m_Expression_system));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Expression_system;
}

inline
bool CTx_evidence_Base::IsSetLow_prec_data(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CTx_evidence_Base::CanGetLow_prec_data(void) const
{
    return true;
}

inline
void CTx_evidence_Base::ResetLow_prec_data(void)
{
    m_Low_prec_data = false;
    m_set_State[0] &= ~0x30;
}

inline
void CTx_evidence_Base::SetDefaultLow_prec_data(void)
{
    ResetLow_prec_data();
}

inline
CTx_evidence_Base::TLow_prec_data CTx_evidence_Base::GetLow_prec_data(void) const
{
    return m_Low_prec_data;
}

inline
void CTx_evidence_Base::SetLow_prec_data(CTx_evidence_Base::TLow_prec_data value)
{
    m_Low_prec_data = value;
    m_set_State[0] |= 0x30;
}

inline
CTx_evidence_Base::TLow_prec_data& CTx_evidence_Base::SetLow_prec_data(void)
{
#ifdef _DEBUG
    if (!IsSetLow_prec_data()) {
        memset(&m_Low_prec_data,UnassignedByte(),sizeof(m_Low_prec_data));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Low_prec_data;
}

inline
bool CTx_evidence_Base::IsSetFrom_homolog(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CTx_evidence_Base::CanGetFrom_homolog(void) const
{
    return true;
}

inline
void CTx_evidence_Base::ResetFrom_homolog(void)
{
    m_From_homolog = false;
    m_set_State[0] &= ~0xc0;
}

inline
void CTx_evidence_Base::SetDefaultFrom_homolog(void)
{
    ResetFrom_homolog();
}

inline
CTx_evidence_Base::TFrom_homolog CTx_evidence_Base::GetFrom_homolog(void) const
{
    return m_From_homolog;
}

inline
void CTx_evidence_Base::SetFrom_homolog(CTx_evidence_Base::TFrom_homolog value)
{
    m_From_homolog = value;
    m_set_State[0] |= 0xc0;
}

inline
CTx_evidence_Base::TFrom_homolog& CTx_evidence_Base::SetFrom_homolog(void)
{
#ifdef _DEBUG
    if (!IsSetFrom_homolog()) {
        memset(&m_From_homolog,UnassignedByte(),sizeof(m_From_homolog));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_From_homolog;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQFEAT_TX_EVIDENCE_BASE_HPP
