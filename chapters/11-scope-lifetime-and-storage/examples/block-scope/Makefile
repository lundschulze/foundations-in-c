CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: block_scope

block_scope: block_scope.c
	$(CC) $(CFLAGS) $(CPPFLAGS) block_scope.c $(LDFLAGS) $(LDLIBS) -o $@

test: block_scope
	./test.sh

clean:
	$(RM) block_scope

