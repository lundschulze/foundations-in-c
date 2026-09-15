#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "pointer array walk" "./walk-array" 0 "" $'8\n13\n21'
