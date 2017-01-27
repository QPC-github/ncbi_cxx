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
 *   'id2.asn'.
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
#include <objects/id2/ID2_Reply_Data.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CID2_Reply_Data_Base::, EData_type, true)
{
    SET_ENUM_INTERNAL_NAME("ID2-Reply-Data", "data-type");
    SET_ENUM_MODULE("NCBI-ID2Access");
    ADD_ENUM_VALUE("seq-entry", eData_type_seq_entry);
    ADD_ENUM_VALUE("seq-annot", eData_type_seq_annot);
    ADD_ENUM_VALUE("id2s-split-info", eData_type_id2s_split_info);
    ADD_ENUM_VALUE("id2s-chunk", eData_type_id2s_chunk);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CID2_Reply_Data_Base::, EData_format, true)
{
    SET_ENUM_INTERNAL_NAME("ID2-Reply-Data", "data-format");
    SET_ENUM_MODULE("NCBI-ID2Access");
    ADD_ENUM_VALUE("asn-binary", eData_format_asn_binary);
    ADD_ENUM_VALUE("asn-text", eData_format_asn_text);
    ADD_ENUM_VALUE("xml", eData_format_xml);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CID2_Reply_Data_Base::, EData_compression, true)
{
    SET_ENUM_INTERNAL_NAME("ID2-Reply-Data", "data-compression");
    SET_ENUM_MODULE("NCBI-ID2Access");
    ADD_ENUM_VALUE("none", eData_compression_none);
    ADD_ENUM_VALUE("gzip", eData_compression_gzip);
    ADD_ENUM_VALUE("nlmzip", eData_compression_nlmzip);
    ADD_ENUM_VALUE("bzip2", eData_compression_bzip2);
}
END_ENUM_INFO

void CID2_Reply_Data_Base::ResetData(void)
{
    {
        for ( std::list< std::vector< char >* >::iterator listIter1 = (m_Data).begin(); listIter1 != (m_Data).end(); ++listIter1 ) {
            delete (*listIter1);
        }
    }
    m_Data.clear();
    m_set_State[0] &= ~0xc0;
}

void CID2_Reply_Data_Base::Reset(void)
{
    ResetData_type();
    ResetData_format();
    ResetData_compression();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2-Reply-Data", CID2_Reply_Data)
{
    SET_CLASS_MODULE("NCBI-ID2Access");
    ADD_NAMED_ENUM_MEMBER("data-type", m_Data_type, EData_type)->SetDefault(new TData_type(eData_type_seq_entry))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("data-format", m_Data_format, EData_format)->SetDefault(new TData_format(eData_format_asn_binary))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("data-compression", m_Data_compression, EData_compression)->SetDefault(new TData_compression(eData_compression_none))->SetOptional()->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("data", m_Data, STL_list, (POINTER, (STL_CHAR_vector, (char))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
}
END_CLASS_INFO

// constructor
CID2_Reply_Data_Base::CID2_Reply_Data_Base(void)
    : m_Data_type(eData_type_seq_entry), m_Data_format(eData_format_asn_binary), m_Data_compression(eData_compression_none)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CID2_Reply_Data_Base::~CID2_Reply_Data_Base(void)
{
    {
        for ( std::list< std::vector< char >* >::iterator listIter1 = (m_Data).begin(); listIter1 != (m_Data).end(); ++listIter1 ) {
            delete (*listIter1);
        }
    }
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

