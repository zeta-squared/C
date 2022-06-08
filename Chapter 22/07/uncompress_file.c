#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    char *filename;
    unsigned char pair[2];
    FILE *fpin, *fpout;

    if (argc != 2) {
        fprintf(stderr, "Usage: uncompress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((filename = malloc(strlen(argv[1]) + 13)) == NULL) {
        fprintf(stderr, "Error: memory heap exhausted.\n");
        exit(EXIT_FAILURE);
    }
    snprintf(filename, strlen(argv[1]) - 2, "%s", argv[1]);
    strcat(filename, "uncompress_file");

    if ((fpout = fopen(filename, "w+")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    free(filename);
    while ((fread(pair, sizeof(unsigned char), 2, fpin)) > 0) {
        for (i = 0; i < pair[0]; i++)
            fprintf(fpout, "%c", pair[1]);
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}
