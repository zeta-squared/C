#include <stdio.h>
#include <ctype.h>

#define NUM_CHARS ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
    int i = 0;
    char ch, a[100] = {0};

    printf("Enter message: ");
    while((ch = getchar()) != '\n' && i < NUM_CHARS) {
        a[i] = toupper(ch);
        i++;
    }

    printf("In B1FF-speak: ");
    for (i = 0; i < NUM_CHARS; i++) {
        switch(a[i]) {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(a[i]);
                break;
        }
    }
    printf("!!!!!!!!!!\n");

    return 0;
}
