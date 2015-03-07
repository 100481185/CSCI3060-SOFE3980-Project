#!/usr/bin/env bash
source ../../TestCase.sh;

program=./../../../build/xstream/

function ValidLoginTestCase() {
     TestCase ${program} $(pwd)
}

ValidLoginTestCase
