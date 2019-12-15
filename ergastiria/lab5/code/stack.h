#ifndef __STACK_H__
#define __STACK_H__

#include "stacktype.h"

typedef struct stack_struct *stack_handle;

stack_handle stack_create();
void stack_destroy(stack_handle *);
int stack_empty(const stack_handle);
int stack_full(const stack_handle);
void stack_pop(const stack_handle, stackelem_t *, int *,
	void (*)(stackelem_t *, stackelem_t));
void stack_push(const stack_handle, stackelem_t, int *,
	void (*)(stackelem_t *, stackelem_t));

#endif
