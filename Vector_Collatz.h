#ifndef _VECTOR_COLLATZ_H
#define _VECTOR_COLLATZ_H
#include "Vector_Int.h"

typedef Vector_Int Vector_Collatz;

Vector_Collatz *new_Vector_Collatz (int seed);

void push_Vector_Collatz (Vector_Collatz **v, int element);

void print_Vector_Collatz (const Vector_Collatz *v);

void delete_Vector_Collatz (Vector_Collatz *v);
#endif
