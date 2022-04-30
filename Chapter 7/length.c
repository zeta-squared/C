#include <stdio.h>

int main(void)
{
	int characters = 0;

	printf("Enter a message: ");
	while (getchar() != '\n')
		characters += 1;
		;
	printf("Your message was %d character(s) long.\n", characters);
	
	return 0;
}
