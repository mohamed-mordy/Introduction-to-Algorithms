#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "list.h"
#include "graph.h"
#include "list.h"

struct Edge {
	int vertexid;
	Vertex vertex;
};
struct Vertex {
	int id;
	Color color;
	int d;
	int f;
	Vertex parent;
	List elist;
};
struct Graph {
	int N;
	int M;
	Vertex varray;
};

// graph operations
Graph Graph_new(int N)
{
	Graph graph = (Graph) malloc(sizeof *graph);
	assert(graph);
	Vertex vertex = (Vertex) malloc(N * sizeof *vertex);
	assert(vertex);
	for (int i = 0; i < N; i++) {
		(vertex[i]).id = i;
		(vertex[i]).color = WHITE;
		(vertex[i]).d = INT_MAX;
		(vertex[i]).f = INT_MAX;
		(vertex[i]).parent = NULL;
		(vertex[i]).elist = NULL;
	}
	graph->N = N;
	graph->M = 0;
	graph->varray = vertex;
	return graph;
}
void Graph_free(Graph *graph)
{
	
}
Graph Graph_copy(Graph graph)
{
	
}

