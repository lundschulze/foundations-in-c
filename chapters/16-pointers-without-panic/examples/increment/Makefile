CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: increment

increment: increment.c
	$(CC) $(CFLAGS) $< -o $@

test: increment
	./test.sh

clean:
	$(RM) increment
