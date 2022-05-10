#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

int main(void)
{
    int i, j, k = 0, step, direction;
    char walk[10][10];
    char letters[] = {'A', 'B', 'C', 'D' ,'E', 'F', 'G', 'H', 'I', 'J', 'K',
                        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                        'W', 'X', 'Y', 'Z'};
    
    srand((unsigned) time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            walk[i][j] = '.';
        }
    }

    i = 0;
    j = 0;
    walk[i][j] = letters[k];
    while(k < 25) {
        direction = 0;
        step = rand();
        switch (step % 4) {
            case 0:
                if ((i - 1) >= 0 && walk[i-1][j] == '.') {
                    i -= 1;
                    k += 1;
                    walk[i][j] = letters[k];
                    break;
                }
                direction += 1;
            case 1:
                if ((j - 1) >= 0 && walk[i][j-1] == '.') {
                    j -= 1;
                    k += 1;
                    walk[i][j] = letters[k];
                    break;
                }
                direction += 1;
            case 2:
                if ((i + 1) <= 9 && walk[i+1][j] == '.') {
                    i += 1;
                    k += 1;
                    walk[i][j] = letters[k];
                    break;
                }
                direction += 1;
            case 3:
                if ((j + 1) <= 9 && walk[i][j+1] == '.') {
                    j += 1;
                    k += 1;
                    walk[i][j] = letters[k];
                    break;
                }
                direction += 1;
            default:
                if (direction >= 4) {
                    k = 25;
                }
                break;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%2c", walk[i][j]);
        }
        printf("\n");
    }

    return 0;
}
