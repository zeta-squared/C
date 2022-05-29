#include <stdio.h>
#include <string.h>

double compute_average_word_length(const char *sentence);

int main(void)
{
    int i = 0;
    char sentence[501], word[47];

	printf("Enter a sentence: ");
    while (1) {
        scanf("%s", word);
        if (getchar() != '\n') {
            strcat(sentence, strcat(word, " "));
        } else {
            strcat(sentence, strcat(word, "\0"));
            break;
        }
    }

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
    int words = 0;
    double letters = 0.0;

    for (; *sentence != 0; sentence++)
        if (*sentence == ' ')
            words++;
        else
            letters += 1.0;

    return letters/((double) (++words));
}
