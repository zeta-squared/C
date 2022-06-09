#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int item;
    double price;
    char date[11];
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: product_information filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item           Unit            Purchase\n"
            "               Price           Date\n");

    while ((fscanf(fp, "%d,%lf,%s\n", &item, &price, date)) == 3) {
        printf("%-15d$%7.2lf        %s\n", item, price, date);
    }

	return 0;
}
