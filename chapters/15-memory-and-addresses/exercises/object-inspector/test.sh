#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_pattern "values sizes and addresses" "./answer" 0 "" $'^char: value=C size=1 address=.+\nint: value=42 size=[1-9][0-9]* address=.+\ndouble: value=1\\.5 size=[1-9][0-9]* address=.+$'
