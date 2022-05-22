#include <stdio.h>

#define N 80

int main(void)
{
    char a[N], *p = a, ch;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n') {
        *p = ch;
        p++;
    }
    
    for (p--; p >= a; p--)
        putchar(*p);
    putchar('\n');

    return 0;
}
