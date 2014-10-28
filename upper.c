#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

char *upper (const char *s) {
	char *u = (char*)calloc(strlen(s) + 1, sizeof(char));
	int i = 0;
	for (i = 0; i < strlen(s); i++) {
		u[i] = (char)toupper((int)(s[i]));
	}
	u[strlen(s)] = '\0';
	return u;
}

int main () {
	char *s = "hacker";
	char *u = upper(s);
	assert(strncmp(u, "HACKER", strlen(s)) == 0 && "upper(\"hacker\") call failed.");
	free(u);
	return 0;
}
