#ifndef LIST_H_
#define LIST_H_

#include "listtype.h"

typedef struct list_node {
    listelem content;
    struct list_node *next;
} list_node;

int list_empty(list_node *);
list_node* list_create_node(listelem);
void list_create(list_node **, int *);
void list_insert_first(list_node **, listelem);
void list_destroy_node(list_node **);
void list_destroy(list_node **, int *);
void list_print(list_node *, int *);
listelem list_remove_first(list_node **, int *);

void list_insert_last(list_node **, listelem);
listelem list_remove_last(list_node **, int *);
void list_reverse(list_node **, int *);

#endif
