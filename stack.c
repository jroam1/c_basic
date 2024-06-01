/*
    Basic Stack implementation in C.
    Functions are used to invert a given string.
    May, 2024
*/

#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack {
    char s[MAX_LEN];
    int top;
} stack;

void reset(stack *stk) {
    /*
        Se reinicia el stack, llevandolo al estado vacío.
    */
    stk->top = EMPTY;
};

void push(char c, stack *stk){
    /*
        Esta función aumenta en 1 el valor de top 
        y agrega el caracter al final del stack
    */
    stk-> top++;
    stk-> s[stk->top] = c;
};

char pop(stack *stk){
    /*
        Primero retorna el último elemento del stack
        y luego reduce en 1 el valor de top
    */
   return (stk-> s[stk-> top--]);
};

char top(const stack *stk){
    /*
        Retorna el caracter almacenado en el último 
        elemento del stack. Usamos const para evitar
        modificar la estructura, que se pasa por referencia
    */
   return (stk->s[stk->top]);
};

int is_empty(const stack *stk){
    /*
        Retorna 1 ó 0 dependiendo si top es igual a EMPTY
    */
   return (stk-> top==EMPTY);
};

int is_full(const stack *stk){
    /*
        Retorna 1 ó 0 según sea top igual a FULL
    */
   return (stk-> top==FULL);
};

int main(){
    stack stack_of_char;
    char *str = "i am otto am i";
    char str_back[20];
    int i=0;
    // Primero reseteamos el stack 
    reset(&stack_of_char);
    printf("Original string is: %s\n", str);
    // Insertamos cada caracter de la cadena en el stack
    while (str[i] != '\0'){
        printf("%c\n", str[i]);
        push(str[i++], &stack_of_char);
    };
    // Mientras el stack no este vacío, retorne el último 
    // caracter que va quedando en el stack y agreguelo
    // a la cadena str_back
    i = 0;
    while(!is_empty(&stack_of_char) && i<20){
        str_back[i] = pop(&stack_of_char);
        i++;
    };
    printf("Reverse string is: %s\n", str_back);
    printf("\n\n");
};




