CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: journey-status

journey-status: journey_status.c
	$(CC) $(CFLAGS) $< -o $@

test: journey-status
	./test.sh

clean:
	$(RM) journey-status
