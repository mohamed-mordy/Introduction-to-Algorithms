#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct List *List;

extern List List_new(void);
extern List List_arrToList(int len, void *x, size_t size);
extern void List_foreach(List list, void apply(void **x, void *cl), void *cl);
extern void List_free(List *list);

#endif
