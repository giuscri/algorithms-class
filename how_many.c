#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void printarray_Int(int *v, int v_length) {
	printf("[ ");
	for (int i = 0; i < v_length; i++) {
		printf("%d ", v[i]);
	}
	printf("]");
}

void initializearray_Int(int **v, int v_length, int initializing_value) {
	for (int i = 0; i < v_length; i++) {
		(*v)[i] = initializing_value;
	}
}

void resizearray_Int(int **v, int v_length, int desired_length) {
	if (desired_length > v_length) {
		printf("resizearray_Int: cannot resize to longer length.\n");
		exit(1);
	}
	int *tmp = malloc(sizeof(int) * desired_length);
	for (int i = 0; i < desired_length; i++) {
		tmp[i] = (*v)[i];
	}
	free(*v);
	*v = tmp;
}

int countdigits_Int (int number) {
	int number_of_digits = 0;
	for (int i = 1, tmp_number = number;; i++) {
		tmp_number /= 10;
		if (tmp_number < 1) {
			number_of_digits = i;
			break;
		}
	}
	return number_of_digits;
}

void fillarraywith_Int (int **digits, int *digits_length, int number) {
	*digits_length = countdigits_Int(number);
	// Create an array of length <digits_length>
	*digits = malloc(sizeof(int) * *digits_length);
	// Fill it with the digits of number via %10'ing
	for (int i = 0, tmp_number = number; i < *digits_length; i++) {
		(*digits)[i] = tmp_number % 10;
		tmp_number /= 10;
		if (tmp_number < 1) {
			break;
		}
	}
}

void fillarraywithduplicatesfrom_Int (int **duplicates, int *duplicates_length, int *digits, int digits_length) {
	// Create a new array of length <number_of_digits>
	// since duplicates are <= <number_of_digits>
	*duplicates = malloc(sizeof(int) * digits_length);
	*duplicates_length = digits_length;
	// ...
	initializearray_Int(duplicates, *duplicates_length, 0);
	// Traversing over the first array, fill the second
	// only with the duplicates in the first AND
	// if not already in the second
	bool already_in = false;
	// Iterating over the digits array ...
	for (int i = 0, h = 0; i < digits_length; i++) {
		for (int j = i + 1; j < digits_length; j++) {
			// If found a duplicate ...
			if (digits[i] == digits[j]) {
				// ... that's not already loaded ...
				for (int k = i - 1; k >= 0; k--) {
					if (digits[i] == (*duplicates)[k]) {
						already_in = true;
						break;
					}
				}
				// ... save it into duplicates!
				if (!already_in) {
					(*duplicates)[h] = digits[i];
					h = h + 1;
					*duplicates_length = h;
					break;
				}
			}
		}
	}
	// Resizing, using digits_lengt as initial length
	// since we allocated digits_length * sizeof(int) bytes
	resizearray_Int(duplicates, digits_length, *duplicates_length);
}

void how_many (int number, int **duplicates, int *duplicates_length) {
	// Count the number of digits via dividing
	// by 10. The number of times needed to
	// obtain 0, is the number of digits
	int digits_length;
	int *digits;
	fillarraywith_Int(&digits, &digits_length, number);
	// Initialize the duplicates array with 0's
	fillarraywithduplicatesfrom_Int(duplicates, duplicates_length, digits, digits_length);
	free(digits);
}

int main () {
	int *duplicates;
	int duplicates_length;
	how_many(33010, &duplicates, &duplicates_length);
	printarray_Int(duplicates, duplicates_length);
	printf("\n");
	int testerarray[] = { 0, 3 };
	for (int i = 0; i < duplicates_length; i++) {
		if (testerarray[i] != duplicates[i]) {
			assert(false && "Test on '33010' failed.");
		}
	}
	free(duplicates);
	return 0;
}
