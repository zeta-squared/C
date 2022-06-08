#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

int main(int argc, char *argv[])
{
    struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
    } part1, part2;

    FILE *fpin1, *fpin2, *fpout;
    int fp1_read, fp2_read;

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

    fp1_read = fread(&part1, sizeof(part1), 1, fpin1);
    fp2_read = fread(&part2, sizeof(part2), 1, fpin2);
    while (fp1_read == 1 && fp2_read == 1) {
#ifdef DEBUG
        printf("%d %s\n", part1.number, part1.name);
        printf("%d %s\n", part2.number, part2.name);
#endif
        if (part1.number > part2.number) {
            fwrite(&part2, sizeof(part2), 1, fpout);
            fp2_read = fread(&part2, sizeof(part2), 1, fpin2);
        } else if (part1.number < part2.number) {
            fwrite(&part1, sizeof(part1), 1, fpout);
            fp1_read = fread(&part1, sizeof(part1), 1, fpin1);
        } else {
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
            fp1_read = fread(&part1, sizeof(part1), 1, fpin1);
            fp2_read = fread(&part2, sizeof(part2), 1, fpin2);
        }
    }

    while (fp1_read == 1) {
        fwrite(&part1, sizeof(part1), 1, fpout);
        fp1_read = fread(&part1, sizeof(part1), 1, fpin1);
    }

    while (fp2_read == 1) {
        fwrite(&part2, sizeof(part2), 1, fpout);
        fp2_read = fread(&part2, sizeof(part2), 1, fpin2);
    }

    fclose(fpin1);
    fclose(fpin2);
    fclose(fpout);

    return 0;
}
