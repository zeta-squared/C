#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *file;
    long int pos;
    FILE *fpin, *fpout;
    unsigned char ch, next_ch, count;

    if (argc != 2) {
        fprintf(stderr, "Usage: compress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    file = malloc(strlen(argv[1]) + 4);
    strcpy(file, argv[1]);
    strcat(file, ".rle");

    if ((fpout = fopen(file, "wb+")) == NULL) {
        fprintf(stderr, "Error: could not create new file.\n");
        exit(EXIT_FAILURE);
    }

    free(file);
    while ((fread(&ch, sizeof(unsigned char), 1, fpin)) > 0) {
        count = 1;
        pos = ftell(fpin);
        while ((fread(&ch, sizeof(unsigned char), 1, fpin)) > 0 && \
                    ch == next_ch)
            count++;
        fwrite(&count, sizeof(unsigned char), 1, fpout);
        fwrite(&ch, sizeof(unsigned char), 1, fpout);
        fseek(fpin, pos + count - 1, SEEK_SET);
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}
