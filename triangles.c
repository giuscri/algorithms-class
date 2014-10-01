#include <stdio.h>

int is_triangolizable(int *dimensions) {
	if (
		dimensions[2] < (dimensions[0] + dimensions[1]) &&
		dimensions[1] < (dimensions[0] + dimensions[2]) &&
		dimensions[0] < (dimensions[1] + dimensions[2])
	) {
		return 1;
	} else {
		return 0;
	}
}

int main () {
	int dimensions[3];
	int i;
	for (i = 0; i < 3; i++) {
		printf("Type a dimension: ");
		scanf("%d", &dimensions[i]);
	}
	if (is_triangolizable(dimensions)) {
		printf("Numbers typed might be the ones of a triangle.\n");
	} else {
		printf("Numbers typed can NOT be the ones of a triangle.\n");
	}
	return 0;
}
