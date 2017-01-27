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
 * File Description:
 *   This code was generated by application DATATOOL
 *   using the following specifications:
 *   'mmdb1.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serialimpl.hpp>

// generated includes
#include <objects/mmdb1/Biostruc_id.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/general/Object_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_id_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CBiostruc_id_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Mmdb_id:
        m_Mmdb_id.Destruct();
        break;
    case e_Other_database:
    case e_Local_id:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CBiostruc_id_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Mmdb_id:
        m_Mmdb_id.Construct();
        break;
    case e_Other_database:
        (m_object = new(pool) ncbi::objects::CDbtag())->AddReference();
        break;
    case e_Local_id:
        (m_object = new(pool) ncbi::objects::CObject_id())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CBiostruc_id_Base::sm_SelectionNames[] = {
    "not set",
    "mmdb-id",
    "other-database",
    "local-id"
};

NCBI_NS_STD::string CBiostruc_id_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CBiostruc_id_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CBiostruc_id_Base::SetMmdb_id(const CBiostruc_id_Base::TMmdb_id& value)
{
    Select(e_Mmdb_id, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Mmdb_id = value;
}

const CBiostruc_id_Base::TOther_database& CBiostruc_id_Base::GetOther_database(void) const
{
    CheckSelected(e_Other_database);
    return *static_cast<const TOther_database*>(m_object);
}

CBiostruc_id_Base::TOther_database& CBiostruc_id_Base::SetOther_database(void)
{
    Select(e_Other_database, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TOther_database*>(m_object);
}

void CBiostruc_id_Base::SetOther_database(CBiostruc_id_Base::TOther_database& value)
{
    TOther_database* ptr = &value;
    if ( m_choice != e_Other_database || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Other_database;
    }
}

const CBiostruc_id_Base::TLocal_id& CBiostruc_id_Base::GetLocal_id(void) const
{
    CheckSelected(e_Local_id);
    return *static_cast<const TLocal_id*>(m_object);
}

CBiostruc_id_Base::TLocal_id& CBiostruc_id_Base::SetLocal_id(void)
{
    Select(e_Local_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TLocal_id*>(m_object);
}

void CBiostruc_id_Base::SetLocal_id(CBiostruc_id_Base::TLocal_id& value)
{
    TLocal_id* ptr = &value;
    if ( m_choice != e_Local_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Local_id;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Biostruc-id", CBiostruc_id)
{
    SET_CHOICE_MODULE("MMDB");
    ADD_NAMED_BUF_CHOICE_VARIANT("mmdb-id", m_Mmdb_id, CLASS, (CMmdb_id));
    ADD_NAMED_REF_CHOICE_VARIANT("other-database", m_object, CDbtag);
    ADD_NAMED_REF_CHOICE_VARIANT("local-id", m_object, CObject_id);
}
END_CHOICE_INFO

// constructor
CBiostruc_id_Base::CBiostruc_id_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CBiostruc_id_Base::~CBiostruc_id_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
