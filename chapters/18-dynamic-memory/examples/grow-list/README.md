# Grow list

The result of `realloc` first goes into a temporary pointer. If resizing fails, the original pointer still owns a valid allocation and can be released.

```bash
make grow-list
./grow-list
```

The multiplication is checked before the resize.
