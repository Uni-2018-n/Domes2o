#include <stdio.h>
#include <stdlib.h>
#include "listtype.h"

void readvalue(listelem *x)
{
	int result = 0;
	char buf[100];

	while (result != 1) {
		printf("Type an int: ");
		fgets(buf, sizeof(buf), stdin);
		result = sscanf(buf, "%d", x);
	}
}

void printvalue(listelem x)
{
	printf("%d", x);
}
