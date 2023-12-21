/*
    Tamaños específicos de los tipos de datos fundamentales según la máquina
    November, 2023
*/

#include <stdio.h>

int main (void) {
    int numerador_int = 5;
    int denominador_int = 2;
    double numerador_float = 5.0;
    double denominador__float = 2.0;

    printf("On my sistem -> \n");
    printf("Int is %lu bytes\n", sizeof(int));
    printf("Long int is %lu bytes\n", sizeof(long int));
    printf("Long long int is %lu bytes\n", sizeof(long long int));
    printf("Short int is %lu bytes\n", sizeof(short int));
    printf("Float is %lu bytes\n", sizeof(float));
    printf("Double is %lu bytes\n", sizeof(double));
    printf("Long double is %lu bytes\n", sizeof(long double));
    printf("Char is %lu bytes\n", sizeof(char));
    printf("Signed char is %lu bytes\n", sizeof(signed char));
    printf("Unsigned char is %lu bytes\n", sizeof(unsigned char));

    if (numerador_int)
        printf("Entero 5 divido 2 declarado como entero: %d \n", numerador_int/denominador_int);
        printf("Entero 5 divido 2 declarado como float: %lf \n", numerador_int/denominador__float);
        printf("Float 5 divido 2 declarado como entero: %lf \n", numerador_float/denominador_int);
        printf("Float 5 divido 2 declarado como float: %lf \n", numerador_float/denominador__float);

    printf("Entero 5 sumado a 2 declarado como float: %lf \n", numerador_int + denominador__float);
    printf("Float 5 sumado a 2 declarado como entero: %lf \n", numerador_float + denominador_int);
    printf("Float 5 sumando a 2 declarado como float: %lf \n", numerador_float + denominador__float);

    printf("Entero 5 multiplicado a 2 declarado como float: %lf \n", numerador_int*denominador__float);
    printf("Float 5 multiplicado a 2 declarado como entero: %lf \n", numerador_float*denominador_int);
    printf("Float 5 multiplicado a 2 declarado como float: %lf \n", numerador_float*denominador__float);
    return 0;
}