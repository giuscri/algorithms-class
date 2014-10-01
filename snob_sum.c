#include <stdio.h>

int main () {
	int sum = 0;
	int snob_counter;
	for (snob_counter = 0; snob_counter < 10;) {
		printf("Type in a new term: ");
		int last_term;
		scanf("%d", &last_term);
		sum = sum + last_term;
		if (last_term != 0) {
			snob_counter = snob_counter + 1;
		}
	}
	printf("Total sum is: %d\n", sum);
	return 0;
}
