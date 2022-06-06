#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_OFFSET 10

int main(int argc, char *argv[])
{
    int offset, n, i;
    FILE *fp;
    unsigned char chars[MAX_OFFSET];

    if (argc != 2) {
        fprintf(stderr, "Usage: contents filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");
    for (offset = 0;; offset += MAX_OFFSET) {
        n = fread(chars, sizeof(unsigned char), MAX_OFFSET, fp);
        if (n == 0)
            break;

        printf("%6d  ", offset);
        for (i = 0; i < n; i++)
            printf("%.2X ", (unsigned int) chars[i]);
        for (; i < MAX_OFFSET; i++)
            printf("   ");
        printf(" ");
        for (i = 0; i < n; i++) {
            if (!isprint(chars[i]))
                chars[i] = '.';
            printf("%c", chars[i]);
        }
        printf("\n");
    }

    fclose(fp);
    
    return 0;
}
