#ifndef _POINT_INT_H
#define _POINT_INT_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} Point_Int;

Point_Int *new_Point_Int (int x, int y);

void print_Point_Int (const Point_Int *p);

void delete_Point_Int (Point_Int *p);

size_t distance_Point_Int (const Point_Int *p, const Point_Int *q);

bool equal_Point_Int (const Point_Int *p, const Point_Int *q);
#endif
