#include <stdio.h>

int main(void)
{
	float avg = 0.0f;
	int words = 0;
	char ch;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n') {
		if (ch != ' ') {
			avg += 1.0f;
		} else {
			words += 1;
		}
	}
	words += 1;
	avg = avg / words;
	printf("Average word length: %.1f\n", avg);

	return 0;
}
