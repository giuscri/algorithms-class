#include <assert.h>

int power_Int (int base, int exponent) {
	int power_Int;
	int index;
	for (power_Int = 1, index = 0; index < exponent; index++) {
		power_Int *= base;
	}
	return power_Int;
}

int main () {
	assert(power_Int(2,0) == 1 && "2 ** 0 test failed.");
	assert(power_Int(2,1) == 2 && "2 ** 1 test failed.");
	assert(power_Int(2,2) == 4 && "2 ** 2 test failed.");
	return 0;
}
