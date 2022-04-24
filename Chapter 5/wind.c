#include <stdio.h>

int main(void)
{
	float knots;

	printf("Enter wind speed (knots): ");
	scanf("%f", &knots);

	if (knots < 1) {
		printf("Calm\n");
	} else if (knots < 4) {
		printf("Light air\n");
	} else if (knots < 28) {
		printf("Breeze\n");
	} else if (knots < 48) {
		printf("Gale\n");
	} else if (knots < 64) {
		printf("Storm\n");
	} else {
		printf("Hurricane\n");
	}

	return 0;
}
