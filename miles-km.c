/*
    Distance of marathon in yards
    November, 2023
*/

#include <stdio.h>

int main (void) {
    // Declaración con inicialización
    int miles,yards=385;
    // Declaración
    double kilometers;

    printf("Insert the marathon's distance in miles: ");
    scanf("%d", &miles);
    kilometers = 1.609*(miles + yards/1760.0);
    printf("\n A marathon is %lf kilometers.\n", kilometers);
    return 0;
}