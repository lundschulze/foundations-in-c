#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'inclusive range' './answer' 0 $'' $'10: 1\n15: 1\n20: 1\n9: 0\n21: 0'
