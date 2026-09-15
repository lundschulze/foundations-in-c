CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: boarding

boarding: boarding.c
	$(CC) $(CFLAGS) $(CPPFLAGS) boarding.c $(LDFLAGS) $(LDLIBS) -o $@

test: boarding expected.txt
	@mkdir -p test-results
	@./boarding > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) boarding test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

