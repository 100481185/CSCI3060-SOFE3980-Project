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

# Normal Colors
Black='\e[0;30m'        # Black
Red='\e[0;31m'          # Red
Green='\e[0;32m'        # Green
Yellow='\e[0;33m'       # Yellow
Blue='\e[0;34m'         # Blue
Purple='\e[0;35m'       # Purple
Cyan='\e[0;36m'         # Cyan
White='\e[0;37m'        # White

# Bold
BBlack='\e[1;30m'       # Black
BRed='\e[1;31m'         # Red
BGreen='\e[1;32m'       # Green
BYellow='\e[1;33m'      # Yellow
BBlue='\e[1;34m'        # Blue
BPurple='\e[1;35m'      # Purple
BCyan='\e[1;36m'        # Cyan
BWhite='\e[1;37m'       # White

# Background
On_Black='\e[40m'       # Black
On_Red='\e[41m'         # Red
On_Green='\e[42m'       # Green
On_Yellow='\e[43m'      # Yellow
On_Blue='\e[44m'        # Blue
On_Purple='\e[45m'      # Purple
On_Cyan='\e[46m'        # Cyan
On_White='\e[47m'       # White

NC="\e[m"               # Color Reset


LDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TARGET=$1


# set stdin, stdout, and stderr.
STDIN="${TARGET}/$(basename ${TARGET} .sh).in"
STDOUT="${TARGET}/$(basename ${TARGET} .sh).out"
STDERR="${TARGET}/$(basename ${TARGET} .sh).err"
STDLOG="${TARGET}/$(basename ${TARGET} .sh).log"

#exec > ${STDOUT} 2> >(tee ${STDOUT} >&2)

input() {
    {
    	$1 < ${STDIN}
	} 0>& $(output)
}



output() {
	VAR=""
	{
		echo "$[0]"
		echo "$@"
	}
}


error() {
	NAME="$(basename $(1) .sh)"
	{
		echo "[$(date +'%Y-%m-%dT%H:%M:%S%z')]: $@"
	} 2>> ${STDERR}
}


log() {
	MSG=${1:-"$@"}
	VALUE=${2:-${@}}
	{
		echo "$@"
	} &> ${STDLOG}
}



#$(awk'
#{
#    if (NF != 4) {
#        error("Expected 4 fields");
#    } else {
#        print;
#    }
#}')
#
#$(awk'
#function error ( message ) {
#    if (FILENAME != "-") {
#        printf("%s: ", FILENAME) > '${STDLOG}';
#    }
#    printf("line # %d, %s, line: %s\n", NR, message, $0) > "$(${STDLOG})";
#}')

