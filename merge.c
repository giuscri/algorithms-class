#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray_int (int *A, int A_length) {
	int i;
	for (i = 0; i < A_length; i = i + 1) {
		printf("Element %d: %3d\n", i, A[i]);
	}
	return;
}

void merge (int *A, int p, int q, int r) {
	int subA_length = r - p + 1;
	int L_length = q - p + 1;
	int R_length = r - q;
	int *L = malloc(sizeof(int) * (L_length + 1));
	int *R = malloc(sizeof(int) * (R_length + 1));
	int i, j;
	for (i = 0; i < L_length; i = i + 1) {
		L[i] = A[p + i];
	}
	for (j = 0; j < R_length; j = j + 1) {
		R[j] = A[q + 1 + j];
	}
	L[L_length] = R[R_length] = INT_MAX;
	int k;
	for (k = p, i = 0, j = 0; k < subA_length;) {
		// If the lower value is on the left
		// array, copy it into A and move
		// to the next value
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		// If the lower value is on the right
		// array, copy it into A and move
		// to the next value
		else {
			A[k] = R[j];
			j = j + 1;
		}
		// Increment index k such to point
		// to the next cell of memory of A
		k = k + 1;
	}
	// Preventing memory leaking here ...
	free(L);
	free(R);
	return;
}

int main () {
	int A[] = {172, 421, 213, 389};
	int A_length = 4;
	printf("Printing NOT sorted A ...\n");
	printArray_int(A, A_length);
	// Merge A[0..1] with A[2..3]
	merge(A, 0, 1, 3);
	printf("Printing sorted A ...\n");
	printArray_int(A, A_length);
	return 0;
}
