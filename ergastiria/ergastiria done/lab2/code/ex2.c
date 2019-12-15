#include <stdio.h>

int main()
{
	int i = 4;
	double d = 3.14;
	char c = 'a';

	int *ipt = &i;
	double *dpt = &d;
	char *cpt = &c;
	/* Ορίστε ένα δείκτη σε κάθε μία από τις τρεις μεταβλητές. */

	*ipt = 6;
	*dpt = 5.0;
	*cpt = 'd';
	/* Αλλάξτε τις τιμές περιεχομένων των δεικτών ως εξής:
		*iptr <- 6
		*dptr <- 5.0
		*cptr <- 'd'  */
	/* Τυπώστε τις τιμές των μεταβλητών i, d, c */
	printf("Fin: %d\n", i);
	printf("Fin: %.01f\n", d);
	printf("Fin: %c\n", c);
	return 0;
}
