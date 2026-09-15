# Remembered calls

`calls` has block scope but static storage duration. The object persists while its name remains usable only inside `report_call`.

```bash
make remembered_calls
./remembered_calls
```

Expected output:

```text
Call 1
Call 2
Call 3
```

