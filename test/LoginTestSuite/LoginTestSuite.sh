#!/usr/bin/env bash

SDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

LoginTestSuite() {
      bash ${SDIR}/ValidLoginTestCase/ValidLoginTestCase.sh
      bash ${SDIR}/InvalidLoginTestCase/InvalidLoginTestCase.sh
}


LoginTestSuite