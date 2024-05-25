/*
    Basic Stack Implementation in C.
    May, 2024
*/

#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

// Definimos la estructura:
struct stack {
    char s[MAX_LEN];
    int top;
}

// Definimos la función reset
void reset(struct stack *stk) {
    stk->top++ = EMPTY;
};

// Definimos la función push
void push(char c, struct stack *stk){
    stk->top++;
    stk->s[stk->top] = c;
}


