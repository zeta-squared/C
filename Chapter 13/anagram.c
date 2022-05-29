#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[46], word2[46];

    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);

    if (are_anagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int i, letters[26] = {0};
    if (strlen(word1) != strlen(word2))
        return false;

    for (; word1 < word1 + strlen(word1); word1++, word2++) {
        letters[tolower(*word1) - 'a']++;
        letters[tolower(*word2) - 'a']--;
    }

    for (i = 0; i < 26; i++)
        if (letters[i] != 0)
            return false;

    return true;
}
