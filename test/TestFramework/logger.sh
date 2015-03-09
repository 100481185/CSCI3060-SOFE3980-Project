#!/bin/bash
exec  > >(tee -a $1/output.txt) 2>&1

#!/bin/bash
log() {
#	echo $1
#	basename $0 .sh
	echo "$@"
}

exit_err(){
	echo `date +'%b %e %R: Exit Error: '` $1 "failed with exit status" $2
}

err() {
	echo `date +'%b %e %R '` "$@"
}

#log "writting to stdout"
#err "writting to stderr"