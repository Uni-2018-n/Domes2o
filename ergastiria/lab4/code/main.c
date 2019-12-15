#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "queuetype.h"
#define MAX_OPTIONS 8

void print_options()
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create queue\n");
	printf("2. Read and Insert item into queue (enqueue)\n");
	printf("3. Remove item from the list (dequeue)\n");
	printf("4. Print queue\n");
	printf("5. Check for empty queue\n");
	printf("6. Peek (not remove) first item from queue\n");
	printf("7. Print size of queue\n");	
	printf("8. Reverse queue\n");
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
	queue *q = NULL;
	qelem item;

	do {
		option = get_option();
		switch (option) {
		case 1:
			queue_create(&q, &error);
			if (error) {
				printf("\nQueue already exists!\n");
			} else {
				printf("\nQueue Created!\n");
			}
			break;
		case 2:
			readvalue(&item);
			queue_insert(q, item);
			break;
		case 3:
			item = queue_remove(q, &error);
			if (error) {
				printf("\nEmpty queue!\n");
			} else {
				printf("\nItem ");
				printvalue(item);
				printf(" removed successfully!\n");
			}
			break;
		case 4:
			queue_print(q);
			break;
		case 5:
			if (queue_empty(q)) {
				printf("\nQueue empty!\n");
			} else {
				printf("\nQueue not empty!\n");
			}
			break;
		case 6:
			item = queue_peek(q, &error);
			if (error) {
				printf("\nEmpty queue!\n");
			} else {
				printf("\"Item ");
				printvalue(item);
				printf(" is in the first place of the queue!\n");
			}
			break;
		case 7:
			printf("The queue size is %d.\n", queue_size(q));
			break;
		case 8:
			queue_reverse(q);
			break;
		}
	}	while (option);
	if (q) {
		queue_destroy(&q);
	}
	return(0);
}
