#include <stdlib.h>
#include <stdio.h>

#include "Node_Int.h"

Node_Int *new_Node_Int (int value) {
	Node_Int *n = (Node_Int*)calloc((size_t)1, sizeof(Node_Int));
	n->value = value;
	n->next = NULL;
	return n;
}

void delete_Node_Int (Node_Int *n) {
	free(n);
}

void print_Node_Int (Node_Int *n) {
	printf("%d", n->value);
}
