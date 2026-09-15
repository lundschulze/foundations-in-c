CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: remembered_calls

remembered_calls: remembered_calls.c
	$(CC) $(CFLAGS) $(CPPFLAGS) remembered_calls.c $(LDFLAGS) $(LDLIBS) -o $@

test: remembered_calls
	./test.sh

clean:
	$(RM) remembered_calls

