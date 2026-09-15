#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "line with newline" "./answer" 0 $'Ready for departure\n' $'Enter text: Text: Ready for departure\nLength: 19\nFirst character: R\nThe newline fitted in the array.'
check_case "empty line" "./answer" 0 $'\n' $'Enter text: Text: \nLength: 0\nFirst character: (none)\nThe newline fitted in the array.'
check_case "line without newline" "./answer" 0 "no newline" $'Enter text: Text: no newline\nLength: 10\nFirst character: n\nThe newline did not fit in the array.'
