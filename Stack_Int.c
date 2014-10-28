#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "Stack_Int.h"

Stack_Int *new_Stack_Int () {
	Stack_Int *s = (Stack_Int*)calloc(1, sizeof(Stack_Int));
	s->length = 0;
	return s;
}

int top_Stack_Int (Stack_Int *s) {
	if (s->length < 1) {
		assert("Cannot top empty stack.");
	}
	return s->elements[s->length - 1];
}

int pop_Stack_Int (Stack_Int **s) {
	if ((*s)->length < 1) {
		assert("Cannot top empty stack.");
	}
	int popped_element = 0;
	Stack_Int *t = (Stack_Int*)calloc(1, sizeof(Stack_Int));
	t->elements = (int*)calloc((*s)->length - 1, sizeof(int));
	t->length = (*s)->length - 1;
	memcpy(t->elements, (*s)->elements, sizeof(int) * ((*s)->length - 1));
	popped_element = (*s)->elements[(*s)->length - 1];
	delete_Stack_Int(*s);
	*s = t;
	return popped_element;
}

void push_Stack_Int (Stack_Int **s, int element) {
	Stack_Int *t = (Stack_Int*)calloc(1, sizeof(Stack_Int));
	t->length = (*s)->length + 1;
	t->elements = (int*)calloc((*s)->length + 1, sizeof(int));
	memcpy(t->elements, (*s)->elements, sizeof(int) * (*s)->length);
	t->elements[t->length - 1] = element;
	delete_Stack_Int(*s);
	*s = t;
}

void delete_Stack_Int (Stack_Int *s) {
	free(s->elements);
	free(s);
}

void print_Stack_Int (Stack_Int *s) {
	printf("[ ");
	int i = 0;
	for (i = 0; i < s->length; i++) {
		printf("%d ", s->elements[i]);
	}
	printf("]");
}
