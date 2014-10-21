#include <assert.h>
#include <stdbool.h>

bool isprime_Int (int n) {
	bool isprime = true;
	int i = 0;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			isprime = false;
			break;
		}
	}
	return isprime;
}

int main () {
	assert(isprime_Int(2) == true && "Primarity test failed on 2.");
	assert(isprime_Int(4) == false && "Primarity test failed on 4.");
	assert(isprime_Int(5) == true && "Primarity test failed on 5.");
	return 0;
}
