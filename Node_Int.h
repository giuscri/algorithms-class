#ifndef _NODE_INT_H
#define _NODE_INT_H
struct Node_Int {
	int value;
	struct Node_Int *next;
};

typedef struct Node_Int Node_Int;

Node_Int *new_Node_Int (int value);

void delete_Node_Int (Node_Int *n);

void print_Node_Int (Node_Int *n);
#endif
