#!/usr/bin/env bash

set -eu

source ../../../../scripts/test-helpers.sh

check_case 'banner' './banner' 0 $'' $'------------------------\nJourney control\n------------------------'
