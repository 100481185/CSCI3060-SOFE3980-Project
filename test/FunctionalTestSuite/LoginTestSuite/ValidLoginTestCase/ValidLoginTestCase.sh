#!/usr/bin/env bash

RED='\033[0;31m'
alias blue='echo -en "\033[36m"'
alias red='echo -en "\033[31m"'
alias formatOutput='while read line; do blue; echo $line; red; done'


TDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${TDIR}/../../../TestFramework/TestCase.sh" ${TDIR};

function ValidLoginTestCase {
     TestCase
}

ValidLoginTestCase