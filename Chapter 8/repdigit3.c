#include <stdio.h>

#define NUM_SEEN ((int) (sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void)
{
	int digit;
	long n, N;

	printf("Enter a number: ");

    while (scanf("%ld", &n) && n > 0) {
        N = n;
        int digit_seen[10] = {0};
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
        printf("(in %ld)\n", N);
    }

	return 0;
}
