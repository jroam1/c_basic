/*
    Single Linked List as ADT in C
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

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

list *create_list(int d){
    /*
        Inicializa la lista. Separa un espacio de memoria heap
        y guarda un valor entero proporcionado como dato.
        El head apunta a NULL, para indicar que con este elemento
        acaba la lista.
        Retorna un puntero a head.
    */
    list *head = malloc(sizeof(list));
    head->data = d;
    head->next=NULL;
    return head;
};

list *add_to_front(int d, list *h){
    /*
        Permite agregar un elemento al final de la lista.
        El miembro next del nuevo head creado apunta ahora
        al elemento anterior en la lista. El nuevo elemento
        esta linkeado a través de un pointer al elemento anterior.
    */
    list *head = create_list(d);
    head->next = h; 
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
    for (int i=1; i<size; i++){
        head = add_to_front(d[i], head);
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

int main(void){
    list *head = NULL;
    list *head2 = NULL;
    int data[6] = {2,3,5,7,8,9};
    int data2[3] = {10,13,15};
    head = array_to_list(data, 6);
    head2 = array_to_list(data2, 3);
    print_list(head, "Element List");
    printf("Número de elementos en la lista = %d\n", count(head));
    concatenation(head, head2);
    print_list(head, "Concatenated list");
    printf("\n\n");
    return 0;
};



