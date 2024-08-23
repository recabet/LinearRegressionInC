CC = cc
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations

all: example

example: example.o linear_regression.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c linear_regression.h
	$(CC) $(CFLAGS) -c -o $@ $<

run: example
	./example

clean:
	$(RM) example *.o

.PHONY: all run clean
