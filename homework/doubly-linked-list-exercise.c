/*
    Doubly Linked List as ADT in C
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#define MAX_SIZE 200

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

void concatenation(list *h1, list *h2){
    /*
        Permite concatenar dos listas. Esencialmente
        usamos recursión para llegar al head de la lista
        h1. Al llegar allí sustituimos su next a NULL
        para que apunte al final de la lista h2. 
        Estrictamente, agregamos h1 a h2, puesto que 
        h2 conserva el head intacto.
        Al imprimirse la lista aparece h1 primero y luego
        aparece h2, por lo que pareciera que se ha agregado
        h2 a h1.
    */
   assert(h1 != NULL);
   if ( h1->next == NULL){
        h1->next = h2;
   } else {
        concatenation(h1->next, h2);
   };
};

void insert(list *p1, list *p2, list* q){
    /*
        Permite insertar un elemento a la lista
        en la posición intermedia de los 
        elementos p1 y p2. 
    */
   assert(p1->next == p2); // Garantizamos que p1 y p2 son consecutivos
   p1->next = q; // p1 apunta ahora a q
   q->next = p2; // q apunta a p2
};

void delete(list *elem, list **prev, list **hd){
    /*
        Elimina un elemento de la lista, para ello se índica
        el head de la lista y el elemento previo al que se quiere
        eliminar
    */
    // En C, TODO SE PASA POR CALL BY VALUE, todo se pasa por copia...
    // El call by reference es una trampa que usamos, pasando por copia un puntero
    // Ahora, los elementos previos a element y la cabeza de la lista se estan pasando
    // como puntero, pero necesitamos modificar ese puntero en sí, no el elemento
    // al que apunta, por eso hacemos una doble referenciación **

    if (*hd == *prev)
        // Si el elemento a eliminar es el head, trasladamos el head al siguiente elemento
        // del que se quiere eliminar
        *hd = elem->next;
    else 
        // Eliminamos el elemento, trasladando el next del elemento anterior al next del elemento
        // siguiente al que se ha eliminado
        (*prev)->next = elem->next;
    
    // Finalmente liberamos el espacio de memoria donde se aloja el elemento
    free(elem);
};

void delete_list(list *h){
    /*
        Elimina todos los elementos de la lista.
    */
    list *temp;
    if (h != NULL){
        temp = h;
        delete_list(h = h->next);
        free(temp);
    };
};

int main(void){
    list *head = NULL;

    // Prueba de funcionamiento 
    // head = create_list(10);
    // head2 = create_list(20);
    // for (int i = 0; i<10; i++){
    //     head = add_to_beginning(i, head);
    // }
    // print_list(head, "Añadiendo al inicio"); 
    // print_list(head2, "Añadiendo al final"); 

    // Ejercicio:
    int data[MAX_SIZE];
    head = array_to_list(data, MAX_SIZE);
    printf("Numero de elementos en la lista:%d", count(head));
    print_list(head, "Exercise");
    printf("\n\n");
    return 0;
};



