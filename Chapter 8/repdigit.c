#include <stdio.h>

#define NUM_SEEN ((int) (sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void)
{
	int digit, digit_seen[10] = {0}, dd = 0;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit] == 1) {
            dd += 1;
        }
        digit_seen[digit] += 1;
		n /= 10;
	}

    if (dd > 0) {
        printf("Repeated digit(s):");
        for (int i = 0; i < NUM_SEEN; i++) {
            if (digit_seen[i] > 1) {
                printf(" %d", i);
            }
        }
        printf("\n");
    } else {
        printf("No repeated digits\n");
    }

	return 0;
}
