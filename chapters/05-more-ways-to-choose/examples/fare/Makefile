CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: fare

fare: fare.c
	$(CC) $(CFLAGS) $(CPPFLAGS) fare.c $(LDFLAGS) $(LDLIBS) -o $@

test: fare expected.txt
	@mkdir -p test-results
	@./fare > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) fare test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

