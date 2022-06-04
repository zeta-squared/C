#include <stdio.h>

int main(void)
{
    int i;
    double d;
    char ch;

    printf("bytes in integer = %d\n", ((int) sizeof(i)));
    printf("bytes in double = %d\n", ((int) sizeof(d)));
    printf("bytes in char = %d\n", ((int) sizeof(ch)));

    return 0;
}
