#!/usr/bin/env bash
source ../../TestCase.sh;

program_dir=./../../../build/xstream/

function ValidLoginTestCase() {
     TestCase ${program_dir} $(pwd)
}

ValidLoginTestCase
