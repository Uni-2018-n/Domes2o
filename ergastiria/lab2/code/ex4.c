#include <stdio.h>
int main( )
{
	char c = 'Z';
	char *cp = &c;
	printf("cp is %p\n", cp);
	printf("The character at cp is %c\n", *cp);

	cp = cp+1;
	printf("cp is %p\n", cp);
	/* Μην τυπώσετε το *cp τώρα γιατί δείχνει σε μνήμη
	   μη αρχικοποιημένη. */
	return 0;
}
