#include <stdio.h>

#include "Vector_Fibonacci.h"

int main () {
	Vector_Fibonacci *v = new_Vector_Fibonacci(25);
	print_Vector_Fibonacci(v);
	delete_Vector_Fibonacci(v);
	printf("\n");
	return 0;
}
