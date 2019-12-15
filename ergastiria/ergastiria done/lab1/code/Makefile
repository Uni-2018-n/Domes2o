CC=gcc
CFLAGS=-Wall

.PHONY: clean

myprog: myprog.o stack.o stacktype.o
	$(CC) $(CFLAGS) -o myprog myprog.o stack.o stacktype.o

stacktype.o: stacktype.c
	$(CC) $(CFLAGS) -c  stacktype.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

myprog.o: myprog.c
	$(CC) $(CFLAGS) -c myprog.c

clean:
	rm -f myprog myprog.o stack.o stacktype.o

