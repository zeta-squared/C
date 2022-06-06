#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int ch, words = 0;
    bool in_word;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: count filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        if (isgraph(ch) && in_word == false) {
            words++;
            in_word = true;
        }

        if (isspace(ch))
            in_word = false;
    }

    printf("Number of words in %s: %d\n", argv[1], words);
    fclose(fp);

    return 0;
}
