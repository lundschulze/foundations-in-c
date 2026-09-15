#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "automatic and static storage" "./answer" 0 "" $'Automatic: 1\nStatic: 1\nAutomatic: 1\nStatic: 2\nAutomatic: 1\nStatic: 3'
