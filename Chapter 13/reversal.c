#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char sentence[30][20], terminating_ch;

    printf("Enter a sentence: ");
    do {
        scanf("%s", sentence[i]);
        strcat(sentence[i++], "\0");
    } while (getchar() != '\n');

    terminating_ch = sentence[--i][strlen(sentence[i]) - 1];
    sentence[i][strlen(sentence[i]) - 1] = '\0';
    for (; i > 0; i--) {
        printf("%s ", sentence[i]);
    }

    printf("%s%c\n", sentence[i], terminating_ch);

    return 0;
}
