CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: owned-buffer

owned-buffer: owned_buffer.c
	$(CC) $(CFLAGS) $< -o $@

test: owned-buffer
	./test.sh

clean:
	$(RM) owned-buffer
