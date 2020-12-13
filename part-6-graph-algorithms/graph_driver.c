#include <stdio.h>
#include <stdlib.h>
#include "graph_parser.h"
#include "graph_algorithms.h"

int main(int argc, char **argv)
{
	if (argc == 2) {
		FILE *fptr;
		if ((fptr = fopen(argv[1], "r"))) {
			graph_init();
			int vertex;
			int edges[200];
			int nedges;
			while (parse_line(fptr, &vertex, edges, &nedges) != EOF) {
				graph_add(vertex, edges, nedges);
				fprintf(stdout, "%d\n", vertex);
				
			}
			fclose(fptr);
			graph_print();
			BFS();
			graph_print();
			graph_dispose();
		} else {
			fprintf(stderr, "error: can't open file \"%s\"\n", argv[1]);
		}
		return 0;
	} else {
		fprintf(stderr, "Usage: ./mincut input_graph_file\n");
		exit(1);
	}
}

