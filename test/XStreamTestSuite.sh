#!/usr/bin/env bash
#
# XStream Complete Test Suite, version 1
#   script to run the complete collection of test suites.

##########################################
#
#
#
#
#
#



readonly DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${DIR}/TestFramework/TestSuite.sh" ${DIR};

function XStreamTestSuite {
    TestSuite
}

XStreamTestSuite