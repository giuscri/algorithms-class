#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int *elements;
	int length;
} Vector_Int;

Vector_Int *initvector_Vector_Int () {
	Vector_Int *v = calloc(1, sizeof(Vector_Int));
	v->length = 0;
	return v;
}

void delete_Vector_Int (Vector_Int *v) {
	free(v->elements);
	free(v);
}

void stretchvectorby1_Vector_Int (Vector_Int **v) {
	Vector_Int *tmp = initvector_Vector_Int();
	tmp->elements = calloc((*v)->length + 1, sizeof(int));
	tmp->length = (*v)->length + 1;
	for (int i = 0; i < (*v)->length; i++) {
		tmp->elements[i] = (*v)->elements[i];
	}
	free(*v);
	*v = tmp;
}

void print_Vector_Int (Vector_Int *v) {
	printf("[ ");
	for (int i = 0; i < v->length; i++) {
		printf("%d ", v->elements[i]);
	}
	printf("]");
}

void addelementtovector_Vector_Int (int element, Vector_Int **v) {
	if ((*v)->length < 1) {
		stretchvectorby1_Vector_Int(v);
		(*v)->elements[0] = element;
	}
	else {
		bool elementinserted = false;
		for (int i = 0; i < (*v)->length; i++) {
			if (element <= (*v)->elements[i]) {
				stretchvectorby1_Vector_Int(v);
				for (int j = (*v)->length - 2; j >= i; j--) {
					(*v)->elements[j + 1] = (*v)->elements[j];
				}
				(*v)->elements[i] = element;
				elementinserted = true;
				break;
			}
		}
		if (!elementinserted) {
			stretchvectorby1_Vector_Int(v);
			(*v)->elements[(*v)->length - 1] = element;
		}
	}
}

int main () {
	Vector_Int *v = initvector_Vector_Int();
	printf("Type in your numbs, bitch: ");
	for (int i = 0, d = 0; scanf("%d", &d) && d != 0; i++) {
		addelementtovector_Vector_Int(d, &v);
	}
	print_Vector_Int(v);
	printf("\n");
	delete_Vector_Int(v);
	return 0;
}
