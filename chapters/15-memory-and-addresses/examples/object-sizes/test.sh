#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_pattern "portable object sizes" "./object-sizes" 0 "" $'^char: 1 byte\\(s\\)\nint: [1-9][0-9]* byte\\(s\\)\ndouble: [1-9][0-9]* byte\\(s\\)\nanswer: [1-9][0-9]* byte\\(s\\), value 42$'
