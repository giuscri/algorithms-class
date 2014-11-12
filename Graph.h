#ifndef _GRAPH_H
#define _GRAPH_H
#include <stdlib.h>
#include <stdbool.h>

#include "Linkedlist.h"

typedef struct {
	size_t nV;
	size_t nE;
	Linkedlist **A;
} Graph;

Graph *new_Graph (size_t nV, size_t nE);

void delete_Graph (Graph *g);

void read_Graph (Graph *g, FILE *fp);

void print_Graph (const Graph *g);

void traverse_Graph (const Graph *g, void (*cb)(const Graph*,const Node_Int*,bool*));

void dfs_Graph (const Graph *g);

void bfs_Graph (const Graph *g);
#endif
