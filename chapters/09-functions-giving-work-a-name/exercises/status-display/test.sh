#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'status panel' './answer' 0 $'' $'------------------------\nSystem status: ready.\n------------------------'
