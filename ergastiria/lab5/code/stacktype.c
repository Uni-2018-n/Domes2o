#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacktype.h"

int readvalue(FILE *from, stackelem_t * elemp)
{
	char *buf = NULL;
	size_t len = 0;
	int result = 0;
	getline(&buf, &len, from);
	result = sscanf(buf, "%d %s", &(elemp->integer), elemp->string);

	free(buf);
	buf = NULL;
	len = 0;

	return result;
}

int printvalue(FILE *to, stackelem_t elem)
{
	return fprintf(to, "{%d, '%s'}", elem.integer, elem.string);
}

void setvalue(stackelem_t * destp, stackelem_t src)
{
	destp->integer = src.integer;
	strncpy(destp->string, src.string, sizeof(destp->string));
	destp->string[sizeof(destp->string)-1] = '\0';
}

int isequal(stackelem_t lhs, stackelem_t rhs)
{
	return ((lhs.integer == rhs.integer) && (strcmp(lhs.string, rhs.string) == 0));
}
