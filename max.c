#include <stdio.h>

int main () {
	int first, second;
	printf("Type in the first number: ");
	scanf("%d", &first);
	printf("Type in the second number: ");
	scanf("%d", &second);
	int is_first_the_max = first > second ? 1 : 0;
	if (is_first_the_max) {
		printf("%d is the maximum.\n", first);
	} else {
		printf("%d is the maximum.\n", second);
	}
	return 0;
}
