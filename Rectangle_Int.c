#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Point_Int.h"
#include "Rectangle_Int.h"

Rectangle_Int *new_Rectangle_Int (Point_Int *ll, Point_Int *ur) {
	Rectangle_Int *r = (Rectangle_Int*)calloc(1, sizeof(Rectangle_Int));
	r->lowerleft = ll;
	r->upperright = ur;
	return r;
}

void delete_Rectangle_Int (Rectangle_Int *r) {
	delete_Point_Int(r->lowerleft);
	delete_Point_Int(r->upperright);
	free(r);
}

void print_Rectangle_Int (const Rectangle_Int *r) {
	print_Point_Int(r->lowerleft);
	printf(" ");
	print_Point_Int(r->upperright);
}

size_t computearea_Rectangle_Int (const Rectangle_Int *r) {
	size_t area = 0;
	Point_Int *lowerright = new_Point_Int(r->upperright->x, r->lowerleft->y);
	area = distance_Point_Int(r->lowerleft, lowerright) * distance_Point_Int(lowerright, r->upperright);
	delete_Point_Int(lowerright);
	return area;
}

Point_Int *computecenter_Rectangle_Int (const Rectangle_Int *r) {
	return new_Point_Int((r->upperright->x - r->lowerleft->x) / 2, (r->upperright->y - r->lowerleft->y) / 2);
}

void translate_Rectangle_Int (Rectangle_Int *r, int v_x, int v_y) {
	r->lowerleft->x = r->lowerleft->x + v_x;
	r->upperright->x = r->upperright->x + v_x;
	r->lowerleft->y = r->lowerleft->y + v_y;
	r->upperright->y = r->upperright->y + v_y;
}

bool pointinside_Rectangle_Int (const Rectangle_Int *r, const Point_Int *p) {
	return r->lowerleft->x <= p->x && p->x <= r->upperright->x &&
		r->lowerleft->y <= p->y && p->y <= r->upperright->y;
}
