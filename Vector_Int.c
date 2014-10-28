#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Vector_Int.h"

Vector_Int *new_Vector_Int (int length, int (*cb) ()) {
	Vector_Int *v = (Vector_Int*)calloc(1, sizeof(Vector_Int));
	v->length = length;
	v->elements = (int*)calloc(length, sizeof(int));
	int i;
	for (i = 0; i < v->length; i++) {
		v->elements[i] = cb();
	}
	return v;
}

void delete_Vector_Int (Vector_Int *v) {
	free(v->elements);
	free(v);
}

void print_Vector_Int (const Vector_Int *v) {
	printf("[ ");
	int i;
	for (i = 0; i < v->length; i++) {
		printf("%d ", v->elements[i]);
	}
	printf("]");
}

Vector_Int *sum_Vector_Int (const Vector_Int *v, const Vector_Int *w) {
	if (v->length != w->length) {
		assert(false && "Vectors MUST have the same length to be summed up.");
	}
	Vector_Int *z = new_Vector_Int (v->length, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int i;
	for (i = 0; i < v->length; i++) {
		z->elements[i] = v->elements[i] + w->elements[i];
	}
	return z;
}

void stretch_Vector_Int (Vector_Int **v) {
	Vector_Int *w = new_Vector_Int((*v)->length + 1, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int i;
	for (i =  0; i < (*v)->length; i++) {
		w->elements[i] = (*v)->elements[i];
	}
	delete_Vector_Int(*v);
	*v = w;
}

void push_Vector_Int (Vector_Int **v, int element) {
	stretch_Vector_Int(v);
	(*v)->elements[(*v)->length - 1] = element;
}

int pop_Vector_Int (Vector_Int **v) {
	Vector_Int *w = new_Vector_Int((*v)->length, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int poppedvalue = (*v)->elements[(*v)->length - 1];
	int i = 0;
	for (i = 0; i < (*v)->length - 1; i++) {
		w->elements[i] = (*v)->elements[i];
	}
	delete_Vector_Int(*v);
	*v = w;
	return poppedvalue;
}
