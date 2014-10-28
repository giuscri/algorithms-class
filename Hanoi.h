#ifndef _HANOI_H
#define _HANOI_H

#include <stdlib.h>

#include "Stack_Int.h"

typedef struct {
	Stack_Int **pegs;
	size_t numberofpegs;
} Tower_Hanoi;

Tower_Hanoi *new_Tower_Hanoi ();

void movedisksfromtovia (Tower_Hanoi **th, size_t numberofdisks, int from, int to, int via);

void delete_Tower_Hanoi (Tower_Hanoi *th);

void print_Tower_Hanoi (Tower_Hanoi *th);
#endif
