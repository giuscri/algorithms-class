#ifndef VECTOR_INT_H
#define VECTOR_INT_H
typedef struct {
	int *elements;
	int length;
} Vector_Int;

Vector_Int *new_Vector_Int (int length, int (*cb) ());

void delete_Vector_Int (Vector_Int *v);

void print_Vector_Int (const Vector_Int *v);

Vector_Int *sum_Vector_Int (const Vector_Int *v, const Vector_Int *w);
#endif
