#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>

#include "Linkedlist.h"

typedef Linkedlist Queue;

Queue *new_Queue ();

void delete_Queue (Queue *q);

void enqueue_Queue (Queue *q, const Node_Int *n);

Node_Int dequeue_Queue (Queue *q);

void print_Queue (const Queue *q);

bool isempty_Queue (const Queue *q);
#endif
