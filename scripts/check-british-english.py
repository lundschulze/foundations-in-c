#!/usr/bin/env python3
"""Reject unambiguous American spellings in reader-facing Markdown prose."""

from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

REPLACEMENTS = {
    "analyze": "analyse",
    "analyzed": "analysed",
    "analyzer": "analyser",
    "analyzers": "analysers",
    "analyzes": "analyses",
    "analyzing": "analysing",
    "behavior": "behaviour",
    "behaviors": "behaviours",
    "canceled": "cancelled",
    "canceling": "cancelling",
    "center": "centre",
    "centers": "centres",
    "color": "colour",
    "colors": "colours",
    "gray": "grey",
    "initialize": "initialise",
    "initialized": "initialised",
    "initializes": "initialises",
    "initializing": "initialising",
    "labeled": "labelled",
    "labeling": "labelling",
    "modeled": "modelled",
    "modeling": "modelling",
    "organize": "organise",
    "organized": "organised",
    "organizes": "organises",
    "organizing": "organising",
    "program": "programme",
    "programs": "programmes",
    "traveled": "travelled",
    "traveler": "traveller",
    "travelers": "travellers",
    "traveling": "travelling",
}

repository_root = Path(__file__).resolve().parent.parent
result = subprocess.run(
    ["git", "-C", str(repository_root), "ls-files", "-z", "--", "*.md"],
    check=True,
    capture_output=True,
)
paths = [Path(item.decode()) for item in result.stdout.split(b"\0") if item]
pattern = re.compile(
    r"\b(" + "|".join(map(re.escape, REPLACEMENTS)) + r")\b",
    re.IGNORECASE,
)
inline_code = re.compile(r"`[^`]*`")
link_destination = re.compile(r"\]\([^)]*\)")
failures: list[str] = []

for relative_path in paths:
    full_path = repository_root / relative_path
    in_fence = False

    for line_number, line in enumerate(
        full_path.read_text(encoding="utf-8").splitlines(), start=1
    ):
        if re.match(r"^\s*(```|~~~)", line):
            in_fence = not in_fence
            continue
        if in_fence:
            continue

        prose = inline_code.sub("", line)
        prose = link_destination.sub("]", prose)

        for match in pattern.finditer(prose):
            word = match.group(0)
            suggestion = REPLACEMENTS[word.lower()]
            failures.append(
                f"{relative_path}:{line_number}: {word} -> {suggestion}"
            )

if failures:
    print("British-English prose check found American spellings:", file=sys.stderr)
    for failure in failures:
        print(f"  {failure}", file=sys.stderr)
    sys.exit(1)

print(f"British-English prose check passed for {len(paths)} Markdown files.")
