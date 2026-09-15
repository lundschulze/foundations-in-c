CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: age

age: age.c
	$(CC) $(CFLAGS) $(CPPFLAGS) age.c $(LDFLAGS) $(LDLIBS) -o $@

test: age
	./test.sh

clean:
	$(RM) age

