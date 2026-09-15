#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "journey module assertions" "./journey-tests" 0 "" ""
check_case "linked journey programme" "./journey" 0 "" $'Destination: Aurora Station\nPassengers: 3'
