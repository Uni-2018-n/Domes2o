#include "stack.h"
#include "stacktype.h"
void stack_create(stack_t * stackPtr)
{
	stackPtr->top = -1;
}

int stack_empty(stack_t stackPtr)
{
	return (stackPtr.top == -1);
}

int stack_full(stack_t stack)
{
	return (stack.top == MAX_ELEMS - 1);
}

stackelem_t stack_pop(stack_t * stackPtr, int *underflow)
{
	stackelem_t elem;
	if (stack_empty(*stackPtr)) {
		*underflow = 1;
	} else {
		*underflow = 0;
		elem = stackPtr->table[stackPtr->top];
		stackPtr->top--;
	}
	return elem;
}

void stack_push(stack_t * stackPtr, stackelem_t elem, int *overflow)
{
	if (stack_full(*stackPtr))	/* (stackPtr->top == (MAX_ELEMS -1)) */
		*overflow = 1;
	else {
		*overflow = 0;
		stackPtr->top++;
		stackPtr->table[stackPtr->top] = elem;
	}
}