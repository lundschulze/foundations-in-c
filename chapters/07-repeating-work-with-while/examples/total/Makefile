CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: total

total: total.c
	$(CC) $(CFLAGS) $(CPPFLAGS) total.c $(LDFLAGS) $(LDLIBS) -o $@

test: total
	./test.sh

clean:
	$(RM) total

