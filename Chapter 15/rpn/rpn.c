#include <stdio.h>
#include "stack.h"

#define PRINT_DEBUG(n) printf("Character read is: %c\n", n)

int main(void)
{
    int i, j;
    char ch;
    
    for (;;) {
        printf("Enter an RPN expression: ");
        do {
            scanf(" %c", &ch);
            switch(ch) {
                case '+': push(pop() + pop()); break;
                case '-': i = pop(); j = pop(); push(j - i); break;
                case '*': push(pop() * pop()); break;
                case '/': i = pop(); j = pop(); push(j / i); break;
                case '=': printf("Value of expression: %d\n", pop());\
                          make_empty(); break;
                case '0': case '1': case '2': case '3': case '4': case '5':\
                case '6': case '7': case '8': case '9':
                          push(9 - ((int) ('9' - ch))); break;
                default: return 0; 
            }
            #ifdef DEBUG
            PRINT_DEBUG(ch);
            printf("Stack empty: %d\n", is_empty());
            printf("Top stack index: %d\n", top);
            #endif
        } while (!is_empty());
    }

    return 0;
}
