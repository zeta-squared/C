#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char *message);

int main(void)
{
    int i = 0;
    char word[46], message[501], ch;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && ch != '\?' && ch != '.') {
        if (ch == ',' || ch == '\'' || ch == ' ')
            continue;
        message[i++] = ch;
    }

    message[i] = '\0';
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
        if (tolower(*p) != tolower(*message))
            return false;

    return true;
}
