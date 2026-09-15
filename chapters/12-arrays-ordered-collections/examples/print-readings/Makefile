CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: print_readings

print_readings: print_readings.c
	$(CC) $(CFLAGS) $(CPPFLAGS) print_readings.c $(LDFLAGS) $(LDLIBS) -o $@

test: print_readings
	./test.sh

clean:
	$(RM) print_readings

