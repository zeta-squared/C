#include <stdio.h>
#include <string.h>

#define STR 20

int main(void)
{
    char str[STR], smallest_word[STR], largest_word[STR];

    printf("Enter word: ");
    scanf("%s", str);
    strcpy(smallest_word, str);
    strcpy(largest_word, str);

    while (strlen(str) != 4) {
        printf("Enter word: ");
        scanf("%s", str);
        if (strcmp(str, smallest_word) < 0)
            strcpy(smallest_word, str);
        if (strcmp(str, largest_word) > 0)
            strcpy(largest_word, str);
    }
    
    printf("\nSmallest word: %s\nLargest word: %s\n",
            smallest_word, largest_word);

    return 0;
}
