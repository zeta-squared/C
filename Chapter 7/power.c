#include <stdio.h>

int main(void)
{
	long int base, exponent, result;

	printf("Enter base: ");
	scanf("%ld", &base);
	printf("Enter exponent: ");
	scanf("%ld", &exponent);
	result = base;

	for (long int i = 2; i <= exponent; i++) {
		result *= base;
	}
	printf("Result: %ld\n", result);
}
