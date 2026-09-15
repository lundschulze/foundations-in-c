CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: square

square: square.c
	$(CC) $(CFLAGS) $(CPPFLAGS) square.c $(LDFLAGS) $(LDLIBS) -o $@

test: square
	./test.sh

clean:
	$(RM) square

