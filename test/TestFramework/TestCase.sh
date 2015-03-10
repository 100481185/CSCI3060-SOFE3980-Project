#!/usr/bin/env bash
#
# TestCase, version 1
#   library for testing c++ classes in bash.

##########################
# A Test Case template for
#+xstream project.
# Globals:
#   DIR
#   TARGET
#   NAME
# Arguments:
#   TARGET_PATH
#   TARGET_NAME
# Returns:
#   None

# set the DIR to the files directory
readonly DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# link the logging module
source ${DIR}/Logger.sh $1;

# set the path to the calling directory
readonly TARGET=$1

# set the name of the test case
readonly NAME=$(basename ${TARGET} .sh)

# setup():
#   creates a new build from source can
#+  be called if test requires clean data
function setup {
    # remove the current TestBuild dir
    clean
    # remake the build
    mkdir ${DIR}/../tBuild && cd ${DIR}/../tBuild
    cmake ${DIR}/../.. && make
}

# clean():
#   deletes the current build directory if
#+  one exists.
function clean {
    if [ -d ${DIR}/../tBuild ]; then
        rm -r ${DIR}/../tBuild
    fi
}

# cleanTest():
#   cleans test data and output files
function cleanTest {
    if [ -f ${TARGET}/output.txt ]; then
        rm ${TARGET}/output.txt
    fi

    if [ -d ${TARGET}/data ]; then
        rm -r ${TARGET}/data
    fi
}

# TestCase():
#   creates a new test case which checks exit
#+  status and the difference between stdout
#+  and expected
#   RETURN 0 on success, -int on failure
function TestCase {
    # remove the old data
    cleanTest

    cd "${DIR}/../TestBuild"

    xstream=`./xstream`
#    ./xstream -s < ${TARGET}/input.txt : >> ${TARGET}/output.txt 2<&1
    ${xstream} <& input 2>> output 2<&1

    if [ $? -lt "0" ]; then
        exit_err ${NAME} $?
        pass=false
    else
        pass=true
    fi

    cp ${DIR}/../TestBuild/data ${TARGET}/data -R
    cd ${DIR}
    return 0
}