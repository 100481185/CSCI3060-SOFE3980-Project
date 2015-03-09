#!/usr/bin/env bash

TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source ${TDIR}/../../TestFramework/TestCase.sh;

function TemplateTestCase {
    TestCase ${TDIR}
}

#TemplateTestCase #Uncomment to enable test