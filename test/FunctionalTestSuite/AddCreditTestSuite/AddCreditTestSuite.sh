#!/usr/bin/env bash

SDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

source "${SDIR}/../../TestFramework/TestSuite.sh" ${SDIR};

AddCreditTestSuite() {
      TestSuite
}

AddCreditTestSuite

#      bash ${SDIR}/ValidAddCreditTestCaseA/ValidAddCreditTestCaseA.sh
#      bash ${SDIR}/ValidAddCreditTestCaseB/ValidAddCreditTestCaseB.sh
#      bash ${SDIR}/InvalidAddCreditTestCaseA/InvalidAddCreditTestCaseA.sh
#      bash ${SDIR}/InvalidAddCreditTestCaseB/InvalidAddCreditTestCaseB.sh
#      #bash ${SDIR}/InvalidAddCreditTestCaseC/InvalidAddCreditTestCaseC.sh
#      #bash ${SDIR}/InvalidAddCreditTestCaseD/InvalidAddCreditTestCaseD.sh