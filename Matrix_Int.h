#include "Vector_Int.h"

#ifndef MATRIX_INT_H
#define MATRIX_INT_H
typedef struct {
	Vector_Int **elements;
	int n;
	int m;
} Matrix_Int;

Matrix_Int *new_Matrix_Int (int n, int m, int (*cb) ());

void delete_Matrix_Int (Matrix_Int *mat);

void print_Matrix_Int (const Matrix_Int *mat);

Matrix_Int *sum_Matrix_Int (const Matrix_Int *m1, const Matrix_Int *m2);
#endif
