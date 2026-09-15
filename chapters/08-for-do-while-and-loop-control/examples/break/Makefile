CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: break

break: break.c
	$(CC) $(CFLAGS) $(CPPFLAGS) break.c $(LDFLAGS) $(LDLIBS) -o $@

test: break
	./test.sh

clean:
	$(RM) break

