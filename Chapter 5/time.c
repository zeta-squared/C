#include <stdio.h>

int main(void)
{
	int hour, minutes;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minutes);

	switch (hour) {
		case 0:
			printf("Equivalent 12-hour time: 12:%d AM\n", minutes);
			break;
		case 12:
			printf("Equivalent 12-hour time: 12:%d PM\n", minutes);
			break;
		default:
			if (hour > 12) {
				printf("Equivalent 12-hour time: %d:%d PM\n", (hour % 12), minutes);
			} else {
				printf("Equivalent 12-hour time: %d:%d AM\n", (hour % 12), minutes);
			}
			break;
	}

	return 0;
} 
