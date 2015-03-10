#!/usr/bin/env bash

readonly TSDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

readonly TARGET=$1

readonly NAME=$(basename ${TARGET} .sh)

function TestSuite {

	check=$(find . -maxdepth 1 -name "*Test*" -type d)
	if [ "$?" == 0 ]; then

		num_tests=0
		passed=0

		for ts in ${check}
		do
			((num_tests+=1))

			bash ${ts}/${ts:2}.sh

			if [ $? -eq 0 ]; then
				echo $(basename ${TARGET} .sh)":" Passed
				((passed+=1))
			else
				echo $(basename ${TARGET} .sh)":" Failed
			fi
		done
		echo ${passed} "out of" ${num_tests} passed <&1
	fi
}