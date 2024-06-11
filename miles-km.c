/*
    Distance of marathon in yards
    November, 2023
*/

#include <stdio.h>

int main (void) {
    // Declaración con inicialización
    int miles,yards=385, ejemplo;
    // Declaración
    double kilometers;

    printf("Insert the marathon's distance in miles: ");
    scanf("%d", &miles);
    // Es importante tener en cuenta que, al dividir dos enteros en C que no se pueden expresar como un entero, obtendremos el entero más próximo
    // Si se divide un entero y un número decimal (punto flotante como float o double) el resultado es un número decimal
    kilometers = 1.609*(miles + yards/1760.0);
    printf("\n A marathon is %lf kilometers.\n", kilometers);
    ejemplo = 4/3;
    printf("\nEste es el ejemplo: %d\n", ejemplo);
    return 0;
}