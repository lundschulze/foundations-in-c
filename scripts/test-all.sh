#!/usr/bin/env bash

set -eu

repository_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
compiler=${CC:-cc}
strict_flags=${CFLAGS:--std=c17 -Wall -Wextra -Wpedantic -Werror}
linker_flags=${LDFLAGS:-}
libraries=${LDLIBS:-}
expected_project_count=75
expected_test_count=72
project_count=0
test_count=0

if ! command -v "$compiler" >/dev/null 2>&1; then
    printf 'Compiler not found: %s\n' "$compiler" >&2
    exit 1
fi

printf 'Compiler: %s\n' "$compiler"
"$compiler" --version | sed -n '1p'
printf 'Compiler flags: %s\n' "$strict_flags"
printf 'Linker flags: %s\n\n' "$linker_flags"

while IFS= read -r -d '' makefile
do
    project_directory=${makefile%/Makefile}
    relative_directory=${project_directory#"$repository_root/"}
    project_count=$((project_count + 1))

    printf '[build] %s\n' "$relative_directory"
    make --no-print-directory -s -C "$project_directory" clean
    make --no-print-directory -s -C "$project_directory" \
        CC="$compiler" CFLAGS="$strict_flags" \
            LDFLAGS="$linker_flags" LDLIBS="$libraries"

    if grep -Eq '^[[:space:]]*starter[[:space:]]*:' "$makefile"
    then
        printf '[starter] %s\n' "$relative_directory"
        make --no-print-directory -s -C "$project_directory" starter \
            CC="$compiler" CFLAGS="$strict_flags" \
            LDFLAGS="$linker_flags" LDLIBS="$libraries"
    fi

    if grep -Eq '^[[:space:]]*test[[:space:]]*:' "$makefile"
    then
        printf '[test] %s\n' "$relative_directory"
        make --no-print-directory -s -C "$project_directory" test \
            CC="$compiler" CFLAGS="$strict_flags" \
            LDFLAGS="$linker_flags" LDLIBS="$libraries"
        test_count=$((test_count + 1))
    fi

    make --no-print-directory -s -C "$project_directory" clean
done < <(find "$repository_root/chapters" \
    "$repository_root/milestone-projects" \
    -type f -name Makefile -print0)

printf '\nValidated %d build directories and ran %d test targets.\n' \
    "$project_count" "$test_count"

if [ "$project_count" -ne "$expected_project_count" ]
then
    printf 'Expected %d build directories, found %d.\n' \
        "$expected_project_count" "$project_count" >&2
    exit 1
fi

if [ "$test_count" -ne "$expected_test_count" ]
then
    printf 'Expected %d test targets, found %d.\n' \
        "$expected_test_count" "$test_count" >&2
    exit 1
fi

printf 'Coverage baseline matched: %d build directories and %d test targets.\n' \
    "$expected_project_count" "$expected_test_count"
