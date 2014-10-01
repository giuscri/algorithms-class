#include <stdio.h>

int main () {
	int sum = 0;
	int counter;
	for (counter = 0;; counter++) {
		printf("Type in a new term: ");
		int last_term;
		scanf("%d", &last_term);
		if (last_term != 0) {
			sum = sum + last_term;
		} else {
			printf("Final mean is: %d\n", sum / counter);
			break;
		}
	}
	return 0;
}
