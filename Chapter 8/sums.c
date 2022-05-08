#include <stdio.h>

#define ROWS 5
#define COLUMNS 5

int main(void)
{
    long a[ROWS + 1][COLUMNS + 1] = {0}; // added an additional row so that index matches row index
    long row_sums[ROWS + 1] = {0}, column_sums[COLUMNS + 1] = {0};

    for (int i = 1; i <= ROWS; i++) {
        printf("Enter row %d: ", i);
        for (int j = 1; j <= COLUMNS; j++) {
            scanf("%ld", &a[i][j]);
            row_sums[i] += a[i][j];
            column_sums[j] += a[i][j];
        }
    }

    printf("Row totals:");
    for (int i = 1; i <= ROWS; i++) {
        printf(" %ld", row_sums[i]);
    }
    printf("\nColumn totals:");
    for (int j = 1; j <= COLUMNS; j++) {
        printf(" %ld", column_sums[j]);
    }
    printf("\n");

    return 0;
}
