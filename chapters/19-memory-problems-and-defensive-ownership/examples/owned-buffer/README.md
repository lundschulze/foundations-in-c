# Owned buffer

The `IntBuffer` object owns its allocation. `buffer_destroy` releases the region exactly once and resets both the pointer and count.

```bash
make owned-buffer
./owned-buffer
```

The programme prints 10, 20 and 30, then confirms that the destroyed buffer is empty.
