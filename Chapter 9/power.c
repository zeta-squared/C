#include <stdio.h>

double power(double x, int n);

int main(void)
{
    int n;
    double x;

    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter an exponent: ");
    scanf("%d", &n);
    printf("%.2lf^%d = %.2lf\n",
            x, n, power(x, n));

    return 0;
}

double
power(double x, int n)
{
    if (n == 1) return x;

    if (n % 2 == 0) {
        x = power(x * x, n / 2);
    } else {
        x *= power(x * x, (n - 1) / 2);
    }

    return x;
}
