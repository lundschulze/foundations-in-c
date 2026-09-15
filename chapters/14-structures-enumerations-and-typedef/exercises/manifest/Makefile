CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: answer

answer: answer.c
	$(CC) $(CFLAGS) $< -o $@

starter: starter.c
	$(CC) $(CFLAGS) $< -o $@

test: answer
	./test.sh

clean:
	$(RM) answer starter
