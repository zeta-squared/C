#include <stdio.h>
#include <string.h>

#define MAX_CH 200

void encrypt(char *message, int shift);

int main(void)
{
    int i = 0, shift;
    char word[46], message[MAX_CH + 1];

    printf("Enter message to be encrypted: ");
    do {
        scanf("%s", word);
        strcat(message, strcat(word, " "));
    } while (getchar() != '\n');

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    printf("Encrypted message: ");
    encrypt(message, shift);
    printf("%s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    for (; message < message + strlen(message); message++) {
        if (*message >= 'A' && *message <= 'Z')
            *message = (((*message - 'A') + shift) % 26) + 'A';
        else if (*message >= 'a' && *message <= 'z')
            *message = (((*message - 'a') + shift) % 26) + 'a';

    }

    return;
}
