#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listtype.h"
#define MAX_OPTIONS 8

void print_options()
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create list\n");
	printf("2. Read and Insert item into list (first)\n");
	printf("3. Remove item from the list (first)\n");
	printf("4. Print list\n");
	printf("5. Check for empty list\n");
	printf("6. Read and Insert item into list (last)\n");
	printf("7. Remove item from the list (last)\n");	
	printf("8. Reverse list\n");
	printf("Enter your input (0-%d): ", MAX_OPTIONS);
}

int get_option()
{
	char buf[100];
	int option;

	option = -1;
	while (option < 0 || option > MAX_OPTIONS) {
		print_options();
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &option);
	}
	return option;
}

int main()
{
	int option, error;
	list_node *list = NULL;
	listelem item;

	do {
		option = get_option();
		switch (option) {
		case 1:
			list_create(&list, &error);
			if (error) {
				printf("\nList already exists!\n");
			} else {
				printf("\nList Created!\n");
			}
			break;
		case 2:
			readvalue(&item);
			list_insert_first(&list, item);
			break;
		case 3:
			item = list_remove_first(&list, &error);
			if (error) {
				printf("\nEmpty list!\n");
			} else {
				printf("\nItem ");
				printvalue(item);
				printf(" removed successfully!\n");
			}
			break;
		case 4:
			list_print(list, &error);
			if (error) {
				printf("\nList empty!\n");
			}
			break;
		case 5:
			if (list_empty(list)) {
				printf("\nList empty!\n");
			} else {
				printf("\nList not empty!\n");
			}
			break;
		case 6:
			readvalue(&item);
			list_insert_last(&list, item);
			break;
		case 7:
			item = list_remove_last(&list, &error);
			if (error) {
				printf("\nEmpty list!\n");
			} else {
				printf("\nItem ");
				printvalue(item);
				printf(" removed successfully!\n");
			}
			break;
		case 8:
			list_reverse(&list, &error);
			if (error) {
				printf("\nEmpty list!\n");
			}
			break;
		}
	}	while (option);
	return(0);
}
