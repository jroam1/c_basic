/*
    Simple Queue as ADT in C
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#define FULL 1000
#define EMPTY 0

// Element in the Queue
typedef struct element {
    int data;
    struct element *next;
} element;

// Struct of the Queue
typedef struct {
    int count;
    element *front;
    element *rear;
} queue;

int is_empty(const queue *q){
    /*
        Retorna 1 si la cola está vacía ó 0
        si la cola contiene algún elemento.
    */
   return ( q->count == EMPTY);
};

int is_full(const queue *q){
    /*
        Retorna 1 si la lista está llena ó
        0 en caso contrario.
    */
   return ( q->count == FULL);
};

void initialize (queue *q){
    /*
        Inicializa la cola.
    */
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
};

void enqueue(int d, queue *q){
    /*
        Añadimos un nuevo elemento a la cola
    */
    element *p;

    // Creamos el elemento de la cola
    p = malloc(sizeof(element));
    p->data = d;
    p->next = NULL;

    // Añadimos el elemento a la cola
    if (!is_empty(q)){
        // Se agrega como fin de la cola si hay elementos
        q->rear->next = p;
        q->rear = p;
    } else {
        // se agrega como inicio y fin de la cola si no hay elementos
        q->front = q->rear = p;
    };
    // Aumentamos en 1 el número de elementos en la cola
    if ((q->count++) < FULL){
        q->count++;
    } else {
        q->count = FULL;
    }
};

int dequeue(queue *q){
    /*
        Retiramos el primer elemento de la cola.
    */
    int d;
    element *p;

    // Recuperamos el valor contenido en el elemento
    d = q->front->data;
    p = q->front;
    // Trasladamos el front al siguiente elemento de la lista
    q->front = q->front->next;
    // Reducimos en uno el número de elementos
    q->count--;
    // Liberamos el espacio ocupado por el elemento
    free(p);
    return d;
};

int front(queue *q){
    /*
        Retorna el valor del primer elemento de la cola.
    */
    return (q->front->data);
};

int rear(queue *q){
    /*
        Retorna el valor del último elemento de la cola.
    */
   return (q->rear->data);
};

int main(){    
    queue *process;
    int service;
    int f, r;

    // Inicializamos la cola
    initialize(process);

    // Añadimos elementos a la cola
    for (int i=0; i<10; i++){
        enqueue(i, process);
    }; 

    printf("Número inicial de elementos en cola : %d\n", process->count);

    // Retiramos el primer elemento de la cola
    service = dequeue(process);
    printf("El primer elemento a atender es: %d\n", service);

    // Retornamos el primer y último elemento de la cola
    f = front(process);
    r = rear(process);
    printf("El primer elemento es {%d} y el último elemento es {%d}\n", f, r);
    printf("Número final de elementos en cola: %d\n", process->count);
    return 0;
}







