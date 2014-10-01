#include <stdio.h>
#include <math.h>

int main () {
	float radius;
	printf("Type radius' value: ");
	scanf("%f", &radius);
	printf("Resulting area is: %.2f\n", powf(radius, 2.) * M_PI);
	return 0;
}
