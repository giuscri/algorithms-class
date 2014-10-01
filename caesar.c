#include <stdio.h>

int main () {
	int k;
	char current_character, lf;
	printf("Type the key: ");
	scanf("%d%c", &k, &lf);
	for (; (current_character = getchar()) != '.';) {
		if (current_character != ' ') {
			printf("%c", current_character + k);
		} else {
			printf("%c", current_character);
		}
	}
	printf("\n");
}
