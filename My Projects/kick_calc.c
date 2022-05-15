#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define STRING_LENGTH 100
#define LETTERS ((sizeof(alphabet) / sizeof(alphabet[0])))

void clear_entry(char b[]);

int main(void)
{
    srand((unsigned) time(NULL));
    int i, j, distance, angle, to_clear = STRING_LENGTH;
    char b[STRING_LENGTH]={0};
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                        'w', 'x', 'y', 'z'};

    /* initialise dummy array of characters */
    if (((int) (1.0 + 3.0 * rand() / RAND_MAX)) == 1) {
        b[5] = 'b';
        b[13] = 'r';
        b[44] = 'u';
        b[91] = 'h';
        to_clear -= 4;
    } else {
        b[5] = 'b';
        b[13] = 'r';
        b[44] = 'u';
        b[91] = 'h';
        to_clear -= 4;
    }

    for (i = 0; i < STRING_LENGTH; i++)
        if (i != 5 && i != 13 && i != 44 && i != 91)
            b[i] = alphabet[(int) ((double) (LETTERS - 1) * rand() / RAND_MAX)];

    printf("Enter distance from goal line: ");
    scanf("%d", &distance);
    printf("Enter angle to goal posts: ");
    scanf("%d", &angle);

    for (i = 0; i < to_clear; i++) {
        for (j = 0; j < STRING_LENGTH; j++) {
            if (b[j] != 0) {
                putchar(b[j]);
            }
        }
        putchar('\n');
        clear_entry(b);
        for (j = 0; j < STRING_LENGTH; j++)
            if (j != 5 && j != 13 && j != 44 && j != 91 && b[j] != 0)
                b[j] = alphabet[(int) ((double) (LETTERS - 1) * rand() / RAND_MAX)];
        usleep(300000);
    }

    for (i = 0; i < STRING_LENGTH; i++)
        if (b[i] != 0)
            putchar(b[i]);

    putchar('\n');

    return 0;
}

void clear_entry(char b[])
{
    int index;

    index = (int) (((double) STRING_LENGTH) * rand() / RAND_MAX);
    if (index != 5 && index != 13 && index != 44 && index != 91 && b[index] != 0)
        b[index] = 0;
    else
        clear_entry(b);

    return;
}
