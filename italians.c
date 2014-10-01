// Italians do it better.
#include <stdio.h>
#include <ctype.h>

int is_italian(char character) {
	int returned_value = 1;
	if (
		character != 'j' && character != 'k' && character != 'w' && character != 'x' && character != 'y'
	) {
		returned_value = 1;
	} else {
		returned_value = 0;
	}
	return returned_value;
}

int main () {
	char character;
	printf("Type a character: ");
	scanf("%c", &character);
	if (is_italian(character)) {
		printf("You've typed an italian character!\n");
	} else {
		printf("You've NOT typed an italian character.\n");
	}
	return 0;
}
