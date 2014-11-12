#include <stdio.h>

#include "Linkedlist.h"

Linkedlist *new_Linkedlist () {
	Linkedlist *ll = (Linkedlist*)calloc(1, sizeof(Linkedlist));
	ll->first = NULL;
	ll->length = 0;
	return ll;
}

void delete_Linkedlist (Linkedlist *ll) {
	Node_Int *current = NULL;
	Node_Int *previous = NULL;
	current = previous = ll->first;
	for (; current != NULL;) {
		previous = current;
		current = current->next;
		delete_Node_Int(previous);
	}
	free(ll);
}

void insert_Linkedlist (Linkedlist *ll, Node_Int *n) {
	n->next = NULL;
	if (ll->length > 0) {
		Node_Int *p = NULL;
		for (p = ll->first; p->next != NULL; p = p->next)
			;
		p->next = n;
	}
	else {
		ll->first = n;
	}
	ll->length += 1;
}

void print_Linkedlist (const Linkedlist *ll) {
	Node_Int *p = NULL;
	printf("[ ");
	for (p = ll->first; p != NULL; p = p->next) {
		print_Node_Int(p);
		printf(" ");
	}
	printf("]");
}
