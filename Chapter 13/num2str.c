#include <stdio.h>

int main(void)
{
    int tens, ones;
    char *t[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                 "eighty", "ninety"};
    char *o[] = {"one", "two", "three", "four", "five", "six", "seven",
                 "eight", "nine"};
    char *teens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", 
                     "sixteen", "seventeen", "eighteen", "nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &tens, &ones);
    if (tens == 1)
        printf("%s\n", teens[ones - 1]);
    else
        printf("%s %s\n", t[tens - 2], o[ones - 1]);

    return 0;
}
