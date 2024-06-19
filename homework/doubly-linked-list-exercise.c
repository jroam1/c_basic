/*
    Doubly Linked List as ADT in C
    Johann Roa
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX_SIZE 210

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} list;


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
        Add a new element into the beginning of 
        the list. Return a pointer to the first
        element in the list.
    */
    list *head = create_list(d);
    head->next = h; 
    head->prev = NULL;
    if (h != NULL){
        // If the list is not empty, we indicate that 
        // the new element is the head of the list
        h->prev = head;
    }
    return head;
};

list *array_to_list(int d[], int size){
    /*
       Transform an array into a list adding each element
       in the beginning of the list.
       Each element is randomly generated
    */
    // Seed the random number generator with the current time
    srand(time(NULL));
    d[0] = rand()%50;
    list *head = create_list(d[0]);
    for (int i=1; i<size; i++){
        d[i] = rand()%50;
        head = add_to_beginning(d[i], head);
    };
    return head;
};

void print_list(list *h, char *title){
    /*
        Print every element into the list. 
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
        Return the number of elements into the list
    */
    if (h==NULL){
        return 0;
    } else {
        return(1 + count(h->next));
    };
};

void delete_repeated_elements(list *h){
    /*
        Check every element in the list, if an element 
        is repeated then it is removed from the list.  
    */

    list *temp = h; // Store each element in the list
    list *initial = h; // Store the list, allow restart the cicle
    list *new_prev; // Store the element before the current element
    list *new_next; //  Store the element after the current element

    while (temp != NULL){
        if (h->next == NULL){
            temp = temp->next;
            h = initial;
        } else if (temp->data == h->next->data && temp!=h->next){
            new_prev = (h->next)->prev;
            new_next = (h->next)->next;
            // Delete the repeated element
            if (new_next != NULL){
                ((h->next)->prev)->next = new_next;
            } else {
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
    printf("Initial number of elements:%d\n", count(head));
    print_list(head, "Before delete");
    delete_repeated_elements(head);
    print_list(head, "After delete");
    printf("Number of elements after delete operation:%d\n", count(head));
    printf("\n\n");
    return 0;
};



