# Block scope

The nested block gives `inner` a smaller scope than `outer`.

```bash
make block_scope
./block_scope
```

Expected output:

```text
Outer: 42
Inner: 7
Outer again: 42
```

Using `inner` after its closing brace would be rejected because that name is out of scope.

