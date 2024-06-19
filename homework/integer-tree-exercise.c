/*
    Transform an array of integers into a binary tree
    Johann Roa
    June, 2024
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NINT 100

struct node{
    int d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

void read_data(FILE *ptr, int d[], int *size, int *r_size){
    /*
        It takes the first integer as the size of the array and 
        adds the rest as array elements.
    */
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size])==1)
        (*size)++;
    *r_size = d[0];
    for (int i = 0; i <(*r_size); i++){
        d[i] = d[i+1];
    };
};

void print_data(int d[], int size, char *title){
    printf("%s\n", title);
    for (int i=0; i<size; i++){
        printf("%d\t", d[i]);
    };
    printf("\n\n");
}

void inorder(BTREE root){
    /*
        Traverse the tree in order.
    */
    if (root != NULL){
        inorder(root->left);
        printf("-%d-", root->d);
        inorder(root->right);
    };
};

BTREE new_node(void){
    /*
        It takes a specific memory space for the node
    */
    return (malloc(sizeof(NODE)));
};

BTREE init_node(int d1, BTREE p1, BTREE p2){
    BTREE t;
    t = new_node();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
};

BTREE create_tree(int a[], int i, int size){
    /*
        Create a node for each element in the array 
    */
    if (i >= size){
        return NULL;
    } else {
        return (init_node(a[i], create_tree(a, 2*i + 1, size), create_tree(a, 2*i + 2, size)));
    }
};

int main(int argc, char *argv[]){
    int r_sz, sz = MAX_NINT;
    FILE *ifp;
    int data[MAX_NINT];
    BTREE b;

    if (argc != 2){
        printf("Need executable inputfile. Invalid options.\n");
        exit(1);
    };
  
    ifp = fopen(argv[1], "r");
    read_data(ifp, data, &sz, &r_sz);
    print_data(data, r_sz, "Integer Array");
    b = create_tree(data, 0, r_sz);
    printf("Binary Tree Structure\n");
    inorder(b);
    printf("\n\n");
    return 0;
};

