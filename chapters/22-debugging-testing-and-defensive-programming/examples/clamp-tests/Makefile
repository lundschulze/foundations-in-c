CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: clamp-tests

clamp-tests: clamp_tests.c
	$(CC) $(CFLAGS) $< -o $@

test: clamp-tests
	./test.sh

clean:
	$(RM) clamp-tests
