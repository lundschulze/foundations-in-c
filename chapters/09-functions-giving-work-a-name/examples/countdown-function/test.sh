#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'function call' './countdown_function' 0 $'' $'Preparing departure.\n3\n2\n1\nLift off.\nDeparture sequence complete.'
