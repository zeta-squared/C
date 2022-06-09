#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int ch, digits[10] = {0}, i;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: phone filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        i = 0;
        do {
            if (isdigit(ch))
                digits[i++] = ch;
        } while ((ch = getc(fp)) != '\n');
        /*
        while ((ch = getc(fp)) != '\n')
            if (isdigit(ch))
                digits[i++] = ch;
        */

        putchar('(');
        for (i = 0; i < 3; i++)
            putchar(digits[i]);

        printf(") ");
        for (; i < 6; i++)
            putchar(digits[i]);

        putchar('-');
        for (; i < 10; i++)
            putchar(digits[i]);
        
        putchar(ch);
    }

    fclose(fp);

    return 0;
}
