#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "uppercase first character" "./uppercase_first" 0 "" "Maya"
