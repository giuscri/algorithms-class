#include <assert.h>

int *smallest (int a[], int n) {
	int *m;
	int i = 0;
	for (i = 0, m = &(a[0]); i < n; i++) {
		if (a[i] < *m) {
			m = &(a[i]);
		}
	}
	return m;
}

int main () {
	int a[] = {3, 1, 2};
	int *m = smallest(a, 3);
	assert(*m == 1 && "Computing smallest test failed.");
	return 0;
}
