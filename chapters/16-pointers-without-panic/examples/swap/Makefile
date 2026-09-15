CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: swap

swap: swap.c
	$(CC) $(CFLAGS) $< -o $@

test: swap
	./test.sh

clean:
	$(RM) swap
