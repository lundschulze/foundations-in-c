CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: name

name: name.c
	$(CC) $(CFLAGS) $(CPPFLAGS) name.c $(LDFLAGS) $(LDLIBS) -o $@

test: name
	./test.sh

clean:
	$(RM) name

