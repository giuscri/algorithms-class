#ifndef _STACK_INT_H
#define _STACK_INT_H

#include <stdlib.h>

typedef struct {
	int *elements;
	size_t length;
} Stack_Int;

Stack_Int *new_Stack_Int ();

int top_Stack_Int (Stack_Int *s);

int pop_Stack_Int (Stack_Int **s);

void push_Stack_Int (Stack_Int **s, int element);

void delete_Stack_Int (Stack_Int *s);

void print_Stack_Int (Stack_Int *s);
#endif
