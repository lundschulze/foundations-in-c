#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'five steps' './steps' 0 $'' $'Step 1\nStep 2\nStep 3\nStep 4\nStep 5'
