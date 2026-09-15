# Pointer basics

The pointer stores the address of `answer`, not a second copy of 42. Dereferencing it reaches the original object.

```bash
make pointer-basics
./pointer-basics
```

Expected output:

```text
Directly: 42
Through the pointer: 42
After the change: 43
```
