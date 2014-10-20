#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
	int **elements;
	size_t n;
	size_t m;
} Matrix_Char;

Matrix_Char *initmatrix (size_t n, size_t m) {
	Matrix_Char *mat = (Matrix_Char*)calloc(1, sizeof(Matrix_Char));
	mat->n = n;
	mat->m = m;
	mat->elements = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat->elements[i] = (int*)calloc(m, sizeof(int));
		for (int j = 0; j < mat->m; j++) {
			mat->elements[i][j] = '.';
		}
	}
	return mat;
}

void delete_Matrix_Char (Matrix_Char *mat) {
	for (int i = 0; i < mat->n; i++) {
		free(mat->elements[i]);
	}
	free(mat->elements);
	free(mat);
}

void printrow_Matrix_Char (int *row, size_t row_length) {
	printf("[");
	for (int i = 0; i < row_length; i++) {
		printf("%c ", row[i]);
	}
	printf("]");
}

void print_Matrix_Char (Matrix_Char *mat) {
	for (int i = 0; i < mat->n; i++) {
		printrow_Matrix_Char(mat->elements[i], mat->m);
		printf("\n");
	}
}

bool noroomleft (Matrix_Char *mat, int rowsindex, int colsindex) {
	bool noroomleft, noroomright, noroomup, noroomdown;
	noroomleft = noroomright = noroomup = noroomdown = true;
	if (rowsindex == 0) {
		noroomup = true;
	}
	else if (mat->elements[rowsindex - 1][colsindex] == '.') {
		noroomup = false;
	}
	if (rowsindex >= mat->n - 1) {
		noroomdown = true;
	}
	else if (mat->elements[rowsindex + 1][colsindex] == '.') {
		noroomdown = false;
	}
	if (colsindex == 0) {
		noroomleft = true;
	}
	else if (mat->elements[rowsindex][colsindex - 1] == '.') {
		noroomleft = false;
	}
	if (colsindex >= mat->m - 1) {
		noroomright = true;
	}
	else if (mat->elements[rowsindex][colsindex + 1] == '.') {
		noroomright = false;
	}
	return noroomleft && noroomright && noroomup && noroomdown;
}

void randomwriteon_Matrix_Char (Matrix_Char *mat) {
	enum { up=0, down=1, left=2, right=3 };
	char value = 'A';
	srand((unsigned int)time(NULL));
	for (int rowsindex = 0, colsindex = 0; value <= 'Z';) {
		mat->elements[rowsindex][colsindex]= value;
		if (noroomleft(mat, rowsindex, colsindex)) {
			break;
		}
		int move = rand() % 4;
		if (move == up && rowsindex == 0) {
			continue;
		}
		else if (move == up && mat->elements[rowsindex - 1][colsindex] == '.') {
			rowsindex -= 1;
			value += 1;
		}
		else if (move == left && colsindex == 0) {
			continue;
		}
		else if (move == left && mat->elements[rowsindex][colsindex - 1] == '.') {
			colsindex -= 1;
			value += 1;
		}
		else if (move == right && colsindex >= mat->m - 1) {
			continue;
		}
		else if (move == right && mat->elements[rowsindex][colsindex + 1] == '.') {
			colsindex += 1;
			value += 1;
		}
		else if (move == down && rowsindex >= mat->n - 1) {
			continue;
		}
		else if (move == down && mat->elements[rowsindex + 1][colsindex] == '.') {
			rowsindex += 1;
			value += 1;
		}
	}
}

int main () {
	Matrix_Char *mat = initmatrix(10, 10);
	randomwriteon_Matrix_Char(mat);
	print_Matrix_Char(mat);
	delete_Matrix_Char(mat);
	return 0;
}
