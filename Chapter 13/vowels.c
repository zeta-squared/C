#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compute_vowel_count(const char *sentence);

int main(void)
{
	char sentence[201], string[47];

	printf("Enter a sentence: ");
    do {
        scanf("%s", string);
        strcat(sentence, strcat(string, " "));
    } while (getchar() != '\n');
	printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;

    while(*sentence) {
        if (*sentence == 'a' || *sentence == 'e' || *sentence == 'i' \
                || *sentence == 'o' || *sentence == 'u')
            vowels += 1;
        *sentence++;
    }

    return vowels;
}
