/* Sums a sequence of numbers (using long variables) */

#include <stdio.h>

int main(void)
{
	double n, sum = 0.0;

	printf("This program sums a sequence of numbers.\n"
			"Enter numbers (0 to terminate): ");

	scanf("%lf", &n);
	while (n != 0.0) {
		sum += n;
		scanf("%lf", &n);
	}
	printf("The sum is: %lf\n", sum);

	return 0;
}
