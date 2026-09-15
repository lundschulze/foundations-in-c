CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic
PROGRAMS := starter answer

.PHONY: all clean test

all: answer

starter: starter.c
	$(CC) $(CFLAGS) $(CPPFLAGS) starter.c $(LDFLAGS) $(LDLIBS) -o $@

answer: answer.c
	$(CC) $(CFLAGS) $(CPPFLAGS) answer.c $(LDFLAGS) $(LDLIBS) -o $@

test: answer expected.txt
	@mkdir -p test-results
	@./answer > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) $(PROGRAMS) test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

