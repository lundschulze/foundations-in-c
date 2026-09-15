CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: countdown_function

countdown_function: countdown_function.c
	$(CC) $(CFLAGS) $(CPPFLAGS) countdown_function.c $(LDFLAGS) $(LDLIBS) -o $@

test: countdown_function
	./test.sh

clean:
	$(RM) countdown_function

