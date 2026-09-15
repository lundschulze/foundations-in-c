#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

trap 'rm -f journey.txt' EXIT
rm -f journey.txt
check_case "write report" "./write-report" 0 "" "Wrote journey.txt"
check_file "written report contents" "journey.txt" $'Destination: Aurora Station\nPassengers: 3'
