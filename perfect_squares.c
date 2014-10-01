#include <stdio.h>
#include <math.h>

int main () {
	int counter, candidate, i;
	for (counter = 0, candidate = 1; counter < 10; candidate++) {
		for (i = 0; i < candidate; i++) {
			if ((int)pow((double)i, 2.) == candidate) {
				counter++;
				printf("%d is a perfect square.\n", candidate);
				break;
			}
		}
	}
	return 0;
}
