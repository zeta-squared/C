#include <stdio.h>

#define NUM_RATES ((int) (sizeof(balance) / sizeof(balance[0])))
#define INITIAL_BALANCE 100.00
#define COMPOUND_FREQUENCY 12.0

int main(void)
{
	int rate, years;
	double balance[5];

	printf("Enter interest rate: ");
	scanf("%d", &rate);
	printf("Enter number of years: ");
	scanf("%d", &years);

	printf("\nYears");
	for (int i = 0; i < NUM_RATES; i++) {
		printf("%6d%%", rate + i);
		balance[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (int i = 0; i < years; i++) {
		printf("%3d", i+1);
		printf("    ");
		for (int j = 0; j < NUM_RATES; j++) {
            for (int k = 1; k <= COMPOUND_FREQUENCY; k++) {
                balance[j] += balance[j] * ((rate + j) / 100.0) / COMPOUND_FREQUENCY;
            }
			printf("%7.2f", balance[j]);
		}
		printf("\n");
	}

	return 0;
}
