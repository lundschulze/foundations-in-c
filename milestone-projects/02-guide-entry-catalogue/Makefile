CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

PROGRAM = guide-entry-catalogue

.PHONY: all clean
all: $(PROGRAM)

$(PROGRAM): starter.c
	$(CC) $(CFLAGS) $(CPPFLAGS) starter.c $(LDFLAGS) $(LDLIBS) -o $@

clean:
	$(RM) $(PROGRAM)
