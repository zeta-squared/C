#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch, chars = 0;
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
        chars++;

    printf("Number of characters in %s: %d\n", argv[1], chars);
    fclose(fp);

    return 0;
}
