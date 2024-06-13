/*
    Use of FILE I/O
    Se lee un archivo que contiene solamente numeros enteros
    y se calcula el promedio de estos datos.

    June, 2024
*/

#include <stdio.h>
#define MAX_N 20 // Número máximo de enteros permitido

void read_data(FILE *ptr, int d[], int *size){
    *size = 0;
    // El primer argumento de fscanf es un puntero al archivo a leer
    // El segundo argumento específica la conversión que debe hacerse sobre los bits leídos
    // El tercer argumento indica la variable en donde ha de guardarse el valor leído luego de su conversión
    while (fscanf(ptr, "%d", &d[*size])==1)
        (*size)++;
    // Pasamos el tamaño del arreglo "size" por referencia. Durante el ciclo se modifica su valor (contando, en este caso
    // el número de enteros contenido en el archivo). Por lo general lo que se cuenta en el while depende de lo que se
    // especifíca en el segundo parámetro -- pueden ser líneas, caracteres, palabras,...
    // De este modo que solo se llenan los espacios requeridos en "d" (a pesar de que el arreglo tiene 
    // más espacio del necesario y esto no puede cambiarse). Esta estrategia nos permite usar "size"
    // para calcular el promedio despues.
};

void print_data(int d[], int size){
    int i;
    for (i=0; i<size; i++){
        printf("%d\t", d[i]);
        if ((i+1)%10 == 0)
            printf("\n");
    };
};

double average(int d[], int size){
    int i;
    double avg = 0.0;

    for (i=0; i<size; i++){
        avg += d[i];
        return (avg/size);
    }
};

int main(void){
    int i, sz = MAX_N;
    FILE *ifp; // Input File Pointer
    int data[MAX_N] = {100,0};

    // La funcion fopen puede ejecutar tres acciones sobre el input file
    // r -> Abre el archivo como de solo lectura
    // w -> Abre el archivo con permiso de escritura: Puede escribir sobre el archivo
    // a -> Abre el archivo con permiso de edición: Puede agregar más líneas al archivo
    // Retorna un puntero al archivo.
    ifp = fopen("name_text", "r");
    read_data(ifp, data, &sz);
    printf("Number of integers in the file: %d", &sz);
    print_data(data, sz);
    printf("\n Average score was %10f", average(data, sz));
    printf("\n\n");
    // Si bien no es necesario cerrar el archivo, si se considera una buena práctica
    // liberar el puntero y así no usar más el archivo.
    fclose(ifp); 
    return 0;
};


