#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "structure copy" "./traveller" 0 "" $'Maya is 42 and carries 2 bags.\nMaya is 42 and carries 3 bags.'
