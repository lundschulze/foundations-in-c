#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "summed readings" "./sum_readings" 0 "" "Total: 75"
