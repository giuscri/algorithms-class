#ifndef _RECTANGLE_DOUBLE_H
#define _RECTANGLE_DOUBLE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	Point_Double *lowerleft;
	Point_Double *upperright;
} Rectangle_Double;

Rectangle_Double *new_Rectangle_Double (Point_Double *ll, Point_Double *ur);

void delete_Rectangle_Double (Rectangle_Double *r);

void print_Rectangle_Double (const Rectangle_Double *r);

size_t computearea_Rectangle_Double (const Rectangle_Double *r);

Point_Double *computecenter_Rectangle_Double (const Rectangle_Double *r);

void translate_Rectangle_Double (Rectangle_Double *r, double v_x, double v_y);

bool pointinside_Rectangle_Double (const Rectangle_Double *r, const Point_Double *p);
#endif
