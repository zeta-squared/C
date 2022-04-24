#include <stdio.h>

int main(void)
{
	int amount, twenty_bill, ten_bill, five_bill, one_bill;

	printf("Enter dollar amout: ");
	scanf("%d", &amount);

	twenty_bill = amount/20;
	ten_bill = (amount - 20*twenty_bill)/10;
	five_bill = (amount - 20*twenty_bill - 10*ten_bill)/5;
	one_bill = amount - 20*twenty_bill - 10*ten_bill - 5*five_bill;

	printf("$20 bills: %d\n", twenty_bill);
	printf("$10 bills: %d\n", ten_bill);
	printf("$5 bills: %d\n", five_bill);
	printf("$1 bill: %d\n", one_bill);

	return 0;
}
