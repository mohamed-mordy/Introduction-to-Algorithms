#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Item *Item;
struct List {
	int len;
	struct Item {
		void *x;
		Item link;
	} *head;
};


List List_new(void)
{
	List list = (List) malloc(sizeof *list);
	list->len = 0;
	list->head = NULL;
	return list;
}
List List_arrToList(int len, void *x, size_t size)
{
	Item item, *p = &item;
	for (int i = 0; i < len; i++) {
		*p = (Item) malloc(sizeof *p);
		assert(*p);
		(*p)->x = (x + size * i);
		p = &(*p)->link;
	}
	*p = NULL;
	/* */
	List list = (List) malloc(sizeof *list);
	assert(list);
	list->len = len;
	list->head = item;
	return list;
}
void List_foreach(List list, void apply(void **x, void *cl), void *cl)
{
	for (Item item = list->head; item; item = item->link) {
		apply(&item->x, cl);
	}
}
void List_free(List *list)
{
	assert(list);
	for (Item item = (*list)->head, next; item; item = next) {
		next = item->link;
		free(item);
	}
	free(*list);
	*list = NULL;
}
