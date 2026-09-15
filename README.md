# Foundations in C

Companion code and learning resources for *Foundations in C: A Practical Path from First Programme to Modular Systems* by **Filip L. Schulze**.

> **Release status:** Companion examples and exercises are available for all 23 C17 chapters. Automated GCC, Clang, sanitizer, repository-hygiene and full-history secret validation is active. Three independent milestone projects and the Getting Started, Command Reference and Troubleshooting guides are included.

## About the book

*Foundations in C* is a practical, beginner-friendly introduction to programming with C17. Across 23 chapters, the book develops the language step by step—from compiling a first programme and working with values, decisions and loops to functions, arrays, strings, pointers, dynamic memory and larger modular programmes.

The examples favour clear reasoning, explicit code and good habits that transfer to later study of C++ and other programming languages.

## What this repository contains

- Runnable examples matching all 23 chapters
- Exercise starter files and completed answer programmes
- Small, local Makefiles for a consistent learner workflow
- Focused tests for boundaries, input validation, resource handling and the final project
- The multi-file Traveller Database from Chapter 23
- A cross-platform [Getting Started guide](resources/getting-started.md)
- A concise [Command Reference](resources/command-reference.md)
- A diagnostic [Troubleshooting guide](resources/troubleshooting.md)

The three independent projects in `milestone-projects/` deliberately provide open-ended briefs and starter code rather than official solutions.

The repository mirrors the paths used in the book, so readers do not need to reorganise downloaded files.

## Repository structure

```text
foundations-in-c/
├── chapters/
│   ├── 01-before-the-first-line/
│   ├── 02-a-c-programme-one-line-at-a-time/
│   ├── ...
│   └── 23-the-traveller-database/
├── milestone-projects/
├── resources/
├── scripts/
├── tests/
└── README.md
```

See the [chapter index](chapters/README.md) for all 23 chapter directories.

## Requirements

You will need:

- A compiler with C17 support
- GNU Make or a compatible `make` implementation
- A terminal and a plain-text code editor such as Visual Studio Code

Recommended platforms:

- **macOS:** Clang supplied with Apple's Command Line Tools
- **Windows:** GCC through MSYS2 UCRT64
- **Linux:** GCC or Clang supplied by the distribution

See [Getting Started](resources/getting-started.md) for installation and first-use instructions.

## Building the first example

From the repository root, build and run the `hello` programme from Chapter 1:

```bash
cd chapters/01-before-the-first-line/hello
make hello
./hello
```

The expected output is:

```text
Hello, world!
```

Exercise directories normally provide separate starter and completed-answer targets:

```bash
make starter
./starter
make answer
./answer
```

Read the README in an individual example or exercise directory for its exact targets. Running `make` builds the default target shown in that directory.

Examples are compiled explicitly as C17 with useful warnings enabled:

```text
-std=c17 -Wall -Wextra -Wpedantic
```

Strict validation additionally treats warnings as errors with `-Werror`.

## Tests

Focused test targets are included where a chapter benefits from executable checks. Run every build and available test target from the repository root:

```bash
./scripts/test-all.sh
```

The command uses strict C17 flags including `-Werror`. GitHub Actions runs the same validation automatically with both GCC and Clang after pushes and for pull requests. It can also be started manually from the repository's **Actions** tab.

## Contributing

Before opening an issue or pull request, see [CONTRIBUTING.md](CONTRIBUTING.md) for reporting, coding, testing and publication-safety requirements.

## Release preparation

Maintainers should complete the [Release Readiness Checklist](RELEASE_CHECKLIST.md) before changing repository visibility. The checklist covers editorial consistency, licensing, rights, complete-history privacy review, validation and release rehearsal. The latest read-only reviews are recorded in the [Git History Audit](HISTORY_AUDIT.md), [Starter Separation Audit](STARTER_AUDIT.md) and [Sample Data and Privacy Audit](DATA_AUDIT.md).

## Publication boundaries

This is a companion-code repository. It does not contain the complete manuscript, print-layout sources, production PDFs, private backups or other confidential publishing material.

## Author

**Filip L. Schulze**

## Licence

Source code, headers, tests, scripts, Makefiles and workflow configuration are
available under the [MIT License](LICENSE). Explanatory Markdown documentation
is available under the [Creative Commons Attribution 4.0 International
licence](LICENSE-DOCUMENTATION.md).

The book manuscript and production files are not part of this repository and
remain all rights reserved.
