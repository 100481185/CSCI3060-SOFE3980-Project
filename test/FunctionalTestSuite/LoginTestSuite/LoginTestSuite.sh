#!/usr/bin/env bash

BRed='\e[1;31m'
BGreen='\e[1;32m'

SDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${SDIR}/../../TestFramework/TestSuite.sh";


if ! [ -d "${SDIR}/../../Tbuild" ]; then
    echo "Failed"
fi

LoginTestSuite() {
    TestSuite
}

LoginTestSuite