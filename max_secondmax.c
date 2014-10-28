#include <assert.h>

void max_secondmax (int a[], int n, int *max, int *second_max) {
	*max = 0;
	*second_max = 0;
	int i = 0;
	for (i = 0, *max = *second_max = a[0]; i < n; i++) {
		if (a[i] > *max) {
			*second_max = *max;
			*max = a[i];
		}
	}
}

int main () {
	int max = 0;
	int second_max = 0;
	int a[] = {1, 2, 3, 4};
	int n = 4;
	max_secondmax(a, n, &max, &second_max);
	assert(max == 4 && second_max == 3 && "max_secondmax test failed.");
	return 0;
}
