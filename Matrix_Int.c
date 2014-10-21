#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Matrix_Int.h"

Matrix_Int *new_Matrix_Int (int n, int m, int (*cb) ()) {
	Matrix_Int *mat = (Matrix_Int*)calloc(1, sizeof(Matrix_Int));
	mat->n = n;
	mat->m = m;
	mat->elements = (Vector_Int**)calloc(n, sizeof(Vector_Int*));
	int i;
	for (i = 0; i < mat->n; i++) {
		mat->elements[i] = new_Vector_Int(m, cb);
	}
	return mat;
}

void delete_Matrix_Int (Matrix_Int *mat) {
	int i;
	for (i = 0; i < mat->n; i++) {
		delete_Vector_Int(mat->elements[i]);
	}
	free(mat->elements);
	free(mat);
}

void print_Matrix_Int (const Matrix_Int *mat) {
	int i;
	for (i = 0; i < mat->n; i++) {
		print_Vector_Int(mat->elements[i]);
		printf("\n");
	}
}

Matrix_Int *sum_Matrix_Int (const Matrix_Int *m1, const Matrix_Int *m2) {
	if ((m1->n != m2->n) && (m1->m != m2->m)) {
		assert(false && "Matrixes MUST have the same dimensions to be summed up.");
	}
	Matrix_Int *s = new_Matrix_Int(m1->n, m1->m, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int i;
	for (i = 0; i < m1->n; i++) {
		delete_Vector_Int(s->elements[i]);
		s->elements[i] = sum_Vector_Int(m1->elements[i], m2->elements[i]);
	}
	return s;
}
