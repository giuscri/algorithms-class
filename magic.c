#include <stdio.h>
#include <stdlib.h>

void printarray_Int (int *v, int v_length) {
	printf("[ ");
	for (int i = 0; i < v_length; i++) {
		printf("%2d ", v[i]);
	}
	printf("]");
}

void printmatrix_Int (int **m, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		printarray_Int(m[i], cols);
		printf("\n");
	}
}

void fillmatrixasmagic_Int (int **m, int rows, int cols) {
	int rows_position;
	int cols_position;
	rows_position = 0;
	cols_position = cols / 2;
	for (int n_insertions = 0; n_insertions < (rows * cols);) {
		if (rows_position < 0) {
			rows_position = rows + rows_position;
		}
		else if (rows_position >= rows) {
			rows_position = rows_position - rows;
		}
		if (cols_position >= cols) {
			cols_position = cols_position - cols;
		}
		else if (cols_position < 0) {
			cols_position = cols + cols_position;
		}
		if (m[rows_position][cols_position] > 0) {
			rows_position = rows_position + 2;
			cols_position = cols_position - 1;
			continue;
		}
		m[rows_position][cols_position] = n_insertions + 1;
		n_insertions = n_insertions + 1;
		rows_position = rows_position - 1;
		cols_position = cols_position + 1;
	}
}

int main () {
	int rows;
	int cols;
	rows = cols = 5;
	int **m = (int**)malloc(sizeof(int*) * cols);
	for (int i = 0; i < cols; i++) {
		m[i] = malloc(sizeof(int) * rows);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m[i][j] = 0;
		}
	}
	fillmatrixasmagic_Int(m, rows, cols);
	printmatrix_Int(m, rows, cols);
	// Missing tests ...
	//...
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			free(m[j]);
		}
	}
	free(m);
	return 0;
}
