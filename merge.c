#include <stdio.h>
#include <stdlib.h>

void printArray_int (int *A, int A_length) {
	int i;
	for (i = 0; i < A_length; i++) {
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
	for (i = 0; i < L_length; i++) {
		L[i] = A[p + i];
	}
	for (j = 0; j < R_length; j++) {
		R[j] = A[q + 1 + j];
	}
	int k;
	for (k = p, i = 0, j = 0; k < subA_length;) {
		// If there's no value for the array
		// on the left, consume every value
		// from the right array and copy them
		// into A
		if (i >= L_length) {
			for (; k < subA_length && j < R_length;) {
				A[k] = R[j];
				k =  k + 1;
				j =  j + 1;
			}
			break;
		}
		// If there's no value for the array
		// on the right, consume every value
		// from the left array and copy them
		// into A
		if (j >= R_length) {
			for (; k < subA_length && i < L_length;) {
				A[k] = L[i];
				k = k + 1;
				i = i + 1;
			}
			break;
		}
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
