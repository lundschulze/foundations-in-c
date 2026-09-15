#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "underscores empty and unchanged" "./answer" 0 "" $'Ready for departure\n\nBag'
