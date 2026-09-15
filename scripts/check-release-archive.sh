#!/usr/bin/env bash

set -eu

repository_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
compiler=${CC:-cc}
strict_flags=${CFLAGS:--std=c17 -Wall -Wextra -Wpedantic -Werror}
temporary_parent=${TMPDIR:-/tmp}
work_directory=$(mktemp -d "$temporary_parent/foundations-in-c-release.XXXXXX")

cleanup()
{
    case "$work_directory" in
        "$temporary_parent"/foundations-in-c-release.*)
            rm -rf -- "$work_directory"
            ;;
        *)
            printf 'Refusing to remove unexpected temporary path: %s\n' \
                "$work_directory" >&2
            return 1
            ;;
    esac
}

trap cleanup EXIT HUP INT TERM

for command_name in git tar make cmp find sort sed "$compiler"
do
    if ! command -v "$command_name" >/dev/null 2>&1
    then
        printf 'Required command not found: %s\n' "$command_name" >&2
        exit 1
    fi
done

"$repository_root/scripts/check-repository-hygiene.sh"

archive_path="$work_directory/foundations-in-c.tar.gz"
extract_directory="$work_directory/extracted"
release_root="$extract_directory/foundations-in-c"
expected_files="$work_directory/expected-files.txt"
archive_files="$work_directory/archive-files.txt"
final_files="$work_directory/final-files.txt"
actual_output="$work_directory/answer-output.txt"

mkdir -p "$extract_directory"

git -C "$repository_root" archive \
    --format=tar.gz \
    --prefix=foundations-in-c/ \
    --output="$archive_path" \
    HEAD

tar -xzf "$archive_path" -C "$extract_directory"

git -C "$repository_root" ls-files | LC_ALL=C sort > "$expected_files"
(
    cd "$release_root"
    find . -type f -print | sed 's#^\./##' | LC_ALL=C sort
) > "$archive_files"

if ! cmp -s "$expected_files" "$archive_files"
then
    printf 'Release archive file list differs from the tracked Git file list.\n' >&2
    diff -u "$expected_files" "$archive_files" >&2 || true
    exit 1
fi

hello_directory="$release_root/chapters/01-before-the-first-line/hello"
make --no-print-directory -s -C "$hello_directory" clean
make --no-print-directory -s -C "$hello_directory" hello \
    CC="$compiler" CFLAGS="$strict_flags"
"$hello_directory/hello" > "$actual_output"
cmp "$hello_directory/expected.txt" "$actual_output"
make --no-print-directory -s -C "$hello_directory" clean

database_directory="$release_root/chapters/23-the-traveller-database"
make --no-print-directory -s -C "$database_directory" clean
make --no-print-directory -s -C "$database_directory" test \
    CC="$compiler" CFLAGS="$strict_flags"
make --no-print-directory -s -C "$database_directory" clean

(
    cd "$release_root"
    find . -type f -print | sed 's#^\./##' | LC_ALL=C sort
) > "$final_files"

if ! cmp -s "$expected_files" "$final_files"
then
    printf 'Build or test files remain in the extracted release archive.\n' >&2
    diff -u "$expected_files" "$final_files" >&2 || true
    exit 1
fi

printf 'Release archive rehearsal passed with %s.\n' "$compiler"
printf 'Verified the tracked file list, Chapter 1 output and Chapter 23 tests.\n'
