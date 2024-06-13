/*
    Conversion of Fahrenheit to Celsius

    C = (F-32)/1.8
    Noviembre, 2023
*/

#include <stdio.h>

int main(void) {
    int fahrenheit, celsius;

    printf("Please enter fahrenheit degrees as an integer:");
    // %d es la notacion para indicar que se va a recuperar un valor entero
    // &fahrenheit indica que el valor recuperado se inyecte en la direccion de memoria creada por fahrenheit
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit - 32)/1.8; 
    printf("\n %d fahrenheit is %d celsius.\n", fahrenheit, celsius);
    return 0;
}