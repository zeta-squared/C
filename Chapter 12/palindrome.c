#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char ch, a[N], *p = a, *k = a;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n') {
        if (ch != ',' && ch != '\'' && ch != '.' && ch != '\?' && ch != ' ')
            *p++ = tolower(ch);
    }

    for (p -= 1; p >= a; p--, k++) {
        if (*p != *k)
            break;
    }

    if (++p == a)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
