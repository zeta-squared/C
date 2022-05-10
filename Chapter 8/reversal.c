#include <stdio.h>

#define NUM_LETTERS ((int) (sizeof(sentence) / sizeof(sentence[0])))

int main(void)
{
    int i = 0, j;
    char sentence[1000], ch, terminating_ch;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '!' && ch != '\?' && ch != '.') {
        sentence[i] = ch;
        i++;
    }
    sentence[i++] = ch;
    terminating_ch = ch;

    for (; i >= 0; i--) {
        if (sentence[i] == ' ') {
            j = i + 1;
            while (sentence[j] != terminating_ch && sentence[j] != ' ') {
                putchar(sentence[j]);
                j++;
            }
            putchar(sentence[i]);
        } else if (i == 0) {
            j = i;
            while (sentence[j] != terminating_ch && sentence[j] != ' ') {
                putchar(sentence[j]);
                j++;
            }
        }
    }
    printf("%c\n", terminating_ch);

    return 0;
}
