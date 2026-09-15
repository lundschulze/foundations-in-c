#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "zero-initialised counters" "./calloc-counters" 0 "" $'0\n2\n0\n1'
