#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "clamp below within and above" "./answer" 0 "" $'0\n5\n10'
