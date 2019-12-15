#include <stdio.h>
#include <stdlib.h>
#include "queuetype.h"

void readvalue(qelem *x)
{
	int result = 0;
	char buf[100];

	while (result != 1) {
		printf("Type an int: ");
		fgets(buf, sizeof(buf), stdin);
		result = sscanf(buf, "%d", x);
	}
}

void printvalue(qelem x)
{
	printf("%d", x);
}
