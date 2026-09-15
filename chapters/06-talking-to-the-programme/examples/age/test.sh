#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'valid age' './age' 0 $'41\n' $'Enter your age: Next year you will be 42.'
check_case 'invalid text' './age' 1 $'tea\n' $'Enter your age: That was not a whole number.'
