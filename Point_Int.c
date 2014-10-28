#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "Point_Int.h"

Point_Int *new_Point_Int (int x, int y) {
	Point_Int *p = (Point_Int*)calloc(1, sizeof(Point_Int));
	p->x = x;
	p->y = y;
	return p;
}

void print_Point_Int (const Point_Int *p) {
	printf("(%d, %d)", p->x, p->y);
}

void delete_Point_Int (Point_Int *p) {
	free(p);
}

size_t distance_Point_Int (const Point_Int *p, const Point_Int *q) {
	return (size_t)sqrt(pow((double)abs(p->x - q->x), (double)2) + pow((double)abs(p->y - q->y), (double)2));
}

bool equal_Point_Int (const Point_Int *p, const Point_Int *q) {
	return p->x == q->x && p->y && q->y;
}
