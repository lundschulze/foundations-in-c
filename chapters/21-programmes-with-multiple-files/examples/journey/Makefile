CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

TEST_OBJECTS = tests.o journey.o

.PHONY: all clean test
all: journey

journey: main.o journey.o
	$(CC) $(LDFLAGS) main.o journey.o $(LDLIBS) -o $@

journey-tests: $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(LDLIBS) -o $@

main.o: main.c journey.h
	$(CC) $(CFLAGS) -c main.c

tests.o: tests.c journey.h
	$(CC) $(CFLAGS) -c tests.c

journey.o: journey.c journey.h
	$(CC) $(CFLAGS) -c journey.c

test: journey journey-tests
	./test.sh

clean:
	$(RM) journey journey-tests main.o tests.o journey.o
