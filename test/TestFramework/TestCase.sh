#!/usr/bin/env bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# call if your test requires a clean build
function setup {
    clean
    mkdir ${DIR}/../test_build && cd ${DIR}/../test_build
    cmake ${DIR}/../.. && make
}

function clean {
    if [ -d ${DIR}/../test_build ]; then
        rm -r ${DIR}/../test_build
    fi
}

function TestCase {
    cd ${DIR}/../test_build
    ./xstream -s < $1/input.txt &> $1/output.txt
    diff $1/output.txt $1/expected.txt
    cp ${DIR}/../test_build/data $1/data -R
}
