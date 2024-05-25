/*
    Use of Simple arrays as parameters
    MergeSort (simple sort algorithm)
    Display each loop
    Easy but inefficient (Useful just for small arrays)
    -- 
    Qué hace?: El programa recibe dos arreglos de números enteros y los organiza de menor a mayor 
    en un tercer arreglo, que es el que finalmente se retorna. 

    Cómo funciona?: Se inicia comparando los primeros elemento ambos arreglos. 
    El menor valor entre ellos se agrega como primer elemento al tercer arreglo y se aumenta el índice 
    del arreglo que tenía el menor valor para reiniciar la comparación. De forma iterativa se van comparando 
    los elementos restantes de cada arreglo y se van reubicando los valores pequeños. 
    Al final, uno de los arreglos va a ser recorrido en su totalidad (el que tuvo el último valor más pequeño)
    mientras que el otro va a quedar con el último elemento sin comparar, para agregar este último elemento se agregan
    dos ciclos más, que solamente se activan si no se ha recorrido por completo alguno de los arreglos.
    Este algoritmo crece como nlog(n) -con n el número de elementos de cada arreglo -- y se conoce como "merge sort".

    Desventaja: Cuando hay valores repetidos en los arreglos a y b, aparece más de una vez dicho valor en el arreglo c. 
    --
    Helliot May 7, 2024
*/

#include <stdio.h>
#define SIZE 5

void print_array(int how_many, int data[], char *str){
    /*
        Imprime el valor de cada elemento del arreglo.
    */
    int i;
    printf("%s", str);

    for (i = 0; i < how_many; i++){
        printf("%d\t", data[i]);
    };
};

void merge(int a[], int b[], int c[], int size){
    int i = 0, j = 0, k = 0;

    while ( i<size && j<size )
        if (a[i] < b[j])
            c[k++] = a[i++];
            /*
                Esta formulación es equivalente a hacer:
                c[k] = a[i];
                k+=1;
                i+=1;
                Debido a la prelación del operador incremento-> En este caso i++ implica
                que el compilador usa primero el valor actual de i ó j y luego los aumenta.
            */
        else
            c[k++] = b[j++];
    
    while (i < size) 
        c[k++] = a[i++];

    while (j < size) 
        c[k++] = b[j++];
};

int main(void) {
    int a[SIZE] = {67, 82, 83, 88, 99};
    int b[SIZE] = {58, 69, 72, 81, 93};
    int c[2*SIZE];

    print_array(SIZE, a, "My grades\n");
    printf("\n\n");
    print_array(SIZE, b, "More grades\n");
    printf("\n\n");
    merge(a, b, c, SIZE);
    printf("\n\n");
    print_array(2*SIZE, c, "My sorted grades\n");
    printf("\n\n");
    return 0;
}