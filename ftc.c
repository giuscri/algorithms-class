#include <stdio.h>

float farenheit_to_celsius (int farenheit_temperature) {
	return (float)(farenheit_temperature - 32) * 5. / 9;
}

int main () {
	int farenheit_temperature = 0;
	printf("Type a farenheit temperature: ");
	scanf("%d", &farenheit_temperature);
	printf("Corresponding celsius temperature: %.2f\n", farenheit_to_celsius(farenheit_temperature));
	return 0;
}
