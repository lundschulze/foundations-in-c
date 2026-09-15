# Fare calculation

`calculate_fare` receives an age and returns the selected price instead of deciding how the caller must display it.

```bash
make fare_calculation
./fare_calculation
```

Expected output:

```text
Ticket price: 7.50
```

This compact example uses `0.0` for a negative age only to demonstrate return mechanics; an ordinary-looking price is not a suitable error report in a real booking system.

