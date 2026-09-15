# Temperature

The first decision checks conversion. The second checks whether the converted value is within the supported range.

```bash
make temperature
./temperature
```

Try `20`, `-100`, `100`, `101` and a word. A word fails conversion; `101` converts successfully but fails domain validation.

