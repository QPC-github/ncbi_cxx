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

/// @file Cdd_Project_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'cdd.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_CDD_CDD_PROJECT_BASE_HPP
#define OBJECTS_CDD_CDD_PROJECT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CCdd;
class CCdd_Script;
class CCdd_Viewer;
class CCdd_id_set;
class CDate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// cd colors are as:  0000FF for red, 00FF00 for green, FF0000 for blue
class NCBI_CDD_EXPORT CCdd_Project_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCdd_Project_Base(void);
    // destructor
    virtual ~CCdd_Project_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CCdd > > TCds;
    typedef list< int > TCdcolor;
    typedef list< CRef< CCdd_Viewer > > TViewers;
    typedef string TLog;
    typedef list< CRef< CCdd_Script > > TScripts;
    typedef CCdd_id_set TId;
    typedef list< string > TRids;
    typedef CDate TCreate_date;
    typedef CDate TUpdate_date;
    typedef int TProject_id;

    // getters
    // setters

    /// cds
    /// mandatory
    /// typedef list< CRef< CCdd > > TCds
    ///  Check whether the Cds data member has been assigned a value.
    bool IsSetCds(void) const;
    /// Check whether it is safe or not to call GetCds method.
    bool CanGetCds(void) const;
    void ResetCds(void);
    const TCds& GetCds(void) const;
    TCds& SetCds(void);

    /// colors  
    /// mandatory
    /// typedef list< int > TCdcolor
    ///  Check whether the Cdcolor data member has been assigned a value.
    bool IsSetCdcolor(void) const;
    /// Check whether it is safe or not to call GetCdcolor method.
    bool CanGetCdcolor(void) const;
    void ResetCdcolor(void);
    const TCdcolor& GetCdcolor(void) const;
    TCdcolor& SetCdcolor(void);

    /// Sequence viewers
    /// mandatory
    /// typedef list< CRef< CCdd_Viewer > > TViewers
    ///  Check whether the Viewers data member has been assigned a value.
    bool IsSetViewers(void) const;
    /// Check whether it is safe or not to call GetViewers method.
    bool CanGetViewers(void) const;
    void ResetViewers(void);
    const TViewers& GetViewers(void) const;
    TViewers& SetViewers(void);

    /// log
    /// mandatory
    /// typedef string TLog
    ///  Check whether the Log data member has been assigned a value.
    bool IsSetLog(void) const;
    /// Check whether it is safe or not to call GetLog method.
    bool CanGetLog(void) const;
    void ResetLog(void);
    const TLog& GetLog(void) const;
    void SetLog(const TLog& value);
    TLog& SetLog(void);

    /// command scripts
    /// optional
    /// typedef list< CRef< CCdd_Script > > TScripts
    ///  Check whether the Scripts data member has been assigned a value.
    bool IsSetScripts(void) const;
    /// Check whether it is safe or not to call GetScripts method.
    bool CanGetScripts(void) const;
    void ResetScripts(void);
    const TScripts& GetScripts(void) const;
    TScripts& SetScripts(void);

    /// to assign unique project id
    /// optional
    /// typedef CCdd_id_set TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    void SetId(TId& value);
    TId& SetId(void);

    /// to store request IDs for batch CD-Searches
    /// optional
    /// typedef list< string > TRids
    ///  Check whether the Rids data member has been assigned a value.
    bool IsSetRids(void) const;
    /// Check whether it is safe or not to call GetRids method.
    bool CanGetRids(void) const;
    void ResetRids(void);
    const TRids& GetRids(void) const;
    TRids& SetRids(void);

    /// optional
    /// typedef CDate TCreate_date
    ///  Check whether the Create_date data member has been assigned a value.
    bool IsSetCreate_date(void) const;
    /// Check whether it is safe or not to call GetCreate_date method.
    bool CanGetCreate_date(void) const;
    void ResetCreate_date(void);
    const TCreate_date& GetCreate_date(void) const;
    void SetCreate_date(TCreate_date& value);
    TCreate_date& SetCreate_date(void);

    /// optional
    /// typedef CDate TUpdate_date
    ///  Check whether the Update_date data member has been assigned a value.
    bool IsSetUpdate_date(void) const;
    /// Check whether it is safe or not to call GetUpdate_date method.
    bool CanGetUpdate_date(void) const;
    void ResetUpdate_date(void);
    const TUpdate_date& GetUpdate_date(void) const;
    void SetUpdate_date(TUpdate_date& value);
    TUpdate_date& SetUpdate_date(void);

    /// for temporary tracking in the database
    /// optional
    /// typedef int TProject_id
    ///  Check whether the Project_id data member has been assigned a value.
    bool IsSetProject_id(void) const;
    /// Check whether it is safe or not to call GetProject_id method.
    bool CanGetProject_id(void) const;
    void ResetProject_id(void);
    TProject_id GetProject_id(void) const;
    void SetProject_id(TProject_id value);
    TProject_id& SetProject_id(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCdd_Project_Base(const CCdd_Project_Base&);
    CCdd_Project_Base& operator=(const CCdd_Project_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CCdd > > m_Cds;
    list< int > m_Cdcolor;
    list< CRef< CCdd_Viewer > > m_Viewers;
    string m_Log;
    list< CRef< CCdd_Script > > m_Scripts;
    CRef< TId > m_Id;
    list< string > m_Rids;
    CRef< TCreate_date > m_Create_date;
    CRef< TUpdate_date > m_Update_date;
    int m_Project_id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCdd_Project_Base::IsSetCds(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CCdd_Project_Base::CanGetCds(void) const
{
    return true;
}

inline
const CCdd_Project_Base::TCds& CCdd_Project_Base::GetCds(void) const
{
    return m_Cds;
}

inline
CCdd_Project_Base::TCds& CCdd_Project_Base::SetCds(void)
{
    m_set_State[0] |= 0x1;
    return m_Cds;
}

inline
bool CCdd_Project_Base::IsSetCdcolor(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCdd_Project_Base::CanGetCdcolor(void) const
{
    return true;
}

inline
const CCdd_Project_Base::TCdcolor& CCdd_Project_Base::GetCdcolor(void) const
{
    return m_Cdcolor;
}

inline
CCdd_Project_Base::TCdcolor& CCdd_Project_Base::SetCdcolor(void)
{
    m_set_State[0] |= 0x4;
    return m_Cdcolor;
}

inline
bool CCdd_Project_Base::IsSetViewers(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CCdd_Project_Base::CanGetViewers(void) const
{
    return true;
}

inline
const CCdd_Project_Base::TViewers& CCdd_Project_Base::GetViewers(void) const
{
    return m_Viewers;
}

inline
CCdd_Project_Base::TViewers& CCdd_Project_Base::SetViewers(void)
{
    m_set_State[0] |= 0x10;
    return m_Viewers;
}

inline
bool CCdd_Project_Base::IsSetLog(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CCdd_Project_Base::CanGetLog(void) const
{
    return IsSetLog();
}

inline
const CCdd_Project_Base::TLog& CCdd_Project_Base::GetLog(void) const
{
    if (!CanGetLog()) {
        ThrowUnassigned(3);
    }
    return m_Log;
}

inline
void CCdd_Project_Base::SetLog(const CCdd_Project_Base::TLog& value)
{
    m_Log = value;
    m_set_State[0] |= 0xc0;
}

inline
CCdd_Project_Base::TLog& CCdd_Project_Base::SetLog(void)
{
#ifdef _DEBUG
    if (!IsSetLog()) {
        m_Log = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Log;
}

inline
bool CCdd_Project_Base::IsSetScripts(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CCdd_Project_Base::CanGetScripts(void) const
{
    return true;
}

inline
const CCdd_Project_Base::TScripts& CCdd_Project_Base::GetScripts(void) const
{
    return m_Scripts;
}

inline
CCdd_Project_Base::TScripts& CCdd_Project_Base::SetScripts(void)
{
    m_set_State[0] |= 0x100;
    return m_Scripts;
}

inline
bool CCdd_Project_Base::IsSetId(void) const
{
    return m_Id.NotEmpty();
}

inline
bool CCdd_Project_Base::CanGetId(void) const
{
    return IsSetId();
}

inline
const CCdd_Project_Base::TId& CCdd_Project_Base::GetId(void) const
{
    if (!CanGetId()) {
        ThrowUnassigned(5);
    }
    return (*m_Id);
}

inline
bool CCdd_Project_Base::IsSetRids(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CCdd_Project_Base::CanGetRids(void) const
{
    return true;
}

inline
const CCdd_Project_Base::TRids& CCdd_Project_Base::GetRids(void) const
{
    return m_Rids;
}

inline
CCdd_Project_Base::TRids& CCdd_Project_Base::SetRids(void)
{
    m_set_State[0] |= 0x1000;
    return m_Rids;
}

inline
bool CCdd_Project_Base::IsSetCreate_date(void) const
{
    return m_Create_date.NotEmpty();
}

inline
bool CCdd_Project_Base::CanGetCreate_date(void) const
{
    return IsSetCreate_date();
}

inline
const CCdd_Project_Base::TCreate_date& CCdd_Project_Base::GetCreate_date(void) const
{
    if (!CanGetCreate_date()) {
        ThrowUnassigned(7);
    }
    return (*m_Create_date);
}

inline
bool CCdd_Project_Base::IsSetUpdate_date(void) const
{
    return m_Update_date.NotEmpty();
}

inline
bool CCdd_Project_Base::CanGetUpdate_date(void) const
{
    return IsSetUpdate_date();
}

inline
const CCdd_Project_Base::TUpdate_date& CCdd_Project_Base::GetUpdate_date(void) const
{
    if (!CanGetUpdate_date()) {
        ThrowUnassigned(8);
    }
    return (*m_Update_date);
}

inline
bool CCdd_Project_Base::IsSetProject_id(void) const
{
    return ((m_set_State[0] & 0xc0000) != 0);
}

inline
bool CCdd_Project_Base::CanGetProject_id(void) const
{
    return IsSetProject_id();
}

inline
void CCdd_Project_Base::ResetProject_id(void)
{
    m_Project_id = 0;
    m_set_State[0] &= ~0xc0000;
}

inline
CCdd_Project_Base::TProject_id CCdd_Project_Base::GetProject_id(void) const
{
    if (!CanGetProject_id()) {
        ThrowUnassigned(9);
    }
    return m_Project_id;
}

inline
void CCdd_Project_Base::SetProject_id(CCdd_Project_Base::TProject_id value)
{
    m_Project_id = value;
    m_set_State[0] |= 0xc0000;
}

inline
CCdd_Project_Base::TProject_id& CCdd_Project_Base::SetProject_id(void)
{
#ifdef _DEBUG
    if (!IsSetProject_id()) {
        memset(&m_Project_id,UnassignedByte(),sizeof(m_Project_id));
    }
#endif
    m_set_State[0] |= 0x40000;
    return m_Project_id;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_CDD_CDD_PROJECT_BASE_HPP
