/*
    Use of Simple arrays as parameters
    MergeSort (simple sort algorithm)
    Display each loop
    Easy but inefficient (Useful just for small arrays)
    -- 
    Qué hace?: El programa recibe un arreglo de números enteros y lo organiza de menor a mayor
    usando el algoritmo "merge sort". 

    Cómo funciona?: Es una variación de "merge sort" que se aplica a arreglos más extensos cuya
    longitud sea una potencia de 2. En este caso se van comparando arreglos de 1, 2, 4, ...
    elementos usando la función merge, luego se trasladan todos los elementos del tercer arreglo
    generado por merge al arreglo original.

    Desventaja: Cuando hay valores repetidos en los arreglos a y b, aparece más de una vez dicho valor en el arreglo c. 
    --
    Helliot May 7, 2024
*/

#include <stdio.h>
#define SIZE 8

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

void merge_sort( int key[], int how_many){
    int j,k;
    int w[how_many];

    for (k=1; k<how_many; k*=2){
        for (j=0;j<how_many-k; j+=2*k)
            /*
                Bajo la notación key+j ó key+j+k ó w+j estamos usando aritmetica de punteros
                para particionar el arreglo, es decir, estamos pasando un puntero que inicia
                en el índice j y refiere a este elemento del arreglo key ó en el índice j+k. 
                Al hacer key+j adicionamos j a la dirección de memoria donde inicia el arreglo key 
                y el resultado es la dirección de memoria del elemento j.
                Al pasar a la función merge, el valor de k establece el número de elementos en los que
                va a recorrerse desde la dirección de memoria que pasa por argumento:
                * Asi para k=1, j=0 recorre hasta un elemento, retorna el arreglo a = 67 y b=82
                * Para k=2, j=0 recorre hasta dos elementos, retorna el arreglo a = [67, 82] y
                  b = [83,88].
                El arreglo ordenado se guarda en w.
                Ojo: Lo anterior funciona teniendo en cuenta que, al pasar un arreglo como argumento de
                una función se efectúa un "array decay" (en realidad se pasa un puntero a la dirección base
                del arreglo, no un arreglo en sí).
            */
            merge(key + j, key + j + k, w + j, k);
        for (j=0; j<how_many; j++)
            /*
                Finalmente, se reescriben los elementos ordenados guardados en w al arreglo original key.
            */
            key[j] = w[j];
    };
}

int main(void) {
    // int a[SIZE] = {67, 82, 83, 88};
    int a[SIZE] = {99, 82, 74, 85, 92, 67, 76, 49};

    print_array(SIZE, a, "My grades\n");
    printf("\n\n");
    merge_sort(a, SIZE);
    printf("\n\n");
    print_array(SIZE, a, "My sorted grades\n");
    printf("\n\n");
    return 0;
}