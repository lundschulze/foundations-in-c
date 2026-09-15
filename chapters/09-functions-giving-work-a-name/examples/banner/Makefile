CC := cc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: banner

banner: banner.c
	$(CC) $(CFLAGS) $(CPPFLAGS) banner.c $(LDFLAGS) $(LDLIBS) -o $@

test: banner
	./test.sh

clean:
	$(RM) banner

