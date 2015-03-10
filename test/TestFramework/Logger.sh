#!/usr/bin/env bash
#
# Logger, version 1.4
#   logs stdin, stdout and stderr to their
#   repective files.
#

#######################################
# redirects stdin, stdout, and stderr
# to .in, .out, and .err files
# Globals:
#   BLACK   *color code for console
#   RED     *
#   BLUE    *
#   BLACK   *
# Param:
#       None
# Return
#       None
#

BLACK='\033[0;30m'
RED='\033[0;31m'
BLUE='\033[0;35m'
GREEN='\033[0;32m'

LDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

TARGET=$1

# set stdin, stdout, and stderr.
STDIN="${TARGET}/*.in)"
STDOUT="${TARGET}/*.out"
STDERR="${TARGET}/*.err)"
# set log to failure_table
STDLOG="${TARGET}/failure.log"



function input() {
    {
        $1
	} <<< ${STDIN}
}

function output() {
	VAR=""
	{
		echo "$@"
	} >> ${STDOUT} <&1
}

function error() {
	NAME=$(basename ${TARGET} .sh)
	{
		echo "$``{`RED`}``[$(date +"%D %T")] STD  ERROR: $@"
	} >> ${STDERR} 2>&1
}

function log() {
	MSG=${1:-"$@"}
	VALUE=${2:-${@}}
	{
		echo "$@"
	}
}

#input >&1
#log "writting to stdout"
#err "writting to stderr"



#`awk'
#{
#    if (NF != 4) {
#        error("Expected 4 fields");
#    } else {
#        print;
#    }
#}
#
#function error ( message ) {
#    if (FILENAME != "-") {
#        printf("%s: ", FILENAME) > '${STDLOG}';
#    }
#    printf("line # %d, %s, line: %s\n", NR, message, $0) > '${STDLOG}';
#}'`


# Black        0;30
# Dark Gray    1;30
# Blue         0;34
# Light Blue   1;34
# Green        0;32
# Light Green  1;32
# Cyan         0;36
# Light Cyan   1;36
# Red          0;31
# Light Red    1;31
# Purple       0;35
# Light Purple 1;35
# Brown/Orange 0;33
# Yellow       1;33
# Light Gray   0;37
# White        1;37
