CC=gcc
CFLAGS=-Wall -g

myprog: myprog.o stack.o stacktype.o
	$(CC) $(CFLAGS) -o myprog myprog.o stack.o stacktype.o

myprog.o: myprog.c
	$(CC) $(CFLAGS) -c myprog.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

stacktype.o: stacktype.c
	$(CC) $(CFLAGS) -c stacktype.c

.PHONY: clean

clean:
	rm -f myprog myprog.o stack.o stacktype.o
