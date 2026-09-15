#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

trap 'rm -f journey.txt' EXIT
printf 'Destination: Aurora Station\nPassengers: 3\n' > journey.txt
check_case "read existing report" "./read-report" 0 "" $'Destination: Aurora Station\nPassengers: 3'
rm -f journey.txt
check_pattern "missing report" "./read-report" 1 "" $'^journey\\.txt: .+$'
