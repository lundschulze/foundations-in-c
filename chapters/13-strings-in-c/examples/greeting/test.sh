#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "full name" "./greeting" 0 $'Leo Martins\n' "Your name: Welcome, Leo Martins."
check_case "blank name" "./greeting" 0 $'\n' "Your name: Welcome, ."
check_case "end of input" "./greeting" 1 "" "Your name: No name was read."
