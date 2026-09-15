CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: fare_calculation

fare_calculation: fare_calculation.c
	$(CC) $(CFLAGS) $(CPPFLAGS) fare_calculation.c $(LDFLAGS) $(LDLIBS) -o $@

test: fare_calculation
	./test.sh

clean:
	$(RM) fare_calculation

