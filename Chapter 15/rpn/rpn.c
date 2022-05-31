#include <stdio.h>
#include "stack.h"

int main(void)
{
    int i, j;
    char ch;

    printf("Enter an RPN expression: ");
    while (!is_full()) {
        scanf(" %c", &ch);
        switch(ch) {
            case '+':
                i = pop();
                j = pop();
                push(j + i);
                break;
            case '-':
                i = pop();
                j = pop();
                push(j - i);
                break;
            case '*':
                i = pop();
                j = pop();
                push(j * i);
                break;
            case '/':
                i = pop();
                j = pop();
                push(j / i);
                break;
            case '=':
                printf("Value of expression: %d\n", pop());
                break;
            default:
                push(ch);
                break;
        }
    }

    return 0;
}
