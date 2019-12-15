#ifndef QUEUE_H_
#define QUEUE_H_

#include "queuetype.h"

typedef struct qnode {
	qelem content;
	struct qnode *next;
	struct qnode *prev;
} qnode;

typedef struct queue {
	qnode *front;
	qnode *rear;
} queue;

int queue_empty(queue *);
int queue_full(queue *);
qnode* queue_create_node(qelem);
void queue_create(queue **, int *);
void queue_insert(queue *, qelem);
void queue_destroy_node(qnode **);
void queue_destroy(queue **);
void queue_print(queue *);
qelem queue_remove(queue *, int *);

qelem queue_peek(queue *, int *);
int queue_size(queue *);
void queue_reverse(queue *);

#endif
