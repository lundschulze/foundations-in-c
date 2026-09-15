#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "journey manifest" "./answer" 0 "" $'101: Maya, 2 bag(s), waiting\n102: Leo, 1 bag(s), ready\n103: Priya, 3 bag(s), departed'
