CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: pointer-basics

pointer-basics: pointer_basics.c
	$(CC) $(CFLAGS) $< -o $@

test: pointer-basics
	./test.sh

clean:
	$(RM) pointer-basics
