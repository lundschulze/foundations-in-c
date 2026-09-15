# Tests

Focused tests live beside the examples and exercises they verify. A directory that provides a `test` target is executed automatically by the repository-wide test script.

Run the complete validation from the repository root:

```bash
./scripts/test-all.sh
```

The script compiles every chapter directory with strict C17 warnings and runs all available test targets. GitHub Actions runs the same command with both GCC and Clang.

This top-level directory is reserved for future checks that span several chapters or milestone projects.

## Output-test coverage

Chapters 1–5 include exact-output fixtures. Each participating directory runs its programme, captures stdout in the ignored `test-results/` directory and compares it with `expected.txt` using `diff`.

Chapters 6–10 add scenario tests for interactive input, conversion failures, inclusive boundaries, loops and function results. The chapter-local `test.sh` files use the shared scenario-test helper.

Chapters 11–15 test automatic and static storage, array traversal, string input, structures and enumerations. Memory-address examples use output patterns rather than fixed addresses or object sizes, because those values may legitimately differ between systems.

Chapters 16–20 test pointer-based mutation and traversal, successful dynamic-memory lifecycles, capacity checks, defensive ownership and file round trips. File tests create controlled fixtures locally, verify their contents and remove every temporary file before finishing.

Chapters 21–23 complete the chapter coverage with multi-file module assertions, exact parsing and output-channel checks, and an end-to-end database round trip. The tests also verify that every temporary database fixture is removed.
