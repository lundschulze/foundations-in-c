CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

PROGRAM = traveller-database
OBJECTS = main.o traveller.o database.o
TEST_OBJECTS = tests.o traveller.o database.o

.PHONY: all clean test
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

tests: $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(LDLIBS) -o $@

main.o: main.c database.h traveller.h
	$(CC) $(CFLAGS) -c main.c

tests.o: tests.c database.h traveller.h
	$(CC) $(CFLAGS) -c tests.c

traveller.o: traveller.c traveller.h
	$(CC) $(CFLAGS) -c traveller.c

database.o: database.c database.h traveller.h
	$(CC) $(CFLAGS) -c database.c

test: $(PROGRAM) tests
	./test.sh

clean:
	$(RM) $(PROGRAM) tests $(OBJECTS) tests.o travellers-practice.txt test-valid.txt test-malformed.txt
