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
	printf("\n");
	//i
	int i = 1;
	int *ip = &i;
	printf("ip is &%p\n", ip);
	printf("The interger at ip is %d\n", *ip);
	ip = ip + 1;
	printf("ip is %p\n", ip);

	printf("\n");
	//ii
	double d = 2.0;
	double *dp = &d;
	printf("dp is &%p\n", dp);
	printf("The double at dp is %f\n", *dp);
	dp = dp + 1;
	printf("dp is %p\n", dp);

	printf("\n");
	//iii
	char cc = 'Z';
	char *ccp = &c;
	printf("ccp is %p\n", ccp);
	printf("The character at ccp is %c\n", *ccp);

	ccp = ccp+2;
	printf("ccp is %p\n", ccp);
	/* Μην τυπώσετε το *cp τώρα γιατί δείχνει σε μνήμη
		 μη αρχικοποιημένη. */
	printf("\n");
	//i
	int ii = 1;
	int *iip = &ii;
	printf("iip is &%p\n", iip);
	printf("The interger at iip is %d\n", *iip);
	iip = iip + 2;
	printf("iip is %p\n", iip);

	printf("\n");
	//ii
	double dd = 2.0;
	double *ddp = &dd;
	printf("ddp is &%p\n", ddp);
	printf("The double at ddp is %f\n", *ddp);
	ddp = ddp + 2;
	printf("ddp is %p\n", ddp);
	return 0;
}
