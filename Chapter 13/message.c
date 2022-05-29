#include <stdio.h>
#include <string.h>

void reverse(char *message);

int main(void)
{
    char word[46], message[501];

    printf("Enter a message: ");
    do {
        scanf("%s", word);
        strcat(message, strcat(word, " "));
    } while (getchar() != '\n');
    
    message[strlen(message) - 1] = '\0';
    reverse(message);
    printf("%s\n", message);

    return 0;
}

void reverse(char *message)
{
    char *p = &message[strlen(message) - 1], ch;

    for (; p != message; message++, p--) {
        ch = *p;
        *p = *message;
        *message = ch;
    }

    return;
}
