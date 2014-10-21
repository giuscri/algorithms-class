#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
	int *elements;
	int length;
} Vector_Int;

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

int main () {
	srand(time(NULL));
	Vector_Int *v = new_Vector_Int(10, rand);
	Vector_Int *w = new_Vector_Int(10, rand);
	Vector_Int *sum = sum_Vector_Int(v, w);
	delete_Vector_Int(sum);
	delete_Vector_Int(w);
	delete_Vector_Int(v);
	return 0;
}
