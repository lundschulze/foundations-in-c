# Exercise — Quantity reader

Complete `starter.c` so it displays and flushes a prompt, reads one decimal integer, checks the conversion, accepts only 0 through 100 and returns a non-zero value after invalid input.

```bash
make starter
./starter
```

Test `42`, `0`, `100`, `-1` and a word. Identify whether each rejected input fails conversion or range validation.

Compare your work with one possible solution:

```bash
make answer
./answer
```

With input `42`, the answer ends with:

```text
Accepted quantity: 42
```

