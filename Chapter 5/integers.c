#include <stdio.h>

int main(void)
{
	int i1, i2, i3, i4, m1, M1, m2, M2, max, min;

	printf("Enter four integers: ");
	scanf("%d%d%d%d", &i1, &i2, &i3, &i4);
	
	if (i1 - i2 > 0) {
		M1 = i1;
		m1 = i2;
	} else {
		M1 = i2;
		m1 = i1;
	}

	if (i3 - i4 > 0) {
		M2 = i3;
		m2 = i4;
	} else {
		M2 = i4;
		m2 = i3;
	}

	if (M1 - M2 > 0) {
		max = M1;
	} else {
		max = M2;
	}

	if (m1 - m2 > 0) {
		min = m2;
	} else {
		min = m1;
	}

	printf("Largest: %d\nSmallest: %d\n", max, min);

	return 0;
}
