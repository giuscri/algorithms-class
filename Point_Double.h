#ifndef _POINT_DOUBLE_H
#define _POINT_DOUBLE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	double x;
	double y;
} Point_Double;

Point_Double *new_Point_Double (double x, double y);

void print_Point_Double (const Point_Double *p);

void delete_Point_Double (Point_Double *p);

size_t distance_Point_Double (const Point_Double *p, const Point_Double *q);

bool equal_Point_Double (const Point_Double *p, const Point_Double *q);
#endif
