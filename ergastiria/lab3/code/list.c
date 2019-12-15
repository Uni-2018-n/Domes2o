#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listtype.h"


int list_empty(list_node *l)
{
	return(l == NULL);
}

list_node* list_create_node(listelem item)
{
	list_node* lnode = malloc(sizeof(list_node));
	lnode->content = item;
	lnode->next = NULL;
	return lnode;
}

void list_create(list_node **l, int *error)
{
	if (*l) {
		*error = 1;
	} else {
		*error = 0;
		*l = NULL;
	}
}

void list_destroy_node(list_node **l)
{
	free(*l);
	*l = NULL;
}

void list_destroy(list_node **l, int *error)
{
	list_node* temp;
	if (*l == NULL) {
		*error = 1;
	} else {
		*error = 0;
		while (*l) {
			temp = *l;
			*l = (*l)->next;
			list_destroy_node(&temp);
		}
	}
}

void list_insert_first(list_node **lnode, listelem item)
{
	list_node* ltemp = list_create_node(item);
	ltemp->next = *lnode;
	*lnode = ltemp;
}
	

listelem list_remove_first(list_node **l, int *error)
{
	list_node* to_del;
	listelem item;

	if (*l == NULL) {
		*error = 1;
	} else {
		*error = 0;
		to_del = *l;
		*l = (*l)->next;
		item = to_del->content;
		list_destroy_node(&to_del);
	}
	return item;
}

void list_print(list_node *l, int *error)
{
	if (l == NULL ) {
		*error = 1;
	} else {
		*error = 0;
		printf("List: ");
		while (l) {
			printvalue(l->content);
			printf(" ");
			l = l->next;
		}
		printf("\n");
	}
}

void list_insert_last(list_node **l, listelem item)
{
	/* Insert code*/
}

listelem list_remove_last(list_node **l , int *error)
{
	/* Insert code*/
}

void list_reverse(list_node **l, int *error)
{
	/* Insert code*/
}

