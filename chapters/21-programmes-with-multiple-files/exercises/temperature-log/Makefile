CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic

.PHONY: all clean test
all: answer

answer: answer.o temperature_log.o
	$(CC) $(LDFLAGS) answer.o temperature_log.o $(LDLIBS) -o $@

starter: starter.o temperature_log.o
	$(CC) $(LDFLAGS) starter.o temperature_log.o $(LDLIBS) -o $@

temperature-log-tests: tests.o temperature_log.o
	$(CC) $(LDFLAGS) tests.o temperature_log.o $(LDLIBS) -o $@

answer.o: answer.c temperature_log.h
	$(CC) $(CFLAGS) -c answer.c

starter.o: starter.c temperature_log.h
	$(CC) $(CFLAGS) -c starter.c

tests.o: tests.c temperature_log.h
	$(CC) $(CFLAGS) -c tests.c

temperature_log.o: temperature_log.c temperature_log.h
	$(CC) $(CFLAGS) -c temperature_log.c

test: answer temperature-log-tests
	./test.sh

clean:
	$(RM) answer starter temperature-log-tests answer.o starter.o tests.o temperature_log.o
