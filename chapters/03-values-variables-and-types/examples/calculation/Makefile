CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: calculation

calculation: calculation.c
	$(CC) $(CFLAGS) $(CPPFLAGS) calculation.c $(LDFLAGS) $(LDLIBS) -o $@

test: calculation expected.txt
	@mkdir -p test-results
	@./calculation > test-results/actual.txt
	@diff -u expected.txt test-results/actual.txt

clean:
	$(RM) calculation test-results/actual.txt
	@rmdir test-results 2>/dev/null || true
