#include <stdlib.h>

#include "Vector_Int.h"
#include "Matrix_Int.h"

int main () {
	srand(time(NULL));
	Matrix_Int *m = new_Matrix_Int(10, 10, rand);
	Matrix_Int *n = new_Matrix_Int(10, 10, rand);
	Matrix_Int *s = sum_Matrix_Int(m, n);
	delete_Matrix_Int(s);
	delete_Matrix_Int(n);
	delete_Matrix_Int(m);
	return 0;
}
