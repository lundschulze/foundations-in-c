#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'lower boundary' './answer' 0 $'1\n' $'Enter an integer from 1 through 12: 1 x 1 = 1\n1 x 2 = 2\n1 x 3 = 3\n1 x 4 = 4\n1 x 5 = 5\n1 x 6 = 6\n1 x 7 = 7\n1 x 8 = 8\n1 x 9 = 9\n1 x 10 = 10\n1 x 11 = 11\n1 x 12 = 12'
check_case 'upper boundary' './answer' 0 $'12\n' $'Enter an integer from 1 through 12: 12 x 1 = 12\n12 x 2 = 24\n12 x 3 = 36\n12 x 4 = 48\n12 x 5 = 60\n12 x 6 = 72\n12 x 7 = 84\n12 x 8 = 96\n12 x 9 = 108\n12 x 10 = 120\n12 x 11 = 132\n12 x 12 = 144'
check_case 'below range' './answer' 1 $'0\n' $'Enter an integer from 1 through 12: Number is outside the supported range.'
check_case 'above range' './answer' 1 $'13\n' $'Enter an integer from 1 through 12: Number is outside the supported range.'
check_case 'invalid text' './answer' 1 $'tea\n' $'Enter an integer from 1 through 12: Please enter a whole number.'
