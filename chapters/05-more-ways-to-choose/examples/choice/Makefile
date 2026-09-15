CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: choice

choice: choice.c
	$(CC) $(CFLAGS) $(CPPFLAGS) choice.c $(LDFLAGS) $(LDLIBS) -o $@

test: choice expected.txt
	@mkdir -p test-results
	@./choice > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) choice test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

