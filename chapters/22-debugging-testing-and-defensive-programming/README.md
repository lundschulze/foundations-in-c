# Chapter 22 — Debugging, testing and defensive programming

This chapter builds evidence in layers: warnings, focused tests, boundaries, complete input validation, diagnostics and sanitizers.

## Examples

- [`clamp-tests`](examples/clamp-tests) — turn range expectations into assertions.
- [`parse-integer`](examples/parse-integer) — reject empty input, overflow and valid-looking prefixes.

## Exercise

- [`output-channels`](exercises/output-channels) — keep stdout, stderr and exit status distinct.
