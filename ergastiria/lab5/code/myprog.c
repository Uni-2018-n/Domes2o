#include <stdio.h>
#include <stdlib.h>
#include "stacktype.h"
#include "stack.h"

void print_options();
int get_option();

void print_options()
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create stack\n");
	printf("2. Push item into stack\n");
	printf("3. Pop item from stack\n");
	printf("4. Check for empty stack (default)\n");
	printf("5. Destroy stack\n");
	printf("Enter your input (0-5): ");
}

int get_option()
{
	char *buf = NULL;
	size_t len;
	int option;

	option = -1;
	while (option < 0 || option > 5) {
		print_options();
		getline(&buf, &len, stdin);
		sscanf(buf, "%d", &option);
		free(buf);
	}
	return option;
}

int main(void)
{
	int option, error, out_err;
	stack_handle stackp = NULL;
	stackelem_t x;

	do {
		option = get_option();
		switch (option) {
		case 1:
			/* Add Test: Create if stack != NULL 
			 * otherwise message "Destroy stack first!" */
			stackp = stack_create();
			printf("\nStack created!\n");
			break;
		case 2:
			/* Add 3 tests, following case 3 as an example */
			/* Add test if(stack==NULL) */
			printf("Type a stack element (integer + string): ");
			readvalue(stdin, &x);
			/* Add test if out_err is OK */
			
			stack_push(stackp, x, &error, setvalue);
			/* Add test  if(error) OK */
			break;
		case 3:
			if (stackp == NULL) {
				printf("\nThere is no stack to pop from!\n");  
        	} else {
				stack_pop(stackp, &x, &error, setvalue);
				if (error) {
					printf("\nEmpty stack!\n");
				} else {
					printf("\nItem ");
					out_err = printvalue(stdout, x);
					printf(" popped successfully!\n");
					if (out_err < 0) {
						printf("\n error stin writeValue !\n");
					}
				}
			}
			break;
		case 4:
			if (stackp == NULL) {
				printf("\nThere is no stack to check!\n");  
        	} else {
				if (stack_empty(stackp))
					printf("\nStack empty!\n");
				else
					printf("\nStack not empty!\n");
			}
			break;
		case 5:
			if (stackp == NULL) {
				printf("\nThere is no stack to destroy!\n");  
        	} else {
				stack_destroy(&stackp);
				printf("\nStack destroyed!\n");
			}
			break;
		}
	}
	while (option);
	
	if (stackp) {
		stack_destroy(&stackp);
	}
	return 0;
}
