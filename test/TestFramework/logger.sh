#!/bin/bash

exec 1> >(logger -s -t $(basename $0)) 2>&1

echo "stdout"
echo "writting to stderr" >&2

