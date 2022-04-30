//
// Sum a sequence of integers
//

#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	printf("This program sums a sequence of integers.\n"
			"Enter integers (0 to terminate): ");
	scanf("%d", &n);
	while (n != 0) {
		sum += n;
		scanf("%d", &n);
	}
	printf("The sum is: %d\n", sum);

	return 0;
}
