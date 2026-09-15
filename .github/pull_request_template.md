## Summary

Describe the focused change and why it is needed.

## Affected material

- Chapter, example, milestone or resource path:
- Reader-visible filenames, commands or output changed:
- Matching manuscript update required:

## Validation

List the exact commands used, for example:

```bash
CC=gcc ./scripts/test-all.sh
CC=clang ./scripts/test-all.sh
./scripts/test-sanitizers.sh
./scripts/check-repository-hygiene.sh
./scripts/check-markdown-links.py
./scripts/scan-secrets.sh
```

## Checklist

- [ ] The change is focused and follows the surrounding teaching style.
- [ ] New or changed C code targets C17 and builds without warnings.
- [ ] Relevant tests cover the behaviour change.
- [ ] GCC, Clang and sanitizer checks pass.
- [ ] Reader-facing documentation and indexes are updated.
- [ ] Internal links and filename capitalisation are correct.
- [ ] Generated files and local editor settings are excluded.
- [ ] No manuscript, production PDF, backup or unpublished publishing material is included.
- [ ] No password, token, private key, environment file or personal test data is included.
- [ ] I reviewed the complete staged diff before submission.
