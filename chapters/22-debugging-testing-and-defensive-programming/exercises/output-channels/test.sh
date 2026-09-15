#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_channels "separate output channels" "./answer" 1 "" \
    "Result: no record saved." \
    "Diagnostic: the practice destination was unavailable."
