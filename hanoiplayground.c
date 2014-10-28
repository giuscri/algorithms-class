#include <stdio.h>

#include "Hanoi.h"

int main () {
	Tower_Hanoi *th = new_Tower_Hanoi();
	int i = 0;
	for (i = 0; i < 5; i++) {
		push_Stack_Int(&(th->pegs[0]), 5 - i);
	}
	print_Tower_Hanoi(th);
	printf("\n");
	movedisksfromtovia(&th, 5, 0, 2, 1);
	print_Tower_Hanoi(th);
	printf("\n");
	delete_Tower_Hanoi(th);
	return 0;
}
