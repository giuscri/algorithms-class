#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printarray_Int(int *v, int v_length) {
	printf("[ ");
	for (int i = 0; i < v_length; i++) {
		printf("%d ", v[i]);
	}
	printf("]");
}

int main () {
	printf("Type in a number: ");
	int in_number;
	#ifdef DEBUG
		in_number = 123;
		printf("%d\n", in_number);
	#else
		scanf("%d", &in_number);
	#endif
	// Count the number of digits via dividing
	// by 10. The number of times needed to
	// obtain 0, is the number of digits
	int digits_length = 0;
	for (int i = 1, tmp_number = in_number;; i++) {
		tmp_number /= 10;
		if (tmp_number < 1) {
			digits_length = i;
			break;
		}
	}
	#ifdef DEBUG
		printf("[DEBUG] digits_length: %d\n", digits_length);
	#endif
	// Create an array of length <digits_length>
	int *digits = malloc(sizeof(int) * digits_length);
	// Fill it with the digits of in_number via %10'ing
	for (int i = 0, tmp_number = in_number; i < digits_length; i++) {
		digits[i] = tmp_number % 10;
		tmp_number /= 10;
		if (tmp_number < 1) {
			break;
		}
	}
	#ifdef DEBUG
		printf("[DEBUG] digits: ");
		printarray_Int(digits, digits_length);
		printf("\n");
	#endif
	// Create a new array of length <number_of_digits>
	int *duplicates = malloc(sizeof(int) * digits_length);
	int duplicates_length = digits_length;
	// Traversing over the first array, fill the second
	// only with the duplicates in the first AND
	// if not already in the second
	bool already_in = false;
	// Iterating over the digits array ...
	for (int i = 0; i < digits_length; i++) {
		for (int j = i + 1; j < digits_length; j++) {
			// If found a duplicate ...
			if (digits[i] == digits[j]) {
				// ... that's not already loaded ...
				for (int k = i - 1; k >= 0; k--) {
					if (digits[i] == duplicates[k]) {
						already_in = true;
						break;
					}
				}
				// ... save it into duplicates!
				if (!already_in) {
					#ifdef DEBUG
						printf("[DEBUG] %d already in!\n", digits[i]);
					#endif
					duplicates[i] = digits[i];
					break;
				}
			}
		}
	}
	bool duplicates_empty = true;
	for (int i = 0; i < duplicates_length; i++) {
		if (duplicates[i] != 0) {
			duplicates_empty = false;
			break;
		}
	}
	// Print the second array if there are duplicates
	if (!duplicates_empty) {
		printf("Initial number has duplicates.\n");
		//printarray_Int(duplicates, duplicates_length);
		//printf("\n");
		printf("[ ");
		for (int i = 0; i < duplicates_length; i++) {
			if (duplicates[i] != 0) {
				printf("%d ", duplicates[i]);
			}
		}
		printf("]\n");
	}
	else {
		printf("Initiali number has NO duplicates.\n");
	}
	free(duplicates);
	free(digits);
	return 0;
}
