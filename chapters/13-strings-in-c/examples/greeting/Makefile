CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: greeting

greeting: greeting.c
	$(CC) $(CFLAGS) $(CPPFLAGS) greeting.c $(LDFLAGS) $(LDLIBS) -o $@

test: greeting
	./test.sh

clean:
	$(RM) greeting

