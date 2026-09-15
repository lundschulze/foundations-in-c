# Scripts

Repository-wide maintenance and validation tools live here.

## Check repository hygiene

From the repository root:

```bash
./scripts/check-repository-hygiene.sh
```

The script inspects files registered by Git and rejects private publishing paths, document and archive formats, environment files, key containers, build products, logs and recognised compiled executables. GitHub Actions runs it in a separate **Repository hygiene** job.

This is a current-tree guardrail. It does not inspect deleted files in Git history, provide high-entropy secret detection or replace a recognised full-history secret scanner before publication.

## Check British-English prose

From the repository root:

```bash
./scripts/check-british-english.py
```

The checker scans tracked Markdown prose while excluding fenced code, inline code and link destinations. It rejects a conservative list of unambiguous American spellings, including `program` in ordinary prose, and suggests the project's preferred British form. Official product terms such as GitHub Actions `artifact`, executable names and commands are not rewritten.

GitHub Actions runs this check alongside the internal Markdown-link validation. Human proofreading is still required for grammar, tone, punctuation and context-sensitive words.

## Check Markdown structure

From the repository root:

```bash
./scripts/check-markdown-structure.py
```

The checker validates that every reader-facing Markdown file has the expected top-level heading, heading levels do not jump, fenced code blocks are closed and every table has a consistent number of columns. The pull-request template is intentionally allowed to omit an H1 because GitHub inserts it into a larger form.

GitHub Actions runs this structural check in the documentation job. Relative links and heading anchors are checked separately by `check-markdown-links.py`.

## Check internal Markdown links

From the repository root:

```bash
./scripts/check-markdown-links.py
```

The script uses the Python 3 standard library to check every tracked Markdown file. It validates relative file and directory targets, heading anchors, filename capitalisation and repository boundaries. Fenced code examples, inline code and external URLs are excluded.

GitHub Actions runs the same validation in a separate **Internal Markdown links** job.

## Scan complete Git history for secrets

With Gitleaks installed, run:

```bash
./scripts/scan-secrets.sh
```

The script scans commits reachable in the locally fetched Git history and redacts detected values from its output. A shallow clone cannot provide a complete history scan.

GitHub Actions runs this check independently. The workflow:

1. checks out the complete reachable history with `fetch-depth: 0`;
2. downloads the official Gitleaks CLI version 8.30.1 for Linux x64;
3. verifies the release archive against its pinned SHA-256 digest;
4. scans the fetched Git history with redacted output.

The workflow uses the MIT-licensed Gitleaks CLI directly. It does not use the separately licensed Gitleaks GitHub Action for organisation repositories.

## Test every chapter

From the repository root:

```bash
./scripts/test-all.sh
```

The script:

1. finds every `Makefile` below `chapters/` and `milestone-projects/`;
2. cleans and builds its default target;
3. builds `starter` when that target exists;
4. runs `test` when that target exists;
5. cleans generated executables and object files afterwards.

The default compiler is `cc`. Select GCC or Clang with `CC`:

```bash
CC=gcc ./scripts/test-all.sh
CC=clang ./scripts/test-all.sh
```

The default validation flags are:

```text
-std=c17 -Wall -Wextra -Wpedantic -Werror
```

Milestone project starters receive compile validation but no automated behavioural assessment. The command stops at the first failed build or test and returns a non-zero exit status.

The script also enforces the reviewed coverage baseline of 75 build directories and 72 `test` targets. If either total changes, validation fails so that an accidental deletion cannot silently reduce coverage. Intentional additions or removals require the two expected totals near the top of `test-all.sh` to be reviewed and updated in the same change.

## Scenario-test helper

`scripts/test-helpers.sh` supplies `check_case` to chapter-local Bash tests. A case provides input, expected exit status and expected combined output. The helper reports the case name and stops at the first mismatch.

## Runtime sanitizers

Use Clang's AddressSanitizer and UndefinedBehaviorSanitizer across every chapter project:

```bash
./scripts/test-sanitizers.sh
```

This reuses the complete test suite with runtime instrumentation. AddressSanitizer detects problems such as out-of-bounds access, use-after-free and memory leaks. UndefinedBehaviorSanitizer stops on undefined operations that the compiler can diagnose at runtime. GitHub Actions runs this check independently of the normal GCC and Clang jobs.

`test-all.sh` forwards `CFLAGS`, `LDFLAGS` and `LDLIBS` to each Makefile, so compiler instrumentation is also linked into programmes built from multiple source files.

## Rehearse the source archive

From a Git working tree, run:

```bash
./scripts/check-release-archive.sh
```

The script creates a temporary `git archive`, extracts it and confirms that its regular-file list exactly matches the files tracked by Git. It then builds and checks the Chapter 1 `hello.c` programme, runs the Chapter 23 multi-file tests, cleans both projects and confirms that no generated files remain. Repository hygiene is checked before packaging, and the temporary archive is removed automatically.

GitHub Actions runs the same rehearsal after the repository-hygiene job. This is safe while the repository is private: the archive remains inside the temporary runner workspace and is not uploaded as an Actions artifact.
