#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'positive start' './answer' 0 $'' $'3\n2\n1'
