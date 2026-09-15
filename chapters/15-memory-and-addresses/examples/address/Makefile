CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: address

address: address.c
	$(CC) $(CFLAGS) $< -o $@

test: address
	./test.sh

clean:
	$(RM) address
