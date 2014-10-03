#include <stdio.h>

int main () {
	printf("Please type the dimension of our next draw: ");
	int number_of_rows, number_of_cols;
	scanf("%d", &number_of_rows);
	number_of_cols = number_of_rows;
	if (!(number_of_rows % 2)) {
		printf("We can only accept odd dimensions.\n");
		return 1;
	}
	int rows_index, cols_index;
	char temporary_character;
	int left_body_bound, right_body_bound;
	left_body_bound = right_body_bound = number_of_cols / 2;
	for (rows_index = 0; rows_index < number_of_rows; rows_index++) {
		for (cols_index = 0; cols_index < number_of_cols; cols_index++) {
			if (left_body_bound <= cols_index && cols_index <= right_body_bound) {
				temporary_character = 'o';
			} else {
				temporary_character = '|';
			}
			printf("%c", temporary_character);
		}
		if (rows_index < (number_of_rows / 2)) {
			left_body_bound = left_body_bound - 1;
			right_body_bound = right_body_bound + 1;
		} else {
			left_body_bound = left_body_bound + 1;
			right_body_bound = right_body_bound - 1;
		}
		printf("\n");
	}
	return 0;
}
