/* Simulate craps game */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char ch, new_game;
    bool result;
    int wins = 0, losses = 0;

    srand((unsigned) time(NULL));
    for(;;) {
        result = play_game();
        if (result) {
            printf("You win!");
            wins += 1;
        } else {
            printf("You lose!");
            losses += 1;
        }
        printf("\nPlay again? ");
        while ((ch = getchar()) != '\n'){
            if (tolower(ch) != 'y') {
                new_game = 'n';
                break;
            } else {
                new_game = 'y';
            }
        }
        if (new_game != 'y')
            break;
        printf("\n");
    }

    printf("\n\nWins: %d  Losses: %d\n", wins, losses);

    return 0;
}

int
roll_dice(void)
{
    double sum;
    sum = (1.0 + 6.0 * rand() / RAND_MAX) + (1.0 + 6.0 * rand() / RAND_MAX);

    return (int) sum;
}

bool
play_game(void)
{
    int sum, point;

    sum = roll_dice();
    if (sum == 7 || sum == 12) {
        printf("You rolled: %d\n", sum);
        return true;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You rolled: %d\n", sum);
        return false;
    }
    
    point = sum;
    printf("You rolled: %d\nYour point is %d\n", sum, point);
    while ((sum = roll_dice()) != point && sum != 7) {
        printf("You rolled: %d\n", sum);
    }

    if (sum == point) {
        printf("You rolled: %d\n", sum);
        return true;
    } else {
        printf("You rolled: %d\n", sum);
        return false;
    }
}
