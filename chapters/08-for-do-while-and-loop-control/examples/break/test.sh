#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'break before four' './break' 0 $'' $'1\n2\n3'
