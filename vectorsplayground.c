#include "Vector_Int.h"

int main () {
	Vector_Int *v = new_Vector_Int(0, ({
		int __fn__ () { return 0; }
		__fn__;
	}));
	int i;
	for (i = 0; i < 10; i++) {
		push_Vector_Int(&v, i);
	}
	print_Vector_Int(v);
	delete_Vector_Int(v);
	return 0;
}
