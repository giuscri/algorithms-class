#include <stdio.h>

int main () {
	printf("Please type the dimension of our next draw: ");
	int largest_rows_index, largest_cols_index;
	scanf("%d", &largest_rows_index);
	largest_cols_index = largest_rows_index;
	int rows_index, cols_index;
	char temporary_character = '+';
	for (rows_index = 0; rows_index < largest_rows_index; rows_index++) {
		for (cols_index = 0; cols_index < largest_cols_index; cols_index++) {
			if (cols_index < rows_index) {
				temporary_character = 'o';
			} else if (cols_index > rows_index) {
				temporary_character = '+';
			} else {
				temporary_character = '|';
			}
			printf("%c", temporary_character);
		}
		printf("\n");
	}
	return 0;
}
