# Object sizes

`sizeof` returns a `size_t` value, printed with `%zu`. C guarantees that `sizeof(char)` is 1; the other sizes depend on the implementation.

```bash
make object-sizes
./object-sizes
```

The hexadecimal literal `0x2A` still represents the integer value 42.
