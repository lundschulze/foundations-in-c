#!/usr/bin/env bash
set -eu

source ../../../../scripts/test-helpers.sh

check_case "weekly analysis" "./answer" 0 "" $'Measurement 0: 12\nMeasurement 1: 15\nMeasurement 2: 14\nMeasurement 3: 18\nMeasurement 4: 16\nMeasurement 5: 11\nMeasurement 6: 17\nTotal: 103\nSmallest: 11\nLargest: 18'
