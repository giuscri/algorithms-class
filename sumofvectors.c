#include <stdlib.h>
#include <time.h>

#include "Vector_Int.h"

int main () {
	srand(time(NULL));
	Vector_Int *v = new_Vector_Int(10, rand);
	Vector_Int *w = new_Vector_Int(10, rand);
	Vector_Int *sum = sum_Vector_Int(v, w);
	delete_Vector_Int(sum);
	delete_Vector_Int(w);
	delete_Vector_Int(v);
	return 0;
}
