# Parse integer

The programme reads a complete line and accepts it only when `strtol` consumes one valid `int` plus optional whitespace.

```bash
make test
```

The tests cover 42, trailing junk, an empty line and an out-of-range number.
