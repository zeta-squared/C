#include <stdio.h>

#define NUM_FLIGHTS ((int) (sizeof(flights) / sizeof(flights[0])))

struct time {
    int departure;
    int arrival;
};

struct time flights[] = {{480, 616}, {583, 712}, {679, 811}, {767, 900},
                         {840, 968}, {945, 1075}, {1140, 1280},
                         {1305, 1438}};

int main(void)
{
    char departure[11], arrival[11];
    int i, hour, minute, closest;
    int error[NUM_FLIGHTS] = {0};

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    minute += 60 * hour;

    for (i = 0; i < NUM_FLIGHTS; i++)
        if (flights[i].departure <= minute)
            error[i] = minute - flights[i].departure;
        else
            error[i] = flights[i].departure - minute;

    for (i = 1, closest = 0; i < NUM_FLIGHTS; i++)
        if (error[closest] > error[i])
            closest = i;

    if (flights[closest].departure >= 780)
        sprintf(departure, "%d:%.2d p.m.", (flights[closest].departure - 720) / 60,
                (flights[closest].departure - 720) % 60);
    else if (flights[closest].departure >= 720)
        sprintf(departure, "12:%.2d p.m.", (flights[closest].departure - 720) % 60);
    else if (flights[closest].departure >= 60)
        sprintf(departure, "%d:%.2d a.m.", flights[closest].departure / 60,
                flights[closest].departure % 60);
    else
        sprintf(departure, "12:%.2d a.m.", flights[closest].departure % 60);

    if (flights[closest].arrival >= 780)
        sprintf(arrival, "%d:%.2d p.m.", (flights[closest].arrival - 720) / 60,
                (flights[closest].arrival - 720) % 60);
    else if (flights[closest].arrival >= 720)
        sprintf(arrival, "12:%.2d p.m.", (flights[closest].arrival - 720) % 60);
    else if (flights[closest].arrival >= 60)
        sprintf(arrival, "%d:%.2d a.m.", flights[closest].arrival / 60,
                flights[closest].arrival % 60);
    else
        sprintf(arrival, "12:%2d a.m.", flights[closest].arrival % 60);

    printf("Closest departure time is %s, arriving at %s\n", departure, arrival);

    return 0;
}
