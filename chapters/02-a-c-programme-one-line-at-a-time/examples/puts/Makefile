CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: puts

puts: puts.c
	$(CC) $(CFLAGS) $(CPPFLAGS) puts.c $(LDFLAGS) $(LDLIBS) -o $@

test: puts expected.txt
	@mkdir -p test-results
	@./puts > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) puts test-results/actual.txt
	@rmdir test-results 2>/dev/null || true
