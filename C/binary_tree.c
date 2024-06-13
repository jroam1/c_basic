/*
    Basic Binary Tree as ADT in C
*/
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node{
    DATA d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
// Llamamos BTREE al puntero que apunta a un nodo, *node
typedef NODE *BTREE;

void inorder(BTREE root){
    /*
        Recorremos cada nodo de izquierda a derecha.
    */
    if (root != NULL){
        inorder(root->left);
        printf("%c", root->d);
        inorder(root->right);
    };
};

BTREE new_node(void){
    /*
        Separamos en memoria el espacio necesario para
        almacenar un nodo
    */
    return (malloc(sizeof(NODE)));
};

BTREE init_node(DATA d1, BTREE p1, BTREE p2){
    BTREE t;
    t = new_node();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
};

BTREE create_tree(DATA a[], int i, int size){
    /*
        Creamos un nodo para cada elemento del arreglo. 
        El valor de i se modifica de modo que para:
        root -> el hijo izquierdo será a[1] y el hijo derecho a[2]
        nodo 1 -> el hijo izquierdo sera a[3] y el hijo derecho a[4]
        nodo 2 -> el hijo izquierdo sera a[5] y el hijo derecho a[6]
        Y así sucesivamente .... 
    */
    if (i >= size){
        return NULL;
    } else {
        return (init_node(a[i], create_tree(a, 2*i + 1, size), create_tree(a, 2*i + 2, size)));
    }
};

int main(){
    char d[] = {'a', 'b', 'c', 'd', 'e'};
    BTREE b;
    b = create_tree(d, 0, 5);
    inorder(b);
    printf("\n\n");
    return 0;
};

/*
    El árbol binario resultante es:
                 a
                / \
               b   c
              / \
             d   e

    En el archivo explicacion_arbol.jpg se muestra la deducción de esta estructura.
    Es claro que al recorrer al arbol "in-order" el resultado es d-b-e-a-c
*/







