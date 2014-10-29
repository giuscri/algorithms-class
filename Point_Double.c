#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "Point_Double.h"

Point_Double *new_Point_Double (double x, double y) {
	Point_Double *p = (Point_Double*)calloc(1, sizeof(Point_Double));
	p->x = x;
	p->y = y;
	return p;
}

void print_Point_Double (const Point_Double *p) {
	printf("(%f, %f)", p->x, p->y);
}

void delete_Point_Double (Point_Double *p) {
	free(p);
}

size_t distance_Point_Double (const Point_Double *p, const Point_Double *q) {
	return (size_t)sqrt(pow((double)abs(p->x - q->x), (double)2) + pow((double)abs(p->y - q->y), (double)2));
}

bool equal_Point_Double (const Point_Double *p, const Point_Double *q) {
	return p->x == q->x && p->y && q->y;
}
