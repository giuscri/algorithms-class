#include <stdio.h>
#include <math.h>

int main (int argc, char* argv[]) {
	char first_capital_letter, second_capital_letter;
	printf("Type in <first capital letter> and <second capital letter>: ");
	scanf("%c %c", &first_capital_letter, &second_capital_letter);
	printf("distance(%c, %c) is %d\n", first_capital_letter, second_capital_letter, (int)fabs(first_capital_letter - second_capital_letter) +1);
}
