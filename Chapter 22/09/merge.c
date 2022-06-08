#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25;
#define MAX_PARTS 100;

int main(int argc, char *argv[])
{
    struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
    } part1, part2;

    FILE *fpin1, *fpin2, *fpout;
    int num_parts[2], i, j;

    if (argc != 4) {
        fprintf(stderr, "Usage: merge filename1 filename2 output_file\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fpin2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((fpout = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "Error: cannot create file %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    for (;(fread(&part1, sizeof(part1), 1, fpin1)) == 1 && \
            (fread(&part2, sizeof(part2), 1, fpin2)) == 1; ) {
        /* check if the two parts have the same part number */
        if (part1.number == part2.number) {
            // if the two parts have identical part numbers make sure the
            // part names match
            if (strcmp(part1.name, part2.name) != 0) {
                fprintf(stderr,\
                        "Part name for part number %d do not match between "\
                        "files being merged. Taking name from first file.\n",\
                        part1.number);
            }
            part1.on_hand += part2.on_hand;
            fwrite(&part1, sizeof(part1), 1, fpout);
        } else if (part1.number < part2.number) {
        } else {
        }
    }
}
