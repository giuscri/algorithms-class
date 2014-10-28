#include <stdlib.h>

#include "Vector_Fibonacci.h"

Vector_Fibonacci *new_Vector_Fibonacci (size_t length) {
	Vector_Fibonacci *v = new_Vector_Int(0, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int i;
	for (i = 0; i < length; i++) {
		push_Vector_Fibonacci(&v, getfibonaccielement(i));
	}
	return v;
}

void push_Vector_Fibonacci (Vector_Fibonacci **v, int element) {
	push_Vector_Int((Vector_Int**)v, element);
}

void print_Vector_Fibonacci (const Vector_Fibonacci *v) {
	print_Vector_Int((Vector_Int*)v);
}

void delete_Vector_Fibonacci (Vector_Fibonacci *v) {
	delete_Vector_Int((Vector_Int*)v);
}

int getfibonaccielement (int index) {
	int fibelement = 0;
	if (index < 2) {
		fibelement = 1;
	}
	else {
		fibelement = getfibonaccielement(index - 1) + getfibonaccielement(index - 2);
	}
	return fibelement;
}
