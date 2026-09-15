#!/usr/bin/env python3

"""Validate repository-internal links and heading anchors in tracked Markdown."""

from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path
from urllib.parse import unquote, urlsplit

INLINE_LINK = re.compile(r"!?(?:\[[^\]]*\])\(([^)]+)\)")
REFERENCE_TARGET = re.compile(r"^\s*\[[^\]]+\]:\s*(\S+)")
HEADING = re.compile(r"^\s{0,3}#{1,6}\s+(.+?)\s*#*\s*$")
INLINE_CODE = re.compile(chr(96) + r"[^" + chr(96) + r"]*" + chr(96))
HTML_TAG = re.compile(r"<[^>]+>")
MARKDOWN_LINK_TEXT = re.compile(r"!?\[([^\]]*)\]\([^)]+\)")
WHITESPACE = re.compile(r"\s+")


def tracked_markdown(repository_root: Path) -> list[Path]:
    result = subprocess.run(
        ["git", "-C", str(repository_root), "ls-files", "-z", "*.md"],
        check=True,
        capture_output=True,
    )
    paths = result.stdout.decode("utf-8").split("\0")
    return [repository_root / path for path in paths if path]


def visible_markdown_lines(path: Path):
    fence = None
    backtick_fence = chr(96) * 3

    for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        stripped = line.lstrip()

        if fence is not None:
            if stripped.startswith(fence):
                fence = None
            continue

        if stripped.startswith(backtick_fence):
            fence = backtick_fence
            continue

        if stripped.startswith("~~~"):
            fence = "~~~"
            continue

        yield number, line


def github_slug(text: str) -> str:
    text = MARKDOWN_LINK_TEXT.sub(r"\1", text)
    text = HTML_TAG.sub("", text)
    text = text.replace(chr(96), "").lower()
    text = text.replace("&amp;", "and")

    characters = []
    for character in text:
        if character.isalnum() or character in {" ", "-", "_"}:
            characters.append(character)

    return WHITESPACE.sub("-", "".join(characters).strip())


def heading_anchors(path: Path) -> set[str]:
    anchors: set[str] = set()
    occurrences: dict[str, int] = {}

    for _, line in visible_markdown_lines(path):
        match = HEADING.match(line)
        if match is None:
            continue

        base = github_slug(match.group(1))
        if not base:
            continue

        occurrence = occurrences.get(base, 0)
        anchor = base if occurrence == 0 else f"{base}-{occurrence}"
        occurrences[base] = occurrence + 1
        anchors.add(anchor)

    return anchors


def link_target(raw_target: str) -> str:
    target = raw_target.strip()

    if target.startswith("<") and ">" in target:
        return target[1 : target.index(">")]

    return target.split(maxsplit=1)[0] if target else ""


def is_external(target: str) -> bool:
    if target.startswith("//"):
        return True

    scheme = urlsplit(target).scheme.lower()
    return bool(scheme)


def main() -> int:
    repository_root = Path(__file__).resolve().parent.parent
    markdown_files = tracked_markdown(repository_root)
    anchor_cache: dict[Path, set[str]] = {}
    errors: list[str] = []
    link_count = 0

    for source in markdown_files:
        source_relative = source.relative_to(repository_root)

        for line_number, line in visible_markdown_lines(source):
            searchable = INLINE_CODE.sub("", line)
            raw_targets = [match.group(1) for match in INLINE_LINK.finditer(searchable)]

            reference = REFERENCE_TARGET.match(searchable)
            if reference is not None:
                raw_targets.append(reference.group(1))

            for raw_target in raw_targets:
                target = link_target(raw_target)
                if not target or is_external(target):
                    continue

                link_count += 1
                parsed = urlsplit(target)
                relative_path = unquote(parsed.path)
                fragment = unquote(parsed.fragment).lower()

                if relative_path:
                    if relative_path.startswith("/"):
                        destination = repository_root / relative_path.lstrip("/")
                    else:
                        destination = source.parent / relative_path
                else:
                    destination = source

                destination = destination.resolve()

                try:
                    destination.relative_to(repository_root)
                except ValueError:
                    errors.append(
                        f"{source_relative}:{line_number}: link leaves repository: {target}"
                    )
                    continue

                if not destination.exists():
                    errors.append(
                        f"{source_relative}:{line_number}: target does not exist: {target}"
                    )
                    continue

                if fragment:
                    anchor_file = destination
                    if destination.is_dir():
                        anchor_file = destination / "README.md"

                    if anchor_file.suffix.lower() != ".md" or not anchor_file.is_file():
                        errors.append(
                            f"{source_relative}:{line_number}: anchor target is not Markdown: {target}"
                        )
                        continue

                    anchors = anchor_cache.setdefault(
                        anchor_file, heading_anchors(anchor_file)
                    )
                    if fragment not in anchors:
                        errors.append(
                            f"{source_relative}:{line_number}: heading anchor does not exist: {target}"
                        )

    if errors:
        for error in errors:
            print(f"Markdown link failure: {error}", file=sys.stderr)

        print(
            f"\nFound {len(errors)} broken internal link(s) "
            f"across {len(markdown_files)} tracked Markdown files.",
            file=sys.stderr,
        )
        return 1

    print(
        f"Validated {link_count} internal link(s) "
        f"across {len(markdown_files)} tracked Markdown files."
    )
    print("External URLs were not requested and were not checked.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
