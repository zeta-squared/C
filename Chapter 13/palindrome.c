#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char *message);

int main(void)
{
    char word[46], message[501];

    printf("Enter a message: ");
    do {
        scanf("%s", word);
        strcat(message, word);
        printf("%s\n", message);
    } while (getchar() != '\n');

    message[strlen(message) - 1] = '\0';

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p = &message[strlen(message) - 1];

    for (; *message != '\0'; message++, p--)
        if (*p != *message)
            return false;

    return true;
}
