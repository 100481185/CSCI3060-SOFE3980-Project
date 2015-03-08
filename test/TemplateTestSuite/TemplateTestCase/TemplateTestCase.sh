#!/usr/bin/env bash

TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source ${TDIR}/../../TestCase.sh;

function TemplateTestCase {
    TestCase ${TDIR}
}