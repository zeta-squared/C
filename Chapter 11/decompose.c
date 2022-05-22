#include <stdio.h>

void decompose(double x, long *, double *);

int main(void)
{
    long i;
    double d;

    printf("Enter a number: ");
    scanf("%lf", &d);
    decompose(d, &i, &d);
    printf("Integer part is: %ld\nFractional part is: %lf\n",
            i, d);

    return 0;
}

void decompose(double x, long *int_part, double *frac_part)
{
    *int_part = (long) x;
    *frac_part = x - *int_part;

    return;
}
