//
// Prints a table of squares using a while statement.
//

#include <stdio.h>

int main(void)
{
	int n, i = 1;

	printf("This program prints a table of squares.\n"
			"Enter number of entries in table: ");
	scanf("%d", &n);

	while (i <= n) {
		printf("\t%d\t%d\n", i++, i*i);
	}

	return 0;
}
