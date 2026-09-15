#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "owned buffer lifecycle" "./owned-buffer" 0 "" $'10\n20\n30\nAfter destroy: count=0, empty=yes'
