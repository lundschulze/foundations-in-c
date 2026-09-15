# Exercise — Multiplication line

Complete `starter.c` so it reads an integer from 1 through 12, rejects failed conversions and out-of-range values, then prints twelve products with a `for` loop.

```bash
make starter
./starter
```

Test `1`, `12`, `0`, `13` and a word. The loop must never use invalid input.

Compare your work with one possible solution:

```bash
make answer
./answer
```

For input `3`, the output begins:

```text
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
```

The condition uses `<= 12` because twelve is an included boundary.

