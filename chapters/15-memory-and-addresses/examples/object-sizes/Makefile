CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: object-sizes

object-sizes: object_sizes.c
	$(CC) $(CFLAGS) $< -o $@

test: object-sizes
	./test.sh

clean:
	$(RM) object-sizes
