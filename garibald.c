#include <stdbool.h>
#include <stdio.h>

char exchange_Char (char changer, char changee, bool (*cb) (char)) {
	char changed = changee;
	if (cb(changee)) {
		changed = changer;
	}
	return changed;
}

int main () {
	int characterread = '\0';
	printf("Type your string: ");
	char changer;
	char changee;
	changer = getchar();
	getchar();
	for (; (changee=getchar()) != '.';) {
		changee = 97 <= changee && changee <= 122 ? exchange_Char(changer, changee, ({
			bool __fn__ (char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
			__fn__;
		})) : changee;
		printf("%c", changee);
	}
	printf("\n");
	return 0;
}
