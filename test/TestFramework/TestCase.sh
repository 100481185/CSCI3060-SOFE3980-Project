#!/usr/bin/env bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source ${DIR}/logger.sh $1

TARGET=$1

NAME=$2

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
    
    cleanTest
    
    cd ${DIR}/../test_build

    echo ${NAME} <&1

    # (./doit >> log) 2>&1 | tee -a log

    ./xstream -s < ${TARGET}/input.txt : >> ${TARGET}/output.txt 2<&1 

    echo $?

    if [ $? -lt "0" ]; then
        exit_err ${NAME} $?
        pass=false
    else 
        pass=true
    fi
    
    cp ${DIR}/../test_build/data ${TARGET}/data -R
    cd ${DIR}

    if [ ${pass} ]; then
        return 0;
    else
        return -1;
    fi
}

function cleanTest {
    if [ -f ${TARGET}/output.txt ]; then
        rm ${TARGET}/output.txt
    fi

    if [ -d ${TARGET}/data ]; then
        rm -r ${TARGET}/data
    fi
}
