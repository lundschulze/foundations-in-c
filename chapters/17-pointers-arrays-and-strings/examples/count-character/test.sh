#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "character counts" "./count-character" 0 "" $'e: 3\nR: 1\nz: 0'
