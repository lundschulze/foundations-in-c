CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: odd

odd: odd.c
	$(CC) $(CFLAGS) $(CPPFLAGS) odd.c $(LDFLAGS) $(LDLIBS) -o $@

test: odd
	./test.sh

clean:
	$(RM) odd

