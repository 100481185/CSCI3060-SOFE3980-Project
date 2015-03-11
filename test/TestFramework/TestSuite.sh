#!/usr/bin/env bash

readonly TSDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

readonly TARGET=$1

readonly NAME=$(basename ${TARGET} .sh)

function TestSuite {

	FUNC_INFO=`caller 0`
	num_tests=0
	passed=0
	for test in `find . -maxdepth 1 -type d -name "*Test*"`;
	do
		((num_tests+=1))
		bash ${test}/${test:2}.sh
		if [ $? -eq 0 ]; then
			echo "${test:2}"":" Passed
			((passed+=1))
		else
			echo "${test:2}"":" Failed
		fi
	done
	echo ${passed} "out of" ${num_tests} passed <&1
}