#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph_algorithms.h"
#include "queue.h"


static Vertex *graph_head;
static unsigned int V = 0;
static unsigned int E = 0;
static int time;

static void graph_update(void);
static Vertex *graph_get_vptr(int vid);
static void DFS_visit(Vertex *u);

static void graph_update(void)
{
	for (Vertex *vtmp = graph_head->next; vtmp; vtmp = vtmp->next)
		for (Edge *etmp = vtmp->edges->next; etmp; etmp = etmp->next)
			etmp->vertexptr = graph_get_vptr(etmp->vertexid);
}
static Vertex *graph_get_vptr(int vid)
{
	for (Vertex *vtmp = graph_head->next; vtmp; vtmp = vtmp->next)
		if (vtmp->id == vid)
			return vtmp;
	return NULL;
}
void DFS_visit(Vertex *u)
{
	time++;
	u->d = time;
	u->color = GRAY;
	for (Edge *e = u->edges->next; e; e = e->next) {
		Vertex *v = e->vertexptr;
		if (v->color == WHITE) {
			v->parent = u;
			DFS_visit(v);
		}
	}
	u->color = BLACK;
	time++;
	u->f = time;
}

/*****************************************************************************************************
 *
 * global functions definitions section
 *
*****************************************************************************************************/
void graph_init(void)
{
	graph_head = (Vertex *) malloc(sizeof(Vertex));
	graph_head->next = NULL;
	graph_head->prev = NULL;
	graph_head->edges = NULL;
}
void BFS(void)
{
	graph_update();
	Vertex *s = graph_head->next;
	s->color = BLACK;
	s->d = 0;
	s->parent = NULL;
	for (Vertex *u = s->next; u; u = u->next) {
		u->color = WHITE;
		u->d = INT_MAX;
		u->parent = NULL;
	}
	Queue q = Queue_new();
	Queue_enqueue(q, s);
	while (!Queue_empty(q)) {
		Vertex *u = (Vertex *) Queue_dequeue(q);
		for (Edge *e = u->edges->next; e; e = e->next) {
			Vertex *v = e->vertexptr;
			if (v->color == WHITE) {
				v->color = BLACK;
				v->d = u->d + 1;
				v->parent = u;
				Queue_enqueue(q, v);
			}
		}
	}
	Queue_free(&q);
}
void DFS(void)
{
	graph_update();
	for (Vertex *u = graph_head->next; u; u = u->next) {
		u->color = WHITE;
		u->parent = NULL;
	}
	time = 0;
	for (Vertex *u = graph_head->next; u; u = u->next)
		if (u->color == WHITE)
			DFS_visit(u);
}
void DFS_Stack(void)
{
	/* TO DO*/
}
void DFS_Recursive(void)
{
	/* TO DO*/
}
void graph_add(int vertex, int *edges, int nedges)
{
	V++; E += nedges;
	Vertex *tmp_vptr = graph_head;
	while (tmp_vptr->next) tmp_vptr = tmp_vptr->next;
	tmp_vptr->next = (Vertex *) malloc(sizeof(Vertex));
	tmp_vptr->next->number = V;
	tmp_vptr->next->id = vertex;
	tmp_vptr->next->next = NULL;
	tmp_vptr->next->prev = tmp_vptr;
	tmp_vptr = tmp_vptr->next;
	tmp_vptr->edges = (Edge *) malloc(sizeof(Edge));
	tmp_vptr->edges->prev = NULL;
	tmp_vptr->edges->next = NULL;
	Edge *tmp_eptr = tmp_vptr->edges;
	for (int i = 0; i < nedges; i++) {
		tmp_eptr->next = (Edge *) malloc(sizeof(Edge));
		tmp_eptr->next->next = NULL;
		tmp_eptr->next->prev = tmp_eptr;
		tmp_eptr = tmp_eptr->next;
		tmp_eptr->vertexid = edges[i];
	}
}
void graph_print(void)
{
	for (Vertex *tmp_vptr = graph_head->next; tmp_vptr; tmp_vptr = tmp_vptr->next) {
		fprintf(stdout, "%03d: ", tmp_vptr->id);
		fprintf(stdout, "color = %d: ", tmp_vptr->color);
		fprintf(stdout, "d = %03d: ", tmp_vptr->d);
		for (Edge *tmp_eptr = tmp_vptr->edges->next; tmp_eptr; tmp_eptr = tmp_eptr->next)
			fprintf(stdout, "%d ", tmp_eptr->vertexid);
		fprintf(stdout, "\n");
	}
}
void graph_dispose(void)
{
	Vertex *tmp_vptr = graph_head;
	Edge *tmp_eptr;
	while (tmp_vptr) {
		tmp_eptr = tmp_vptr->edges;
		while (tmp_eptr) {
			Edge *tmp = tmp_eptr;
			tmp_eptr = tmp_eptr->next;
			free(tmp);
		}
		Vertex *tmp = tmp_vptr;
		tmp_vptr = tmp_vptr->next;
		free(tmp);
	}
	graph_head = NULL;
}
