#!/usr/bin/env bash




TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source "${TDIR}/../../../TestFramework/TestCase.sh" ${TDIR};

function ValidLoginTestCase {
     TestCase
}

BLACK='\e[0;30m'

echo -e "${Black}"
#setup
ValidLoginTestCase