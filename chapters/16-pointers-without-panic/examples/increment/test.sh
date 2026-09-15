#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "increment through pointer" "./increment" 0 "" "Visits: 43"
