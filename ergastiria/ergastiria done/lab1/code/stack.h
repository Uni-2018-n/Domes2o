#ifndef __STACK_H__
#define __STACK_H__

#define MAX_ELEMS 10

#include "stacktype.h"

typedef struct {
	float top;
	stackelem_t table[MAX_ELEMS];
} stack_t;

void stack_create(stack_t * stackPtr);
int stack_empty(stack_t stackPtr);
int stack_full(stack_t stack);
stackelem_t stack_pop(stack_t * stackPtr, int *underflow);
void stack_push(stack_t * stackPtr, stackelem_t elem, int *overflow);

#endif