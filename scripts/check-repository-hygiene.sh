#!/usr/bin/env bash

set -eu

repository_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$repository_root"

failure_count=0
tracked_count=0
binary_signature_checks=0

report_failure()
{
    printf 'Repository hygiene failure: %s\n' "$1" >&2
    failure_count=$((failure_count + 1))
}

while IFS= read -r -d '' path
do
    tracked_count=$((tracked_count + 1))
    lower_path=$(printf '%s' "$path" | tr '[:upper:]' '[:lower:]')
    base_name=${lower_path##*/}

    case "/$lower_path/" in
        */private/*|*/manuscript/*|*/publishing/*|*/backups/*|*/dist/*)
            report_failure "private or generated directory is tracked: $path"
            ;;
        */build/*|*/bin/*|*/coverage/*|*/test-results/*|*/tmp/*|*/temp/*)
            report_failure "build or test-output directory is tracked: $path"
            ;;
        *".dsym/"*)
            report_failure "debug-symbol bundle is tracked: $path"
            ;;
    esac

    case "$base_name" in
        .ds_store|.appledouble|.lsoverride|thumbs.db|desktop.ini)
            report_failure "operating-system metadata is tracked: $path"
            ;;
        .env.example)
            ;;
        .env|.env.*)
            report_failure "environment file is tracked: $path"
            ;;
        answer|program)
            report_failure "common extensionless executable name is tracked: $path"
            ;;
    esac

    case "$lower_path" in
        *.o|*.obj|*.a|*.so|*.dylib|*.dll|*.exe|*.out)
            report_failure "compiled build product is tracked: $path"
            ;;
        *.gcda|*.gcno|*.gcov|*.log)
            report_failure "test, coverage or log output is tracked: $path"
            ;;
        *.pdf|*.doc|*.docx|*.pages|*.odt|*.epub|*.mobi|*.indd|*.afpub|*.webarchive)
            report_failure "private publishing or document format is tracked: $path"
            ;;
        *.zip|*.7z|*.rar|*.tar|*.tar.gz|*.tgz|*.tar.bz2|*.tbz2|*.tar.xz|*.txz|*.gz|*.bz2|*.xz|*.bak)
            report_failure "archive or backup format is tracked: $path"
            ;;
        *.pem|*.key|*.p12|*.pfx)
            report_failure "key or credential container is tracked: $path"
            ;;
    esac

    if test -f "$path" && grep -aEq -- '-----BEGIN ([A-Z0-9]+ )?PRIVATE KEY-----' "$path"
    then
        report_failure "private-key header appears in tracked file: $path"
    fi

    if command -v file >/dev/null 2>&1 && test -f "$path"
    then
        binary_signature_checks=$((binary_signature_checks + 1))
        file_description=$(file -b -- "$path")

        case "$file_description" in
            ELF*"executable"*|Mach-O*"executable"*|PE32*"executable"*)
                report_failure "compiled executable signature is tracked: $path"
                ;;
        esac
    fi
done < <(git ls-files -z)

if test "$tracked_count" -eq 0
then
    printf 'Repository hygiene failure: no tracked files were found.\n' >&2
    exit 1
fi

if test "$failure_count" -ne 0
then
    printf '\nRepository hygiene check found %d problem(s) in %d tracked files.\n'         "$failure_count" "$tracked_count" >&2
    exit 1
fi

printf 'Repository hygiene check passed for %d tracked files.\n' "$tracked_count"

if test "$binary_signature_checks" -eq 0
then
    printf 'Note: the file utility was unavailable; executable signature checks were skipped.\n'
else
    printf 'Inspected %d regular files for executable signatures.\n'         "$binary_signature_checks"
fi

printf 'This current-tree check does not replace full-history secret scanning.\n'
