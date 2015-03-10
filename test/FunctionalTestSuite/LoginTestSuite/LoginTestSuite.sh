#!/usr/bin/env bash

BRed='\e[1;31m'
BGreen='\e[1;32m'

SDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${SDIR}/../../TestFramework/TestSuite.sh";

LoginTestSuite() {
    TestSuite
}

LoginTestSuite