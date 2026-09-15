#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'square value' './square' 0 $'' $'Square of 6: 36'
