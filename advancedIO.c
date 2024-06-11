/*
    Modifiers Format for Printf
*/
#include <stdio.h>


int main(void){
    double x = 0.123456789;
    printf("General Printing Ideas\n");
    // Diferentes formatos para mostrar el valor de x
    printf("x is %-12.5e and %e and %10.5f and %10d\n\n", x, x, x, x);

    // Los primeros modificadores (%-12.5e y %e) se usan para notación científica

    // El modificador %10.5f agrega 10 espacios en blanco antes del número
    // y especifica que se muestren solamente 5 cifras decimales

    // Interesante: los formatos %d, %s, ... no hacen en realidad una conversión
    // intepretan bajo ese tipo de dato especificado lo que este en bits almacenado
    // en la memoria. En este caso, %d no hace la conversión de 0.123456789 a su valor
    // entero, lo que hace es leer los 32 bit que lo representan como si fueran un número entero
    // por eso arroja 1485030048!!!
    // Para hacer la conversión debemos usar directamente las funciones de C:
    printf("x is %-12.5e and %e and %10.5f and %10d\n\n", x, x, x, (int)x);

    return 0;
}