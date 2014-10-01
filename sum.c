#include <stdio.h>

int main () {
	int sum = 0;
	for (;;) {
		printf("Type in a new term: ");
		int last_term;
		scanf("%d", &last_term);
		if (last_term != 0) {
			sum = sum + last_term;
		} else {
			break;
		}
	}
	printf("Total sum is: %d\n", sum);
	return 0;
}
