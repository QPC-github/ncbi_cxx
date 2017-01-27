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
 *   'macro.asn'.
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
#include <objects/macro/Source_location.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_INFO("Source-location", ESource_location, false)
{
    SET_ENUM_MODULE("NCBI-Macro");
    ADD_ENUM_VALUE("unknown", eSource_location_unknown);
    ADD_ENUM_VALUE("genomic", eSource_location_genomic);
    ADD_ENUM_VALUE("chloroplast", eSource_location_chloroplast);
    ADD_ENUM_VALUE("chromoplast", eSource_location_chromoplast);
    ADD_ENUM_VALUE("kinetoplast", eSource_location_kinetoplast);
    ADD_ENUM_VALUE("mitochondrion", eSource_location_mitochondrion);
    ADD_ENUM_VALUE("plastid", eSource_location_plastid);
    ADD_ENUM_VALUE("macronuclear", eSource_location_macronuclear);
    ADD_ENUM_VALUE("extrachrom", eSource_location_extrachrom);
    ADD_ENUM_VALUE("plasmid", eSource_location_plasmid);
    ADD_ENUM_VALUE("transposon", eSource_location_transposon);
    ADD_ENUM_VALUE("insertion-seq", eSource_location_insertion_seq);
    ADD_ENUM_VALUE("cyanelle", eSource_location_cyanelle);
    ADD_ENUM_VALUE("proviral", eSource_location_proviral);
    ADD_ENUM_VALUE("virion", eSource_location_virion);
    ADD_ENUM_VALUE("nucleomorph", eSource_location_nucleomorph);
    ADD_ENUM_VALUE("apicoplast", eSource_location_apicoplast);
    ADD_ENUM_VALUE("leucoplast", eSource_location_leucoplast);
    ADD_ENUM_VALUE("proplastid", eSource_location_proplastid);
    ADD_ENUM_VALUE("endogenous-virus", eSource_location_endogenous_virus);
    ADD_ENUM_VALUE("hydrogenosome", eSource_location_hydrogenosome);
    ADD_ENUM_VALUE("chromosome", eSource_location_chromosome);
    ADD_ENUM_VALUE("chromatophore", eSource_location_chromatophore);
}
END_ENUM_INFO


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

