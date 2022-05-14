#include <stdio.h>

#define N 100

void selection_sort(int sort_index, int a[sort_index]);

int main(void)
{
    char ch;
    int i = 0, a[N], length = 0;

    printf("Enter a series of integers: ");
    do {
        scanf("%d", &a[i]);
        i++;
    } while ((ch = getchar()) != '\n');
    
    length = i;
    selection_sort(length - 1, a);
    printf("In sorted order: ");
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);

    printf("\n");
    
    return 0;
}

void
selection_sort(int sort_index, int a[sort_index])
{
    if (sort_index == 0) return;

    int i, max = a[0], max_index = 0;

    for (i = 1; i <= sort_index; i++) {
        if (a[i] > max) {
            max_index = i;
            max = a[i];
        }
    }

    a[max_index] = a[sort_index];
    a[sort_index] = max;
    selection_sort(sort_index - 1, a);
}
