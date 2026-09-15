#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_pattern "value and address" "./address" 0 "" $'^Value: 42\nAddress: .+$'
