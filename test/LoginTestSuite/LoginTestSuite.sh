#!/usr/bin/env bash

LoginTestSuite() {
      bash ./ValidLoginTestCase/ValidLoginTestCase.sh
      bash ./InvalidLoginTestCase/InvalidLoginTestCase.sh
}


LoginTestSuite