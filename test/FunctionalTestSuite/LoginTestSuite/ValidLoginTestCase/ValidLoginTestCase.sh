#!/usr/bin/env bash

TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source "${TDIR}/./../../../TestFramework/TestCase.sh" ${TDIR};
cd ..
echo "${TDIR}"
#diff "/home/nicholas/Desktop/xstream/test/TestFramework/TestCase.sh" ${TDIR} >1

function ValidLoginTestCase {
     TestCase
}


BLACK='\e[0;30m'

#echo -e "${Black}"
#setup
ValidLoginTestCase