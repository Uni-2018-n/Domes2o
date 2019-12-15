#ifndef __STACKTYPE_H__
#define __STACKTYPE_H__
#include <stdio.h>

#define MAX_CHARS 20

typedef struct {
	int integer;
	char string[MAX_CHARS];
} stackelem_t;

int readvalue(FILE *, stackelem_t *);
int printvalue(FILE *, stackelem_t);
void setvalue(stackelem_t *, stackelem_t);
int isequal(stackelem_t, stackelem_t);

#endif
