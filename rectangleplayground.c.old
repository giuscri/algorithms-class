#include <stdio.h>
#include <assert.h>

#include "Point_Int.h"
#include "Rectangle_Int.h"

int main () {
	Rectangle_Int *r = new_Rectangle_Int(new_Point_Int(0, 0), new_Point_Int(2, 4));
	print_Rectangle_Int(r);
	printf("\n");
	assert(computearea_Rectangle_Int(r) == (size_t)8 && "Computing area test failed.");
	Point_Int *c = new_Point_Int(1, 2);
	Point_Int *cc = computecenter_Rectangle_Int(r);
	assert(equal_Point_Int(c, cc) && "Computing center test failed.");
	translate_Rectangle_Int(r, 2, 2);
	delete_Point_Int(cc);
	delete_Point_Int(c);
	c = new_Point_Int(1, 1);
	cc = computecenter_Rectangle_Int(r);
	print_Rectangle_Int(r);
	printf("\n");
	assert(equal_Point_Int(c, cc) && "Computing center test -- after shift -- failed.");
	delete_Point_Int(c);
	c = new_Point_Int(3, 5);
	assert(pointinside_Rectangle_Int(r, c) == true && "Computing pointinside test failed.");
	delete_Point_Int(c);
	c = new_Point_Int(1, 8);
	assert(pointinside_Rectangle_Int(r, c) == false && "Computing pointinside test failed.");
	delete_Point_Int(c);
	delete_Point_Int(cc);
	delete_Rectangle_Int(r);
	return 0;
}
