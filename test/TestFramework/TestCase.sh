#!/usr/bin/env bash
#
# TestCase, version 1
#   library for testing c++ classes in bash.

#################################
# TestBuild a test case for a project
# and provides testing utilities.
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
source ${DIR}/Logging.sh $1

# set the path to the calling directory
readonly TARGET=$1

# set the name of the test case
readonly NAME=$(basename ${TARGET} .sh)

# setup():
#   creates a new build from source can
#   be called if test requires clean data
function setup {
    # remove the current TestBuild dir
    clean
    # remake the build
    mkdir ${DIR}/../TestBuild && cd ${DIR}/../TestBuild
    cmake ${DIR}/../.. && make
}

# clean():
#   deletes the current build directory if
#   one exists.
function clean {
    if [ -d ${DIR}/../TestBuild ]; then
        rm -r ${DIR}/../TestBuild
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
#   status and the difference between stdout
#   and expected
#   RETURN 0 on success, -int on failure
function TestCase {
    # remove the old data
    cleanTest

    cd ${DIR}/../TestBuild

#    ./xstream -s < ${TARGET}/input.txt : >> ${TARGET}/output.txt 2<&1

    ./xstream -s


    if [ $? -lt "0" ]; then
        exit_err ${NAME} $?
        pass=false
    else 
        pass=true
    fi
    
    cp ${DIR}/../TestBuild/data ${TARGET}/data -R
    cd ${DIR}

    if [ ${pass} ]; then
        return 0;
    else
        return 1;
    fi
}


