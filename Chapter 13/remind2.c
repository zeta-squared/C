/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main (void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[9], time[6], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf(" -- No space left --\n");
            break;
        }

        printf("Enter day, time (24 hour format) and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        else if (day < 0 || day > 31) {
            printf("Error: invalid day value.\n");
            read_line(msg_str, MSG_LEN);
            continue;
        }
        sprintf(day_str, "%2d ", day);
        scanf("%s", time);
        if (strlen(time) < 5)
            strcat(day_str, "0");
        strcat(day_str, time);

        read_line(msg_str, MSG_LEN);
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Time  Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';

    return i;
}
