#include "queue.h"
#include <assert.h>
#include <stdlib.h>

struct Queue {
	int count;
	struct elem  {
		void *x;
		struct elem *link;
	} *head;
	struct elem *tail;
};

Queue Queue_new(void)
{
	Queue q = (Queue) malloc(sizeof *q);
	q->count = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}
void Queue_enqueue(Queue q, void *x)
{
	assert(q);
	struct elem *t = (struct elem *) malloc(sizeof(*t));
	t->x = x;
	t->link = NULL;
	if (q->head == NULL && q->tail == NULL) {
		q->head = q->tail = t;
		q->count++;
	} else {
		q->tail->link = t;
		q->tail = t;
		q->count++;
	}
}
void *Queue_dequeue(Queue q)
{
	assert(q);
	assert(q->count > 0);
	struct elem *t = q->head;
	q->head = t->link;
	q->count--;
	void *x = t->x;
	free(t);
	if (q->count == 0) {
		q->head = NULL;
		q->tail = NULL;
	}
	return x;
}
int Queue_empty(Queue q)
{
	assert(q);
	return q->count == 0;
}
void Queue_free(Queue *q)
{
	assert(q && *q);
	for (struct elem *t = (*q)->head, *u; t; t = u) {
		u = t->link;
		free(t);
	}
	free(*q);
	*q = NULL;
}
