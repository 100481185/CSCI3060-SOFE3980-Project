#!/usr/bin/env bash

#exec 1> >(logger -s -t $(basename $0)) 2>&1

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# call if your test requires a clean build
function setup {
    echo ${DIR}/test_build
    if [ -f ${DIR}/../test_build ]; then
        rm -r ${DIR}/../test_build
    fi

    rm -r ${DIR}/../test_build
    mkdir ${DIR}/../test_build && cd ${DIR}../test_build
    cmake ${DIR}/../.. && make
}


function TestCase {
    setup
    cd ${DIR}/../test_build
    ./xstream -s < $1/input.txt > $1/output.txt
    diff $1/output.txt $1/expected.txt
    cp ${DIR}/../test_build/data $1/data -R
}
