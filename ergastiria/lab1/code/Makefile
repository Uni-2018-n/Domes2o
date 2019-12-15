CC=gcc
CFLAGS=-Wall

test: test.o
	$(CC) $(CFLAGS) -o test test.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

.PHONY: clean

clean:
	rm -f test test.o
