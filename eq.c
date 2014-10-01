#include <stdio.h>
#include <math.h>

int computing_delta_from(int a, int b, int c) {
	return pow((double)b, 2) - 4 * a * c;
}

int main () {
	int coefficients[3];
	int i = 0;
	for (i = 0; i < 3; i++) {
		char temporary_character = 'a';
		printf("Type '%c': ", temporary_character + i);
		scanf("%d", &coefficients[i]);
	}
	int delta = computing_delta_from(coefficients[0], coefficients[1], coefficients[2]);
	if (delta < 0) {
		printf("First radix is: %.2f - %.2f i\n", (-1. * coefficients[1] / (2 * coefficients[0])), sqrt(-delta) / (2. * coefficients[0]));
		printf("Second radix is: %.2f + %.2f i\n", (-1. * coefficients[1] / (2 * coefficients[0])), sqrt(-delta) / (2. * coefficients[0]));
	} else if (delta > 0) {
		double first_radix = (-1. * coefficients[1] - sqrt(delta)) / (2 * coefficients[0]);
		double second_radix = (-1. * coefficients[1] + sqrt(delta)) / (2 * coefficients[0]);
		printf("First radix is: %.2f\n", first_radix);
		printf("Second radix is: %.2f\n", second_radix);

	} else {
		printf("Single radix is: %.2f\n", -1. * coefficients[1] / (2 * coefficients[0]));
	}
	return 0;
}
