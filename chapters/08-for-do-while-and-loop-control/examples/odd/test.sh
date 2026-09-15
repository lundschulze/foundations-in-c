#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'skip even values' './odd' 0 $'' $'1\n3\n5\n7'
