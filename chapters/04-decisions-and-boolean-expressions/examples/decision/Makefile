CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: decision

decision: decision.c
	$(CC) $(CFLAGS) $(CPPFLAGS) decision.c $(LDFLAGS) $(LDLIBS) -o $@

test: decision expected.txt
	@mkdir -p test-results
	@./decision > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) decision test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

