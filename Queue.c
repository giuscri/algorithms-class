#include <string.h>
#include <stdio.h>

#include "Queue.h"

Queue *new_Queue () {
	return new_Linkedlist();
}

void delete_Queue (Queue *q) {
	delete_Linkedlist(q);
}

void enqueue_Queue (Queue *q, const Node_Int *n) {
	if (q->length > 0) {
		Node_Int *p = NULL;
		for (p = q->first; p->next != NULL; p = p->next)
			;
		p->next = new_Node_Int(n->value);
		p->next->next = NULL;
	}
	else {
		q->first = new_Node_Int(n->value);
		q->first->next = NULL;
	}
	q->length += 1;
}

Node_Int dequeue_Queue (Queue *q) {
	Node_Int *todequeue = NULL;
	todequeue = q->first;
	q->first = q->first->next;
	q->length -= 1;
	Node_Int n = *todequeue;
	delete_Node_Int(todequeue);
	return n;
}

void print_Queue (const Queue *q) {
	print_Linkedlist(q);
}

bool isempty_Queue (const Queue *q) {
	return q->length < 1;
}
