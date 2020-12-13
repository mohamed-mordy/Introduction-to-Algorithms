#ifndef GRAPH_ALGORITHMS_INCLUDED
#define GRAPH_ALGORITHMS_INCLUDED

extern void graph_init(void);
extern void BFS(void);
extern void DFS(void);
extern void graph_add(int vertex, int *edges, int nedges);
extern void graph_print(void);
extern void graph_dispose(void);

#endif
