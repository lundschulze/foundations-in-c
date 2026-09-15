#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'body runs first' './do_while' 0 $'' $'Choice: 2\nChoice: 1'
