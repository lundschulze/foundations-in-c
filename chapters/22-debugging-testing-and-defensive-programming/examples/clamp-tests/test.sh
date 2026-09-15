#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "clamp boundary assertions" "./clamp-tests" 0 "" ""
