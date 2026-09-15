CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: hello

hello: hello.c
	$(CC) $(CFLAGS) $(CPPFLAGS) hello.c $(LDFLAGS) $(LDLIBS) -o $@

test: hello expected.txt
	@mkdir -p test-results
	@./hello > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) hello test-results/actual.txt
	@rmdir test-results 2>/dev/null || true
