#include <stdio.h>
#include <stdlib.h>

#include "stacktype.h"
#include "stack.h"
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
//    char buf[100];
	int option, error;//, result;
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
			readvalue(&x);
			stack_push(&stack, x, &error);
			if (error)
				printf("\nStack overflow. %d NOT pushed!\n", x);
			break;
		case 3:
			x = stack_pop(&stack, &error);
			if (error)
				printf("\nEmpty stack!\n");
			else
				printf("\nNumber");
 				printvalue(x);
				printf("popped successfully!\n");
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
