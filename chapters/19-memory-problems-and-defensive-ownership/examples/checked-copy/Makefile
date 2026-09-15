CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: checked-copy

checked-copy: checked_copy.c
	$(CC) $(CFLAGS) $< -o $@

test: checked-copy
	./test.sh

clean:
	$(RM) checked-copy
