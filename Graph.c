#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Queue.h"
#include "Graph.h"

Graph *new_Graph (size_t nV, size_t nE) {
	Graph *g = (Graph*)calloc(1, sizeof(Graph));
	g->nV = nV;
	g->nE = nE;
	g->A = (Linkedlist**)calloc(nV, sizeof(Linkedlist*));
	int i = 0;
	for (i = 0; i < (int)nV; i++) {
		g->A[i] = new_Linkedlist();
		insert_Linkedlist(g->A[i], new_Node_Int(i));
	}
	return g;
}

void delete_Graph (Graph *g) {
	int i = 0;
	for (i = 0; i < (int)(g->nV); i++) {
		delete_Linkedlist(g->A[i]);
	}
	free(g->A);
	free(g);
}

void read_Graph (Graph *g, FILE *fp) {
	int i = 0;
	size_t v1_index = 0;
	size_t v2_index = 0;
	for (i = 0; i < (int)(g->nE); i++) {
		if (fscanf(fp, "%d %d", &v1_index, &v2_index) != EOF) {
			insert_Linkedlist(g->A[v1_index], new_Node_Int(v2_index));
			insert_Linkedlist(g->A[v2_index], new_Node_Int(v1_index));
		}
	}
}

void print_Graph (const Graph *g) {
	int i = 0;
	for (i = 0; i < (int)(g->nV); i++) {
		printf("Node %d is linked with ", i);
		print_Linkedlist(g->A[i]);
		printf("\n");
	}
}

void dfs (const Graph *g, const Node_Int *r, bool *marked) {
	marked[r->value] = true;
	Node_Int *p = NULL;
	for (p = g->A[r->value]->first; p != NULL; p = p->next) {
		if (marked[p->value] != true) {
			print_Node_Int(p);
			printf(" ");
			dfs(g, p, marked);
		}
	}
}

void bfs (const Graph *g, const Node_Int *r, bool *marked) {
	Queue *q = new_Queue();
	enqueue_Queue(q, r);
	for (;!isempty_Queue(q);) {
		Node_Int n = dequeue_Queue(q);
		marked[n.value] = true;
		Node_Int *p = NULL;
		for (p = g->A[n.value]->first; p != NULL; p = p->next) {
			if (marked[p->value] != true) {
				print_Node_Int(p);
				printf(" ");
				enqueue_Queue(q, p);
				marked[p->value] = true;
			}
		}
	}
	delete_Queue(q);
}

void traverse_Graph (const Graph *g, void (*cb)(const Graph*,const Node_Int*,bool*)) {
	int i = 0;
	bool *marked = (bool*)calloc(g->nV, sizeof(bool));
	for (i = 0; i < (int)(g->nV); marked[i] = false, i++)
		;
	printf("Starting from radix ");
	print_Node_Int(g->A[0]->first);
	printf(" ");
	for (i = 0; i < (int)(g->nV); i++) {
		Node_Int *p = g->A[i]->first;
		if (marked[p->value] != true) {
			cb(g, p, marked);
		}
	}
	free(marked);
}

void dfs_Graph (const Graph *g) {
	traverse_Graph(g, dfs);
}

void bfs_Graph (const Graph *g) {
	traverse_Graph(g, bfs);
}
