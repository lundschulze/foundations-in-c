#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'lower boundary' './temperature' 0 $'-100\n' $'Temperature in Celsius: Recorded temperature: -100 C'
check_case 'upper boundary' './temperature' 0 $'100\n' $'Temperature in Celsius: Recorded temperature: 100 C'
check_case 'outside range' './temperature' 1 $'101\n' $'Temperature in Celsius: Temperature is outside the supported range.'
check_case 'invalid text' './temperature' 1 $'tea\n' $'Temperature in Celsius: Please enter a whole number.'
