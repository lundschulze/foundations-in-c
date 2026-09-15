#!/usr/bin/env bash
set -eu

source ../../scripts/test-helpers.sh

trap 'rm -f travellers-practice.txt test-valid.txt test-malformed.txt' EXIT
rm -f travellers-practice.txt test-valid.txt test-malformed.txt

check_case "database module assertions" "./tests" 0 "" ""
check_absent "unit-test fixtures removed" "test-valid.txt"
check_absent "malformed fixture removed" "test-malformed.txt"
check_case "complete database round trip" "./traveller-database" 0 "" $'1: Maya Chen, 2 bags\n2: Leo Martins, 1 bag\n3: Priya Shah, 3 bags\nDatabase round trip verified.'
check_absent "practice database removed" "travellers-practice.txt"
