#!/usr/bin/env bash
#
# Setup.sh, version 1
#
#    <description>

# <brief description>
#
# Globals:
#       None
# Param:
#       None
# Return:
#       None

# Set files location directory 
readonly SETUPDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${SETUPDIR}"/Colours.sh;
source "${SETUPDIR}"/Clean.sh

# setup():
#   creates a new build from source can
#+  be called if test requires clean data
function setup {
    echo -e "${Black}"
    # remove the current TestBuild dir
    clean
    # remake the build
    mkdir "${SETUPDIR}"/../TestBuild && cd "${SETUPDIR}"/../TestBuild
    cmake ../.. && make
    echo -e "${NC}"
}

