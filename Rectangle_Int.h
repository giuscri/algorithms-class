#ifndef _RECTANGLE_INT_H
#define _RECTANGLE_INT_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	Point_Int *lowerleft;
	Point_Int *upperright;
} Rectangle_Int;

Rectangle_Int *new_Rectangle_Int (Point_Int *ll, Point_Int *ur);

void delete_Rectangle_Int (Rectangle_Int *r);

void print_Rectangle_Int (const Rectangle_Int *r);

size_t computearea_Rectangle_Int (const Rectangle_Int *r);

Point_Int *computecenter_Rectangle_Int (const Rectangle_Int *r);

void translate_Rectangle_Int (Rectangle_Int *r, int v_x, int v_y);

bool pointinside_Rectangle_Int (const Rectangle_Int *r, const Point_Int *p);
#endif
