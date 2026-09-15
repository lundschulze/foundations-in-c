CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: traveller

traveller: traveller.c
	$(CC) $(CFLAGS) $< -o $@

test: traveller
	./test.sh

clean:
	$(RM) traveller
