# Increment

`increment` receives a copy of an address. Dereferencing that copied pointer still reaches the object owned by `main`.

```bash
make increment
./increment
```

Expected output: `Visits: 43`.
