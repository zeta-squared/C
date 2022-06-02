#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int compare_dates(const struct date d1, const struct date d2);

int main(void)
{
    struct date dates[2];

    printf("Enter first date (dd/mm/yy): ");
    scanf("%d/%d/%d", &dates[0].day, &dates[0].month, &dates[0].year);
    printf("Enter second date (dd/mm/yy): ");
    scanf("%d/%d/%d", &dates[1].day, &dates[1].month, &dates[1].year);

    if (compare_dates(dates[0], dates[1]) == -1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                dates[0].day, dates[0].month, dates[0].year,
                dates[1].day, dates[1].month, dates[1].year);
    else if (compare_dates(dates[0], dates[1]) == 1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
                dates[1].day, dates[1].month, dates[1].year,
                dates[0].day, dates[0].month, dates[0].year);
    else
        printf("Both dates are the same.\n");

    return 0;
}

int compare_dates(const struct date d1, const struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;

    if (d1.month < d2.month)
        return -1;
    else if (d1.month > d2.month)
        return 1;

    if (d1.day < d2.day)
        return -1;
    else if (d1.day > d2.day)
        return 1;

    return 0;
}
