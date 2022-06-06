#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: convert filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        if (isalpha(ch))
            putchar(toupper(ch));
        else
            putchar(ch);
    }

    fclose(fp);

    return 0;
}
