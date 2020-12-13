#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct Stack {
	int count;
	struct elem {
		void *x;
		struct elem *link;
	} *head;
};

Stack Stack_new(void)
{
	Stack t = (Stack) malloc(sizeof(*t));
	t->count = 0;
	t->head = NULL;
	return t;
}
void Stack_push(Stack stk, void *x)
{
	assert(stk);
	struct elem *t = (struct elem *) malloc(sizeof(*t));
	t->x = x;
	t->link = stk->head;
	stk->head = t;
	stk->count++;
}
void *Stack_pop(Stack stk)
{
	assert(stk);
	assert(stk->count > 0);
	struct elem *t = stk->head;
	stk->head = t->link;
	stk->count--;
	void *x = t->x;
	free(t);
	return x;
}
void Stack_free(Stack *stk)
{
	assert(stk && *stk);
	for (struct elem *t = (*stk)->head, *u; t; t = u) {
		u = t->link;
		free(t);
	} 
	free(*stk);
	*stk = NULL;
}

