# Git History Audit

This document records the history boundary for the *Foundations in C* companion repository.

## Release-candidate boundary

The repository was created from the approved, tested companion tree on 15 September 2026. Its public-candidate history begins with the root commit containing this document; private development history was deliberately not transferred.

The source tree was checked before the root commit was created:

- all tracked paths and regular-file contents were enumerated;
- no manuscript, publishing, backup or generated release files were included;
- no compiled executables, object files, private keys or credential containers were included;
- the current-tree sample-data and repository-hygiene checks passed;
- the complete C17 build and test suite passed in a fresh clone;
- the address and undefined-behaviour sanitizer suite passed in the same fresh clone.

## Required publication check

Before repository visibility changes, repeat the full-history secret scan and inspect every reachable branch and tag. Confirm that the release-candidate commit and its GitHub Actions runs match the approved source tree.

This audit is evidence of the clean-history boundary. Licensing, ownership, editorial approval and the final publication decision remain separate release gates.
