CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: calloc-counters

calloc-counters: calloc_counters.c
	$(CC) $(CFLAGS) $< -o $@

test: calloc-counters
	./test.sh

clean:
	$(RM) calloc-counters
