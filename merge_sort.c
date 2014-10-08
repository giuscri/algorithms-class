#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//#define DEBUG

void printArray_int (int *A, int A_length) {
	printf("[ ");
	int i;
	for (i = 0; i < A_length; i = i + 1) {
		printf("%d ", A[i]);
	}
	printf("]");
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
	L[L_length] = R[R_length] = INT_MAX;
	int k;
	for (k = p, i = 0, j = 0; (k - p) < subA_length;) {
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
	// Preventing memory leaking here
	free(L);
	free(R);
	return;
}

void merge_sort(int *A, int from, int to) {
	// If from >= to we have at most one
	// element which is already sorted
	// by definition. Otherwise ...
	if (from < to) {
		// ... find a middle_index such
		// to call recursively this function ...
		int middle_index = (from + to) / 2;
		#ifdef DEBUG
		printf("[-] Calling merge_sort on A[%d..%d]: ", from, middle_index);
		printArray_int(A + from, middle_index - from + 1);
		printf("\n");
		#endif
		// ... on A[from..middle_index] ...
		merge_sort(A, from, middle_index);
		#ifdef DEBUG
		printf("[-] Calling merge_sort on A[%d..%d]: ", middle_index + 1, to);
		printArray_int(A + middle_index + 1, to - middle_index);
		printf("\n");
		#endif
		// ... and on A[middle_index + 1..to] ...
		merge_sort(A, middle_index + 1, to);
		#ifdef DEBUG
		printf("[-] Merging ");
		printArray_int(A + from, middle_index - from + 1);
		printf(" with ");
		printArray_int(A + middle_index + 1, to - middle_index);
		printf("\n");
		#endif
		// ... hence merge the two sorted subarrays
		merge(A, from, middle_index, to);
	}
	return;
}

int main () {
	int A[] = {172, 421, 213, 543};
	int A_length = 4;
	printf("[*] Starting from ");
	printArray_int(A, A_length);
	printf("\n");
	// Test the merge_sort on A
	merge_sort(A, 0, A_length - 1);
	printf("[*] Ending with ");
	printArray_int(A, A_length);
	printf("\n\n");
	int B[] = {172, 421, 542, 213, 717};
	int B_length = 5;
	printf("[*] Starting from ");
	printArray_int(B, B_length);
	printf("\n");
	// Test the merge_sort on B
	merge_sort(B, 0, B_length - 1);
	printf("[*] Ending with ");
	printArray_int(B, B_length);
	printf("\n\n");
	int C[] = {2, 4, 5, 7, 1, 2, 3, 6};
	int C_length = 8;
	printf("[*] Starting from ");
	printArray_int(C, C_length);
	printf("\n");
	// Test the merge_sort on C
	merge_sort(C, 0, C_length - 1);
	printf("[*] Ending with ");
	printArray_int(C, C_length);
	printf("\n");
	return true;
}
