#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define WORD_LEN 20
#define WORD_COUNT 2

int compare_str(const void *str1, const void *str2);

int main(void)
{
    int i, num_words = 0, max_words = WORD_COUNT;
    char word[WORD_LEN+1], **words = malloc(max_words * sizeof(*words));

    for (;;) {
        if (num_words == max_words) {
            max_words += WORD_COUNT;
            char **temp = realloc(words, max_words * sizeof(*temp));
            if (temp != NULL)
                words = temp;
            else
                printf("Error: Memory heap full.\n");
        }
        printf("Enter word: ");
        if (!read_line(word, WORD_LEN))
            break;

        words[i] = malloc(strlen(word) + 1);
        if (words[i] == NULL) {
            printf("Error: Memory heap exhausted."
                    "Cannot store any more words.\n");
            break;
        }

        strcpy(words[i++], word);
        num_words++;
    }

#ifdef DEBUG
    for (i = 0; i < num_words; i++)
        printf("%s\n", words[i]);
#endif

    qsort(words, num_words, sizeof(words[0]), compare_str);
    printf("In sorted order:");
    for (i = 0; i < num_words; i++)
        printf(" %s", words[i]);
    printf("\n");

    return 0;
}

int compare_str(const void *p, const void *q)
{
    return strcmp(*((char **) p), *((char **) q));
}
