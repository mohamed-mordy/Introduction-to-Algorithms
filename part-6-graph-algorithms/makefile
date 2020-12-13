objects = graph_driver.o graph.o graph_parser.o queue.o stack.o list.o
compiler= gcc -Wall -ggdb3

mincut: $(objects)
	$(compiler) -o mincut $(objects)


graph_driver.o: graph_driver.c
	$(compiler) -c graph_driver.c

graph.o: graph.c
	$(compiler) -c graph.c

graph_algorithms.o: graph_algorithms.c graph_algorithms.h
	$(compile) -c graph_algorithms.c

graph_parser.o: graph_parser.c
	$(compiler) -c graph_parser.c

queue.o: queue.c
	$(compiler) -c queue.c

stack.o: stack.c
	$(compiler) -c stack.c

list.o: list.c
	$(compiler) -c list.c


.PHONY: clean
clean:
	rm *.o;

