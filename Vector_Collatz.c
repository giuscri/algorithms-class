#include <stdio.h>

#include "Vector_Collatz.h"

Vector_Collatz *new_Vector_Collatz (int seed) {
	Vector_Collatz *c = new_Vector_Int(0, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int tmp;
	for (tmp = seed; tmp != 1;) {
		push_Vector_Collatz(&c, tmp);
		if (tmp % 2) {
			tmp *= 3;
			tmp += 1;
		}
		else {
			tmp /= 2;
		}
	}
	push_Vector_Collatz(&c, 1);
	return c;
}

void push_Vector_Collatz (Vector_Collatz **v, int element) {
	push_Vector_Int((Vector_Int**)v, element);
}

void print_Vector_Collatz (const Vector_Collatz *v) {
	print_Vector_Int((Vector_Int*)v);
}

void delete_Vector_Collatz (Vector_Collatz *v) {
	delete_Vector_Int((Vector_Int*)v);
}
