#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void printarray_Int (int *v, int v_length, bool reverse) {
	printf("[ ");
	if (reverse) {
		for (int i = v_length - 1; i >= 0; i--) {
			printf("%d ", v[i]);
		}
	}
	else {
		for (int i = 0; i < v_length; i++) {
			printf("%d ", v[i]);
		}
	}
	printf("]");
	return;
}

int main () {
	int v[MAX_LENGTH];
	int v_length = 0;
	printf("Type a sequence of numbers: \n");
	for (int i = 0; i < MAX_LENGTH; i++) {
		int tmp, lf;
		scanf("%d", &tmp);
		scanf("%c", &lf);
		v[i] = tmp;
		v_length = i;
		if (tmp < 1) {
			break;
		}
	}
	printarray_Int(v, v_length, true);
	printf("\n");
	return 0;
}
