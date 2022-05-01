#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch, initial;

	printf("Enter a first and last name: ");
	while ((ch = getchar()) == ' ')
		;
	initial = toupper(ch);

	while ((ch = getchar()) != ' ')
		;

	while ((ch = getchar()) == ' ')
		;

	putchar(toupper(ch));
	while ((ch = getchar()) != '\n' || ch == ' ')
	{
		putchar(ch);
	}
	putchar(',');
	putchar(' ');
	putchar(toupper(initial));
	putchar('.');
	putchar('\n');

	return 0;
}
