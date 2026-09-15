#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "replace spaces" "./replace-spaces" 0 "" "Guide_entry"
