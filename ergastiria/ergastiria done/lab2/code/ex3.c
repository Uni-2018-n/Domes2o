#include <stdio.h>
void foo(int xval)
{
	int x;
	x = xval;
	/* Τυπώστε τη διεύθυνση και την τιμή της x εδώ. */
	printf("First: %p, %d\n", &x, x);
}

void bar(int yval)
{
	int y;
	y = yval;
	/* Τυπώστε τη διεύθυνση και την τιμή της y εδώ. */
	printf("First: %p, %d\n", &y, y);
}

int main()
{
	foo(5);
	bar(3);
	return 0;
}
