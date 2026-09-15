CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: sum_readings

sum_readings: sum_readings.c
	$(CC) $(CFLAGS) $(CPPFLAGS) sum_readings.c $(LDFLAGS) $(LDLIBS) -o $@

test: sum_readings
	./test.sh

clean:
	$(RM) sum_readings

