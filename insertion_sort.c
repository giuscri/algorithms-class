#include <stdio.h>

int main () {
	// DISCLAIMER: we use to initialize values to 0 even when we're not
	// meant to use them immediately, since we do not like undefined behaviours.
	// Here's the original array ...
	int v_size = 5;
	int v[] = {2, 3, 1, 5, -2};
	int left_index = 0;
	// Now sort it ...
	int right_index = 0;
	for (right_index = 1; right_index < v_size; right_index++) {
		for (left_index = right_index - 1; left_index >= 0; left_index--) {
			if (v[left_index] > pivot_value) {
				v[left_index + 1] = v[left_index];
			} else {
				break;
			}
		}
		v[left_index + 1] = v[right_index];
	}
	// Then print the resulting array ...
	for (left_index = 0; left_index < v_size; left_index++) {
		printf("v[%d]: %d\n", left_index, v[left_index]);
	}
	return 0;
}
