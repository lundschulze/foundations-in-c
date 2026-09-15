CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: read-report

read-report: read_report.c
	$(CC) $(CFLAGS) $< -o $@

test: read-report
	./test.sh

clean:
	$(RM) read-report
