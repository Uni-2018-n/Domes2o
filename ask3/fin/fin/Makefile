TARGET = main
LIBS =
CC = gcc
CFLAGS = -g -Wall -ggdb3

default: $(TARGET)

$(TARGET): Evretirio.c Evretirio.h TSDDA.c TSEvr.c AirportManagement.c BST/ch8_BSTpointerR.c  AVL/ch8_AVLpointer.c read_data.c
	gcc -o main Evretirio.c Evretirio.h TSDDA.c TSEvr.c AirportManagement.c BST/ch8_BSTpointerR.c  AVL/ch8_AVLpointer.c read_data.c

clean:
	rm -f *.o
	rm -f $(TARGET)
