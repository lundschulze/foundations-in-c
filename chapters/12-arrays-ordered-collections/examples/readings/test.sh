#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "indexed readings" "./readings" 0 "" $'Reading 0: 12\nReading 1: 15\nReading 2: 14\nReading 3: 18\nReading 4: 16'
