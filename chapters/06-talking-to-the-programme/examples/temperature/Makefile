CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: temperature

temperature: temperature.c
	$(CC) $(CFLAGS) $(CPPFLAGS) temperature.c $(LDFLAGS) $(LDLIBS) -o $@

test: temperature
	./test.sh

clean:
	$(RM) temperature

