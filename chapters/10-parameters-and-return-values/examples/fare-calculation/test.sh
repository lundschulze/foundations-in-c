#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'calculated fare' './fare_calculation' 0 $'' $'Ticket price: 7.50'
