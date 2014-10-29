#include <stdio.h>
#include <assert.h>

#include "Point_Double.h"
#include "Rectangle_Double.h"

int main () {
	Rectangle_Double *r = new_Rectangle_Double(new_Point_Double(0., 0.), new_Point_Double(2., 4.));
	assert(computearea_Rectangle_Double(r) == (size_t)8 && "Computing area test failed.");
	Point_Double *c = new_Point_Double(1., 2.);
	Point_Double *cc = computecenter_Rectangle_Double(r);
	assert(equal_Point_Double(c, cc) && "Computing center test failed.");
	translate_Rectangle_Double(r, 2., 2.);
	delete_Point_Double(cc);
	delete_Point_Double(c);
	c = new_Point_Double(1., 1.);
	cc = computecenter_Rectangle_Double(r);
	assert(equal_Point_Double(c, cc) && "Computing center test -- after shift -- failed.");
	delete_Point_Double(c);
	c = new_Point_Double(3., 5.);
	assert(pointinside_Rectangle_Double(r, c) == true && "Computing pointinside test failed.");
	delete_Point_Double(c);
	c = new_Point_Double(1., 8.);
	assert(pointinside_Rectangle_Double(r, c) == false && "Computing pointinside test failed.");
	delete_Point_Double(c);
	delete_Point_Double(cc);
	delete_Rectangle_Double(r);
	return 0;
}

