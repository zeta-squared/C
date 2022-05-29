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
    } while (getchar() != '\n');

    message[strlen(message) - 1] = '\0';
    if (is_palindrome(message))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

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
