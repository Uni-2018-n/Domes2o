#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMS 10

#include "stacktype.h"

typedef struct {
	int top;
	stackelem_t table[MAX_ELEMS];
} stack_t;

void stack_create(stack_t * stackPtr);
int stack_empty(stack_t stackPtr);
int stack_full(stack_t stack);
stackelem_t stack_pop(stack_t * stackPtr, int *underflow);
void stack_push(stack_t * stackPtr, stackelem_t elem, int *overflow);

/* actually initializes stack; does not create */
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

void print_options(void)
{
        printf("\n");
        printf("0. Exit\n");
        printf("1. Create stack\n");
        printf("2. Push integer into stack\n");
        printf("3. Pop integer from stack\n");
        printf("4. Check for empty stack (default)\n");
        printf("Enter your input (0-4): ");
}

int get_option()
{
	char buf[100];
	int option;

	option = -1;
	while (option < 0 || option > 4) {
		print_options();
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &option);
	}
	return option;
}


int main(void)
{
    char buf[100];
	int option, error, result;
	stack_t stack;
	stackelem_t x;

	do {
		option = get_option();
		switch (option) {
		case 1:
			stack_create(&stack);
			printf("\nStack Created!\n");
			break;
		case 2:
			result = 0;
			while (result != 1) {
				printf("Type an int: ");
				fgets(buf, sizeof(buf), stdin);
				result = sscanf(buf, "%d", &x);
			}
			stack_push(&stack, x, &error);
			if (error)
				printf("\nStack overflow. %d NOT pushed!\n", x);
			break;
		case 3:
			x = stack_pop(&stack, &error);
			if (error)
				printf("\nEmpty stack!\n");
			else
				printf("\nNumber %d popped successfully!\n", x);
			break;
		case 4:
			if (stack_empty(stack))
				printf("\nStack empty!\n");
			else
				printf("\nStack not empty!\n");
			break;
		}
	}
	while (option);
	return 0;
}
