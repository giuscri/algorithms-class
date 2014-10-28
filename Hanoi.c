#include <stdlib.h>
#include <stdio.h>

#include "Hanoi.h"

Tower_Hanoi *new_Tower_Hanoi () {
	Tower_Hanoi *th = (Tower_Hanoi*)calloc(1, sizeof(Tower_Hanoi));
	th->numberofpegs = 3;
	th->pegs = (Stack_Int**)calloc(th->numberofpegs, sizeof(Stack_Int*));
	int i = 0;
	for (i = 0; i < th->numberofpegs; i++) {
		th->pegs[i] = new_Stack_Int();
	}
	return th;
}

void movedisksfromtovia (Tower_Hanoi **th, size_t numberofdisks, int from, int to, int via) {
	if (numberofdisks < 2) {
		int popped_element = pop_Stack_Int(&((*th)->pegs[from]));
		push_Stack_Int(&((*th)->pegs[to]), popped_element);
	}
	else {
		movedisksfromtovia(th, numberofdisks - 1, from, via, to);
		movedisksfromtovia(th, 1, from, to, via);
		movedisksfromtovia(th, numberofdisks - 1, via, to, from);
	}
}

void delete_Tower_Hanoi (Tower_Hanoi *th) {
	int i = 0;
	for (i = 0; i < th->numberofpegs; i++) {
		delete_Stack_Int(th->pegs[i]);
	}
	free(th->pegs);
	free(th);
}

void print_Tower_Hanoi (Tower_Hanoi *th) {
	int i = 0;
	for (i = 0; i < th->numberofpegs; i++) {
		print_Stack_Int(th->pegs[i]);
	}
}
