#!/usr/bin/env bash

set -eu

repository_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)

export CC=${CC:-clang}
export CFLAGS=${CFLAGS:--std=c17 -Wall -Wextra -Wpedantic -Werror -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer}
export LDFLAGS=${LDFLAGS:--fsanitize=address,undefined}
if [ "$(uname -s)" = Darwin ]
then
    default_asan_options=detect_leaks=0:halt_on_error=1
else
    default_asan_options=detect_leaks=1:halt_on_error=1
fi

export ASAN_OPTIONS=${ASAN_OPTIONS:-$default_asan_options}
export UBSAN_OPTIONS=${UBSAN_OPTIONS:-halt_on_error=1:print_stacktrace=1}

exec "$repository_root/scripts/test-all.sh"
