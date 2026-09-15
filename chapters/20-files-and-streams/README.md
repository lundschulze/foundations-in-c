# Chapter 20 — Files and streams

This chapter treats an open `FILE *` as an owned resource and checks opening, input/output and closing separately.

## Examples

- [`write-report`](examples/write-report) — create a disposable text report.
- [`read-report`](examples/read-report) — let `fgets` control a reading loop.

## Exercise

- [`round-trip`](exercises/round-trip) — write, close, reopen, display and remove a private practice log.

Use only disposable filenames while experimenting.
