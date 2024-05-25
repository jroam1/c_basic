/*
    Use of Simple arrays as parameters
    Sorting Bubble Sort (simple sort algorithm)
    Display each loop
    Easy but inefficient (Useful just for small arrays)

    Qué hace?: El programa recibe un arreglo de números enteros y los organiza de menor a mayor
    retornando el mismo arreglo pero ya ordenado. 
    
    Cómo funciona?: Para modificar el arreglo directamente usa call-by-reference.
    Básicamente utiliza dos loops para recorrer el arreglo, el primer loop selecciona
    un elemento y con el segundo loop recorre desde el final el arreglo hasta la posición actual
    y va comparando los elementos (el actual con todos los elementos siguientes). Luego, utilizando 
    punteros reescribe el valor más pequeño en la posición actual y continua la siguiente iteración. 
    Esta técnica de ordenamiento se conoce como "bubble sort" y crece como n^2 -con n el número de elementos
    del arreglo-.
    
    Desventaja: Es ineficiente porque no puede determinar de forma autónoma si el arreglo
    ya esta ordenado y en consecuencia detenerse. El programa va a continuar imprimiendo el 
    arreglo hasta recorrerlo por completo. --
    Helliot May 7, 2024
*/

#include <stdio.h>
#define SIZE 5

void swap(int *a, int *b){
    /*
        Esta función utiliza el call-by-reference para intercambiar los valores 
        de las dos variables que se pasan como parámetro.
    */
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void print_array(int how_many, int data[], char *str){
    /*
        Imprime el valor de cada elemento del arreglo.
    */
    int i;
    printf("%s", str);

    for (i = 0; i < how_many; i++){
        printf("%d\t", data[i]);
    }
}

void bubble(int data[], int how_many){
    /*
        Recorre el arreglo en el sentido opuesto usando la función swap() para reorganizar los elementos 
        en orden ascendente de derecha a izquierda e imprime como va cambiando el arreglo usando la función 
        print_array().
    */
    int i,j;
    int go_on;

    for (i=0; i<how_many; i++){
        print_array(how_many, data, "\ninside bubble\n");
        printf("i = %d, input any int to continue:", i);
        scanf("%d", &go_on);
        for (j = how_many-1; j > i; j--){
            if (data[j-1] > data[j])
                swap(&data[j-1], &data[j]);
        }
    };
}

int main(void){
    // const int SIZE = 5; 
    /* 
       El compilador no permite crear el arreglo declarando el tamaño del mismo en tiempo
       de ejecución. Este tamaño debe especificarse como una expresión constante ya definida
       y conocida en tiempo de compilación, por esto hemos usado el preprocesador #define.
       Al usar const int ... estamos declarando el tamaño en tiempo de ejecución y no es conocido
       por el compilador para crear el arreglo en tiempo de compilación, por esto se genera el error.
       Este error aparece porque se usa una versión vieja del compilador, desde el estándar C23
       si se permite crear un arreglo usando como longitud el valor de una variable que se conoce
       en tiempo de ejecución, por esto al profe no le aparecia el error.    
    */
    int grades[SIZE] = {78, 67, 92, 83, 88};

    print_array(SIZE, grades, "My grades\n");
    printf("\n\n");
    bubble(grades, SIZE);
    printf("\n\n");
    print_array(SIZE, grades, "My sorted grades\n");
    printf("\n\n");

    return 0;
}
