#include <stdio.h>

#define NUM_SEEN ((int) (sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void)
{
	int digit, digit_seen[10] = {0};
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
        digit_seen[digit] += 1;
		n /= 10;
	}

    printf("Digit:      ");
    for (int i = 0; i < NUM_SEEN; i++) {
        printf("%3d", i);
    }
    printf("\n");

    printf("Occurences: ");
    for (int i = 0; i < NUM_SEEN; i++) {
        printf("%3d", digit_seen[i]);
    }
    printf("\n");

	return 0;
}
