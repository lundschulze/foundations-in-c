# Release Readiness Checklist

This maintainer checklist must be completed before *Foundations in C* companion repository is made public.

> **Keep the repository private until every blocking item is complete.** A green build confirms that the code works; it does not by itself confirm that the repository is legally, editorially or operationally ready for publication.

## Current verified baseline

Verified against `main` on 13 September 2026:

- [x] The repository is private.
- [x] All 23 chapter directories are present.
- [x] Three independent milestone projects are present.
- [x] Repository-wide GCC, Clang and sanitizer jobs pass.
- [x] Getting Started, Command Reference and Troubleshooting guides are present.
- [x] The current Git tree contains no PDF, Word, EPUB, archive, private-key or named manuscript/backup/publishing paths.
- [x] `.gitignore` excludes common build products, private publishing formats, environment files, keys and backup directories.
- [x] The README states that the manuscript and private publishing files are outside this repository.
- [x] The repository declares C17 consistently in its learner and strict validation workflows.
- [x] A separate GitHub Actions hygiene job rejects forbidden current-tree paths, formats, key headers and compiled executables.
- [x] Contribution guidance and a structured bug-report form are present.
- [x] A read-only [Git History Audit](HISTORY_AUDIT.md) records all history reachable from the 13 September 2026 baseline.
- [x] A separate Gitleaks workflow scans full fetched history with a pinned version and verified archive digest.
- [x] A separate documentation job validates internal Markdown links and heading anchors.
- [x] GitHub Actions dependencies are pinned to reviewed immutable identifiers.
- [x] Dependabot checks GitHub Actions dependencies weekly.
- [x] A pull-request template, CODEOWNERS file, EditorConfig and Git attributes are present.
- [x] An automated source-archive rehearsal verifies the tracked file list, Chapter 1 output, Chapter 23 tests and post-build cleanup.
- [x] A read-only starter/answer audit covers all 24 supplied starting points and records why no complete solution is exposed.
- [x] A current-tree sample-data audit covers all 380 tracked files and finds no personal or confidential data patterns.

These checks describe the current tree only. They do not replace the history, rights and release checks below.

## Technical completion boundary

Routine repository engineering is considered complete when the verified baseline above is green. Do not add further workflows, scripts or maintenance documents unless they fix a demonstrated defect, support a final-manuscript change or close a specific release blocker.

The remaining unchecked items deliberately belong to one of three later gates:

1. **Editorial gate:** compare the final manuscript with paths, commands and expected output.
2. **Rights gate:** approve licences, ownership, attribution and thematic references.
3. **Publication gate:** choose the contribution model and support policy, create the exact release candidate, repeat time-sensitive audits and approve public visibility.

A release-candidate check must be repeated after the final editorial or legal change. Earlier green runs are evidence of the private baseline, not approval to publish.


## Blocking editorial checks

- [ ] Compare the final book table of contents with all 23 directory names and chapter indexes.
- [ ] Compare every example path, executable name, command and expected output quoted in the final manuscript with the repository.
- [x] Use the traditional Chapter 1 `hello.c` programme and the `make hello` workflow (confirmed by the author on 15 September 2026).
- [x] Confirm that the Chapter 1 source filename, directory README, chapter index, root README and repository tests consistently use `hello.c`.
- [x] Confirm through the [Starter Separation Audit](STARTER_AUDIT.md) that starting files provide scaffolding without revealing complete exercise solutions.
- [x] Review all reader-facing Markdown for British spelling and terminology, and enforce unambiguous variants with `scripts/check-british-english.py`.
- [x] Verify that every example README explains its purpose, build command, run or test workflow, expected behaviour and any required input.
- [x] Confirm that each milestone project has a clear brief, starter path, manual acceptance scenarios and self-review instructions.
- [x] Confirm that the deliberate absence of completed milestone solutions and automated answer checkers is explained to readers.
- [x] Confirm through the [Sample Data and Privacy Audit](DATA_AUDIT.md) that tracked examples and tests use fictional data without identified personal or confidential information.

## Blocking rights and licence checks

- [x] License source code, headers, tests, scripts, Makefiles and workflow configuration under the MIT License.
- [x] License explanatory Markdown documentation separately under CC BY 4.0.
- [x] Add the final `LICENSE` and `LICENSE-DOCUMENTATION.md` files.
- [x] Replace the provisional Licence section in the root README with the exact scope and links.
- [ ] Confirm that Filip L. Schulze or the relevant rights holder may publish every included source file, test, data file and text passage.
- [ ] Review any adapted algorithms, quotations, names, datasets or third-party assets and record their source and licence.
- [x] Replace the recurring borrowed thematic names, destinations and phrases identified in the earlier data audit; retain only the approved isolated `towel` example in Chapter 4.
- [ ] Add attribution and notices wherever a third-party licence requires them.
- [ ] Confirm that the book title, author name and repository description match the final publishing agreement.

Do not guess the licence. Obtain publishing or legal advice if ownership or reuse rights are uncertain.

## Blocking privacy and security checks

- [x] Record a read-only tree, path and blob-content audit through baseline commit `b58bef22fabd5e00fb972a91663c8b85c8a412da`.
- [ ] Repeat the complete Git-history audit on the approved release candidate.
- [x] Gitleaks 8.30.1 scans the complete fetched history on every push and pull request; the official release archive is SHA-256 verified and findings are redacted.
- [ ] Review `git log --all --stat` and the complete object list again immediately before changing repository visibility.
- [x] Confirm that no issue, pull request or stored Actions artifact existed at the audit baseline.
- [ ] Confirm that no later issue, pull request, Actions log or artifact contains confidential publishing material.
- [ ] Confirm that no later GitHub Actions artifact exposes files excluded from the repository.
- [ ] Review repository variables, environments and Actions permissions; keep workflow permissions at the minimum required level.
- [ ] Confirm that no access token, password, private key or personal e-mail address is embedded in files or commit metadata where it should not be public.
- [ ] Rotate any credential immediately if there is evidence that it was committed, even if the commit was later deleted.
- [ ] Recheck `.gitignore` against the actual publishing workflow and local backup filenames.
- [ ] Keep private account administration and temporary-account decisions outside public repository documentation.

A file removed from the latest commit may still exist in Git history. Changing visibility exposes reachable history, so a current-tree scan is necessary but not sufficient.

## Blocking code and test checks

- [ ] Run the complete validation from a fresh clone:

  ```bash
  ./scripts/test-all.sh
  ./scripts/test-sanitizers.sh
  ```

- [ ] Confirm that GitHub Actions passes with GCC, Clang and sanitizers on the exact intended release commit.
- [x] Enforce the reviewed baseline of 75 build directories and 72 test targets in `scripts/test-all.sh`; any change now requires an explicit baseline update.
- [ ] Run representative interactive programmes manually, including valid, invalid, empty and boundary input.
- [ ] Check file-reading and file-writing examples from a clean working directory.
- [ ] Check every allocation and cleanup path exercised by the dynamic-memory chapters.
- [ ] Confirm that tests leave no generated executables, object files, logs or temporary data tracked by Git.
- [ ] Verify that `make clean` succeeds in every build directory.
- [ ] Test the documented first-use flow on macOS, MSYS2 UCRT64 and Linux, or record any platform that remains unverified.
- [ ] Confirm that commands and Makefiles do not depend on files available only on the maintainer's computer.

## Blocking documentation and navigation checks

- [x] GitHub Actions validates relative targets and heading anchors across every tracked Markdown file.
- [x] Check every external link against its current official destination (reviewed 13 September 2026).
- [x] Validate Markdown headings, anchors, code fences and table column structure automatically.
- [ ] Perform one final visual rendering check on GitHub for the root README, chapter index, milestone index and maintainer checklists.
- [x] Confirm that the root README accurately describes the current private-development contents.
- [x] Remove future-tense placeholders that are no longer true.
- [x] Ensure requirements and platform limitations are stated before the first build command.
- [ ] Verify that iPad and Codespaces guidance reflects the organisation's final Codespaces policy.
- [x] A structured bug-report form collects reproducible diagnostics and warns against private uploads.
- [x] `CONTRIBUTING.md` defines reporting, testing and publication-safety requirements.
- [ ] Add `SECURITY.md` if a private vulnerability-reporting route is required.
- [ ] Add a code of conduct only if community participation is invited and it can be maintained.

## Repository settings

Current private settings snapshot, reviewed 13 September 2026:

- visibility is private and `main` is the default branch;
- Issues and Projects are enabled;
- Wiki and Discussions are disabled;
- merge commits, squash merges and rebases are allowed;
- auto-merge and automatic branch deletion are disabled;
- repository topics are empty;
- the public description is still provisional;
- repository rulesets are unavailable on the current plan while the repository remains private; reconsider them at the publication gate or after a plan change.


- [x] `main` is confirmed as the default branch.
- [ ] Decide whether direct pushes to `main` should be replaced with pull requests.
- [ ] Configure branch rules or a repository ruleset appropriate to the chosen workflow.
- [ ] Require the GCC, Clang and sanitizer checks before merging, if pull requests are used.
- [x] Current workflows use read-only repository permissions; `actions/checkout` is pinned to the reviewed v7.0.1 commit, and the Gitleaks release archive is version- and digest-pinned.
- [ ] Review collaborator, team and GitHub App access before publication.
- [ ] Review organisation-level Codespaces access separately; it is not controlled by repository files.
- [ ] Enable GitHub security features appropriate to a public C repository.
- [ ] Confirm that Issues and Discussions are enabled only if they will be monitored.
- [ ] Add repository topics and a final public description.
- [ ] Confirm that the organisation owns and displays the repository as intended.

## Release rehearsal

- [ ] Create a release candidate commit without changing repository visibility.
- [ ] Record its full commit SHA.
- [ ] Wait for every required GitHub Actions job to complete successfully.
- [ ] Download or create a source archive from the release candidate.
- [ ] Inspect the archive as a reader would receive it.
- [ ] Build the first example and at least one multi-file project from the extracted archive.
- [ ] Confirm that ignored local files did not become hidden runtime dependencies.
- [ ] Verify that the archive contains no generated executables or private material.
- [ ] Ask a fresh reviewer to follow Getting Started without unpublished instructions.
- [ ] Correct every blocking finding and create a new release candidate if any file changes.

A useful local archive rehearsal is:

```bash
git archive --format=tar.gz --output=foundations-in-c-release-candidate.tar.gz HEAD
```

Create the archive outside the repository or remove it afterwards. Archive files are intentionally ignored and must not be committed.

## Publication decision

Complete this section only after every blocking check above is finished.

- [ ] Record who approved the public release and when.
- [ ] Record the approved release commit SHA.
- [ ] Confirm the selected licence one final time.
- [ ] Confirm that the release commit has green required checks.
- [ ] Confirm that the complete reachable history is safe to expose.
- [ ] Change repository visibility only from the approved organisation and repository settings.
- [ ] Immediately inspect the repository while signed out or in a private browser window.
- [ ] Verify README rendering, licence detection, Actions visibility, links and downloadable source.
- [ ] Create the first version tag and release notes if versioned releases are part of the plan.

## After publication

- [ ] Monitor the first public Actions run.
- [ ] Test cloning without private-repository credentials.
- [ ] Recheck the documented `git clone`, `make` and test commands.
- [ ] Triage the first reader reports against the Troubleshooting guide.
- [ ] Record future manuscript-to-repository changes so paths and output remain synchronised.
- [ ] Repeat the privacy, rights, documentation and validation checks for every substantial release.

## Stop conditions

Do not publish if any of these statements is true:

- the licence or rights are unresolved;
- the final manuscript and repository paths have not been compared;
- a secret or private file may exist in reachable history;
- required tests are failing or still running;
- the release candidate has changed since approval;
- the maintainer is relying on ignored local files;
- the public support and maintenance expectations are unclear.
