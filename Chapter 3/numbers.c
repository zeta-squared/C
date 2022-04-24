#include <stdio.h>

int main(void)
{
	int r1c1, r1c2, r1c3, r1c4, r2c1, r2c2, r2c3, r2c4,
		r3c1, r3c2, r3c3, r3c4, r4c1, r4c2, r4c3, r4c4;
	int r1_sum, r2_sum, r3_sum, r4_sum,
		c1_sum, c2_sum, c3_sum, c4_sum,
		d1_sum, d2_sum;

	printf("Enter the numbers for 1 to 16 in any order:\n");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &r1c1, &r1c2, &r1c3, &r1c4,
			&r2c1, &r2c2, &r2c3, &r2c4, &r3c1, &r3c2, &r3c3, &r3c4,
			&r4c1, &r4c2, &r4c3, &r4c4);

	r1_sum = r1c1 + r1c2 + r1c3 + r1c4;
	r2_sum = r2c1 + r2c2 + r2c3 + r2c4;
	r3_sum = r3c1 + r3c2 + r3c3 + r3c4;
	r4_sum = r4c1 + r4c2 + r4c3 + r4c4;

	c1_sum = r1c1 + r2c1 + r3c1 + r4c1;
	c2_sum = r1c2 + r2c2 + r3c2 + r4c2;
	c3_sum = r1c3 + r2c3 + r3c3 + r4c3;
	c4_sum = r1c4 + r2c4 + r3c4 + r4c4;

	d1_sum = r1c1 + r2c2 + r3c3 + r4c4;
	d2_sum = r4c1 + r3c2 + r2c3 + r1c4;

	printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", r1c1, r1c2, r1c3, r1c4,
			r2c1, r2c2, r2c3, r2c4, r3c1, r3c2, r3c3, r3c4, r4c1, r4c2, r4c3, r4c4);
	printf("Row sums: %d %d %d %d\nColumn sums: %d %d %d %d\nDiagonal sums: %d %d\n",
			r1_sum, r2_sum, r3_sum, r4_sum, c1_sum, c2_sum, c3_sum, c4_sum, d1_sum, d2_sum);

	return 0;
}
