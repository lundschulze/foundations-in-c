CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: rating

rating: rating.c
	$(CC) $(CFLAGS) $(CPPFLAGS) rating.c $(LDFLAGS) $(LDLIBS) -o $@

test: rating expected.txt
	@mkdir -p test-results
	@./rating > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) rating test-results/actual.txt
	@rmdir test-results 2>/dev/null || true

