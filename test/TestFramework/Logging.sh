#!/bin/bash

LDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

TARGET=$1


exec  > >(tee -a ${TARGET}/output.txt) 2>&1

log() {
	MSG=${1:-"$@"}
	VALUE=${2:-${}}
	{
		echo "$@"
	} >(tee ${TARGET}/failure.table)
}

stdin() {
	{
		return
	} <(tee ${TARGET}/input.txt)
}

stdout() {
	VAR=""
	{
		echo "$@"
	} >(tee ${TARGET}/output.txt <&1)
}

stderr() {
	NAME=$(basename ${TARGET} .sh)
	{
		echo "[$(date +"%D %T")] STD  ERROR: $@"
	} >(tee ${TARGET}/error.txt 2<&1)
}


exit_err() {
	{
		echo "[$(date +"%D %T")] EXIT ERROR: $@"
	} >(tee ${Target}/error.txt 2<&1)
}


log "writting to stdout"
#err "writting to stderr"