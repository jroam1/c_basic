#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *name;
    char *symbol;
    double weight;
} element;

typedef struct list {
    element data;
    struct list *next;
} list;

int is_empty(const list *l){
    return (l == NULL);
};

list *create_list(element e){
    list *head = malloc(sizeof(list));
    head->data = e;
    head->next=NULL;
    return head;
};

int count(const list *h){
    if (h==NULL){
        return 0;
    } else {
        return(1 + count(h->next));
    };
};


list *add_to_front(element e, list *h){
    list *head = create_list(e);
    head->next = h; 
    return head;
};

void print_list(list *h, char *title){
    printf("%s\n", title);
    while (h != NULL){
        printf("%s - %s - %lf \n", (h->data).name, (h->data).symbol, (h->data).weight);
        h = h->next;
    }
    printf("\n\n");
};

list *add(element e, list *h){
    list *elements;

    // Creamos el nuevo elemento apartando un espacio en memoria específico
    element *new_element =(element *)malloc(sizeof(element));
    if (new_element == NULL){
        fprintf(stderr, "Memory allocation failed for new element\n");
        exit(1);
    };

    // Memoria para el nombre del elemento
    new_element->name = (char *)malloc((strlen(e.name) + 1)*sizeof(char));
    if (new_element->name == NULL){
        fprintf(stderr, "Memory allocation failed for name\n");
        exit(1);
    };
    // Copiamos en el espacio de memoria reservado el nombre del elemento
    strcpy(new_element->name, e.name);

    // Memoria para el simbolo del elemento
    new_element->symbol = (char *)malloc((strlen(e.symbol) + 1)*sizeof(char));
    if (new_element->symbol == NULL){
        fprintf(stderr, "Memory allocation failed for symbol\n");
        exit(1);
    };
     // Copiamos en el espacio de memoria reservado el simbolo del elemento
    strcpy(new_element->symbol, e.symbol);

    // Guardamos el valor del peso
    new_element->weight = e.weight;

    if (count(h) == 0){
        elements = add_to_front(*new_element, h);
    } else {
        elements = malloc(sizeof(list));
        elements->data = *new_element;
        elements->next = h;
    }
    return elements;
}

int main(){
    int count = 0;
    list *elements = NULL;
    element *e =  (element *)malloc(sizeof(element));

    // Initialize the structure Element
    if (e == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    };
    e->name = (char *)malloc(50 * sizeof(char)); // Allocate memory for name
    e->symbol = (char *)malloc(10 * sizeof(char)); // Allocate memory for symbol
    if (e->name == NULL || e->symbol == NULL) {
        fprintf(stderr, "Memory allocation for name/symbol failed\n");
        free(e);
        return 1;
    };
    // Input for add the elements
    printf("Insert element data:\n");
    while (count<2){
        printf("Element %d\n", count + 1);
        printf("Name: ");
        scanf("%s", e->name);
        printf("Symbol: ");
        scanf("%s", e->symbol);
        printf("Atomic Weight: ");
        scanf("%lf", &e->weight);
        elements = add(*e, elements);
        printf("Element %d: %s - %s - %lf added !!\n", count + 1, e->name, e->symbol, e->weight);
        count++;
    };
    printf("\n\n");
    print_list(elements, "Atomic Elements List");
    free(e->name);
    free(e->symbol);
    free(e);
    return 0;
}