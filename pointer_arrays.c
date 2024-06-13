#include <stdio.h>
#include <string.h>


int main(void){
    // Declaramos un arreglo de punteros a char
    char *text[3];

    // Asignamos a cada puntero la dirección de memoria de los string indicados
    text[0] = "Hola, Violeta";
    text[1] = "Esta es una prueba";
    text[2] = "Porque no entiendo nada";

    for (int i=0;i<3;i++){
        // Muy importante: text[i] es un puntero, sin embargo al usar la función
        // printf() con el argumento %s, internamente desreferencia el puntero, por lo tanto
        // imprime el valor allí almacenado.
        // Si usamos el argumento %d, obtenemos la dirección de memoria directamente
        printf("Este es el elemento:%d\n", text[i]);
    }
    return 0;
};