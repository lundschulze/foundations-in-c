# Contributing

Thank you for helping improve the *Foundations in C* companion repository.

These guidelines define the workflow for reporting problems and proposing changes to the companion material.

## Before you start

- Read the README for the relevant chapter, example or milestone project.
- Check the [Getting Started](resources/getting-started.md), [Command Reference](resources/command-reference.md) and [Troubleshooting](resources/troubleshooting.md) guides.
- Search existing issues before opening a new report.
- Keep one issue or pull request focused on one problem.
- Do not submit the book manuscript, production files or unpublished publishing material.

Editorial changes that affect both the book and repository—such as chapter paths, terminology or the established Chapter 1 `hello.c` workflow—must be coordinated with the maintainer before implementation.

## Report a problem

Use the repository's **Bug report** issue form. A useful report includes:

- the exact chapter, example or milestone path;
- your operating system and terminal environment;
- compiler and Make versions;
- the exact command that failed;
- minimal input needed to reproduce the problem;
- expected and actual behaviour;
- the first complete error message;
- whether GCC, Clang and GitHub Actions behave differently.

Prefer text logs over screenshots because text is searchable and accessible. Reduce logs to the relevant section, but do not remove the first error.

Never include:

- passwords, tokens, private keys or environment files;
- manuscript pages or unpublished excerpts;
- production PDFs, archives or backups;
- personal or confidential test data.

If a log contains sensitive information, redact it before submitting. If a credential may have been exposed, rotate it immediately rather than relying only on redaction.

## Set up a local contribution

Clone the repository and enter it:

```bash
git clone https://github.com/lundschulze/foundations-in-c.git
cd foundations-in-c
```

Create a short branch from an up-to-date `main`:

```bash
git switch main
git pull --ff-only
git switch -c fix/short-description
```

Use a descriptive branch prefix such as `fix/`, `docs/`, `test/` or `feat/`.

## Make a focused change

Follow the surrounding style and preserve the repository's teaching progression.

For C code:

- target C17;
- favour clear, explicit code over clever shortcuts;
- compile without warnings under GCC and Clang;
- validate input where the example's learning goal requires it;
- preserve ownership and cleanup rules for allocated resources;
- avoid platform-specific extensions unless the example documents them;
- add or update a focused test when behaviour changes.

For documentation:

- use British English;
- keep commands executable as written;
- distinguish source filenames, executable names and terminal commands clearly;
- update indexes when adding, removing or renaming paths;
- do not promise material that is not present;
- preserve the boundary between companion resources and private publishing files.

## Build and test

Test the changed example first:

```bash
make clean
make
make test
```

A directory may not provide `make test` when no separate executable test is appropriate.

Then run the repository-wide checks from the root:

```bash
CC=gcc ./scripts/test-all.sh
CC=clang ./scripts/test-all.sh
./scripts/test-sanitizers.sh
./scripts/check-markdown-links.py
./scripts/check-british-english.py
```

Every command must pass before a pull request is ready for review. GitHub Actions repeats these checks on the pushed commit.

## Review your files

Before committing:

```bash
git status
git diff
git diff --check
```

Stage named files rather than everything in the working tree:

```bash
git add path/to/file
git diff --staged
```

Confirm that the staged change contains no generated executable, object file, local editor setting, credential or private publishing material. The `.gitignore` helps, but it is not a substitute for reviewing the staged diff.

## Commit messages

Use a short, imperative summary with an appropriate prefix:

```text
fix: validate empty catalogue input
docs: clarify the Chapter 8 loop example
test: cover the upper journey-cost boundary
chore: update repository maintenance notes
```

Keep unrelated changes in separate commits.

## Pull requests

A pull request should explain:

- what changed;
- why the change is needed;
- which chapter, example or resource it affects;
- how it was tested;
- whether reader-visible paths, commands or output changed;
- whether a matching manuscript update is required.

Before requesting review, confirm that:

- [ ] the change is focused and understandable;
- [ ] new and changed C code builds as C17;
- [ ] GCC, Clang and sanitizer checks pass;
- [ ] relevant tests cover the change;
- [ ] reader-facing documentation is updated;
- [ ] filenames and links use the correct capitalisation;
- [ ] no confidential or generated material is included;
- [ ] the staged diff has been reviewed.

A green workflow is required but does not guarantee acceptance. Teaching clarity, consistency with the book and publication rights also matter.

## Review expectations

Review may request changes for correctness, portability, teaching order, clarity, test coverage or publication safety. Maintainers may decline a technically correct change when it conflicts with the book's learning progression or final editorial plan.

Do not rewrite history on a shared branch without coordinating with its collaborators.

## Licensing

The repository's final licence has not yet been selected. Until licensing terms are published, do not assume that submitting code automatically grants a particular reuse licence. Public contributions should not be accepted until the contribution and licensing terms are explicit.
