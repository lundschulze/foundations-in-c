# Exercise — Observe the channels

Complete `starter.c` so ordinary output, diagnostics and machine-readable status remain separate.

```bash
make answer
./answer >result.txt 2>diagnostic.txt
printf '%s\n' "$?"
```

The answer returns 1. The two text files are local test artefacts and are ignored by Git.
