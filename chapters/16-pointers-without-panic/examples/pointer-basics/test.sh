#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "read and write through pointer" "./pointer-basics" 0 "" $'Directly: 42\nThrough the pointer: 42\nAfter the change: 43'
