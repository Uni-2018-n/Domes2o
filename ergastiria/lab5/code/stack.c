#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stacktype.h"

#define MAX_ELEMS 10
typedef struct stack_struct {
	int top;
	stackelem_t table[MAX_ELEMS];
} stack_struct;

/* actually create stack */
stack_handle stack_create()
{
	stack_handle stackp;
	stackp = malloc(sizeof(stack_struct));
	assert(stackp);
	stackp->top = -1;
	return stackp;
}

void stack_destroy(stack_handle * stackpp)
{
	assert(*stackpp);
	free(*stackpp);
	*stackpp = NULL;
	assert(*stackpp == NULL);
}

int stack_empty(stack_handle stackp)
{
	return (stackp->top == -1);
}

int stack_full(stack_handle stackp)
{
	return (stackp->top == MAX_ELEMS - 1);
}

void stack_pop(stack_handle stackp, stackelem_t *elemp, int *underflow,
	void (* setValue)(stackelem_t *, stackelem_t))
{
	if (stack_empty(stackp)) {
		*underflow = 1;
	} else {
		*underflow = 0;
		setvalue(elemp, stackp->table[stackp->top]);
		stackp->top--;
	}
}

void stack_push(stack_handle stackp, stackelem_t elem, int *overflow,
	void (* setValue)(stackelem_t *, stackelem_t))
{
	if (stack_full(stackp)) {
		*overflow = 1;
	} else {
		*overflow = 0;
		stackp->top++;
		setvalue(&(stackp->table[stackp->top]), elem);
	}
}
