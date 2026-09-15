CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: replace-spaces

replace-spaces: replace_spaces.c
	$(CC) $(CFLAGS) $< -o $@

test: replace-spaces
	./test.sh

clean:
	$(RM) replace-spaces
