#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compute_scrabble_value(const char *word);

int main(void)
{
	char word[46];

	printf("Enter a word: ");
    scanf("%s", word);
	printf("Scrabble value: %d\n", compute_scrabble_value(word));

	return 0;
}

int compute_scrabble_value(const char *word)
{
    int value = 0;
    int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10,
                   1, 1, 1, 1, 4, 4, 8, 4, 10};

    while (*word)
        value += score[(int) tolower(*word++) - 'a'];

    return value;
}
