CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: uppercase_first

uppercase_first: uppercase_first.c
	$(CC) $(CFLAGS) $(CPPFLAGS) uppercase_first.c $(LDFLAGS) $(LDLIBS) -o $@

test: uppercase_first
	./test.sh

clean:
	$(RM) uppercase_first

