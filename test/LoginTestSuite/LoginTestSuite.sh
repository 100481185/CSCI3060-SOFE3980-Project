#!/usr/bin/env bash


program=./../build/xstream/
CWD=$(pwd)/testdata

LoginTestSuite() {
    bash ./TestCase.sh TestCase ${program} ${CWD}
}