#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'lower boundary' './answer' 0 $'0\n' $'Enter a quantity from 0 through 100: Accepted quantity: 0'
check_case 'upper boundary' './answer' 0 $'100\n' $'Enter a quantity from 0 through 100: Accepted quantity: 100'
check_case 'below range' './answer' 1 $'-1\n' $'Enter a quantity from 0 through 100: Quantity is outside the supported range.'
check_case 'above range' './answer' 1 $'101\n' $'Enter a quantity from 0 through 100: Quantity is outside the supported range.'
check_case 'invalid text' './answer' 1 $'tea\n' $'Enter a quantity from 0 through 100: Please enter a whole number.'
