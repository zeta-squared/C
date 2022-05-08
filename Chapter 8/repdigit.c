#include <stdio.h>
#include <stdbool.h>

#define NUM_SEEN ((int) (sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void)
{
	int digit, digit_seen[10] = {false};
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (!digit_seen[digit]) {
            digit_seen[digit] = true;
        }
		n /= 10;
	}

    if (n > 0) {
        printf("Repeated digit(s):");
        for (int i = 0; i < NUM_SEEN; i++) {
            if (digit_seen[NUM_SEEN]) {
                printf(" %d", i);
            }
        }
        printf("\n");
    } else {
        printf("No repeated digits\n");
    }

	return 0;
}
