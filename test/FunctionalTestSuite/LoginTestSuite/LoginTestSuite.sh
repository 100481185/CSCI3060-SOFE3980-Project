#!/usr/bin/env bash

SDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# source=${SDIR}/../../test/TestFramework/TestSu

function TestSuite {
	for test in `find . -name "*TestCase" `
	do
		bash ${test}/${test}.sh
		if [ $? == 0 ]; then
			echo		Passed
		else
			echo 		Failed
		fi
	done
}


LoginTestSuite() {

    TestSuite

}

LoginTestSuite