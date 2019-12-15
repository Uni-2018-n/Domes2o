#include <stdio.h>

int main()
{
	int i = 4;
	double d = 3.14;
	char c = 'a';

	int *ipt = &i;
	double *dpt = &d;
	char *cpt = &c;
	/* Ορίστε ένα δείκτη σε κάθε μία από τις τρεις μεταβλητές */
	printf("First: %p\n", &ipt);
	printf("First: %p\n", &dpt);
	printf("First: %p\n", &cpt);
	/* Τυπώστε τις διευθύνσεις των δεικτών.  Χρησιμοποιείστε το
         προσδιοριστικό "%p" για την εκτύπωση διευθύνσεων μνήμης
         της μορφής '0xbe10a22f'. */
  printf("Second: %lu\n", sizeof(int));
	printf("Second: %lu\n", sizeof(double));
	printf("Second: %lu\n", sizeof(char));

	printf("Second: %lu\n", sizeof(int *));
	printf("Second: %lu\n", sizeof(double *));
	printf("Second: %lu\n", sizeof(char *));
	/* Τυπώστε το μέγεθος της κατειλημμένης μνήμης για κάθε μία
         από τις 6 μεταβλητές (μεταβλητές και δείκτες).
         Χρησιμοποιείστε τον τελεστή sizeof. */

	/* Τυπώστε τις τιμές του περιεχομένου μνήμης */
	printf("Third: %d\n", *ipt);
	printf("Third: %.02f\n", *dpt);
	printf("Third: %c\n", *cpt);
	return 0;
}
