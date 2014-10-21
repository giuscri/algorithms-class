#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
	int *elements;
	int length;
} Vector_Int;

typedef struct {
	Vector_Int **elements;
	int n;
	int m;
} Matrix_Int;

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

void delete_Vector_Int (Vector_Int *v) {
        free(v->elements);
        free(v);
}

void delete_Matrix_Int (Matrix_Int *mat) {
	int i;
	for (i = 0; i < mat->n; i++) {
		delete_Vector_Int(mat->elements[i]);
	}
	free(mat->elements);
	free(mat);
}

void print_Vector_Int (const Vector_Int *v) {
        printf("[ ");
        int i;
        for (i = 0; i < v->length; i++) {
                printf("%d ", v->elements[i]);
        }
        printf("]");
}

void print_Matrix_Int (const Matrix_Int *mat) {
	int i;
	for (i = 0; i < mat->n; i++) {
		print_Vector_Int(mat->elements[i]);
		printf("\n");
	}
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

int main () {
	srand(time(NULL));
	Matrix_Int *m = new_Matrix_Int(10, 10, rand);
	Matrix_Int *n = new_Matrix_Int(10, 10, rand);
	Matrix_Int *s = sum_Matrix_Int(m, n);
	print_Matrix_Int(s);
	delete_Matrix_Int(s);
	delete_Matrix_Int(n);
	delete_Matrix_Int(m);
	return 0;
}
