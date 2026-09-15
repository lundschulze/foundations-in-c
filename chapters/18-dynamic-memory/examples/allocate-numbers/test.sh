#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "allocated numbers" "./allocate-numbers" 0 "" $'1\n2\n3\n4\n5'
