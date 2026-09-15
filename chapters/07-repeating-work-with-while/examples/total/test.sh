#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'several values' './total' 0 $'5\n-2\n0\n' $'Enter a value, or 0 to finish: Enter a value, or 0 to finish: Enter a value, or 0 to finish: Total: 3'
check_case 'invalid text' './total' 1 $'tea\n' $'Enter a value, or 0 to finish: Input was not a whole number.'
