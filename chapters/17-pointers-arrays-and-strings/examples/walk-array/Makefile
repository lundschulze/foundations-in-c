CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: walk-array

walk-array: walk_array.c
	$(CC) $(CFLAGS) $< -o $@

test: walk-array
	./test.sh

clean:
	$(RM) walk-array
