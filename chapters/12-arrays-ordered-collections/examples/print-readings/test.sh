#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "printed readings" "./print_readings" 0 "" $'12\n15\n14\n18\n16'
