#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "swap through pointers" "./swap" 0 "" $'Before: 13 42\nAfter: 42 13'
