CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

PROGRAM = galactic-field-log
OBJECTS = main.o

.PHONY: all clean
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c main.c

clean:
	$(RM) $(PROGRAM) $(OBJECTS)
