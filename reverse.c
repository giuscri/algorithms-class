#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *reverse (const char *s) {
	char *r = (char*)calloc(strlen(s), sizeof(char));
	char *p = s + strlen(s) - 1;
	for (; p != s;) {
		*r = *p;
		p = p - 1;
		r = r + 1;
	}
	*r = *p;
	r = r - strlen(s) + 1;
	return r;
}

int main () {
	char *s = "Hacker";
	char *r = reverse(s);
	assert(strncmp(r, "rekcaH", strlen(s)) == 0 && "Reversing \"Hacker\" failed.");
	free(r);
	return 0;
}
