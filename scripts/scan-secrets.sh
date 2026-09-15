#!/usr/bin/env bash

set -eu

repository_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)

if ! command -v gitleaks >/dev/null 2>&1
then
    printf 'Gitleaks is required. See scripts/README.md for installation guidance.\n' >&2
    exit 1
fi

if ! git -C "$repository_root" rev-parse --is-inside-work-tree >/dev/null 2>&1
then
    printf 'The repository Git history is unavailable.\n' >&2
    exit 1
fi

cd "$repository_root"

printf 'Gitleaks: '
gitleaks version
printf 'Scanning every commit reachable in the fetched Git history.\n'

exec gitleaks git --redact --no-banner --verbose
