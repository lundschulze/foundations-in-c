CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: grow-list

grow-list: grow_list.c
	$(CC) $(CFLAGS) $< -o $@

test: grow-list
	./test.sh

clean:
	$(RM) grow-list
