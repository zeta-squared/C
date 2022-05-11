#include <stdio.h>

#define MAX_CH 80

int main(void)
{
    int i = 0, shift, msg_length = 0;
    char ch, message[MAX_CH] = {0};

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n') {
        message[i] = ch;
        i++;
        msg_length++;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    printf("Encrypted message: ");
    for (i = 0; i < msg_length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (((message[i] - 'A') + shift) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (((message[i] - 'a') + shift) % 26) + 'a';
        }
        putchar(message[i]);
    }
    putchar('\n');

    return 0;
}
