#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

trap 'rm -f private-travel-log.txt' EXIT
rm -f private-travel-log.txt
check_case "write read and remove" "./answer" 0 "" $'Aurora Station|3\nHarbour Point|1\nEarth|2'
check_absent "temporary log removed" "private-travel-log.txt"
