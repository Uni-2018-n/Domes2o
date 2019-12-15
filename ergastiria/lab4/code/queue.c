#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "queuetype.h"


int queue_empty(queue *q)
{
	assert(q);
	return(q->front == NULL);
}

int queue_full(queue *q)
{
	assert(q);
	// A dynamic queue does not fill up.
	return (0);
}

qnode* queue_create_node(qelem item)
{
	qnode* qn = malloc(sizeof(qnode));
	qn->content = item;
	qn->next = NULL;
	qn->prev = NULL;
	return qn;
}

void queue_create(queue **q, int *error)
{
	if (*q) {
		*error = 1;
	} else {
		*error = 0;
		*q = malloc(sizeof(queue));
		(*q)->front = NULL;
		(*q)->rear = NULL;
	}
}

void queue_destroy_node(qnode **qn)
{
	free(*qn);
	*qn = NULL;
}

void queue_destroy(queue **q)
{
	qnode* temp;
	while ((*q)->front) {
		temp = (*q)->front;
		(*q)->front = (*q)->front->next;
		queue_destroy_node(&temp);
	}
	free(*q);
	*q = NULL;
}

void queue_insert(queue *q, qelem item)
{
	assert(q);
	qnode* qn = queue_create_node(item);
	if (q->rear == NULL) {
		q->front = qn;
		q->rear = qn;
	} else {
		q->rear->next = qn;
		qn->prev = q->rear;
		q->rear = qn;
	}
}
	

qelem queue_remove(queue *q, int *error)
{
	qnode* qn;
	qelem item = 0;

	assert(q);
	if (queue_empty(q)) {
		*error = 1;
	} else {
		*error = 0;
		qn = q->front;
		q->front = q->front->next;
		if (q->front) {
			// There exists at least one more item in queue
			q->front->prev = NULL;
		} else {
			// Empty queue
			q->rear = NULL;
		}
		item = qn->content;
		queue_destroy_node(&qn);
	}
	return item;
}

void queue_print(queue *q)
{
	qnode *qn;

	assert(q);
	if (queue_empty(q)) {
		printf("Queue empty!\n");
	} else {
		printf("Queue: ");
		qn = q->front;
		while (qn) {
			printvalue(qn->content);
			printf(" ");
			qn = qn->next;
		}
		printf("\n");
	}
}

qelem queue_peek(queue *q, int *error)
{
	qelem item = 0;
	/* Insert code*/
	return item;
}

int queue_size(queue *q)
{
	int size = 0;
	/* Insert code*/
	return size;
}

void queue_reverse(queue *q)
{
	/* Insert code*/
}

