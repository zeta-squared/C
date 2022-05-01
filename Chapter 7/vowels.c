#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int vowels = 0;
	char ch;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n') {
		ch = tolower(ch);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			vowels += 1;
		}
	}
	printf("Your sentence contains %d vowels.\n", vowels);

	return 0;
}
