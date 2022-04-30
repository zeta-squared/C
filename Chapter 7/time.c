#include <stdio.h>

int main(void)
{
	char ch;
	int hour = 0, minute = 0, hour_complete = 0;

	printf("Enter a 12-hour time: ");
	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case ':':
				hour_complete = 1;
				break;
			case 'A': case 'P': case 'M':
				break;
			default:
				putchar(ch);
				putchar((int) ch);
				if (hour_complete) {
					if (minute > 0) {
						minute *= 10;
						minute += ch;
					} else {
						minute += ch;
					}
				} else {
					if (hour > 0) {
						hour *= 10;
						hour += (int) ch;
					} else {
						hour += (int) ch;
					}
				}
				break;
		}
	}
	printf("Equivalent 24-hour time: %.2d:%d\n", hour, minute);

	return 0;
}
