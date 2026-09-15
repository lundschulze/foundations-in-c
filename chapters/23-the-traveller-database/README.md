# Chapter 23 — The Traveller Database

The final Book 1 programme combines structures, dynamic memory, ownership, separate translation units, validated text input, persistent storage and deliberate error handling.

## Build and run

```bash
make
./traveller-database
```

Expected output:

```text
1: Maya Chen, 2 bags
2: Leo Martins, 1 bag
3: Priya Shah, 3 bags
Database round trip verified.
```

## Test

```bash
make test
```

The tests cover valid construction, rejected names and bag counts, full capacity, a successful round trip and malformed input that must leave the destination database unchanged.

## File format

One record is stored per line:

```text
Maya Chen|2
```

Names containing `|` or a newline are rejected. Bag counts must be from 0 through 20. Loading takes place in a temporary database; ownership is transferred only after the entire file has been validated and closed successfully.
