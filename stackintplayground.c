#include <stdio.h>

#include "Stack_Int.h"

int main () {
	Stack_Int *s = new_Stack_Int();
	push_Stack_Int(&s, 37);
	push_Stack_Int(&s, 42);
	print_Stack_Int(s);
	delete_Stack_Int(s);
	return 0;
}
