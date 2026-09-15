CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic
PROGRAMS := starter answer

.PHONY: all clean test

all: answer

starter: starter.c
	$(CC) $(CFLAGS) $(CPPFLAGS) starter.c $(LDFLAGS) $(LDLIBS) -o $@

answer: answer.c
	$(CC) $(CFLAGS) $(CPPFLAGS) answer.c $(LDFLAGS) $(LDLIBS) -o $@

test: answer
	./test.sh

clean:
	$(RM) $(PROGRAMS)

