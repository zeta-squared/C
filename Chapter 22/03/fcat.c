#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, ch;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: fcat filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Error: cannot open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        while ((ch = getc(fp)) != EOF)
            putchar(ch);

        fclose(fp);
    }

    return 0;
}
