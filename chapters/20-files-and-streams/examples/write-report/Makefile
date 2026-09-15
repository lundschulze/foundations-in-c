CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: write-report

write-report: write_report.c
	$(CC) $(CFLAGS) $< -o $@

test: write-report
	./test.sh

clean:
	$(RM) write-report
