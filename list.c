/*
    Basic Single Link List implementation in C.
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {
    int data;
    struct list *next;
} list;

int is_empty(const list *l){
    /*
        Retorna 1 si la lista está vacía ó 0
        si la lista contiene algún elemento.
    */
    return (l == NULL);
};

void print_list(list *h, char *title){
    /*
        Imprime el elemento contenido en la lista
        luego apunta al siguiente elemento. 
    */
    printf("%s\n", title);
    while (h != NULL){
        printf("%d :", h->data);
        h = h->next;
    }
};

int main(void){
    list *head = NULL;
    head = malloc(sizeof(list));
    printf("sizeof(list) = %lu\n", sizeof(list));
    head->data = 5;
    head->next=NULL;
    print_list(head, "Single Element List");
    printf("\n\n");
    return 0;
};




