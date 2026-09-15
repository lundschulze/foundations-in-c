# Exercise — Design a TemperatureLog interface

The header exposes creation, addition, average calculation and destruction while keeping the representation private.

```bash
make starter
./starter
make answer
./answer
```

The created log owns its array. The caller owns the returned log and must pass it to `temperature_log_destroy`. Zero capacity and null required pointers are invalid.
