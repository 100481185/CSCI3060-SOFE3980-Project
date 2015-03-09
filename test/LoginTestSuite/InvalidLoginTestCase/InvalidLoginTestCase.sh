#!/usr/bin/env bash

TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TEST=$(basename ${TDIR} .sh)

source ${TDIR}/../../TestFramework/TestCase.sh ${TDIR} ${TEST};

function InvalidLoginTestCase {
    TestCase
}

InvalidLoginTestCase