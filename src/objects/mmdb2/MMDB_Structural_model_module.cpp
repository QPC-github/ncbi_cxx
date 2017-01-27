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
 *   'mmdb2.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/mmdb2/MMDB_Structural_model_module.hpp>
#include <objects/mmdb2/Alternate_conformation_ids.hpp>
#include <objects/mmdb2/Anisotro_temperatu_factors.hpp>
#include <objects/mmdb2/Atomic_coordinates.hpp>
#include <objects/mmdb2/Atomic_occupancies.hpp>
#include <objects/mmdb2/Atomic_temperature_factors.hpp>
#include <objects/mmdb2/Biostruc_model.hpp>
#include <objects/mmdb2/Conformation_ensemble.hpp>
#include <objects/mmdb2/Coordinates.hpp>
#include <objects/mmdb2/Density_coordinates.hpp>
#include <objects/mmdb2/Isotropi_temperatu_factors.hpp>
#include <objects/mmdb2/Model_coordinate_set.hpp>
#include <objects/mmdb2/Model_descr.hpp>
#include <objects/mmdb2/Model_space.hpp>
#include <objects/mmdb2/Model_space_points.hpp>
#include <objects/mmdb2/Reference_frame.hpp>
#include <objects/mmdb2/Surface_coordinates.hpp>
#include <objects/mmdb2/T_mesh.hpp>
#include <objects/mmdb2/Triangles.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void MMDB_Structural_model_RegisterModuleClasses(void)
{
    ncbi::objects::CAlternate_conformation_ids::GetTypeInfo();
    ncbi::objects::CAnisotropic_temperature_factors::GetTypeInfo();
    ncbi::objects::CAtomic_coordinates::GetTypeInfo();
    ncbi::objects::CAtomic_occupancies::GetTypeInfo();
    ncbi::objects::CAtomic_temperature_factors::GetTypeInfo();
    ncbi::objects::CBiostruc_model::GetTypeInfo();
    ncbi::objects::CConformation_ensemble::GetTypeInfo();
    ncbi::objects::CCoordinates::GetTypeInfo();
    ncbi::objects::CDensity_coordinates::GetTypeInfo();
    ncbi::objects::CIsotropic_temperature_factors::GetTypeInfo();
    ncbi::objects::CModel_coordinate_set::GetTypeInfo();
    ncbi::objects::CModel_descr::GetTypeInfo();
    ncbi::objects::CModel_space::GetTypeInfo();
    ncbi::objects::CModel_space_points::GetTypeInfo();
    ncbi::objects::CReference_frame::GetTypeInfo();
    ncbi::objects::CSurface_coordinates::GetTypeInfo();
    ncbi::objects::CT_mesh::GetTypeInfo();
    ncbi::objects::CTriangles::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

