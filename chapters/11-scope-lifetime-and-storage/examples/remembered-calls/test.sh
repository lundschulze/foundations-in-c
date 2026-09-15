#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "remembered calls" "./remembered_calls" 0 "" $'Call 1\nCall 2\nCall 3'
