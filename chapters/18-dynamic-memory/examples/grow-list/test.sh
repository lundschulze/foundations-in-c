#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "reallocated list" "./grow-list" 0 "" $'13\n21\n30\n40\n50'
