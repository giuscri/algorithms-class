#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdlib.h>

#include "Node_Int.h"

typedef struct {
	size_t length;
	Node_Int *first;
} Linkedlist;

Linkedlist *new_Linkedlist ();

void delete_Linkedlist (Linkedlist *ll);

void insert_Linkedlist (Linkedlist *ll, Node_Int *n);

void print_Linkedlist (const Linkedlist *ll);
#endif
