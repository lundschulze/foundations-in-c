CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: larger

larger: larger.c
	$(CC) $(CFLAGS) $(CPPFLAGS) larger.c $(LDFLAGS) $(LDLIBS) -o $@

test: larger
	./test.sh

clean:
	$(RM) larger

