#!/usr/bin/env bash

for input in input*.txt ; do
    ./../../src/bin/xstream > ./input.txt < ./output.txt
done
