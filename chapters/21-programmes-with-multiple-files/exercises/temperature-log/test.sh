#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "temperature-log module assertions" "./temperature-log-tests" 0 "" ""
check_case "multi-file exercise programme" "./answer" 0 "" "Average: 15.0"
