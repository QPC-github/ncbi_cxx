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

/// @file Entrez2_link_info_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZ2_ENTREZ2_LINK_INFO_BASE_HPP
#define OBJECTS_ENTREZ2_ENTREZ2_LINK_INFO_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <objects/entrez2/Entrez2_db_id.hpp>
#include <objects/entrez2/Entrez2_link_id.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// info about one link
class NCBI_ENTREZ2_EXPORT CEntrez2_link_info_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CEntrez2_link_info_Base(void);
    // destructor
    virtual ~CEntrez2_link_info_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CEntrez2_link_id TLink_name;
    typedef string TLink_menu;
    typedef string TLink_descr;
    typedef CEntrez2_db_id TDb_to;
    typedef int TData_size;

    // getters
    // setters

    /// mandatory
    /// typedef CEntrez2_link_id TLink_name
    ///  Check whether the Link_name data member has been assigned a value.
    bool IsSetLink_name(void) const;
    /// Check whether it is safe or not to call GetLink_name method.
    bool CanGetLink_name(void) const;
    void ResetLink_name(void);
    const TLink_name& GetLink_name(void) const;
    void SetLink_name(const TLink_name& value);
    TLink_name& SetLink_name(void);

    /// mandatory
    /// typedef string TLink_menu
    ///  Check whether the Link_menu data member has been assigned a value.
    bool IsSetLink_menu(void) const;
    /// Check whether it is safe or not to call GetLink_menu method.
    bool CanGetLink_menu(void) const;
    void ResetLink_menu(void);
    const TLink_menu& GetLink_menu(void) const;
    void SetLink_menu(const TLink_menu& value);
    TLink_menu& SetLink_menu(void);

    /// mandatory
    /// typedef string TLink_descr
    ///  Check whether the Link_descr data member has been assigned a value.
    bool IsSetLink_descr(void) const;
    /// Check whether it is safe or not to call GetLink_descr method.
    bool CanGetLink_descr(void) const;
    void ResetLink_descr(void);
    const TLink_descr& GetLink_descr(void) const;
    void SetLink_descr(const TLink_descr& value);
    TLink_descr& SetLink_descr(void);

    /// database it links to
    /// mandatory
    /// typedef CEntrez2_db_id TDb_to
    ///  Check whether the Db_to data member has been assigned a value.
    bool IsSetDb_to(void) const;
    /// Check whether it is safe or not to call GetDb_to method.
    bool CanGetDb_to(void) const;
    void ResetDb_to(void);
    const TDb_to& GetDb_to(void) const;
    void SetDb_to(const TDb_to& value);
    TDb_to& SetDb_to(void);

    /// size of link data element    
    /// optional
    /// typedef int TData_size
    ///  Check whether the Data_size data member has been assigned a value.
    bool IsSetData_size(void) const;
    /// Check whether it is safe or not to call GetData_size method.
    bool CanGetData_size(void) const;
    void ResetData_size(void);
    TData_size GetData_size(void) const;
    void SetData_size(TData_size value);
    TData_size& SetData_size(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CEntrez2_link_info_Base(const CEntrez2_link_info_Base&);
    CEntrez2_link_info_Base& operator=(const CEntrez2_link_info_Base&);

    // data
    Uint4 m_set_State[1];
    CEntrez2_link_id m_Link_name;
    string m_Link_menu;
    string m_Link_descr;
    CEntrez2_db_id m_Db_to;
    int m_Data_size;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEntrez2_link_info_Base::IsSetLink_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CEntrez2_link_info_Base::CanGetLink_name(void) const
{
    return IsSetLink_name();
}

inline
const CEntrez2_link_info_Base::TLink_name& CEntrez2_link_info_Base::GetLink_name(void) const
{
    if (!CanGetLink_name()) {
        ThrowUnassigned(0);
    }
    return m_Link_name;
}

inline
void CEntrez2_link_info_Base::SetLink_name(const CEntrez2_link_info_Base::TLink_name& value)
{
    m_Link_name = value;
    m_set_State[0] |= 0x3;
}

inline
CEntrez2_link_info_Base::TLink_name& CEntrez2_link_info_Base::SetLink_name(void)
{
    m_set_State[0] |= 0x1;
    return m_Link_name;
}

inline
bool CEntrez2_link_info_Base::IsSetLink_menu(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEntrez2_link_info_Base::CanGetLink_menu(void) const
{
    return IsSetLink_menu();
}

inline
const CEntrez2_link_info_Base::TLink_menu& CEntrez2_link_info_Base::GetLink_menu(void) const
{
    if (!CanGetLink_menu()) {
        ThrowUnassigned(1);
    }
    return m_Link_menu;
}

inline
void CEntrez2_link_info_Base::SetLink_menu(const CEntrez2_link_info_Base::TLink_menu& value)
{
    m_Link_menu = value;
    m_set_State[0] |= 0xc;
}

inline
CEntrez2_link_info_Base::TLink_menu& CEntrez2_link_info_Base::SetLink_menu(void)
{
#ifdef _DEBUG
    if (!IsSetLink_menu()) {
        m_Link_menu = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Link_menu;
}

inline
bool CEntrez2_link_info_Base::IsSetLink_descr(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CEntrez2_link_info_Base::CanGetLink_descr(void) const
{
    return IsSetLink_descr();
}

inline
const CEntrez2_link_info_Base::TLink_descr& CEntrez2_link_info_Base::GetLink_descr(void) const
{
    if (!CanGetLink_descr()) {
        ThrowUnassigned(2);
    }
    return m_Link_descr;
}

inline
void CEntrez2_link_info_Base::SetLink_descr(const CEntrez2_link_info_Base::TLink_descr& value)
{
    m_Link_descr = value;
    m_set_State[0] |= 0x30;
}

inline
CEntrez2_link_info_Base::TLink_descr& CEntrez2_link_info_Base::SetLink_descr(void)
{
#ifdef _DEBUG
    if (!IsSetLink_descr()) {
        m_Link_descr = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Link_descr;
}

inline
bool CEntrez2_link_info_Base::IsSetDb_to(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CEntrez2_link_info_Base::CanGetDb_to(void) const
{
    return IsSetDb_to();
}

inline
const CEntrez2_link_info_Base::TDb_to& CEntrez2_link_info_Base::GetDb_to(void) const
{
    if (!CanGetDb_to()) {
        ThrowUnassigned(3);
    }
    return m_Db_to;
}

inline
void CEntrez2_link_info_Base::SetDb_to(const CEntrez2_link_info_Base::TDb_to& value)
{
    m_Db_to = value;
    m_set_State[0] |= 0xc0;
}

inline
CEntrez2_link_info_Base::TDb_to& CEntrez2_link_info_Base::SetDb_to(void)
{
    m_set_State[0] |= 0x40;
    return m_Db_to;
}

inline
bool CEntrez2_link_info_Base::IsSetData_size(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CEntrez2_link_info_Base::CanGetData_size(void) const
{
    return IsSetData_size();
}

inline
void CEntrez2_link_info_Base::ResetData_size(void)
{
    m_Data_size = 0;
    m_set_State[0] &= ~0x300;
}

inline
CEntrez2_link_info_Base::TData_size CEntrez2_link_info_Base::GetData_size(void) const
{
    if (!CanGetData_size()) {
        ThrowUnassigned(4);
    }
    return m_Data_size;
}

inline
void CEntrez2_link_info_Base::SetData_size(CEntrez2_link_info_Base::TData_size value)
{
    m_Data_size = value;
    m_set_State[0] |= 0x300;
}

inline
CEntrez2_link_info_Base::TData_size& CEntrez2_link_info_Base::SetData_size(void)
{
#ifdef _DEBUG
    if (!IsSetData_size()) {
        memset(&m_Data_size,UnassignedByte(),sizeof(m_Data_size));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Data_size;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_ENTREZ2_LINK_INFO_BASE_HPP
