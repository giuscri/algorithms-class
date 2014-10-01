#include <stdio.h>

int main () {
	int upper_bound, lower_bound;
	for (lower_bound = 0, upper_bound = 1000;;) {
		char answer, lf;
		printf("Is %d? ", (upper_bound - lower_bound) / 2);
		scanf("%c%c", &answer, &lf);
		if (answer == '=') {
			printf("I won, bro.\n");
			break;
		} else if (answer == '<') {
			upper_bound = (upper_bound - lower_bound) / 2;
		} else if (answer == '>') {
			lower_bound = (upper_bound - lower_bound) / 2;
		}
	}
	return 0;
}
