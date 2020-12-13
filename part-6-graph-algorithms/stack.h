#ifndef STACK_INCLUDED
#define STACK_INCLUDED

typedef struct Stack *Stack;

extern Stack Stack_new(void);
extern void Stack_push(Stack stk, void *x);
extern void *Stack_pop(Stack stk);
extern void Stack_free(Stack *stk);

#endif
