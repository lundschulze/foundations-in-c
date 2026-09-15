# Sample Data and Privacy Audit

This read-only audit reviews the current companion repository for personal, confidential or environment-specific data.

## Scope

Reviewed all 380 tracked files on `main` at commit `0b29c370529b22a0a2059f74ac04839cfd4615fc` on 13 September 2026. The inspected UTF-8 content totalled 226,500 characters and included:

- C sources and headers;
- shell and Python test tools;
- expected-output and test-input text;
- Makefiles and workflow configuration;
- all Markdown documentation;
- repository maintenance files.

The separate [Git History Audit](HISTORY_AUDIT.md) and full-history Gitleaks workflow cover reachable history. This audit concentrates on the current tracked content and the meaning of its sample data.

## Automated pattern review

No current tracked file contains a match for:

- an e-mail-address pattern;
- a telephone-number pattern;
- an IPv4 address;
- a macOS, Linux or Windows user-home path;
- a private-key header;
- a credential-style password, secret, API-key or access-token assignment.

The repository contains only expected external URLs: official tool documentation, the repository clone URL and the parameterised official Gitleaks release URL.

## Sample-data review

The examples use small invented values, journey records and science-fiction names rather than customer, employee, financial, location-tracking or publishing-production data.

Recurring sample names and destinations include:

- Maya Chen;
- Leo Martins;
- Priya Shah;
- Earth;
- Aurora Station;
- Harbour Point.

These are fictional sample records, not records about real individuals. The author's name, Filip L. Schulze, appears only as intentional public attribution in reader-facing documentation; no author e-mail address or private contact detail is stored.

The filename `private-travel-log.txt` in Chapter 20 describes a temporary file created by the exercise. No copy of that generated file or its runtime contents is tracked, and the tests remove it after use.

No image collection, binary dataset, customer export, manuscript extract, production PDF or backup archive is present.

## Rights boundary

A fictional name can still involve copyright, trade mark, publishing-contract or attribution considerations. The earlier recurring themed names, destinations and phrases have been replaced with original neutral material. The isolated use of `towel` in Chapter 4 remains an ordinary English noun in a small Boolean example. Final ownership and licensing approval remains part of [RELEASE_CHECKLIST.md](RELEASE_CHECKLIST.md).

## Conclusion

The current sample and test data is fictional and contains no identified personal or confidential information. No source or data file requires a privacy-driven change.

Repeat this audit whenever names, datasets, recorded output, fixtures, external assets or generated-file examples change, and repeat it on the exact release candidate before changing repository visibility.
