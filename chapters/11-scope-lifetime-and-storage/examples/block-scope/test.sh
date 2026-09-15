#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "nested block" "./block_scope" 0 "" $'Outer: 42\nInner: 7\nOuter again: 42'
