CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: parse-integer

parse-integer: parse_integer.c
	$(CC) $(CFLAGS) $< -o $@

test: parse-integer
	./test.sh

clean:
	$(RM) parse-integer
