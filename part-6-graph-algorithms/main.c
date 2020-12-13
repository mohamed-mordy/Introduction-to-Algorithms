#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define len(x) (sizeof(x)/sizeof(x[0]))

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {1,3,3,5,5,6,8,1,3,5,4};
	graph_init();
	graph_add(10, arr, 6);
	graph_add(16, arr2, len(arr2));
	graph_print();
	graph_dispose();
	return 0;
}
