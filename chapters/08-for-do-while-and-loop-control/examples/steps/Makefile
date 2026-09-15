CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: steps

steps: steps.c
	$(CC) $(CFLAGS) $(CPPFLAGS) steps.c $(LDFLAGS) $(LDLIBS) -o $@

test: steps
	./test.sh

clean:
	$(RM) steps

