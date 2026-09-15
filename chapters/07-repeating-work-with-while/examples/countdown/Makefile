CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: countdown

countdown: countdown.c
	$(CC) $(CFLAGS) $(CPPFLAGS) countdown.c $(LDFLAGS) $(LDLIBS) -o $@

test: countdown
	./test.sh

clean:
	$(RM) countdown

