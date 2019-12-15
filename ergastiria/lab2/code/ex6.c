#include <stdio.h>

typedef struct {
	int i;
	char *s;
} D;

void print_D(D d)
{
	printf("Struct contains int: %d, and string: %s\n", d.i, d.s);
}

void swap_struct(D* d1, D* d2);
/* Υλοποιήστε την swap_struct() */

int main()
{
	D d1, d2;
	d1.i = 5;
	d1.s = "Hello.";
	d2.i = 2;
	d2.s = "World.";

	print_D(d1);
	print_D(d2);

	/* Καλέστε την swap_struct() */

	print_D(d1);
	print_D(d2);
	return 0;
}
