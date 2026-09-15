#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "grown exercise list" "./answer" 0 "" $'10\n20\n30\n40\n50'
