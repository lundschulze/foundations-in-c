CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: count-character

count-character: count_character.c
	$(CC) $(CFLAGS) $< -o $@

test: count-character
	./test.sh

clean:
	$(RM) count-character
