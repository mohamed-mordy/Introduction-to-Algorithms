#include <stdio.h>
#include "queue.h"
#include <string.h>

int main(void)
{
	char *x = "hello, ";
	char *y = "world";
	char *z = "!";
	Queue q = Queue_new();
	Queue_enqueue(q, x);
	Queue_enqueue(q, y);
	Queue_enqueue(q, z);
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s\n", (char *) Queue_dequeue(q));
	Queue_enqueue(q, x);
	Queue_enqueue(q, y);
	Queue_enqueue(q, z);
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s\n", (char *) Queue_dequeue(q));
	Queue_enqueue(q, x);
	Queue_enqueue(q, y);
	Queue_enqueue(q, z);
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s", (char *) Queue_dequeue(q));
	printf("%s\n", (char *) Queue_dequeue(q));
	Queue_free(&q);
}

#ifndef QUEUE_INCLUDED
#define QUEUE_INCLUDED

typedef struct Queue *Queue;

extern Queue Queue_new(void);
extern void Queue_enqueue(Queue q, void *x);
extern void *Queue_dequeue(Queue q);
extern int Queue_empty(Queue q);
extern void Queue_free(Queue *q);

#endif

