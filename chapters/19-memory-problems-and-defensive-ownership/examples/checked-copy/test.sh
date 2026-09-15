#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "capacity-checked copy" "./checked-copy" 0 "" $'8\n13\n21'
