#include <assert.h>

void swap (int *p, int *q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int main () {
	int p;
	int q;
	p = 0;
	q = 1;
	swap(&p, &q);
	assert(p == 1 && q == 0 && "swap(0, 1) failed.");
	return 0;
}
