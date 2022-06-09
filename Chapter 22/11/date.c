#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int day, m, year;
    char *month[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November",
                     "December"};

    if (argc != 2) {
        fprintf(stderr, "Usage: date dd/mm/yyy OR date dd-mm-yyyy\n");
        exit(EXIT_FAILURE);
    }

    if ((sscanf(argv[1], "%d-%d-%d", &day, &m, &year)) == 3)
        printf("%s %d, %d\n", month[m - 1], day, year);
    else if ((sscanf(argv[1], "%d/%d/%d", &day, &m, &year)) == 3)
        printf("%s %d, %d\n", month[m - 1], day, year);
    else
        fprintf(stderr, "Date entered in incorrect form\n");

    return 0;
}
