#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "string array" "./name" 0 "" "Traveller: Maya"
