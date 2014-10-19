#include <stdlib.h>
#include <stdio.h>

void fillarray (int *v, size_t v_length, int (*cb)()) {
	for (int i = 0; i < v_length; i++) {
		v[i] = cb();
	}
}

int main () {
	int *v = (int*)calloc(10, sizeof(int));
	size_t v_length = 10;
	fillarray(v, v_length, rand);
	for (int i = 0; i < v_length; i++) {
		printf("%d ", v[i]);
	}
	free(v);
	return 0;
}
