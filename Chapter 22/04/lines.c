#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch, lines = 0;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: count filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
        if (ch == '\n')
            lines++;

    printf("Number of lines in %s: %d\n", argv[1], lines);
    fclose(fp);

    return 0;
}
