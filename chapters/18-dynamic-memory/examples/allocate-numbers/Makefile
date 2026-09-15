CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: allocate-numbers

allocate-numbers: allocate_numbers.c
	$(CC) $(CFLAGS) $< -o $@

test: allocate-numbers
	./test.sh

clean:
	$(RM) allocate-numbers
