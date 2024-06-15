#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_CARDS 52 
#define NUM_SIMULATIONS 1000000

// Define the enum for card suits
typedef enum {
    Hearts,
    Diamonds,
    Clubs,
    Spades
} suit;

// Define the struct for a card
typedef struct {
    suit suit;
    short pips;
} card;

void shuffle_deck(card *deck){
    /*  
        This function shuffles the deck of cards.
    */
    int i,j;
    card temp;

    for (i = NUM_CARDS-1; i>0; i--){
        j = rand()%(i+1); // Return a random position between 0 and 51
        temp = deck[i]; // Save the card in the position i
        deck[i] = deck[j]; // Put the card in the random position in the position i
        deck[j] = temp; // Put the card in the position i in the random position previously obtained
    }
};

int evaluate_hand(card *hand){
    /*
        This function evaluates a 7-card hand and determine its type.
        We consider only six types of hand: Pair, Two pair, Three of a kind,
        Four of a kind, full house and Nothing
    */
    int i,j;
    int rankCounts[13]={0}; //Count occurrences of each rank (Ace to King)
    int suitCounts[4]={0};  //Count ocurrences of each suit 
    int pairCount=0; // Count of pairs
    int threeKind=0; // Flag for three of a kind
    int fourKind=0; // Flag for four of a kind

    // First we count the occurrences of each rank and each suit
    for (i=0; i<7; i++){
        rankCounts[hand[i].pips - 1]++; // Increment 1 each time we have the same rank
        suitCounts[hand[i].suit]++; // Increment 1 each time we have the same suit
    };

    // Check for pairs, three of a kind, and four of a kind
    for (i=0; i<13; i++ ){
        if (rankCounts[i] == 2){
            pairCount++;
        } else if (rankCounts[i] == 3){
            threeKind++;
        } else if (rankCounts[i] == 4){
            fourKind++;
        };
    };

    // Check for full house
    if (threeKind && pairCount == 1){
        return 5;
    };

    // Check for three of a kind
    if (threeKind){
        return 3;
    };

    // Check for four of a kind
    if (fourKind){
        return 4;
    };

    // Check for pairs
    if (pairCount == 2){
        return 2; // Two pair
    } else if (pairCount == 1){
        return 1; // Pair
    };

    // if we dont have any of these options, we assume that the hand has nothing so...
    return 0;
};

void Monte_Carlo_simulations(card *deck, int *handTypeCount){
    // Seed the random number generator
    srand(time(NULL));
    int i,j;
    card hand[7]; // We create a hand of 7 cards
    int handType=0; // Store the type of the hand (0-5)
    
    // Perform the simulations
    for (i=0; i<NUM_SIMULATIONS; i++){
        // First we shuffle the deck (in each iteration)
        shuffle_deck(deck);

        // We deal the cards in hands of 7
        for (j=0; j<7; j++){
            hand[j] = deck[j];
        };

        handType = evaluate_hand(hand);

        // Count each time we have a particular type of hand
        if (handType < 6){
            handTypeCount[handType]++; // The index corresponds to the type of hand
            // Increment his value in 1 each time we have the same type
        };
    };
};

int main(void){
    card deck[NUM_CARDS]; // A deck of 52 cards 
    int handTypeCount[6] = {0}; // This initializacion is important. We count six types of hand
    int i,j;
    // Create the deck
    for (i=0; i<4; i++){ // Iterates the suites
        for (j=0; j<13; j++){ // Iterates the pips
            deck[i*13 + j].suit = i;
            deck[i*13 + j].pips = j+1;
        };
    };
    // Let's do the simulation
    Monte_Carlo_simulations(deck, handTypeCount);

    // Check the probablities
    printf("Probabilities based on Monte Carlo simulation:\n");
    printf("No Pair: %.8f\n", (double)handTypeCount[0] / NUM_SIMULATIONS);
    printf("One Pair: %.8f\n", (double)handTypeCount[1] / NUM_SIMULATIONS);
    printf("Two Pair: %.8f\n", (double)handTypeCount[2] / NUM_SIMULATIONS);
    printf("Three of a Kind: %.8f\n", (double)handTypeCount[3] / NUM_SIMULATIONS);
    printf("Four of a Kind: %.8f\n", (double)handTypeCount[4] / NUM_SIMULATIONS);
    printf("Full House: %.8f\n", (double)handTypeCount[5] / NUM_SIMULATIONS);
    return 0;
};
