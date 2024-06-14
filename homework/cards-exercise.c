#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_CARDS 52


// Define the enum for card suits
typedef enum {
    Hearts,
    Diamonds,
    Clubs,
    Spades
} Suit;

// Define the struct for a card
typedef struct {
    Suit suit;
    short pips;
} Card;

void shuffle_deck(Card *deck){
    /*  
        This function shuffles the deck of cards.
    */
    int i,j;
    Card temp;

    for (i = NUM_CARDS-1; i>0; i--){
        j = rand()%(i+1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
};

int evaluateHand(Card *hand){
    int i,j;
    int rankCounts[13]={0};
    int suitCounts[4]={0};
    int pairCount=0;
    int threeKind=0;
    int fourKind=0;
}

