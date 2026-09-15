#!/usr/bin/env python3
"""Validate structural Markdown conventions used by the repository."""

from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

repository_root = Path(__file__).resolve().parent.parent
result = subprocess.run(
    ["git", "-C", str(repository_root), "ls-files", "-z", "--", "*.md"],
    check=True,
    capture_output=True,
)
paths = [Path(item.decode()) for item in result.stdout.split(b"\0") if item]
delimiter_pattern = re.compile(
    r"^\s*\|?\s*:?-{3,}:?\s*(\|\s*:?-{3,}:?\s*)+\|?\s*$"
)
fence_pattern = re.compile(r"^\s*(`{3,}|~{3,})")
heading_pattern = re.compile(r"^(#{1,6})\s+\S")
h1_optional = {Path(".github/pull_request_template.md")}
failures: list[str] = []
heading_count = 0
table_count = 0
table_row_count = 0


def cell_count(line: str) -> int:
    separators = 0
    escaped = False
    in_code = False

    for character in line:
        if escaped:
            escaped = False
            continue
        if character == "\\":
            escaped = True
            continue
        if character == "`":
            in_code = not in_code
            continue
        if character == "|" and not in_code:
            separators += 1

    stripped = line.strip()
    return separators - int(stripped.startswith("|")) - int(stripped.endswith("|")) + 1


for relative_path in paths:
    lines = (repository_root / relative_path).read_text(encoding="utf-8").splitlines()
    fence_character: str | None = None
    previous_heading_level = 0
    h1_count = 0
    line_index = 0

    while line_index < len(lines):
        line = lines[line_index]
        fence_match = fence_pattern.match(line)

        if fence_match:
            marker = fence_match.group(1)
            if fence_character is None:
                fence_character = marker[0]
            elif marker[0] == fence_character:
                fence_character = None
            line_index += 1
            continue

        if fence_character is not None:
            line_index += 1
            continue

        heading_match = heading_pattern.match(line)
        if heading_match:
            level = len(heading_match.group(1))
            heading_count += 1
            if level == 1:
                h1_count += 1
            if previous_heading_level and level > previous_heading_level + 1:
                failures.append(
                    f"{relative_path}:{line_index + 1}: "
                    f"heading jumps from H{previous_heading_level} to H{level}"
                )
            previous_heading_level = level

        if (
            line_index + 1 < len(lines)
            and "|" in line
            and delimiter_pattern.match(lines[line_index + 1])
        ):
            table_count += 1
            expected_cells = cell_count(line)
            delimiter_cells = cell_count(lines[line_index + 1])

            if expected_cells != delimiter_cells:
                failures.append(
                    f"{relative_path}:{line_index + 2}: table delimiter has "
                    f"{delimiter_cells} cells; header has {expected_cells}"
                )

            row_index = line_index + 2
            while (
                row_index < len(lines)
                and lines[row_index].strip()
                and "|" in lines[row_index]
            ):
                table_row_count += 1
                row_cells = cell_count(lines[row_index])
                if row_cells != expected_cells:
                    failures.append(
                        f"{relative_path}:{row_index + 1}: table row has "
                        f"{row_cells} cells; expected {expected_cells}"
                    )
                row_index += 1

        line_index += 1

    if fence_character is not None:
        failures.append(f"{relative_path}: unclosed fenced code block")

    expected_h1_count = 0 if relative_path in h1_optional else 1
    if h1_count != expected_h1_count:
        failures.append(
            f"{relative_path}: expected {expected_h1_count} H1 heading(s), "
            f"found {h1_count}"
        )

if failures:
    print("Markdown structure check found problems:", file=sys.stderr)
    for failure in failures:
        print(f"  {failure}", file=sys.stderr)
    sys.exit(1)

print(
    f"Markdown structure check passed for {len(paths)} files, "
    f"{heading_count} headings, {table_count} tables and "
    f"{table_row_count} table rows."
)
