CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: do_while

do_while: do_while.c
	$(CC) $(CFLAGS) $(CPPFLAGS) do_while.c $(LDFLAGS) $(LDLIBS) -o $@

test: do_while
	./test.sh

clean:
	$(RM) do_while

