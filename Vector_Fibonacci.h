#ifndef _VECTOR_FIBONACCI_H
#define _VECTOR_FIBONACCI_H
#include <stdlib.h>

#include "Vector_Int.h"

typedef Vector_Int Vector_Fibonacci;

Vector_Fibonacci *new_Vector_Fibonacci (size_t length);

void push_Vector_Fibonacci (Vector_Fibonacci **v, int element);

void print_Vector_Fibonacci (const Vector_Fibonacci *v);

int getfibonaccielement (int index);

void delete_Vector_Fibonacci (Vector_Fibonacci *v);
#endif
