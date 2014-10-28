#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "libpsgraph.h"
#include "Koch.h"

void drawKochsegment (int order, size_t length) {
	assert(length != 0 && "Cannot draw 0mm segments.");
	if (order < 1) {
		draw(length);
	}
	else {
		int i = 0;
		for (i = 0; i < 4; i++) {
			int degree = i % 2 > 0 ? 120 : -60;
			if (i >= 3) {
				degree = 0;
			}
			drawKochsegment(order - 1, length / 3);
			turn(degree);
		}
	}
}
