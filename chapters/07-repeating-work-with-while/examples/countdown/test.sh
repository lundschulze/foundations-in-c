#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'countdown' './countdown' 0 $'' $'3\n2\n1\nLift off.'
