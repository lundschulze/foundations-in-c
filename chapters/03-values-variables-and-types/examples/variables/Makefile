CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: variables

variables: variables.c
	$(CC) $(CFLAGS) $(CPPFLAGS) variables.c $(LDFLAGS) $(LDLIBS) -o $@

test: variables expected.txt
	@mkdir -p test-results
	@./variables > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) variables test-results/actual.txt
	@rmdir test-results 2>/dev/null || true
