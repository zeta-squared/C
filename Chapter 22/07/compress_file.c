#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned char count;
    long int position;
    char *filename;
    FILE *fp, *wp;
    unsigned char byte, next_byte;

    if (argc != 2) {
        fprintf(stderr, "Usage: compress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    filename = malloc(strlen(argv[1]) + 5);
    sprintf(filename, "%s.rle", argv[1]);
    if ((wp = fopen(filename, "wb+")) == NULL) {
        fprintf(stderr, "Error: cannot create file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while(fread(&byte, sizeof(unsigned char), 1, fp) > 0) {
        count = 1;
        position = ftell(fp);
        while (fread(&next_byte, sizeof(unsigned char), 1, fp) > 0 &&\
                byte == next_byte)
            count++;
        fwrite(&count, sizeof(unsigned char), 1, wp);
        fwrite(&byte, sizeof(unsigned char), 1, wp);
        fseek(fp, position + count - 1, SEEK_SET);
    }

    fclose(fp);
    fclose(wp);

    return 0;
}
