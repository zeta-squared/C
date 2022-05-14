#include <stdio.h>

#define C 6.0

double power(double x, int n);

double main(void)
{
    double x;

    printf("Enter value for x: ");
    scanf("%lf", &x);
    printf("3x^7 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %.2lf\n",
            3.0*power(x, 7) + 2*power(x, 4) - 5*power(x, 3) - power(x, 2) + 7*x - C);

    return 0;
}

double
power(double x, int n)
{
    double val;

    if (n == 1) return x;
    val = x * power(x, n - 1);

    return val;
}
