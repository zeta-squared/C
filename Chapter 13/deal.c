#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = {{false}, {false}};
	int num_cards, rank, suit;
    const char *card_rank[] = {"Two", "Three", "Four", "Five", "Six", "Seven",
                          "Eight", "Nine", "Ten", "Joker", "Queen", "King",
                          "Ace"};
    const char *card_suit[] = {"clubs", "diamonds", "hearts", "spades"};


	srand((unsigned) time(NULL));

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	printf("Your hand:\n");
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS; // picks a random suit
		rank = rand() % NUM_RANKS; // picks a random rank
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf(" %s of %s\n", card_rank[rank], card_suit[suit]);
		}
	}
	printf("\n");

	return 0;
}
