#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'larger value' './larger' 0 $'' $'Larger value: 42'
