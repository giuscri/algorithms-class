#include "Vector_Collatz.h"

int main () {
	Vector_Collatz *v = new_Vector_Collatz(9);
	print_Vector_Collatz(v);
	delete_Vector_Collatz(v);
	return 0;
}
