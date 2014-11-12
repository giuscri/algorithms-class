#include <stdio.h>

#include "Node_Int.h"
#include "Linkedlist.h"
#include "Graph.h"
#include "Queue.h"

int main (int argc, char **argv) {
	Graph *g = new_Graph(9, 11);
	if (argc > 1) {
		FILE *file = fopen((char*)argv[1], "r");
		read_Graph(g, file);
		fclose(file);
	}
	print_Graph(g);
	bfs_Graph(g);
	delete_Graph(g);
	return 0;
}
