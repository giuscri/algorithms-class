#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Point_Double.h"
#include "Rectangle_Double.h"

Rectangle_Double *new_Rectangle_Double (Point_Double *ll, Point_Double *ur) {
	Rectangle_Double *r = (Rectangle_Double*)calloc(1, sizeof(Rectangle_Double));
	r->lowerleft = ll;
	r->upperright = ur;
	return r;
}

void delete_Rectangle_Double (Rectangle_Double *r) {
	delete_Point_Double(r->lowerleft);
	delete_Point_Double(r->upperright);
	free(r);
}

void print_Rectangle_Double (const Rectangle_Double *r) {
	print_Point_Double(r->lowerleft);
	printf(" ");
	print_Point_Double(r->upperright);
}

size_t computearea_Rectangle_Double (const Rectangle_Double *r) {
	size_t area = 0;
	Point_Double *lowerright = new_Point_Double(r->upperright->x, r->lowerleft->y);
	area = distance_Point_Double(r->lowerleft, lowerright) * distance_Point_Double(lowerright, r->upperright);
	delete_Point_Double(lowerright);
	return area;
}

Point_Double *computecenter_Rectangle_Double (const Rectangle_Double *r) {
	return new_Point_Double((r->upperright->x - r->lowerleft->x) / 2, (r->upperright->y - r->lowerleft->y) / 2);
}

void translate_Rectangle_Double (Rectangle_Double *r, double v_x, double v_y) {
	r->lowerleft->x = r->lowerleft->x + v_x;
	r->upperright->x = r->upperright->x + v_x;
	r->lowerleft->y = r->lowerleft->y + v_y;
	r->upperright->y = r->upperright->y + v_y;
}

bool pointinside_Rectangle_Double (const Rectangle_Double *r, const Point_Double *p) {
	return r->lowerleft->x <= p->x && p->x <= r->upperright->x &&
		r->lowerleft->y <= p->y && p->y <= r->upperright->y;
}
