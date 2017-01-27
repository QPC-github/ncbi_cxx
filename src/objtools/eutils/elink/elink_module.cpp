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
 *   'elink.dtd'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objtools/eutils/elink/elink_module.hpp>
#include <objtools/eutils/elink/ELinkResult.hpp>
#include <objtools/eutils/elink/FirstChars.hpp>
#include <objtools/eutils/elink/IconUrl.hpp>
#include <objtools/eutils/elink/Id.hpp>
#include <objtools/eutils/elink/IdCheckList.hpp>
#include <objtools/eutils/elink/IdLinkSet.hpp>
#include <objtools/eutils/elink/IdList.hpp>
#include <objtools/eutils/elink/IdUrlList.hpp>
#include <objtools/eutils/elink/IdUrlSet.hpp>
#include <objtools/eutils/elink/Link.hpp>
#include <objtools/eutils/elink/LinkInfo.hpp>
#include <objtools/eutils/elink/LinkSet.hpp>
#include <objtools/eutils/elink/LinkSetDb.hpp>
#include <objtools/eutils/elink/LinkSetDbHistory.hpp>
#include <objtools/eutils/elink/ObjUrl.hpp>
#include <objtools/eutils/elink/Provider.hpp>
#include <objtools/eutils/elink/Url.hpp>


BEGIN_elink_SCOPE // namespace elink::

void elink_RegisterModuleClasses(void)
{
    elink::CELinkResult::GetTypeInfo();
    elink::CFirstChars::GetTypeInfo();
    elink::CIconUrl::GetTypeInfo();
    elink::CId::GetTypeInfo();
    elink::CIdCheckList::GetTypeInfo();
    elink::CIdLinkSet::GetTypeInfo();
    elink::CIdList::GetTypeInfo();
    elink::CIdUrlList::GetTypeInfo();
    elink::CIdUrlSet::GetTypeInfo();
    elink::CLink::GetTypeInfo();
    elink::CLinkInfo::GetTypeInfo();
    elink::CLinkSet::GetTypeInfo();
    elink::CLinkSetDb::GetTypeInfo();
    elink::CLinkSetDbHistory::GetTypeInfo();
    elink::CObjUrl::GetTypeInfo();
    elink::CProvider::GetTypeInfo();
    elink::CUrl::GetTypeInfo();
}

END_elink_SCOPE // namespace elink::
