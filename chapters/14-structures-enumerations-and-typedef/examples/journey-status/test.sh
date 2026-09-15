#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "journey status" "./journey-status" 0 "" "Priya: Ready to depart."
