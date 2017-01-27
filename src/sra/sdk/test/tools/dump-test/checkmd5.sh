#!/bin/bash
# ===========================================================================
#
#                            PUBLIC DOMAIN NOTICE
#               National Center for Biotechnology Information
#
#  This software/database is a "United States Government Work" under the
#  terms of the United States Copyright Act.  It was written as part of
#  the author's official duties as a United States Government employee and
#  thus cannot be copyrighted.  This software/database is freely available
#  to the public for use. The National Library of Medicine and the U.S.
#  Government have not placed any restriction on its use or reproduction.
#
#  Although all reasonable efforts have been taken to ensure the accuracy
#  and reliability of the software and data, the NLM and the U.S.
#  Government do not and cannot warrant the performance or results that
#  may be obtained by using this software or data. The NLM and the U.S.
#  Government disclaim all warranties, express or implied, including
#  warranties of performance, merchantability or fitness for any particular
#  purpose.
#
#  Please cite the author in any work or product based on this material.
#
# ===========================================================================

# verify md5 checksum of dump tool run on a known input

# $1 - dump executable
# $2 - archive: expected to be SRR000123 from the srapath or a local encrypted form
# $3 - expected md5 of the resulting file
# $4 - the result file (stdout if not specified)

DUMP="$1"
shift 1
ARCHIVE="$1"
shift 1
EXPECTED_MD5="$1"
shift 1
RESULT="$1"


#echo ================================
#echo DUMP=${DUMP}
#echo ARCHIVE=${ARCHIVE}
#echo EXPECTED_MD5=${EXPECTED_MD5}
#echo RESULT=${RESULT}
#echo
#echo
echo "$(basename $DUMP)"

OS=$(uname -s)
#echo "$OS"
if [ "$OS" == "Darwin" ]
then
    MD5="/sbin/md5 -q"
    TOUNIX="cat"
else
    MD5="md5sum -b"
    TOUNIX="dos2unix"
fi 

# md5 produced for SRR000123.sff generated by "sff-dump.2.1.6 SRR000123"
#EXPECTED="2fcb231391bb920d2fa38f77b0dc1f8c" 

rm -f ${RESULT} >/dev/null

CMD="${DUMP} ${ARCHIVE} --no-user-settings "
if [ "${RESULT}" == "" ]
then
    RESULT="temp"
    ${CMD} 2>/dev/null | ${TOUNIX} >temp
else
    ${CMD} 1>/dev/null 2>/dev/null
fi

#echo "${CMD}"

if [ $? != 0 ]
then
    echo "error running ${DUMP}. Command issued: '${CMD}'"
    exit 1
else 
    # wait for the result file to appear (for the benefit of the remote builds where there may be a network delay)
    ../../../build/wait_for_file.sh ${RESULT} 200
    if [ "$?" = "0" ]
    then 
        ACTUAL_MD5=($(${MD5} ${RESULT}))
        if [ "${ACTUAL_MD5}" != "${EXPECTED_MD5}" ]
        then
            echo "md5 mismatch, actual ${ACTUAL_MD5}, expected ${EXPECTED_MD5}"
            exit 2
        fi
    else
        echo "File '${RESULT}' not found"        
        exit 3
    fi
fi

rm -f ${RESULT} >/dev/null
exit 0
