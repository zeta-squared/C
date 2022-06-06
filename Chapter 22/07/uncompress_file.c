#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    long int position = 0;
    unsigned char count;
    unsigned char ch;
    char *filename;
    FILE *fp, *wp;

    if (argc != 2) {
        fprintf(stderr, "Usage: uncompress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    filename = malloc(strlen(argv[1]) + 13);
    snprintf(filename, strlen(argv[1]) - 2, "%s", argv[1]);
    strcat(filename, "uncompress_file");
    if ((wp = fopen(filename, "w+")) == NULL) {
        fprintf(stderr, "Error: cannot create file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /*
    while (fread(&count, sizeof(unsigned int), 1, fp) > 0) {
        fread(&ch, sizeof(unsigned int), 1, fp);
        printf("%u\n%c\n", count, ch);
    }
    */

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) {
        if (position % 2 == 0)
            count = ch;
        else {
            for (i = 0; i < count; i++)
                fwrite(&ch, sizeof(unsigned char), 1, wp);
        }
        position++;
    }

    fclose(fp);
    fclose(wp);

    return 0;
}
