#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "valid integer" "./parse-integer" 0 $'42\n' "Value: 42"
check_case "signed integer with whitespace" "./parse-integer" 0 $'  -7  \n' "Value: -7"
check_case "trailing characters" "./parse-integer" 1 $'42xyz\n' "The value is not a valid int."
check_case "empty line" "./parse-integer" 1 $'\n' "No integer was found."
check_case "integer overflow" "./parse-integer" 1 $'999999999999999999999999\n' "The value is not a valid int."
check_case "end of input" "./parse-integer" 1 "" "No input was available."
long_input=$(printf '1%.0s' {1..100})
check_case "line too long" "./parse-integer" 1 "$long_input" "The input line is too long."
