#!/usr/bin/env bash

function TestCase {
    ls $1
    echo $2
    cp $1/xstream $1/data $2 -R
    cd $2
    ./xstream -s < input.txt > output.txt
    #diff -u -I " " $1/output.txt $1/expected.txt

}

function clean {
    rm -r $1/data
    rm $1/xstream
}