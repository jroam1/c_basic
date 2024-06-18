/*
    Doubly Linked List as ADT in C
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#define MAX_SIZE 100

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} list;

int is_empty(const list *l){
    /*
        Retorna 1 si la lista está vacía ó 0
        si la lista contiene algún elemento.
    */
    return (l == NULL);
};

list *create_list(int d){
    /*
        Inicializa la lista. Separa un espacio de memoria heap
        y guarda un valor entero proporcionado como dato.
        El head apunta a NULL, para indicar que con este elemento
        acaba la lista.
        Retorna un puntero a head.
    */
    list *head = malloc(sizeof(list));
    if (head != NULL){
        head->data = d;
        head->next=NULL;
        head->prev=NULL;
    }
    return head;
};

list *add_to_beginning(int d, list *h){
    /*
        Permite agregar un elemento al inicio de la lista.
        El miembro next del nuevo head creado apunta ahora
        al elemento head de la lista. El nuevo elemento
        esta linkeado a través de un pointer al elemento siguiente.

        Opera de forma equivalente al metodo add_to_front de la 
        implementación single linked list en full_list.c
    */
    list *head = create_list(d);
    head->next = h; 
    head->prev = NULL;
    if (h != NULL){
        // Si la lista ya tiene elementos, debemos indicar que el 
        // primer elemento de la lista es justamente el nuevo elemento
        h->prev = head;
    }
    return head;
};

list *array_to_list(int d[], int size){
    /*
        Utilizando las operaciones anteriores, se transforma
        un arreglo en una lista.
        Al retornar head, estamos retornando el último elemento
        de la lista, así que ésta se recorrerá del final hacia el
        inicio. 
    */
    list *head = create_list(d[0]);
    // Seed the random number generator with the current time
    srand(time(NULL));
    for (int i=1; i<size; i++){
        d[i] = rand()%50;
        head = add_to_beginning(d[i], head);
    };
    return head;
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
    printf("\n\n");
};

int count(const list *h){
    /*
        Utilizando recursión, retorna el número
        de elementos contenido en la lista.
    */
    if (h==NULL){
        return 0;
    } else {
        return(1 + count(h->next));
    };
};

void delete_repeated_elements(list *h){
    list *temp = h; // Store each element in the list
    list *initial = h; // Store the list, allow restart the cicle
    list *new_prev;
    list *new_next;

    while (temp != NULL){
        // printf("Este es temp {%d} y este es h {%d}\n", temp->data, h->data);
        if (h->next == NULL){
            temp = temp->next;
            h = initial;
        } else if (temp->data == h->next->data && temp!=h->next){
            printf("Encontre uno repetido: %d\n", (h->next)->data);
            new_prev = (h->next)->prev;
            new_next = (h->next)->next;
            // Delete the repeated element
            if (new_next != NULL){
                printf("Este es el siguiente: %d\n", ((h->next)->next)->data);
                printf("Este es el previo: %d\n", new_prev->data);
                ((h->next)->prev)->next = new_next;
                // ((h->next)->next)->prev = new_prev;
            } else {
                printf("The last one is a repeated element\n");
                printf("Este es el penultimo: %d\n", ((h->next)->prev)->data);
                ((h->next)->prev)->next = NULL;
                break;
            };
        };
        h = h->next;
    }
};

int main(void){
    list *head = NULL;
    int data[MAX_SIZE];

    head = array_to_list(data, MAX_SIZE);
    printf("Numero de elementos en la lista:%d\n", count(head));
    print_list(head, "Before delete");
    delete_repeated_elements(head);
    print_list(head, "After delete");
    printf("Numero de elementos en la lista despues de delete:%d\n", count(head));
    printf("\n\n");
    return 0;
};



