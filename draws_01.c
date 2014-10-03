#include <stdio.h>

int main () {
	printf("Please type the dimension of our next draw: ");
	int largest_rows_index, largest_cols_index;
	scanf("%d", &largest_rows_index);
	largest_cols_index = largest_rows_index;
	int rows_index, cols_index;
	char temporary_character = 'o';
	for (rows_index = 0; rows_index < largest_rows_index; rows_index++) {
		for (cols_index = 0; cols_index < largest_cols_index; cols_index++) {
			printf("%c", temporary_character);
			temporary_character = temporary_character == '+' ? 'o' : '+';
		}
		// If the number of colums is even, we need
		// to make a additional flip the tmp character.
		if (!(largest_cols_index % 2)) {
			temporary_character = temporary_character == '+' ? 'o' : '+';
		}
		printf("\n");
	}
	return 0;
}
