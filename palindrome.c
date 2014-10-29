#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool ispalindrome(const char *s) {
	bool ispalindrome = true;
	char *p = s;
	char *q = s + strlen(s) - 1;
	for (; p < q;) {
		if (*p != *q) {
			ispalindrome = false;
		}
		p = p + 1;
		q = q - 1;
	}
	return ispalindrome;
}

int main () {
	char *s = "Hacker";
	assert(ispalindrome(s) == false && "ispalindrome(\"Hacker\" failed.");
	s = "010";
	assert(ispalindrome(s) == true && "ispalindrome(\"010\" failed.");
	s = "RadaR";
	assert(ispalindrome(s) == true && "ispalindrome(\"RadaR\" failed.");
	s = "fooBAR";
	assert(ispalindrome(s) == false && "ispalindrome(\"fooBAR\" failed.");
	return 0;
}
