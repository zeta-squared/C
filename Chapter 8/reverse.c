#include <stdio.h>

#define A ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
	int a[10];

	printf("Enter %d numbers: ", A);
	for (int i=0; i < A; i++) {
		scanf("%d", &a[i]);
	}

	printf("In reverse order:");
	for (int i=A-1; i>=0; i--) {
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
