CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: readings

readings: readings.c
	$(CC) $(CFLAGS) $(CPPFLAGS) readings.c $(LDFLAGS) $(LDLIBS) -o $@

test: readings
	./test.sh

clean:
	$(RM) readings

