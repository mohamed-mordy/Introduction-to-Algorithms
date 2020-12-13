#ifndef QUEUE_INCLUDED
#define QUEUE_INCLUDED

typedef struct Queue *Queue;

extern Queue Queue_new(void);
extern void Queue_enqueue(Queue q, void *x);
extern void *Queue_dequeue(Queue q);
extern int Queue_empty(Queue q);
extern void Queue_free(Queue *q);

#endif

